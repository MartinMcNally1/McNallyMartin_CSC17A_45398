/*   
 * Author: Martin McNally
 * Purpose: Convert US dollar amount into Japanese Yen and European Euro.
 * Date: 09/02/2021
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <iomanip>    //Formating

using namespace std;  //Library Scope

//Execution Starts Here
int main(){
    
    const float YEN_PER_DOLLAR=98.93; //Following the book
    const float EURO_PER_DOLLAR=0.74; //Following the book
    float US=0;  //Inputted US dollar amount
    float YEN=0; //Converted Yen amount to be outputted
    float EU=0;  //Converted EURO amount to be outputted

    cout << "Input the amount of US dollars you would like to convert into both Japanese Yen and European Euro.\n";
    cout << "Enter here: ";
    cin >> US;
    
    YEN = US*YEN_PER_DOLLAR;    //Conversion from dollar to yen
    EU = US*EURO_PER_DOLLAR;    //Conversion from dollar to euro
    
    cout << fixed << setprecision(2) << endl;   //Outputs a fixed decimals with two decimals
    cout << US << " dollars is " << YEN << " yen." << endl;
    cout << US << " dollars is " << EU << " euros." << endl;
    
    return 0;
}


