
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Book
{
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book()
    {
        id = 0;
        title = "";
        author = "";
        isIssued = false;
    }
};

// Save books to file
void saveBooks(vector<Book>& books)
{
    ofstream file("books.txt");

    for (int i = 0; i < books.size(); i++)
    {
        file << books[i].id << "|"
             << books[i].title << "|"
             << books[i].author << "|"
             << books[i].isIssued << "\n";
    }

    file.close();
}

// Load books from file
void loadBooks(vector<Book>& books)
{
    ifstream file("books.txt");

    if (!file)
        return;

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        Book b;
        string id, title, author, issued;

        getline(ss, id, '|');
        getline(ss, title, '|');
        getline(ss, author, '|');
        getline(ss, issued, '|');

        try
        {
            b.id = stoi(id);
            b.title = title;
            b.author = author;
            b.isIssued = (stoi(issued) != 0);

            books.push_back(b);
        }
        catch (...)
        {
            // Skip invalid records
        }
    }

    file.close();
}

// Add a book
void addBook(vector<Book>& books)
{
    Book b;

    cout << "Enter Book ID: ";
    cin >> b.id;

    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].id == b.id)
        {
            cout << "Book ID already exists!\n";
            return;
        }
    }

    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin, b.title);

    cout << "Enter Author Name: ";
    getline(cin, b.author);

    b.isIssued = false;

    books.push_back(b);

    saveBooks(books);

    cout << "Book added successfully!\n";
}

// Display all books
void listBooks(vector<Book>& books)
{
    if (books.empty())
    {
        cout << "No books available!\n";
        return;
    }

    cout << "\n--- Book List ---\n";

    for (int i = 0; i < books.size(); i++)
    {
        cout << "\nBook ID: " << books[i].id;
        cout << "\nTitle: " << books[i].title;
        cout << "\nAuthor: " << books[i].author;
        cout << "\nStatus: ";

        if (books[i].isIssued)
            cout << "Issued\n";
        else
            cout << "Available\n";
    }
}

// Search book by ID
void searchBook(vector<Book>& books)
{
    int bookId;
    bool found = false;

    cout << "Enter Book ID to search: ";
    cin >> bookId;

    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].id == bookId)
        {
            found = true;

            cout << "\nBook Found!";
            cout << "\nTitle: " << books[i].title;
            cout << "\nAuthor: " << books[i].author;
            cout << "\nStatus: ";

            if (books[i].isIssued)
                cout << "Issued\n";
            else
                cout << "Available\n";

            break;
        }
    }

    if (!found)
        cout << "Book not found!\n";
}

// Issue a book
void issueBook(vector<Book>& books)
{
    int bookId;
    bool found = false;

    cout << "Enter Book ID to issue: ";
    cin >> bookId;

    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].id == bookId)
        {
            found = true;

            if (books[i].isIssued)
            {
                cout << "Book is already issued!\n";
            }
            else
            {
                books[i].isIssued = true;
                saveBooks(books);

                cout << "Book issued successfully!\n";
            }

            break;
        }
    }

    if (!found)
        cout << "Book not found!\n";
}

// Return a book
void returnBook(vector<Book>& books)
{
    int bookId;
    bool found = false;

    cout << "Enter Book ID to return: ";
    cin >> bookId;

    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].id == bookId)
        {
            found = true;

            if (books[i].isIssued)
            {
                books[i].isIssued = false;
                saveBooks(books);

                cout << "Book returned successfully!\n";
            }
            else
            {
                cout << "This book was not issued!\n";
            }

            break;
        }
    }

    if (!found)
        cout << "Book not found!\n";
}

// Main function
int main()
{
    vector<Book> books;

    loadBooks(books);

    int choice;

    do
    {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. List All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addBook(books);
                break;

            case 2:
                listBooks(books);
                break;

            case 3:
                searchBook(books);
                break;

            case 4:
                issueBook(books);
                break;

            case 5:
                returnBook(books);
                break;

            case 6:
                saveBooks(books);
                cout << "Exiting Library System...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
