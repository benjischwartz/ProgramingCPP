// Takes two sorted whitespace-separated files of strings,
// and returns them concatenated and preserving order.

#include "std_lib_facilities.h"


int main() {
    string file1;
    string file2;
    cout << "Please enter the target files, separated by a space:\n";
    cin >> file1 >> file2;
    ifstream ist1{file1};
    ifstream ist2{file2};
    if (!ist1 || !ist2) error("couldn't open files");

    string result;
    cout << "Please enter the resulting file name:\n";
    cin >> result;
    ofstream ost{result};
    string s1;
    string s2;
    while (ist1 >> s1 && ist2 >> s2) {
        if (s1 < s2) {
            ost << s1 << ' ';
            // put s2 back
            ist2.unget();
        } else {
            ost << s2 << ' ';
            // put s1 back
            ist1.unget();
        }
    }
    // Empty remainder of either file
    if (!ist1) {
        while (ist2 >> s2) {
            ost << s2 << ' ';
        }
    }
    else {
        while (ist1 >> s1) {
            ost << s1 << ' ';
        }
    }
    cout << "Complete!\n";
}
