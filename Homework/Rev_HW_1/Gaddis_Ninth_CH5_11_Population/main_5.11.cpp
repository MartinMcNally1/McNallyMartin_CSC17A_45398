/*   
 * Author: Martin McNally
 * Purpose: 5.11 Calculating population of Organisms
 * Date: 06/23/2021
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cmath>      //Math Library
#include <iomanip>    //Formating Output

using namespace std;  //Library Scope

//Execution Starts Here
int main(){
    //Set Random Number Seed Here

    //Declare Variables - Known and Unknown, units, range, description
    int numO=0;       //Starting number of organisms. numO > 2
    float numAPI=0;   //Average population increase, given as a percentage. numAPI > 0
    int numD=0;       //Number of days they will multiply. numD > 1 
 
    //Input the starting number of organisms
    cout << "Input the starting number of organisms.\n";
    cout << "The number cannot be less then 2.\n";
    cout << "Enter here: ";
    cin >> numO;
    while (numO < 2){
        cout << "The number cannot be less then 2.\n";
        cout << "Enter here: ";
        cin >> numO;
    }
    //Input the average daily population increase
    cout << "Input the average daily population increase as a percentage.\n";
    cout << "The number cannot be negative.\n";
    cout << "Enter here: ";
    cin >> numAPI;
    while (numAPI < 0){
        cout << "The number cannot be negative.\n";
        cout << "Enter here: ";
        cin >> numAPI;
    }
    //Input the number of days the population will multiply
    cout << "Input the number of days the population will multiply.\n";
    cout << "The number cannot be less then 1.\n";
    cout << "Enter here: ";
    cin >> numD;
    while ( numD < 1){
        cout << "The number of days cannot be less then 1.\n";
        cout << "Enter here: ";
        cin >> numD;
    }
    //Display the outputs
    cout << "Initial population: " << numO << endl;
    cout << "Average daily population increase: " << numAPI << endl;
    cout << "Period of days: " << numD << endl;
    numAPI/=100;    //Turns it into a number from a percentage for math
    for ( int i=1; i<=numD; i++){
        cout << setprecision(2) << fixed << "Population on day " << i << ": " << pow(1+numAPI, i) * numO << endl;
    }
    return 0;
}

//Function Implementations

