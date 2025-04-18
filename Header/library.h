#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include <string>
using namespace std;

class Library {
private:
    int Capacity; // Maximum number of books
    int Counter;  // Current number of books
    Book* books;  // Dynamic array of books


public:
    Library();
    ~Library();

    void addBook();
    void deleteBook();
    void dispBooks();
    void infoBook();
    int searchById(int id);
    void searchByAuthor(string author);
    void searchByTitle(string title);
    void updateBook();
};

#endif
