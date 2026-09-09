#include <iostream>
#include <string>
using namespace std;
int main(){
    string age, name;
    cout << "Enter your age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter your name: ";
    getline(cin , name);
    cout << "Your age is: " << age << endl;
    cout << "Your name is: " << name << endl;
    return 0;
}