#include "Library.h"
#include <iostream>
#include <fstream>

using namespace std;

void Library::addBook()
{
    int id;
    string title, author, category;

    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore(); // clear newline
    cout << "Enter Book Title: ";
    getline(cin, title);
    cout << "Enter Author Name: ";
    getline(cin, author);
    cout << "Enter Book Category: ";
    getline(cin, category);

    // Check if book ID already exists
    for (const Book &b : books)
    {
        if (b.getId() == id)
        {
            cout << "Book ID already exists! Try again.\n";
            return;
        }
    }

    Book newBook(id, title, author, category, true);
    books.push_back(newBook);
    cout << "Book added successfully!\n";
    saveData();
}

void Library::viewBooks()
{
    if (books.empty())
    {
        cout << "No books available.\n";
        return;
    }

    cout << "\n===== All Books =====\n";
    for (const Book &b : books)
    {
        b.display();
    }
}

void Library::searchBook()
{
    if (books.empty())
    {
        cout << "No books available.\n";
        return;
    }

    string keyword;
    cout << "Enter book title or author to search: ";
    cin.ignore();
    getline(cin, keyword);

    bool found = false;
    for (const Book &b : books)
    {
        if (b.getTitle() == keyword || b.getAuthor() == keyword)
        {
            b.display();
            found = true;
        }
    }

    if (!found)
    {
        cout << "No book found with that title or author.\n";
    }
}

void Library::addUser()
{
    int id;
    string name;

    cout << "Enter User ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter User Name: ";
    getline(cin, name);

    // Check if user already exists
    for (const User &u : users)
    {
        if (u.getId() == id)
        {
            cout << "User ID already exists!\n";
            return;
        }
    }

    User newUser(id, name);
    users.push_back(newUser);
    cout << "User added successfully!\n";
    saveData();
}

void Library::viewUsers()
{
    if (users.empty())
    {
        cout << "No users available.\n";
        return;
    }

    cout << "\n===== All Users =====\n";
    for (const User &u : users)
    {
        cout << "ID: " << u.getId() << " | Name: " << u.getName() << endl;
    }
}

void Library::borrowBook()
{
    if (books.empty())
    {
        cout << "No books available.\n";
        return;
    }
    if (users.empty())
    {
        cout << "No users registered.\n";
        return;
    }

    int userId, bookId;
    cout << "Enter your User ID: ";
    cin >> userId;

    // Find user
    bool userFound = false;
    for (const User &u : users)
    {
        if (u.getId() == userId)
        {
            userFound = true;
            break;
        }
    }
    if (!userFound)
    {
        cout << "User ID not found!\n";
        return;
    }

    cout << "Enter Book ID to borrow: ";
    cin >> bookId;

    // Find book
    for (Book &b : books)
    {
        if (b.getId() == bookId)
        {
            if (b.available())
            {
                b.borrowBook();
                cout << b.getTitle() << " borrowed successfully!\n";
                saveData();
                return;
            }
            else
            {
                cout << b.getTitle() << " is already borrowed.\n";
                return;
            }
        }
    }

    cout << "Book ID not found!\n";
}

void Library::returnBook()
{
    if (books.empty())
    {
        cout << "No books available.\n";
        return;
    }

    int bookId;
    cout << "Enter Book ID to return: ";
    cin >> bookId;

    // Find book
    for (Book &b : books)
    {
        if (b.getId() == bookId)
        {
            if (!b.available())
            {
                b.returnBook();
                cout << b.getTitle() << " returned successfully!\n";
                saveData();
                return;
            }
            else
            {
                cout << b.getTitle() << " was not borrowed.\n";
                return;
            }
        }
    }

    cout << "Book ID not found!\n";
}

void Library::loadData()
{
    // Load Books
    ifstream bookFile("data/books.txt");
    if (bookFile.is_open())
    {
        int id;
        string title, author, category;
        bool isAvailable;
        while (bookFile >> id)
        {
            bookFile.ignore(); // ignore newline
            getline(bookFile, title);
            getline(bookFile, author);
            getline(bookFile, category);
            bookFile >> isAvailable;
            bookFile.ignore();
            books.push_back(Book(id, title, author, category, isAvailable));
        }
        bookFile.close();
    }

    // Load Users
    ifstream userFile("data/users.txt");
    if (userFile.is_open())
    {
        int id;
        string name;
        while (userFile >> id)
        {
            userFile.ignore();
            getline(userFile, name);
            users.push_back(User(id, name));
        }
        userFile.close();
    }
}

void Library::saveData()
{
    // Save Books
    ofstream bookFile("data/books.txt");
    for (const Book &b : books)
    {
        bookFile << b.getId() << "\n"
                 << b.getTitle() << "\n"
                 << b.getAuthor() << "\n"
                 << b.getCategory() << "\n"
                 << b.available() << "\n";
    }
    bookFile.close();

    // Save Users
    ofstream userFile("data/users.txt");
    for (const User &u : users)
    {
        userFile << u.getId() << "\n"
                 << u.getName() << "\n";
    }
    userFile.close();
}
