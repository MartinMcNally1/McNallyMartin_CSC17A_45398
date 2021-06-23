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

//User Libraries

//Global Constants

//Science and Math, Conversions, Higher Dimensions

//const to follow

//Function Prototypes

//Execution Starts Here
int main(){
    //Set Random Number Seed Here

    //Declare Variables - Known and Unknown, units, range, description
    int numO=0;       //Starting number of organisms. numO > 2
    float numAPI=0;   //Average population increase, given as a percentage. numAPI > 0
    int numD=0;       //Number of days they will multiply. numD > 1 
    //Initialize Variables
    
    //Map inputs to outputs -> i.e. process the inputs
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
    //Display the outputs
    
    //Clean up - File closing, memory de-allocation, etc....

    //Exit Stage Correctly
    
    return 0;
}

//Function Implementations

