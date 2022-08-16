#include "std_lib_facilities.h"
#include "Book.h"


ISBN::ISBN(int _n0, int _n1, int _n2, char _x) {
    n0 = _n0;
    n1 = _n1;
    n2 = _n2;
    x = _x;
}

ISBN::ISBN() {
    n0 = 0;
    n1 = 0;
    n2 = 0;
    x = ‘0’;
}

Book::Book(ISBN _isbn, string _title, string _author, Date _copyright_date)
    :isbn{_isbn}, title{_title}, author{_author}, copyright_date{_copyright_date}

Book::Book() {
    isbn = ISBN();
    title = "noTitle";
    author = "noAuthor";
    copyright_date = Date();
    checked_out = false;
}

void Book::check_in()
{
    checked_in = true;
}

void Book::check_out()
{
    check_in = false;
}

bool Book::checked_in()
{
    return checked_in;
}

string Book::get_ISBN() 
{
    string isbn = to_string(isbn.n0) + to_string(isbn.n1) + to_string(isbn.n2) + isbn.x;
    return isbn;
}

string Book::get_title() 
{
    return title;
}

string Book::get_author() 
{
    return author;
}

int Book::get_date() 
{
    return copyright_date;
}
