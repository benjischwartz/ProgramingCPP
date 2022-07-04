#include "std_lib_facilities.h"

int main() {
    vector<string> digits = {"zero", "one", "two", "three", "four",
                            "five", "six", "seven", "eight", "nine"};
    int digit;

    cout << "Please enter a number:\n";

    while (cin >> digit) {
        cout << digits[digit] << '\n';
    }
    
}
