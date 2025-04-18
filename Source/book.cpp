
#include "book.h"
#include <iostream>
using namespace std;

Book::Book() {
    Id= 0 ;
    Author= "";
    Title = "";
    Year = 0 ;
    Available = false ;
    Price = 0.0 ;
}

Book::Book(int id, string author, string title, int year, bool available, double price)
    { Id= id ;
    Author= author;
    Title = title;
    Year = year ;
    Available = available;
    Price = price ;

    }
 Book::Book(int id){
 Id = id ;
 }
Book::Book( const Book& other) {
        Id = other.Id;
        Author = other.Author;
        Title = other.Title;
        Year = other.Year;
        Available = other.Available;
        Price = other.Price;
    }

Book:: ~Book() {

    cout << "\nBook with ID: " << Id << " is being destroyed!" << endl;
    }

int Book::getId() const {

return Id;
 }
string Book::getAuthor() const {
     return Author;
      }
string Book::getTitle() const {
    return Title;
    }
int Book::getYear() const {
    return Year;
 }
bool Book::isAvailable() const{
    return Available;
    }
double Book::getPrice() const {
    return Price;
    }

void Book::setId(int id) {
     Id = id;
     }
void Book::setAuthor(string author) {
     Author = author;
     }
void Book::setTitle(string title) {
     Title = title;
     }
void Book::setYear(int year) {
    Year = year;
     }
void Book::setAvailable(bool available) {
    Available = available;
    }
void Book::setPrice(double price) {
     Price = price;
     }

void Book::Display() const {
    cout << "ID: " << Id << endl;
    cout << "Author: " << Author << endl;
    cout << "Title: " << Title << endl;
    cout << "Year: " << Year << endl;
    cout << "Available: " << (Available ? "Yes" : "No") << endl;
    cout << "Price: " << Price << endl;
}
