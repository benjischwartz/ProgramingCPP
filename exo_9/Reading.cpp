#include "std_lib_facilities.h"

struct Reading {
    int hour;
    double temperature;
};

int main() {
    vector<Reading> temps;
    int hour;
    double temperature;

    ifstream ist {"temps.txt"}; // ist is an input stream from temps.txt
    if (!ist) error("can't open input file");
    while (ist >> hour >> temperature) {
        if (hour < 0 || 23 < hour) error("hour out of range");
        temps.push_back(Reading{hour, temperature});
    }
    ofstream ost {"formatted_temps.txt"};
    if (!ost) error("can't open output file");
    for (int i = 0; i < temps.size(); ++i) {
        ost << '(' << temps[i].hour << ',' << temps[i].temperature << ")\n";
    }
}
