/* 
 * File:   Find.CountOf.Array.main.cpp
 * Purpose:  Simple function to find the size of Count size of an Array
 * Note: Don't need all the System Libraries         
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <iomanip>    //Output Manipulation Library
#include <cstdlib>    //C Standard Library
#include <string>     //String Library
#include <ctime>      //Time library, for rand
#include <cmath>      //Math library(Think of your own functions for math)
#include <vector>     //Vector library

using namespace std;  //STD Name-space where Library is compiled

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
     srand(static_cast<unsigned int>(time(0)));   //Random Number Generator Seed for rand() number
                                                  //Yes, its a weak random number generator. Boo-Hoo Netbeans.
     //rand()%10+1 give a random number between 1-10
     int aryInt [rand()%10+1];  //Integer array with a random count
     
     char aryChar [rand()%10+1];    //Char array with a random count
     
     float aryFloat [rand()%10+1];  //Float array with a random count
     
     string Str [rand()%10+1];   //String with a random count
     
     //Essentially, we divide the array by the size of the matching data type
     cout << "The count of aryInt: " << sizeof(aryInt)/sizeof(int) << endl;     
     cout << "The count of aryFloat: " << sizeof(aryFloat)/sizeof(float) << endl;
     cout << "The count of aryChar: " << sizeof(aryChar)/sizeof(char) << endl;
     cout << "The count of Str: " << sizeof(Str)/sizeof(string) << endl;
     

    return 0;
}