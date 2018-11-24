#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isValidPhone(string phoneNum);
string digitsOf(string phoneNum);

int main() {
    //n-and-a-half-times loop since condition to break out of loop is in the middle
    /*while(true)*/ for(;;) {
        cout << "Enter a phone number: ";
        getline(cin, phone);
        if(isValidPhone(phone)) {
            break;
        }
        cout << "A phone number must contain 10 digits; try again. " << endl;
    }

    cout << "The digits in the number are " << digitsOf(phone) << endl;
}

