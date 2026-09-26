
#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    void SetTitle(string bookTitle) {
        title = bookTitle;
    }
    void SetNumPages(int bookNumPages) {
        numPages = bookNumPages;
    }
    void Print() const;

private:
    string title;
    int numPages;
};

void Book::Print() const {
    cout << title << ". Pages: " << numPages << endl;
}

int main() {
    Book myBook;

    myBook.SetTitle("Neuromancer");
    myBook.SetNumPages(271);

    myBook.Print();

    return 0;
}