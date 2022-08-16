#include "std_lib_facilities.h"

class Name_pairs {
    public:
        void read_names();
        void read_ages();
        void print();
        void sort();
        vector<string> get_names() const {return name;}
        vector<double> get_ages() const {return age;}
    private:
        vector<string> name;
        vector<double> age;
};

void Name_pairs::read_names()
{
    while (true) {
        string input_string;
        cout << "Enter name (\"EXIT\" to quit): ";
        getline(cin, input_string);
        if (input_string == "EXIT") break;
        name.push_back(input_string);
    }
}

void Name_pairs::read_ages()
{
    double input_age;
    cout << "Enter age (\"EXIT\" to quit): ";
    while (cin >> input_age) {
        age.push_back(input_age);
        cout << "Enter age (\"EXIT\" to quit): ";
    }
}


void Name_pairs::print()
{
    if (name.size() != age.size()) error("Different sizes");
    for (int i = 0; i < name.size(); ++i) {
        cout << name[i] << ", " << age[i] << endl;
    }
}

ostream& operator<<(ostream& os, const Name_pairs& np)
{
    vector<string> name = np.get_names();
    vector<double> age = np.get_ages();
    if (name.size() != age.size()) error("Different sizes");
    for (int i = 0; i < name.size(); ++i) {
        return os << name[i] << ", " << age[i] << endl;
    }
}

bool operator==(const Name_pairs np1, const Name_pairs np2)
{
    // check names
    vector<string> names_1 = np1.get_names();
    vector<string> names_2 = np2.get_names();
    if (names_1.size() != names_2.size()) return false;
    for (int i = 0; i < names_1.size(); ++i) {
        if (names_1[i] != names_2[i]) return false;
    }

    // check ages
    vector<double> ages_1 = np1.get_ages();
    vector<double> ages_2 = np2.get_ages();
    if (ages_1.size() != ages_2.size()) return false;
    for (int i = 0; i < ages_1.size(); ++i) {
        if (ages_1[i] != ages_2[i]) return false;
    }
    return true;
}

bool operator!=(const Name_pairs np1, const Name_pairs np2)
{
    return !(np1==np2);
}

void Name_pairs::sort()
{
    vector<double> sorted_age(age.size());
    vector<string> name_copy = name;
    std::sort(name.begin(), name.end());
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

int main() {
    Name_pairs name_pairs;
    name_pairs.read_names();
    name_pairs.read_ages();
    cout << "\n Name pairs:\n"; 
    name_pairs.print();

    name_pairs.sort();
    cout << "\n Sorted Name pairs\n";
    name_pairs.print();
}

