/*   
 * Author: Martin McNally
 * Purpose: Finding the number of days in a month depending on the year
 * Date: 06/21/2021
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cmath>      //Math Library
using namespace std;  //Library Scope

//User Libraries

//Global Constants

//Science and Math, Conversions, Higher Dimensions

//const to follow

//Function Prototypes

//Execution Starts Here
int main(){
    //Set Random Number Seed Here
    int TotalM=12;
    int Mnth[TotalM]={31,28,31,30,31,30,31,31,30,31,30,31};    //Declare Variables - Known and Unknown, units, range, description
    int numM=0;
    int numY=0;

    //Initialize Variables
    cout << "Enter the month, from 1 to 12: ";
    cin >> numM;
    while (numM < 1 || numM > 12){
        cout << "Invalid number, try again: ";
        cin >> numM;
    }    
    numM-=1;    //Now its 0-11 for array.
    cout << "Enter the year: ";
    cin >> numY;

    if (numY%100==0 && numY%400==0 || numY%4==0 )
        Mnth[1]+=1; //Adds one more day to FEB in case of leap year
    
    cout << "Number of days: " << Mnth[numM] << endl;
 
    return 0;
}

//Function Implementations

