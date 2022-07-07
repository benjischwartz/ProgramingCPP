#include "std_lib_facilities.h"

// Program that reads digits and composes them into integers. 
// E.g. 123 is read as characters 1, 2, and 3. 
// Program should output '123 is 1 hundred and 2 tens and 3 ones'.
// The number should output as an int value
// Hint: integever value 5 from character '5' can be done by '5'-'0'==5.
// Handle 1, 2, 3 or 4 digit numbers.
int main() {
    vector<char> input_num; 
    cout << "Please enter a number up to 4 digits, terminated by ';':\n";
    char input_char;

    // Read first character
    cin >> input_char;

    while (input_char != ';') {
        input_num.push_back(input_char);
        cin >> input_char;
    }

    for (char c: input_num) {
        cout << c << ' ';
    } cout << '\n';

    if (input_num.size() == 4) {
        cout << input_num[0] - '0' << " thousands and "
            << input_num[1] - '0' << " hundreds and "
            << input_num[2] - '0' << " tens and "
            << input_num[3] - '0' << " ones.\n";
    }

    else if (input_num.size() == 3) {
        cout << input_num[0] - '0' << " hundreds and "
            << input_num[1] - '0'<< " tens and "
            << input_num[2] - '0'<< " ones.\n";
    }

    else if (input_num.size() == 2) {
        cout << input_num[0] - '0' << " tens and "
            << input_num[1] - '0' << " ones.\n";
    }

    else if (input_num.size() == 1) {
        cout << input_num[0] - '0' << " ones.\n";
    }

    else {
        error("Not a 4 digit number.");
    }

    return 0;
}
