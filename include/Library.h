#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"
#include "User.h"

class Library
{
private:
    vector<Book> books;
    vector<User> users;

public:
    void addBook();
    void viewBooks();
    void searchBook();

    void addUser();
    void viewUsers();

    void borrowBook();
    void returnBook();
};

#endif
