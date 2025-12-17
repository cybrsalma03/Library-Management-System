#include "Library.h"
#include <iostream>

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