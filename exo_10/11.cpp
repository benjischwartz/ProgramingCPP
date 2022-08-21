// Program that produces the sum of al lthe whitespace-separated
// integers ina  text file. For example, "bears: 17 elephants 9 end"
// should output 26

#include "std_lib_facilities.h"

void skip_to_integer(ifstream& ist) {
    if (ist.fail()) {
        ist.clear();
        for (char c; ist >> c;) {
            // throw away non-digits
            if (isdigit(c)) {
                ist.unget();
                return;
            }
        }
    }
}

bool end_of_file(ifstream& ist) {
    char c;
    ist >> c;
    if (!ist) return true;
    else {
        ist.unget();
        return false;
    }
}

int main() {
    cout << "Enter filename:\n";
    string filename;
    cin >> filename;
    ifstream ist{filename};
    if (!ist) error("Unable to open file");

    int sum = 0;
    int x;
    while (true) {
        if (ist >> x) {
            sum += x;
        }
        else {
            skip_to_integer(ist);
        }
        if (end_of_file(ist)) break;
    }
    cout << "Result: " << sum << endl;
}
