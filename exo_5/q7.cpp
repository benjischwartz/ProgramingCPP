#include "std_lib_facilities.h"

void find_roots(int, int, int);

int main() {
    
    int a, b, c;
    cout<<"Please enter a, b and c:\n";
    cin>>a>>b>>c;

    try {
        find_roots(a, b, c);
        return 0;
    }
    catch(exception& e) {
        cerr<<"error: "<<e.what()<<'\n';
        keep_window_open();
        return 1;
    }
}

void find_roots(int a, int b, int c) {
    
    int discriminant = b*b - 4*a*c;
    if (discriminant < 0) {
        error("No real roots");
    }
    else {
        cout<<"x1 = "<<(-b + sqrt(discriminant)/(2*a))
            <<", x2 = "<<(-b - sqrt(discriminant)/(2*a))
            << '\n';
    }
}
