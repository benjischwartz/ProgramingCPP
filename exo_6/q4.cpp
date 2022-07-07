#include "std_lib_facilities.h"

class Name_value {
public:
    string name;
    int value;
    Name_value(string name, int value) :name{name}, value{value} {}
};

// Program where you enter a set of name-and-value pairs. 
// Terminate input with NoName 0. 
// Check that each name is unique and terminate with an error message if a name is entered twice.
// Write out all the (name, score) pairs, one per line.
int main() {
    //
    vector<Name_value> name_values;
    string name_input;
    int value_input = 0;
    cout << "Please enter name-and-value pairs.\n"
        << "Terminate input with 'NoName 0'.\n"
        << "Each name must be unique.\n";
    while(true) {
        cout << ">> ";
        cin >> name_input >> value_input;
        if (name_input == "NoName" && value_input == 0) {
            // Terminate
            break;
        }
        else {
            for (Name_value nv: name_values) {
                if (nv.name == name_input) {
                    error("Name already exists.\n");
                }
            }
            // Add new name_value pair to vector
            Name_value new_nv = Name_value(name_input, value_input);
            name_values.push_back(new_nv);
        }
    }
    // Print out all (name, score) pairs.
    for (Name_value nv: name_values) {
        cout << nv.name << ", " << nv.value << '\n';
    }
}
