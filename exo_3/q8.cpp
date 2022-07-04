#include "std_lib_facilities.h"

int main() {
    int input;
    cout << "Please enter an integer.\n";
    while (cin >> input) {
        int res = input % 2;
        if (res) {
            cout << "The value " << input << " is an odd number.\n";
        }
        else {
            cout << "The value " << input << " is an even number.\n";
        }
    }
}
