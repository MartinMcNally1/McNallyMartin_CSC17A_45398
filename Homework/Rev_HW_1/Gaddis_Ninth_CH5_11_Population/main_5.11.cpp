/*   
 * Author: Martin McNally
 * Purpose: 5.11 Calculating population of Organisms
 * Date: 06/23/2021
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cmath>      //Math library 
//Find faster power method to avoid the pow function
#include <iomanip>    //Formating Output

using namespace std;  //Library Scope

//Execution Starts Here
int main(){
    //Set Random Number Seed Here

    //Declare Variables
    int numO;       //Starting number of organisms. numO > 2
    float numAPI;   //Average population increase, given as a percentage. numAPI > 0
    int numD;       //Number of days they will multiply. numD > 1 
 
    //Input the starting number of organisms
    numO=0;
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
    numAPI=0;
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
    numD=0;
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
    for ( int i=0; i<=numD; i++){
        cout << fixed << setprecision(2) << "Population on day " << i+1 << ": " << pow(1+numAPI, i) * numO << endl;
    }
    return 0;
}


