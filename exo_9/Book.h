#include "std_lib_facilities.h"

struct ISBN {
    int n0;
    int n1;
    int n2;
    char x;
    ISBN(int n0, int n1, int n2, char x);
    ISBN();
};

class Book {
    public:

        //constructors
        Book(ISBN isbn, string title, string author, Date copyright_date);
        Book();

        void check_in();
        void check_out();

        string get_isbn() {return isbn};
        string get_title() {return title};
        string get_author() {return author};
        Date get_date() {return date};
        bool checked_in() {return checked_in};

    private:
        ISBN isbn;
        string title;
        string author;
        int copyright_date;
        bool checked_in = true;
        bool is_valid();
};


