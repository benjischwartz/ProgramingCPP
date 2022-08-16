#include "std_lib_facilities.h"

class Money {
    public:
        Money(string currency, long int amount) : currency{currency}, amount{amount}{}
        Money(string currency, double amount);
        double get_value();
        string get_currency(){return currency;}
        void set_value(long int _amount);
    private:
        long int amount;
        string currency;
};

Money::Money(string _currency, double _amount) {
    currency = _currency;
    amount = (long int) _amount * 100;
}

double Money::get_value() {
    return amount/100.00;
}

void Money::set_value(long int _amount) {
    amount = _amount;
}

int main() {
    Money m = Money{"USD", 1234};
    cout << m.get_currency() <<' '<< m.get_value() << endl;
    m.set_value(6969);
    cout << m.get_currency() <<' '<< m.get_value() << endl;
    Money m1 = Money("DKK", 1.23);
    cout << m1.get_currency() <<' '<< m1.get_value() << endl;
    Money m2 = Money("DKK", 1.256);
    cout << m2.get_currency() <<' '<< m2.get_value() << endl;
}
