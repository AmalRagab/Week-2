#include "library.h"
#include <iostream>
using namespace std;

int main() {
    Library lib;
    int choice;
     cout << "\n\t\t\t ***Welcome*** \n\n";
    while (true) {
        cout << "\n--> Library Menu:";
        cout << "\n 1. Add Book.";
        cout << "\n 2. Delete Book.";
        cout << "\n 3. Display Books.";
        cout << "\n 4. Get Book Info by ID.";
        cout << "\n 5. Search by Author.";
        cout << "\n 6. Search by Title.";
        cout << "\n 7. Update a book.";
        cout << "\n 0. Exit.\n";
        cout << "\n Note :: The program will not save your work if you close it without choosing Exit.\n ";
        cout << "\n Enter your choice , Please:- ";
        cin >> choice;
        cout << endl << endl;
        switch (choice) {
        case 1:
            lib.addBook();
            break;
        case 2:
            lib.deleteBook();
            break;
        case 3:
            lib.dispBooks();
            break;
        case 4:
            lib.infoBook();
            break;
        case 5: {
            string author;
            cout << "Enter Author: \n";
            cin >> author;
            lib.searchByAuthor(author);
            break;
        }
        case 6: {
            string title;
            cout << "Enter Title: ";
            cin >> title;
            lib.searchByTitle(title);
            break;
        }
        case 7 :
            lib.updateBook();
            break;
        case 0:
            cout << "Exiting Library Program...";
            return 0;
        default:
            cout << "Invalid choice! Please try again.";
        }
        cout << "\n\n \t\t---------------------" << endl << endl;
    }
}
