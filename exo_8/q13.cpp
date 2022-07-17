#include "std_lib_facilities.h"

// Function that takes a vector<string> argument and returns a vector<int>
// containing the number of characters in each string. Also find the longest
// and shortest string and the lexicographically first and last string. 

struct Stats {
    vector<int> lengths;
    string longest;
    string shortest;
    string first;
    string last;

    // Construct from 4 strings and a vector<int>
    Stats(string longest, string shortest, string first, string last, vector<int> lengths) :
                longest{longest}, shortest{shortest}, 
                first{first}, last{last}, lengths{lengths}{}
};

vector<string> get_inputs();
Stats calculate(vector<string>);
void print_stats(Stats);

void Catcher();

int main() {

try {
    vector<string> input_strings = get_inputs();
    Stats stats = calculate(input_strings);

    cout << "Result: " << endl;
    print_stats(stats);
}

catch (exception& e) {
    cout << e.what() << endl;
}

catch (...) {
    Catcher();
}

}

vector<string> get_inputs() {
    String input_string;
    vector<string> strings;
    
    while (true) {
        cout << "Enter string (\"EXIT\" to quit): ";
        getline(cin, input_string);
        if (input_string == "EXIT") break;
        strings.push_back(input_string);
    }
    return strings;
}

Stats calculate(vector<string> strings) {

    if (strings.size() == 0) error ("Empty list");

    string longest = strings[0];
    string shortest = strings[0];
    string first = strings[0];
    string last = strings[0];
    vector<int> lengths;

    for (int i = 0; i < strings.size(); ++i) {

        int string_length = strings[i].size();
        if (string_length > longest.size()) longest = strings[i];
        if (string_length < shortest.size()) shortest = strings[i];
        lengths.push_back(string_length);

        if (strings[i] < first) first = strings[i];
        if (strings[i] > last) last = strings[i];
    }

    return Stats(longest, shortest, first, last, lengths);
    
}

void print_stats (Stats stats) {
    cout << "String lengths: " << endl;
    for (int i = 0; i < stats.lengths.size(); ++i) {
        cout << stats.lengths[i] << endl;
    } cout << '\n';
    cout << "Longest string: " << stats.longest << endl;
    cout << "Shortest string: " << stats.shortest << endl;
    cout << "Lexicographically first string: " << stats.first << endl;
    cout << "Lexicographically last string: " << stats.last << endl;
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

