#include <iostream>
#include <cstring>
using namespace std;

void solvePuzzle(char encodedMsg[], char decodedMsg[]) {
    int i = 0;
    int j = 0;

    while(encodedMsg[i]) {
        cout << i << endl;
        if(i % 2 == 0) {
            decodedMsg[j] = encodedMsg[i];
            j++;
        }
        i++;
    }
    decodedMsg[j] = 0;
}

int main() {
    char encodedMsg[] = "BAAANPALNEA";
    char decodedMsg[100];

    solvePuzzle(encodedMsg, decodedMsg);

    cout << decodedMsg << endl;

    return 0;
}