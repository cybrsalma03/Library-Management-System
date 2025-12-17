#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book
{
private:
    int id;
    string title;
    string author;
    string category;
    bool isAvailable;

public:
    Book();
    Book(int id, string title, string author, string category, bool isAvailable);

    int getId() const;
    string getTitle() const;
    string getAuthor() const;
    string getCategory() const;
    bool available() const;

    void borrowBook();
    void returnBook();
    void display() const;
};

#endif
