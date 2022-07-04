#include "std_lib_facilities.h"

int main() {
    vector<string> names;
    vector<int> scores;
    int number = 0;

    while (true) {
        
        string input_name;
        int input_score;
        cin >> input_name >> input_score;

        for (int i = 0; i < names.size(); ++i) {
            if (names[i] == input_name) {
                // Terminate with error message if a name entered twice.
                cout << "Error: repeated name\n";
                exit(1);
            }
        }

        names.push_back(input_name);
        scores.push_back(input_score);

        if (input_name == "NoName") {
            break;
        }
    }

    for (int i = 0; i < names.size(); ++i) {
        cout << names[i] << '\t' << scores[i] << '\n';
    }

    return 0;
}
