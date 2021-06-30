/* 
 * File:
 * Author:
 * Date:
 * Purpose:
 * Version:
 */

//System Libraries - Post Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
   
    float a;
    cin >> a;
    cout << setw(9) << noshowpoint << setprecision(0) << a << setw(10) << showpoint << fixed << setprecision(1) << a << setw(10) << setprecision(2) << a << endl;
    float b;
    cin >> b;
    cout << setw(9) << noshowpoint << setprecision(0) << b << setw(10) << showpoint << fixed << setprecision(1) << b << setw(10) << setprecision(2) << b << endl;
    float c;
    cin >> c;
    cout << setw(9) << noshowpoint << setprecision(0) << c << setw(10) << showpoint << fixed << setprecision(1) << c << setw(10) << setprecision(2) << c << endl;
    float d;
    cin >> d;
    cout << setw(9) << noshowpoint << setprecision(0) << d << setw(10) << showpoint << fixed << setprecision(1) << d << setw(10) << setprecision(2) << d;

    
    //Exit stage left
    return 0;
}
