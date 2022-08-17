#include "std_lib_facilities.h"
#include "Date.cpp"

class Book {
    public:

        //constructors
        Book(string isbn, string title, string author, Date copyright_date);
        Book();

        void check_in();
        void check_out();

        string get_ISBN() const {return isbn;}
        string get_title() const {return title;}
        string get_author() const {return author;}
        Date get_date() const {return copyright_date;}
        bool get_checked_in() const {return checked_in;}

    private:
        string isbn;
        string title;
        string author;
        Date copyright_date;
        bool checked_in;
        bool is_valid();
};


