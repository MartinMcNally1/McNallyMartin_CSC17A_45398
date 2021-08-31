/*   
 * Author: Martin McNally
 * Purpose: Converting Celsius to Fahrenheit
 * Date: 08/30/2021
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cmath>      //Math Library
#include <iomanip>    //Formating Output

using namespace std;  //Library Scope

//Execution Starts Here
int main(){
    float F=0;  //Float Value for Fahrenheit temp
    float C=0;  //Float Value for Celsius 
    
    cout << "Enter the Celsius temperature you would like to convert to Fahrenheit below." << endl;
    cout << "Input temperature here: ";
    cin >> C;

    F=(((9*C)/5)+32); //The conversion from Celsius to Fahrenheit.
    
    cout << fixed << setprecision(2) << endl;
    cout << "\nResults: " << C << " degrees centigrade is " << F << " degrees Fahrenheit." << endl; 
    
    return 0;
}

