/* 
 * File:  Ga9EdCH11P3
 * Author: Martin McNally
 * Created: October 6, 2021 
 * Purpose: Input and Output a structure variable
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
struct DivNam   //Division Name Struct variable
{
    float frstQ;    //First Quarter member
    float secQ;     //Second Quarter member
    float thrdQ;    //Third Quarter member
    float frthQ;    //Fourth Quarter member
    float ttl;      //Total Sales member
    float avQ;      //Average Sales member
};
//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void InputDat(DivNam &);
void PrintDat(DivNam );
//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    DivNam north, west, east, south;
    //Initialize Variables
    InputDat(north);
    InputDat(west);
    InputDat(east);
    InputDat(south);
    //Process or map Inputs to Outputs
    
    //Display Outputs
    cout << "North" << endl;
    PrintDat(north);
    cout << endl << "West" << endl;
    PrintDat(west);
    cout << endl << "East" << endl;
    PrintDat(east);
    cout << endl << "South" << endl;
    PrintDat(south);
    //Exit stage right!
    return 0;
}
void InputDat(DivNam &div){ //Input sales data for quarter, and and calculate average and total sales 
    cin >> div.frstQ >> div.secQ >> div.thrdQ >> div.frthQ;
    div.ttl = div.frstQ + div.secQ + div.thrdQ + div.frthQ;
    div.avQ = div.ttl / 4; 
}
void PrintDat(DivNam div ){
    cout << "Enter first-quarter sales:" << endl;
    cout << "Enter second-quarter sales:" << endl;
    cout << "Enter third-quarter sales:" << endl;
    cout << "Enter fourth-quarter sales:" << endl;
    cout << fixed << showpoint << setprecision(2);
    cout << "Total Annual sales:$" << div.ttl << endl;
    cout << "Average Quarterly Sales:$" << div.avQ;
}
