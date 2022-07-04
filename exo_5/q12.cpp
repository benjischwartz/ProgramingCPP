#include "std_lib_facilities.h"

// Bulls and Cows
// vector of four different integers (0 to 9)
// User's task is to discover the numbers by repeated guesses.
// Bull - right digit in right position
// Cow - right digit in wrong position
// Game ends with 4 Bulls (4 correct digits in correct positions)
constexpr int size = 4;

int main() {

    int seed = 0;
    cout<<"Please enter any number to begin:\n";
    cin>>seed;
    seed_randint(seed);

    // Generate answer
    vector<int> answer(size);
    for (int i = 0; i < size; ++i) {
        int candidate = randint(9);
        bool unique = false;
        while (!unique) {
            int j = 0;
            while (j < i) {
                if (candidate != answer[j]) {
                    j++;
                }
                else {
                    candidate = randint(9);
                    j = 0;
                }
            }
            unique = true;
        }
        answer[i] = candidate;
    }

    vector<int> guess(size);
    while (true) { 
        cout<<"Please enter 4 digits:\n";
        for (int i = 0; i < size; ++i) {
            cin>>guess[i];
        }

        int cows = 0;
        int bulls = 0;
        for (int i = 0; i < size; ++i) {
            if (guess[i] == answer[i]) {
                bulls++;
            }
            else {
                for (int j = 0; j < size; ++j) {
                    if (guess[i] == answer[j]) {
                        cows++;
                    }
                }
            }
        }

        if (bulls == 4) {
            cout<<"You've won!! Answer: ";
            for (int x : answer) {
                cout<<x<<" ";
            } cout<<'\n';
            return 0;
        }
        else {
            cout<<bulls<<" bull(s) "<<cows<<" cow(s).\n";
        }
    }
}
