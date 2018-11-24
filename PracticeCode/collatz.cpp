#include <iostream>
using namespace std;

int main() {
    int n, count;
    while(cin >> n && n > 0) {
        count = 0;

        while(n != 1) {
            if(n % 2 == 0) {
                n/=2;
            }
            else {
                n = 3*n + 1;
            }
            count++;
        }
        cout << "There are  " << count;
        cout << " numbers being generated!" << endl;  
    }
}