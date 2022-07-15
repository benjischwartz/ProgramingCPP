#include "std_lib_facilities.h"

void swap(vector<int>&, int, int);
void printv(vector<int>&);

int main() {
    vector<int> test {1, 3, 5, 7, 9};
    int i = 0;
    int j = test.size() - 1;
    while (i < test.size() && j >= 0) {
        if (i == j) break;
        swap(test, i, j);
        ++i;
        --j;
    }
    printv(test);    
}

void swap(vector<int>& v, int i, int j) {
    if (i < 0 || j < 0 || i >= v.size() || j >= v.size()) error("Out of range.");
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void printv(vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }
}
