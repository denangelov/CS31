#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "What is your name? ";
    string personsName;
    getline(cin, personsName);

    cout << "How old are you? ";
    int age;
    cin >> age;
    cin.ignore(10000, '\n'); //cin leaves a leftover newline which messes up getline -- cin.ignore throws away the remainder of the line after reading in the int

    cout << "What is your quest? ";
    string quest;
    getline(cin, quest);

    cout << "Hello, brave " << personsName << "!" << endl;    
    cout << "You want to " << quest << "!" << endl;
    cout << "If you live another year, you will be " << age + 1 << " years old!" << endl;
}

/* 10/10/18 lecture

declaration with initialization:
    type variable = expression;

assignment statement:
    variable = expression;