#include <iostream>
#include <cassert>
#include <cstring>
#include <cctype>
using namespace std;

const int MAX_WORD_LENGTH = 20;
const int MAX_DOCUMENT_LENGTH = 250;

int makeProper(char word1[][MAX_WORD_LENGTH + 1], char word2[][MAX_WORD_LENGTH + 1], int separation[], int nPatterns);
int rate(const char document[], const char word1[][MAX_WORD_LENGTH + 1], const char word2[][MAX_WORD_LENGTH + 1], const int separation[], int nPatterns);

void shiftArrays(char a[][MAX_WORD_LENGTH + 1], char b[][MAX_WORD_LENGTH + 1], int c[], int n, int pos);
void makeDocumentProper(char a[]);
void print(char a[][MAX_WORD_LENGTH + 1], int n);
void printArray(char a[]);
void empty(char a[]);

int main() {
}

int makeProper(char word1[][MAX_WORD_LENGTH + 1], char word2[][MAX_WORD_LENGTH + 1], int separation[], int nPatterns) {
    if(nPatterns <= 0) {
        return 0;
    }

    int end = nPatterns;

    //check for negative separator values
    for(int i = 0; i < end; i++) {
        if(separation[i] < 0) {
            shiftArrays(word1, word2, separation, nPatterns, i);
            end--;
            i--;
        }
    }

    for(int i = 0; i < end; i++) {
        //check for words with no characters
        if(strlen(word1[i]) == 0 || strlen(word2[i]) == 0) {
            shiftArrays(word1, word2, separation, nPatterns, i);
            end--;
            i--;
            continue;
        }

        //check for non-alphabetical characters in words from word1
        int j = 0;
        while(i < end && word1[i][j] != '\0') {
            if(!isalpha(word1[i][j])) {
                shiftArrays(word1, word2, separation, nPatterns, i);
                end--;
                i--;
                break;
            }
            word1[i][j] = tolower(word1[i][j]);
            j++;
        }
    }

    //check for non-alphabetical characters in words from word2
    for(int i = 0; i < end; i++) {
        int k = 0;
        while(i < end && word2[i][k] != '\0') {
            if(!isalpha(word2[i][k])) {
                shiftArrays(word1, word2, separation, nPatterns, i);
                end--;
                i--;
                break;
            }
            word2[i][k] = tolower(word2[i][k]);
            k++;
        }
    }

    //check for repeat patterns and handle removing pattern with the smaller separation value
    for(int i = 0; i < end - 1; i++) {
        for(int j = i + 1; j < end; j++) {
            if( (strcmp(word1[i], word1[j]) == 0 && strcmp(word2[i], word2[j]) == 0)
                || (strcmp(word1[i], word2[j]) == 0 && strcmp(word2[i], word1[j]) == 0) ) {

                if(separation[i] < separation[j]) {
                    shiftArrays(word1, word2, separation, nPatterns, i);
                    i--;
                }
                else {
                    shiftArrays(word1, word2, separation, nPatterns, j);
                }
                end--;
                j--;
            }
        }
    }

    return end;
}

int rate(const char document[], const char word1[][MAX_WORD_LENGTH + 1], const char word2[][MAX_WORD_LENGTH + 1], const int separation[], int nPatterns) {
    if(nPatterns <= 0) {
        return 0;
    }

    //create a copy of the document and make the contents formatted properly
    char documentCopy[MAX_DOCUMENT_LENGTH + 1] = "";
    strcpy(documentCopy, document);
    makeDocumentProper(documentCopy);

    int numMatches = 0;
    for(int i = 0; i < nPatterns; i++) {
        int documentPos = 0;
        bool isMatch = false;

        while(documentCopy[documentPos] != '\0' && !isMatch) {
            char currentWord[MAX_DOCUMENT_LENGTH + 1] = "";
            int iterator = 0;

            //get next word in the document
            while(documentCopy[documentPos] != '\0' && isalpha(documentCopy[documentPos])) {
                currentWord[iterator] = documentCopy[documentPos];
                documentPos++;
                iterator++;
            }

            //check if the currentWord of the document matches the word at position i in word1 array
            if(strcmp(currentWord, word1[i]) == 0) {
                int count = 0;
                int nextWordPos = documentPos;

                //continue to get next word in document and check it against the word at position i in word2 array separation times
                while(count <= separation[i]) {
                    int iterator = 0;
                    char nextWord[MAX_DOCUMENT_LENGTH + 1] = "";
                    while(documentCopy[nextWordPos] != '\0' && !isalpha(documentCopy[nextWordPos])) {
                        nextWordPos++;
                    }
                    while(documentCopy[nextWordPos] != '\0' && isalpha(documentCopy[nextWordPos])) {
                        nextWord[iterator] = documentCopy[nextWordPos];
                        iterator++;
                        nextWordPos++;
                    }
                    if(strcmp(nextWord, word2[i]) == 0) {
                        numMatches++;
                        isMatch = true;
                        break;
                    }
                    count++;
                }
            }

            //check if the currentWord of the document matches the word at position i of word2 array
            else if(strcmp(currentWord, word2[i]) == 0) {
                int count = 0;
                int nextWordPos = documentPos;

                //continue to get next word in document and check it against the word at position i in word1 array separation times
                while(count <= separation[i]) {
                    int iterator = 0;
                    char nextWord[MAX_DOCUMENT_LENGTH + 1] = "";
                    while(documentCopy[nextWordPos] != '\0' && !isalpha(documentCopy[nextWordPos])) {
                        nextWordPos++;
                    }
                    while(documentCopy[nextWordPos] != '\0' && isalpha(documentCopy[nextWordPos])) {
                        nextWord[iterator] = documentCopy[nextWordPos];
                        iterator++;
                        nextWordPos++;
                    }
                    if(strcmp(nextWord, word1[i]) == 0) {
                        numMatches++;
                        isMatch = true;
                        break;
                    }
                    count++;
                }
            }

            //move past spaces in document to the next word
            while(documentCopy[documentPos] != '\0' && !isalpha(documentCopy[documentPos])) {
                documentPos++;
            }
            empty(currentWord);
        }
    }
    return numMatches;
}

//move elements in array left, overwriting elements at position pos
void shiftArrays(char a[][MAX_WORD_LENGTH + 1], char b[][MAX_WORD_LENGTH + 1], int c[], int n, int pos) {
    for(int i = pos; i < n - 1; i++) {
        c[i] = c[i + 1];
        for(int j = 0; j < MAX_WORD_LENGTH; j++) {
            a[i][j] = a[i + 1][j];
            b[i][j] = b[i + 1][j];
        }
    }
}

void makeDocumentProper(char a[]) {
    //make all characters in document lowercase
    for(int i = 0; i <= MAX_DOCUMENT_LENGTH; i++) {
        a[i] = tolower(a[i]);
    }

    //remove all non alphabetic characters (except spaces)
    for(int i = 0; a[i] != '\0'; i++) {
        if(!isalpha(a[i]) && a[i] != ' ') {
            for(int j = i; a[j] != '\0'; j++) {
                a[j] = a[j+1];
            }
        }
        if(!isalpha(a[i]) && a[i] != ' ') {
            i--;
        }
    }
}

void print(char a[][MAX_WORD_LENGTH + 1], int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
}

void printArray(char a[]) {
    for(int i = 0; a[i] != '\0'; i++) {
        cout << a[i];
    }
    cout << endl;
}

void empty(char a[]) {
    for(int i = 0; a[i] != '\0'; i++) {
        a[i] = 0;
    }
}
