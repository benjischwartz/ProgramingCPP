#include "std_lib_facilities.h"

int main() {
    vector<string> words;

    for (string word; cin>>word; )
        words.push_back(word);

    for (string word : words)
        if (word == "fuck") {
            cout << "BLEEP\n";
        }
        else {
            cout << word << "\n";
        }
}
