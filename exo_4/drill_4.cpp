#include "std_lib_facilities.h"

int main() {
    double i1;
    double i2;
    while (cin >> i1 && cin >> i2) {
        if ((i1 - i2) < 1.0/100 && (i2 - i1) < 1.0/100) {
            cout << "the numbers are almost equal\n";
        }
        else if (i1 < i2) {
            cout << "the smaller value is: " << i1 << "\n";
            cout << "the larger value is: " << i2 << "\n";
        }
        else if (i2 < i1) {
            cout << "the smaller value is: " << i2 << "\n";
            cout << "the larger value is: " << i1 << "\n";
        }
        else {
            cout << "the numbers are equal\n";
        }
    }
}
