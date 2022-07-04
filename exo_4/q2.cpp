#include "std_lib_facilities.h"

int main() {
    vector<double> values;
    for (double value; cin >> value; )
        values.push_back(value);

    sort(values);

    if (values.size() % 2) {
        // odd number of values in sequence
        cout << "Median temperature: " << values[values.size()/2] << '\n';
    }
    else {
        double average = (values[values.size()/2 - 1] + values[values.size()/2])/2;
        cout << "Median temperature: " << average << '\n'; 
    }
}
