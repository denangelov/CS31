#include <iostream>
#include <string>
using namespace std;

void printHyphens();
double calcRentalCharge(int mileage1, int mileage2, int numRentalDays, string isLuxuryCar, int month);

//static prices
const double FIRST_100_MILES_FEE = 0.27;
const double POST_400_MILES_FEE = 0.19;

int main()
{
    int startMileage;
    int endMileage;
    int numRentalDays;
    string name;
    string isLuxuryCar;
    int month;

    //handle getting starting mileage
    cout << "Odometer at start: ";
    cin >> startMileage;
    if(startMileage < 0) {
        printHyphens();
        cout << "The starting odometer reading must be nonnegative." << endl;
        return 0;
    }

    //handle getting ending mileage
    cout << "Odometer at end: ";
    cin >> endMileage;
    if(endMileage < startMileage) {
        printHyphens();
        cout <<"The final odometer reading must be at least as large as the starting reading."<< endl;
        return 0;
    }

    //handle getting the number of rental days
    cout << "Rental days: ";
    cin >> numRentalDays;
    cin.ignore(10000, '\n');
    if(numRentalDays <= 0) {
        printHyphens();
        cout << "The number of rental days must be positive." << endl;
        return 0;
    }

    //handle getting the customer name
    cout << "Customer name: ";
    getline(cin, name);
    if(name == "") {
        printHyphens();
        cout << "You must enter a customer name." << endl;
        return 0;
    }

    //handle getting the car type
    cout << "Luxury car? (y/n): ";
    getline(cin, isLuxuryCar);
    if(!(isLuxuryCar == "y" || isLuxuryCar == "n")) {
        printHyphens();
        cout << "You must enter y or n." << endl;
        return 0;
    }

    //handle getting the month
    cout << "Month (1=Jan, 2=Feb, etc.): ";
    cin >> month;
    if(month < 1 || month > 12) {
        printHyphens();
        cout << "The month number must be in the range 1 through 12." << endl;
        return 0;
    }

    //call function that determines the rental charge and handle the final program output
    double cost = calcRentalCharge(startMileage, endMileage, numRentalDays, isLuxuryCar, month);
    cout.setf(ios::fixed);
    cout.precision(2);
    printHyphens();
    cout << "The rental charge for " << name << " is $" << cost << endl;
    return 0;
}

void printHyphens() {
    cout << "---" << endl;
}

double calcRentalCharge(int mileage1, int mileage2, int numRentalDays, string isLuxuryCar, int month) {
    double totalCost = 0;
    int baseCost;
    
    //determine daily cost of car depending on whether or not it is a luxury vehicle
    if(isLuxuryCar == "y") {
        baseCost = 61;
    } else {
        baseCost = 33;
    }

    //determine what the cost per mile is between 100-400 miles based on the month
    double next300MileCost;
    if(month <= 11 && month >= 4) {
        next300MileCost = 0.21;
    } else {
        next300MileCost = 0.27;
    }

    int totalMiles = mileage2 - mileage1;
    //calculations for customers that drove 100 miles or less (miles <= 100)
    if(totalMiles <= 100) {
        return totalCost = (baseCost * numRentalDays) + (FIRST_100_MILES_FEE * totalMiles);
    }
    //calculations for customers that drove more than 100 miles but no more than 400 miles (100 < miles <= 400)
    if(totalMiles <= 400) {
        return totalCost = (baseCost * numRentalDays) + (FIRST_100_MILES_FEE * 100) + ((totalMiles - 100) * next300MileCost);
    }
    //calculations for customers that drove more than 400 miles (miles > 400)
    return totalCost = (baseCost * numRentalDays) + (FIRST_100_MILES_FEE * 100) + (next300MileCost * 300) + ((totalMiles - 400) * POST_400_MILES_FEE);
}