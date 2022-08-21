// Program which concatenates two input files
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
    for (string s; ist1 >> s;) {
        ost << s << ' ';
    }
    for (string s; ist2 >> s;) {
        ost << s << ' ';
    }

    cout << "Complete!\n";
}
