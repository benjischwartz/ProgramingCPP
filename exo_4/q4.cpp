#include "std_lib_facilities.h"

int main() {
    char input;
    int max = 100;
    int min = 0;
    int guess = 50;

    while (true) {

        cout << "My guess is " << guess << "\n";
        cout << "Is your number equal (=), less than (<) or greater than (>) this?\n";
        cin >> input;
        switch(input) {
            case '<':
                max = guess;
                guess = (min + max)/2;
                break;
            case '>':
                min = guess;
                guess = (min + max)/2;
                break;
            case '=':
                cout << "I've found your number!\n";
                return 0;
        }
    }
}
