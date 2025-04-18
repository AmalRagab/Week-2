#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
    int Id;
    string Author;
    string Title;
    int Year;
    bool Available;
    double Price;

public:
    Book();
    Book(int id, string author, string title, int year, bool available, double price);
    Book(int id);
    Book(const Book& other);
    ~Book();

    //Getter....
    int getId() const;
    string getAuthor() const;
    string getTitle() const;
    int getYear() const;
    bool isAvailable() const;
    double getPrice() const;

    // Setter....
    void setId(int id) ;
    void setAuthor(string author) ;
    void setTitle(string title) ;
    void setYear( int year) ;
    void setAvailable(bool available) ;
    void setPrice( double price) ;

    //Display....
    void Display() const;
};

#endif
