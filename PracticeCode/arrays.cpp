#include <cmath>
#include <iostream>
using namespace std;
int main() {
    const int MAX_NUMBER_OF_SCORES = 10000;
    int scores[MAX_NUMBER_OF_SCORES];
    int nScores = 0;
    int total = 0;

    cout << "Enter the scores (negative when done): ";
    for(;;) {
        int s;
        cin >> s;
        if(s < 0) {
            break;
        }
        if(nScores == MAX_NUMBER_OF_SCORES) {
            cout << "I can only handle " << MAX_NUMBER_OF_SCORES << " scores!" << endl;
            cout << "I will continue to calculate using the first " << MAX_NUMBER_OF_SCORES << " scores." << endl;
        }
        total += s;
        scores[nScores] = s;
        nScores++;
    }

    if(nScores == 0) {
        cout << "There were no scores, so no statistics" << endl;
    }
    else {
        double mean = static_cast<double>(total)/nScores;
        cout << "The average of all the scores is " << mean << endl;
        double sumOfSquares = 0;
        for(int k = 0; k < nScores; k++) {
            double diff = scores[k] - mean;
            sumOfSquares += diff * diff;
        }
        cout << "The std. deviation is " << sqrt(sumOfSquares/nScores) << endl;
    }
}
