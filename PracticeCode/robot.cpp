#include <iostream>
#include <string>
using namespace std;

int updatePoints(int pos) {
    if(pos == 3) return 1;
    if(pos == 1) return -1;
    if(pos == 5) return 2;
    if(pos == 2) return -2;
    return 0;
}

int executeCommands(string cmdStr, int pos, int points) {
    bool hasInvalidChar = false;
    points += updatePoints(pos);
    
    for(int i = 0; i < cmdStr.size(); i++) {     
        switch(cmdStr[i]) {
            case 'L':
                pos--;
                break;
            case 'R':
                pos++;
                break;
            case 'U':
            case 'D':
                break;
            default:
                hasInvalidChar = true;
                break;
        }

        if(hasInvalidChar) {
            return -1;
        }

        points += updatePoints(pos);
    }

    return points;   
}

int main() {
    string command1 = "LULDR";
    string command2 = "LRDULRDUXX";
    string command3 = "UUDDLLRRBA";
    string command4 = "DDURDDUR";
    cout << executeCommands(command1, 0 , 0) << endl;
    cout << executeCommands(command2, 1 , 1) << endl;
    cout << executeCommands(command3, 2 , 2) << endl;
    cout << executeCommands(command4, 3 , 3) << endl; 
}