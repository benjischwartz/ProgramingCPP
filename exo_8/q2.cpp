#include "std_lib_facilities.h"

void printv(const vector<int>&);

int main() {
    vector<int> test {1, 2, 3, 4, 5, 6};
    printv(test);
}

void printv(const vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;            
    }
}

