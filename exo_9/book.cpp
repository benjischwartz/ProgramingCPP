#include "std_lib_facilities.h"
#include "Book.h"


Book::Book(string _isbn, string _title, string _author, Date _copyright_date)
    :isbn{_isbn}, title{_title}, author{_author}, copyright_date{_copyright_date}, checked_in{true} {}

Book::Book() {
    isbn = "noISBN";
    title = "noTitle";
    author = "noAuthor";
    copyright_date = Date();
    checked_in = false;
}

// simple output operator for Book
ostream& operator<<(ostream& os, const Book& b) 
{
    return os << '(' << b.get_ISBN()
              << ',' << b.get_title()
              << ',' << b.get_author()
              << ',' << b.get_date() << ')';
}

// simple input operator for Book
istream& operator>>(istream& is, Book& bb)
{
    string i, t, a;
    Date d;
    char ch1, ch2, ch3, ch4, ch5;
    is>>ch1>>i>>ch2>>t>>ch3>>a>>ch4>>d>>ch5;
    if (!is) return is;
    if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ',' || ch5 != ')') {
        is.clear(ios_base::failbit);
        return is;
    }
    bb = Book{i,t,a,d};
    return is;
}

void Book::check_in()
{
    checked_in = true;
}

void Book::check_out()
{
    checked_in = false;
}

int main() {
    // Create a date
    Date test_date = Date{2001, 10, 12};
    
    // Create a Book
    Book test_book = Book{"DummyISBN", "Book Title", "Benji Schwartz", test_date};

    // Print out Book to terminal
    cout << "Book Summary: "<< test_book << endl;
}
