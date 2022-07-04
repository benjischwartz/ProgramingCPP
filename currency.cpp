#include "std_lib_facilities.h"

int main() {
    constexpr char k = 'k';
    constexpr char y = 'y';
    constexpr char p = 'p';

    constexpr double ktoaud = 0.20;
    constexpr double ytoaud = 0.011;
    constexpr double ptoaud = 1.77;

    double value = 0;
    char currency = 'a';

    cout << "Please enter a value.\n";
    cin >> value;
    cout << "Please enter a currency (k, y or p)\n";
    cin >> currency;

    switch(currency) {
        case k:
            cout << "value: $" << value*ktoaud << " AUD\n"; 
            break;
        case y:
            cout << "value: $" << value*ytoaud << " AUD\n"; 
            break;
        case p:
            cout << "value: $" << value*ptoaud << " AUD\n"; 
            break;
        default:
            cout << "Sorry, I don't know this currency called " << currency << ".\n";
            break;            
    }
}
