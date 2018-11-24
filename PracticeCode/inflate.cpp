#include <iostream>
#include <cstring>
#include <cctype>
#include <cassert>
using namespace std;

void inflateCString(char c[], int index, int spaces) {
    int length = strlen(c);
    int counter = spaces;
    while(counter > 0) {
        for(int i = length; i >= index; i--) {
            c[i+1] = c[i];
        }
        counter--;
        index++;
        length++;
    }
    while(spaces > 0) {
        c[index - 1] = '\0';
        index--;
        spaces--;
    }
}

int main() {
    char hotAir[100] = "balloon!";
    char andrewsEgo[100] = "";
    char usDollar[100] = "so poor!";
    inflateCString(hotAir, 0, 2);
    inflateCString(andrewsEgo, 0, 2);
    inflateCString(usDollar, 3, 1);
    assert(usDollar[3] == 0 && !strcmp(usDollar, "so ") && !strcmp(usDollar+4, "poor!"));
    assert(andrewsEgo[0] == 0 && andrewsEgo[1] == 0 & andrewsEgo[2] == 0);
    assert(hotAir[0] == '\0' && hotAir[1] == '\0' && !strcmp(hotAir+2, "balloon!"));
}