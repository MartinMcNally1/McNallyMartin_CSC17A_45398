/*   
 * Author: Martin McNally
 * Purpose: 6.7 Celsius to Fahrenheit table 
 * Date: 09/02/2021
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <iomanip>    //Formating Outputs

using namespace std;  //Library Scope

//Function Prototypes
int Celsius(int);   //Converts Fahrenheit to Celsius

//Execution Starts Here
int main(){
//Display the outputs
    cout << "Celsius to Fahrenheit" << endl;
    cout << "---------------------" << endl;
    for ( int i=0; i<=20; i++){ 
        cout << setw(9) << left << i << " F" << setw(8) << right << Celsius(i) << " C" << endl;
    }
    return 0;
}

//Function Implementations
int Celsius(int f){
    int c=(5*(f-32))/9;
    return c;
}
