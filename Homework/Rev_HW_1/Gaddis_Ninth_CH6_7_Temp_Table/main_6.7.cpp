/*   
 * Author: Martin McNally
 * Purpose: 6.7 Celsius to Fahrenheit table 
 * Date: 06/24/2021
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cmath>      //Math Library
#include <iomanip>    //Formating Outputs

using namespace std;  //Library Scope

//Function Prototypes
float Celsius(float);   //Converts Fahrenheit to Celsius

//Execution Starts Here
int main(){

    //Display the outputs
    cout << "Celsius Temperature Table" << endl;
    cout << "-------------------------" << endl;
    for ( float i=0; i<=20; i++){
        cout << setprecision(2) << fixed; 
        cout << i << " F" << setw(16) << Celsius(i) << " C" << endl;
    }
    return 0;
}

//Function Implementations
float Celsius(float f){
    float c=(5*(f-32))/9;
    return c;
}
