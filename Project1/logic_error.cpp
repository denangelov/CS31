// Code for Project 1
// Report poll results

#include <iostream>
using namespace std;   // pp. 38-39 in Savitch 6/e explains this line

int main()
{
    int numberSurveyed;
    int forNewsom;
    int forCox;

    cout << "How many registered voters were surveyed? ";
    cin >> numberSurveyed;
    //logic error #1 - assign user inputs to the wrong variable (assign # of votes for Newsom to forCox and vice versa)
    cout << "How many of them say they will vote for Newsom? ";
    //cin >> forNewsom;
    cin >> forCox;
    cout << "How many of them say they will vote for Cox? ";
    //cin >> forCox;
    cin >> forNewsom;

    double pctNewsom = 100.0 * forNewsom / numberSurveyed;
    double pctCox = 100.0 * forCox / numberSurveyed;

    cout.setf(ios::fixed);       // see pp. 32-33 in Savitch 6/e
    cout.precision(1);

    cout << endl;
    cout << pctNewsom << "% say they will vote for Newsom." << endl;
    cout << pctCox << "% say they will vote for Cox." << endl;

    //logic error #2 - change greater than sign with less than sign
    // if (forNewsom > forCox)
    if(forNewsom < forCox)
        cout << "Newsom is predicted to win the election." << endl;
    else
        cout << "Cox is predicted to win the election." << endl;
}