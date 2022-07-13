#include "std_lib_facilities.h"

// Given two vector<double>'s price and weight compute a value that
// is the sum of all price[i]*weight[i]. 
// Make sure to have weight.size() == price.size()

double compute(vector<double>, vector<double>);

void print_vector(vector<double>);


int main() {

    vector<double> prices;
    cout << "Enter prices. Terminate with ';'\n";
    double price = 0;
    while (cin >> price) {
        prices.push_back(price);
    } cin.ignore();

    vector<double> weights;
    cout << "Enter weights. Terminate with ';'\n";
    double weight = 0;
    while (cin >> weight) {
        weights.push_back(weight);
    }

    print_vector(prices);
    print_vector(weights);

    try {
        cout << "Result is: " << compute(prices, weights) << '\n';
    }

    catch(exception& e) {
        cerr << e.what() << '\n';
        keep_window_open();
    }

}

double compute(vector<double> prices, vector<double> weights) {
    if (prices.size() != weights.size()) {
        error("Different number of values");
    }
    double sum = 0;
    for (int i = 0; i < prices.size(); i++) {
        sum += prices[i]*weights[i];
    }
    return sum;
}

void print_vector(vector<double> v) {
    if (v.size() == 0) cout << "Empty!\n";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
    }
}
