#include "std_lib_facilities.h"

// Function that finds the smallest and largest element of a vector argument
// and also computes the mean and the median. Do not use global variables.
// Either return a struct containing the results or pass them back through
// reference arguments.

// Assume input is a vector<double> type

struct Stats {
    double min;
    double max;
    double mean;
    double median;

    // Construct from 4 values
    Stats(double min, double max, double mean, double median) :
        min{min}, max{max}, mean{mean}, median{median} {}
};

vector<double> read_vector();
Stats get_stats(vector<double>);
void Catcher();

int main() {

try {
    vector<double> input_vector = read_vector();
    Stats res = get_stats(input_vector);
    cout << "Min: " << res.min << endl
        << "Max: " << res.max << endl
        << "Mean: " << res.mean << endl
        << "Median: " << res.median << endl;
}

catch (runtime_error e) {
    cout << e.what() << '\n';
}

catch (...) {
    Catcher();
}

}

vector<double> read_vector() {
    cout << "Enter double values (terminate with non-double value): ";
    vector<double> input_vector;
    double input_value = 0;
    while (cin >> input_value) {
        input_vector.push_back(input_value);
    }
    return input_vector;
}

Stats get_stats(vector<double> input_vector) {

    // Empty vector
    if (input_vector.size() == 0) {
        error("Empty vector");
    }
    // Vector has only one element
    if (input_vector.size() == 1) {
        return Stats(input_vector[0], input_vector[0],
                input_vector[0], input_vector[0]);
    }
    // Calculate
    double min = input_vector[0];
    double max = input_vector[0];
    double sum = input_vector[0];

    cout << "# 1 min is: " << min << endl;
    for (int i = 1; i < input_vector.size(); ++i) {
        if (input_vector[i] < min) {
            min = input_vector[i];
            cout << "Here!\n";
        }        
        if (input_vector[i] > max) {
            max = input_vector[i];
        }
        sum += input_vector[i];
    }
    // Calculate mean
    double mean = sum / input_vector.size();

    // Calculate median
    double median = 0;
    if (input_vector.size() % 2 == 0) {
        median = (input_vector[int(input_vector.size()/2)] +
                input_vector[int(input_vector.size()/2) + 1]) / 2;
    } else {
        median = input_vector[int(input_vector.size()/2)];
    }
    
    return Stats(min, max, mean, median);
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
