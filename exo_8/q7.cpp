#include "std_lib_facilities.h"

// Read five names into a vector<string>  name, then prompt the user for the
// ages of the people names and store the ages in a vector<double> age.
// Then print out the five (name[i], age[i]) pairs. Sort the names with
// sort(name.begin(), name.end()) and print out the (name[i], age[i]) pairs.
// Hint: before sorting name, take a copy and use that to make a copy of age
// in the right order after sorting name. 

vector<string> name;
vector<double> age;

void read_pairs();
void sort_pairs(vector<string>&, vector<double>&);
void print_pairs(const vector<string>&, const vector<double>&);
void Catcher();

int main() {

try {
    read_pairs();
    cout << "Unsorted pairs:\n";
    print_pairs(name, age);
    cout << endl;

    cout << "Sorted pairs:\n";
    sort_pairs(name, age);
    print_pairs(name, age);
}

catch (runtime_error e) {
    cout << e.what() << '\n';
}

catch (...) {
    Catcher();
    // cout << "exiting.\n";
}

}

void read_pairs() {
    string input_name;
    double input_age = 0;
    while (true) {
        cin >> input_name >> input_age;
        if (input_name == "NoName") return;
        for (int i = 0; i < name.size(); ++i) {
            if (input_name == name[i]) error("duplicate: ",input_name); // check for duplicate
        }
        name.push_back(input_name);
        age.push_back(input_age);
    }
}

void sort_pairs(vector<string>& name, vector<double>& age) {
    vector<string> name_copy = name;
    vector<double> sorted_age(age.size());
    sort(name.begin(), name.end());
    for (int i = 0; i < name.size(); ++i) {
        for (int j = 0; j < name_copy.size(); ++j) {
            if (name_copy[j] == name[i]) {
                sorted_age[i] = age[j];
                break;
            }
        } // error("Name not found: ", name[i]);
    }
    age = sorted_age;
}

void print_pairs(const vector<string>& n, const vector<double>& a) {
    if (n.size() != a.size()) error("Different sizes");
    for (int i = 0; i < n.size(); ++i) {
        cout << '(' << n[i] << ", " << a[i] << ')' << endl;
    }
}

void Catcher() {
    try
    {
        throw;
    }
    catch (const std::overflow_error& e) {
        // this executes if f() throws std::overflow_error (same type rule)
        cout << e.what() << '\n';
    }
    catch (const std::runtime_error& e) {
        // this executes if f() throws std::underflow_error (base class rule)
        cout << e.what() << '\n';
    }
    catch (const std::exception& e) {
        // this executes if f() throws std::logic_error (base class rule)
        cout << e.what() << '\n';
    }
    catch (...) {
        // oops!
        cout << "exiting.\n";
    }
}
