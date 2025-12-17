#include "Book.h"
#include <iostream>

Book::Book()
{
    id = 0;
    title = "";
    author = "";
    category = "";
    isAvailable = true;
}

Book::Book(int id, string title, string author, string category, bool isAvailable)
{
    this->id = id;
    this->title = title;
    this->author = author;
    this->category = category;
    this->isAvailable = isAvailable;
}

int Book::getId() const
{
    return id;
}

string Book::getTitle() const
{
    return title;
}

string Book::getAuthor() const
{
    return author;
}

bool Book::available() const
{
    return isAvailable;
}

void Book::borrowBook()
{
    isAvailable = false;
}

void Book::returnBook()
{
    isAvailable = true;
}

void Book::display() const
{
    cout << "ID: " << id
         << " | Title: " << title
         << " | Author: " << author
         << " | Category: " << category
         << " | Status: " << (isAvailable ? "Available" : "Borrowed")
         << endl;
}
