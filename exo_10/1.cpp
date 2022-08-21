// Program that produces the sum of all whitespace-separated integers
// in a given file.

#include "std_lib_facilities.h"

int main() {
    cout << "Please enter the target file:\n";
    string filename;
    cin >> filename;

    ifstream ist {filename};
    if (!ist) error("Couldn't open file ", filename);
    
    int sum = 0;
    for(int x; ist >> x;) {
        sum += x;
    }
    cout << "The sum is: " << sum << endl;
}
