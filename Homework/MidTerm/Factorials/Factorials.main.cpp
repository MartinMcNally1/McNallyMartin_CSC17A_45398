/* 
 * File:    Factorials.main.cpp
 * Problem: 5
 * Task:    a) Using a byte variable, what is the largest n where n!=factorial 
 *          that can be calculated( Signed as well as unsigned).
 *          b) What would be the largest n for n! using short, int,
 *          long, long long, float, double,
 *          etc... Use all the primitive data types that you are familiar with 
 *          signed as well as unsigned.
 * Note:    I want you to investigate this and the program you turn in should 
 *          just print ”cout” the final results. You don’t know how to capture 
 *          errors yet so run each till it overflows then back off by 1. 
 *          Don’t need the program that tests for this.
 * Created: 10/19/20           
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
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));  //Random Number Seed
    
    //The limit of a unsigned char data type is 0 to 255
    //The limit of a char data type is -128 to 127
    
    //The limit of a unsigned short data type is 0 to 65535
    //The limit of a short data type is -32768 to 32767
    
    //The limit of a unsigned int data type is 0 to 4294967295
    //The limit of a int data type is -2147483648 to 2147483647
    
    //The limit of a unsigned long data type is 0 to 4294867295 
    //The limit of a long data type is -2147483648 to 2147483647
    
    //The limit of a unsigned long long data type is -9223372036854775808 to 9223372036854775807 
    //The limit of a long long data type is 0 to 18446744073709551615
   
    //The limit of a float data type is 3.4e-38 to 3.4e+38 (7 digits)

    //The limit of a double data type is 1.7e^  
    
    //I replaced each variable with a different data type to test for an overflow overflow
    int num;    //Find factorial of num
    int fnum=1; //Factorial of num
    cin>>num;   //Input Factorial to search for
    for (int i=2; i<=num; ++i){
        fnum *= i;
    }
    cout <<"Factorial of " << num << " is " << fnum << endl;
    
    cout << endl << "The largest n for n! of a unsigned char is 5! = 120" << endl;
    cout << "The largest n for n! of a char is 5! = 120" << endl;
    
    cout << "The largest n for n! of a unsigned short is 8! = 40320" << endl;
    cout << "The largest n for n! of a short is 7! = 5040" << endl;
    
    cout << "The largest n for n! of a unsigned int is 33! = 2147483648" << endl;
    cout << "The largest n for n! of a int is 16! = 2004189184 " << endl;
    
    cout << "The largest n for n! of a unsigned long is 65! = 9223372036854775808" << endl;
    cout << "The largest n for n! of a long is 20! = 2432902008176640000" << endl;
    
    cout << "The largest n for n! of a unsigned long long is 65! = 9223372036854775808" << endl;
    cout << "The largest n for n! of a long long is 20! = 2432902008176640000" << endl;
    
    cout << "The largest n for n! of a float is 34! = 2.95233e+38" << endl;
    
    cout << "The largest n for n! of a double is 170! = 7.25742e+306" << endl;
    

    return 0;
}