#include <iostream>
using namespace std;

int main() {
    int age;
    cout << "Enter age: ";
    cin >> age;

    if(age <= 1)
        cout << "Infant";
    else if(age <= 3)
        cout << "Toddler";
    else if(age <= 12)
        cout << "Child";
    else if(age <= 19)
        cout << "Teenager";
    else if(age <= 35)
        cout << "Young Adult";
    else if(age <= 59)
        cout << "Adult";
    else
        cout << "Senior";

    return 0;
}
