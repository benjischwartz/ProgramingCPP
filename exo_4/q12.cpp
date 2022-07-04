
#include "std_lib_facilities.h"

int is_prime(int);

int main() {
    vector<int> primes;
    
    int max = 0;
    cout << "Please enter a maximum value: \n";
    cin >> max;

    
    for (int i = 2; i < max; ++i) {
        if (is_prime(i)) {
            // Prime
            primes.push_back(i); 
        }
    }
    
    for (int p : primes) {
        cout << p << '\n';
    }

    return 0;
}

int is_prime (int input) {
    double remainder;
    for (double i = 2.0; i < input; i++) {
        remainder = input / i - int(input / i); 
        if (remainder == 0) {
            return 0;
        }
    }
    return 1;
}
