#include "std_lib_facilities.h"

int main() {

    int n;
    cout<<"Please enter the number of values you want to sum:\n";
    cin>>n;

    vector<int>integers;
    int input;
    cout<<"Please enter some integers (press '|' to stop):\n";

    while (cin>>input) {
        integers.push_back(input);
    }

    // Calculate sum
    if (n > integers.size()) {
        cerr<<"Asked to sum more numbers than there are in the vector.\n";
        return 1;
    } else {
        int sum = 0;
        int i = n;
        while (i > 0) {
            sum += integers[i - 1]; 
            --i;
        }
        cout<<"The sum of the first "<<n<<" numbers ( ";
        
        for(int i = 0; i < n; i++) {
            cout<<integers[i]<<" ";
        }

        cout<<") is "<<sum<<".\n";
        return 0;
    }
}
