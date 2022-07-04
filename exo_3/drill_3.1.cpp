#include "std_lib_facilities.h"

int main() {
    cout << "Enter the name of the person you want to write to:\n";
    string first_name;
    cin >> first_name;
    cout << "Dear " << first_name << ",\n"
        << "\tHow are you? I am fine. I miss you.\n"
        << "I hope the family is well, and that you are enjoying the new job.\n"
        << "I'm looking forward to visitng you soon, I can't wait to meet your friends!\n"
        << "All is well at home, just the same old routine. Home never changes.\n";
    cout << "Enter the name of another friend:\n";
    string friend_name;
    cin >> friend_name;
    cout << "Have you seen " << friend_name << " recently?\n";
    char friend_sex = 0;
    cout << "Enter 'm' or 'f' for your friend's gender:\n";
    cin >> friend_sex;
    if (friend_sex == 'm') {
        cout << "If you see " << friend_name << " please ask him to call me.\n";
    }
    if (friend_sex == 'f') {
        cout << "If you see " << friend_name << "please ask her to call me.\n";
    }
    cout << "Enter the age of the recipient:\n";
    int age;
    cin >> age;
    if (age <= 0 or age >= 110) {
        simple_error("you're kidding!");
    }
    cout << "I hear you just had a birthday and you are " << age << " years old.\n";
    if (age < 12) {
        cout << "Next year you will be " << ++age << ".\n";
    }
    if (age == 17) {
        cout << "Next year you will be able to vote.\n";
    }
    if (age > 70) {
        cout << "I hope you are enjoying retirement.\n";
    }
    cout << "Yours sincerely,\n\nBenji\n";
}
