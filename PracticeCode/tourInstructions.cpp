#include <iostream>
#include <cctype>
#include <string>
using namespace std;

string translateInstructionString(string instruction);
bool processLorR(string instruction, int& pos, string& humanInstruction);
bool processStop(string instruction, int& pos, string& humanInstruction);

int main() {
    cout << "Enter coded string (or just hit enter to quit): ";
    string coded;
    getline(cin, coded);
    if(coded == "") {
        return 0;
    } 
    cout << translateInstructionString(coded) << endl;
}

string translateInstructionString(string instruction) {
    int i = 0;
    string humanInstruction = "";
    while(i < instruction.length()) {
        switch(instruction[i]) {
        case 'R':
        case 'L':
            if(!processLorR(instruction, i, humanInstruction)) {
                return "*** There is an error in the string! ***\n";
            }
            break;
        case 'S':
            if(!processStop(instruction, i, humanInstruction)) {
                return "*** There is an error in the string! ***\n";
            }
            break;
        default:
            return "*** There is an error in the string! ***\n";
            break;
        }
    }
    return humanInstruction;
}

bool processLorR(string instruction, int& pos, string& humanInstruction) {
    string distance = "";
    int directionPosition = pos;
    pos++;
    while(isdigit(instruction[pos])) {
        distance += instruction[pos];
        pos++;
    }
    if(distance == "") {
        return false;
    } else {
        switch(instruction[directionPosition]) {
        case 'R':
            humanInstruction += "Turn right and proceed for " + distance + " blocks.\n";
            break;
        case 'L': 
            humanInstruction += "Turn left and proceed for " + distance + " blocks.\n";
            break;
        default:
            break;
        }
    }
    return true;
}

bool processStop(string instruction, int& pos, string& humanInstruction) {
    string destination = "";
    pos++;
    if(!isupper(instruction[pos])) {
        return false;
    }
    else {
        destination = instruction[pos];
    }
    
    humanInstruction += "Stop at point of interest " + destination + ".\n";
    pos++;
    return true;
}

