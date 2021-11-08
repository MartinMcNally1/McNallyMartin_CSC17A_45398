/* 
 * File:   Dynamic_Structure_Practice.main.cpp
 * Purpose:  Practice Dynamically allocating memory for 
 *           a struct array with members that also have
 *           memory dynamically allocated
 *           
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <iomanip>    //Output Manipulation Library
#include <cstdlib>    //C Standard Library
#include <string>     //String Library
#include <fstream>    //File Library Functions  
#include <ctime>      //Time library, for rand
#include <cmath>      //Math library(Think of your own functions for math)
#include <vector>     //Vector library
//Not every library call is needed

using namespace std;  //STD Name-space where Library is compiled

//User Libraries
//Student Info Structure 
struct StudentInfo
{
    char *name;     //Dynamic Char Array of the name of student, limit to 15 char 
    int id;         //Student ID, standard
    char *addres;   //Dynamic Char Array for the address of student, limit to 15 char 
    float *grade;   //Dynamic Float Array, limit to 5 float (5 classes: Math, Bio, P.E., Chem, His)
    //This one is somewhat unneeded, but its good for pracrice
};
//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
StudentInfo *GetStruct (&int);   //Creates a dynamic struct array

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));  //Random Number Seed
    
    //Declare variables here
    StudentInfo *ptr=nullptr;   //Declare Student Info struct array pointer.
    int num=0;                  //Number of student variable
    int namLim=0;               //Size for name member in struct variable 
    int addLim=0;               //Size for address member in struct variable 
    int classLim=5;             //Size for grade member in struct variable
    
    //Initialize variables here
    //Get the number of student for struct array
    //Allocate memory
    //Input Info into Struct array
    
    //Map inputs to outputs here, i.e. the process
    
    //Display the results
    //Print Struct array
    
    //Delete/Deallocate memory
    
    //Quit
    return 0;
}