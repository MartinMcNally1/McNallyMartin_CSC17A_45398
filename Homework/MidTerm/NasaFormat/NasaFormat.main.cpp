/* 
 * File:    NasaFormat.main.cpp
 * Problem: 6
 * Task:    a) Convert the following 3 numbers to binary, octal and hex 49.1875, 3.07421875,
 *          0.2. When done, convert the following to a float representation by the definition in
 *          class. In other words, I want an 8 digit hex number representation using the 4 byte
 *          float specification defined in class. An example .pdf is attached for you to review   
 *          b) Do the same for a) given they are negative values.
 *          c) Convert the float representations of the following into the decimal number given
 *          the definition in class. 69999902, 69999903, 966667FF
 * Note:    This doesn’t require a program, however, I want you to write a simple function
 *          that outputs the answers you did by hand with ”cout”. Also, scan in your calculations
 *          done by hand.
 * Created: 10/19/2021
 */

//System Libraries
#include <iostream>   //Input/Output Library

using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Display the results
    cout << "NASA Format" << endl << endl;
    cout << " a) Convert 49.1875, 3.07421875, 0.2 into binary, octal, and hex," << endl;
    cout << "then representing them in NASA format:" <<  endl << endl;
    
    cout << " 49.1875 base 10 = 110001.0011 base 2 = 61.14 base 8 = 31.3 base 16" << endl;
    cout << " NASA format of 49.1875 base 10: 666666EE " << endl << endl;
    
    cout << " 3.07421875 base 10 = 3.13 base 16 = 11.00010011 base 2 = 3.046 base 8" << endl;
    cout << " NASA format of 3.07421875 base 10: 62600006" << endl << endl;
    
    cout << " 0.2 base 10 = 0.3 (.3 is infinite) base 16 = 0.0011 (.0011 is infinite) base 2 = 0.1463 (.1463 is infinite) base 8" << endl;
    cout << " NASA format of 0.2 base 10: 62600002" << endl << endl;
    
    cout << " b) Convert -49.1875, -3.07421875, -0.2 into binary, octal, and hex:" << endl << endl;
    
    cout << " -49.1875 base 10 = 1110.1101 base 2 = E.D base 16 = 16.61 base 8" << endl;
    
    cout << " -3.07421875 base 10 = 0.11101101 base 2 = 0.73" << endl;
    
    cout << " -0.2 base 10 = 1.1101 (.1101 is infinite) base 2 = 1.6735 (.6735 is infinite) base 8 = 1.D (.D is infinite) base 16" << endl << endl;
    
    cout << " c) Convert the float numbers in NASA format in decimal:" << endl << endl;
    
    cout << " 1) 69999902 = 3.296875" << endl;
    cout << " 2) 69999903 = 6.375" << endl;
    cout << " 3) 966667FF = -1.5875000358" << endl;
    

    return 0;
}