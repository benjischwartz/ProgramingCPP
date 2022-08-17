/* chapter 9.4.2 - improved date class using member functions (of a struct)
   to ensure that dates are initialised before use, an add_day member function
   is also created
*/

#include <iostream>

using namespace std;

/* A stuct is essentially an all public class - you cannot effectively impose
   invariants on it's members */
struct Date {
  
  int y, m, d;
  Date();  
  Date (int y, int m, int d); // constructor - check validity
  void add_day(int n); // incrememnt date by n days
  void add_month(int n);
  void add_year(int n);
  
  enum Month {
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
  };
  
  class Invalid {};
};

// Date last(2000, 12, 31); colloqially initialises last
// Date christmas = Date(1976, 12, 24); verbosely initialises christmas
// Date birthday; error - no initialisation

Date::Date() {
    d = 1;
    m = 1;
    y = 1;
}

Date::Date(int y, int m, int d) {


  if (d <= 0) throw Invalid();

  /* ignoring leap year problem for now */
  switch (m) {

    case Date::apr: case Date::jun: case Date::sep: case Date::nov:
      if (d > 30) throw Invalid();
      break;

    case Date::feb:
      if (d > 29) throw Invalid();
      break;

    default: // month must be invalid
      if (d > 31) throw Invalid();
  }

  Date::y = y;
  Date::m = m;
  Date::d = d;
  // ... need to check constraints and initialise
}

void Date::add_year(int n) {
  Date::y += n;
}

void Date::add_month(int n) {

  Date::m = (Date::m + n) % 12;
  this->add_year(n / 12); // truncation intentional
}

void Date::add_day(int n) {



  int total = Date::d + n;
  /* ignoring leap year problem for now */
  switch (Date::m) {

    case Date::apr: case Date::jun: case Date::sep: case Date::nov:
      if (total > 30) {
        this->add_month(1);
        this->add_day(total - 30);
      }
      else Date::d = total;
      break;

    case Date::feb:
      if (total > 29) {
        this->add_month(1);
        this->add_day(total - 29);
      }
      else  Date::d = total;

      break;

    default: // month must be invalid
      if (total > 31) {
        this->add_month(1);
        this->add_day(total - 31);       
      }
      else Date::d = total;

  }

}

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.d
              << ',' << d.m
              << ',' << d.y << ')';
}

istream& operator>>(istream& is, Date& dd)
{
    int d,m,y;
    char ch1, ch2, ch3, ch4;
    is>>ch1>>d>>ch2>>m>>ch3>>y>>ch4;
    if (!is) return is;
    if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') {
        is.clear(ios_base::failbit);
        return is;
    }
    dd = Date{y,m,d};
    return is;
}
