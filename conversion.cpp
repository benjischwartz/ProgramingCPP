
#include "std_lib_facilities.h"

int main() {
    double d = 0;
    while(cin>>d) {
        // squeeze double into int
        int i = d;
        
        // squeeze int into char
        char c = i;

        // get int value of char
        int i2 = c;
        cout<<"d=="<<d
            <<" i=="<<i
            <<" i2=="<<i2
            <<" char("<<c
            <<")\n";
    }
}
