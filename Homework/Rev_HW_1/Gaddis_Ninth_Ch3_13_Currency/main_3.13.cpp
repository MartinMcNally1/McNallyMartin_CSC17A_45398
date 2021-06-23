/*   
 * Author: Martin McNally
 * Purpose: Convert US dollar amount into Japanese Yen and European Euro.
 * Date: 06/21/2021
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cmath>      //Math Library
#include <iomanip>    //Formating

using namespace std;  //Library Scope

//Global Constants
float YEN_PER_DOLLAR=98.93; //Following the book
float EURO_PER_DOLLAR=0.74; //Following the book

//Execution Starts Here
int main(){
    //Declare Variables
    float US=0;  //Inputted amount
    float YEN=0; //Outputted amount
    float EU=0;  //Outputted amount

    cout << "Input the amount of US dollars you would like to convert into both Yen and Euro.\n";
    cout << "Enter here: ";
    cin >> US;
    
    YEN = US*YEN_PER_DOLLAR;    //Conversion from dollar to yen
    EU = US*EURO_PER_DOLLAR;    //Conversion from dollar to euro
    
    cout << setprecision(2) << fixed;   //Outputs two decimals
    cout << US << " dollars is " << YEN << " yen." << endl;
    cout << US << " dollars is " << EU << " euros." << endl;
    
    return 0;
}


