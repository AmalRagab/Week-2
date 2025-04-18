#include "library.h"
#include <iostream>
#include <fstream>
using namespace std;

Library::Library() {
    Capacity = 100;
    Counter = 0;
    books = new Book[Capacity];

 //to read the number of books stored previously...
    ifstream in("counter.txt");
    if (in >> Counter) {

    } else {
        Counter = 0;
    }
    in.close();

 // to read the stored book data..
    ifstream bookIn("books.txt");

    // to read each book's information  and fill the books array...
    for (int i = 0; i < Counter; i++) {
        int id, year;
        string author, title;
        bool available;
        double price;

        bookIn >> id;
        bookIn.ignore();
        getline(bookIn, author);
        getline(bookIn, title);
        bookIn >> year >> available >> price;

        books[i] = Book(id, author, title, year, available, price);
    }

    // Close the file after reading all book data...
    bookIn.close();
}


// The destructor ensures that all data in memory is saved before the program exits....
Library::~Library() {

    //to save the current Counter...
    ofstream out("counter.txt");
    out << Counter;
    out.close(); //to ensure data is saved .....

// to save books to get it if program is closed...
    ofstream bookOut("books.txt");
    for (int i = 0; i < Counter; i++) {
        bookOut << books[i].getId() << '\n'
                << books[i].getAuthor() << '\n'
                << books[i].getTitle() << '\n'
                << books[i].getYear() << '\n'
                << books[i].isAvailable() << '\n'
                << books[i].getPrice() << '\n';
    }
    bookOut.close();
}



void Library::addBook() {
    if (Counter >= Capacity) {
        cout <<"library is full !! " <<endl ;
    }

    int id, year;
    string author, title;
    bool available;
    double price;

    while (1) {
        cout << "Enter the ID: ";
        cin >> id;

        if (searchById(id) != -1) {
            cout << "Already Exist!!" << endl;
            break;
        } else {
            cout << "Enter the Author: ";
            cin >> author;
            cout << "Enter the Title: ";
            cin >> title;
            cout << "Enter the Year: ";
            cin >> year;
            cout << "Enter Available (Yes '1' or No '0'): ";
            cin >> available;
            cout << "Enter the Price: ";
            cin >> price;

            books[Counter++] = Book(id, author, title, year, available, price);

            cout << "\nThe book is added successfully!" << endl;
            break;
        }
    }
}


int Library::searchById(int id) {
    for (int i = 0; i < Counter; i++) {
        if (books[i].getId() == id)
            return i;
    }
    return -1;
};

void Library::deleteBook(){
    int id ;
    cout<< "Enter the ID for the book you want to delete:- " ;
    cin >> id ;
     int index = searchById(id);
     // check if this book exist or not....
     if ( index == -1)
        cout << "NOT FOUND" << endl;
     else{
          for (int i = index ; i < Counter -1 ; i++) {
            books[i] = books[i+1];

    }
    cout<< " DELETED " << endl;
    Counter -- ; // because i will delete one ...
     }
};

void Library::dispBooks(){
// First, check if there are books or not ......
 if (Counter > 0) {
        for (int i = 0; i < Counter; i++) {
            cout << "Book ID: " << books[i].getId() << endl;
            cout << "Book Title: " << books[i].getTitle() << endl;
            cout << "Book Author: " << books[i].getAuthor() << endl;
            cout << "Book Year: " << books[i].getYear() << endl;
            cout << "Book Price: " << books[i].getPrice() << endl;
            cout << "Book Availability: " << (books[i].isAvailable() ? "Yes" : "No") << endl;
            cout << "-----------------------------" << endl;
        }
    } else {
        cout << "The library is empty!" << endl;
    }
};

void Library::infoBook(){
     int id ;
    cout<< "Enter the ID for the book you want to get information about it:- " ;
     cin >> id ;

     int index = searchById(id);
     // check if this book exist or not....
     if ( index == -1)
        cout << "NOT FOUND" << endl;
     else{
           cout << "Here's The Book... \n";
           books[index].Display();

    }


};


// if the user wants to search by author .....

void Library::searchByAuthor(string author){
    bool check = false ;
for (int i = 0 ; i < Counter  ; i++) {
        if ( books[i].getAuthor() == author){
            books[i].Display();
          cout << "---------------------"<<endl;
          check = true;
        }
    }
     if ( check == false )
        cout << " The author is not found." << endl;
};

// if the user wants to search by title .....

void Library::searchByTitle(string title){
    bool check = false ;
for (int i = 0 ; i < Counter  ; i++) {
        if ( books[i].getTitle() == title){
            books[i].Display();
          cout << "---------------------"<<endl;
          check = true;
        }
    }
     if ( check == false )
        cout << " The title is not found." << endl;
};


// if the user wants to update a book  .....
void Library::updateBook() {
    int id;
    cout << "Enter the ID of the book to update: ";
    cin >> id;

    int index = searchById(id);
    if (index == -1) {
        cout << "Book not found.\n";
        return;
    }

    cout << "The book details:\n";
    books[index].Display();

    string author, title;
    int year;
    double price;
    bool available;

    cout << "Enter new author: ";
    cin >> author;
    books[index].setAuthor(author);

    cout << "Enter new title: ";
    cin  >>  title;
    books[index].setTitle(title);

    cout << "Enter new year: ";
    cin >> year;
    books[index].setYear(year);

    cout << "Enter new price: ";
    cin >> price;
    books[index].setPrice(price);

    cout << "Is the book available? (1 for Yes, 0 for No): ";
    cin >> available;
    books[index].setAvailable(available);

    cout << "The book updated successfully.\n";
}
