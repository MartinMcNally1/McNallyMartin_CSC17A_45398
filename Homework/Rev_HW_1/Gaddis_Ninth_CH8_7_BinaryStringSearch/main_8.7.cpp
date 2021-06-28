/*   
 * Author: Martin McNally
 * Purpose:  
 * Date: 06/21/2021
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <string>   
using namespace std;  //Library Scope

//User Libraries

//Global Constants

//Science and Math, Conversions, Higher Dimensions

//const to follow

//Function Prototypes
int BinarySearch(string[], const int, string);
//Execution Starts Here
int main(){
    //Set Random Number Seed Here

    //Declare Variables - Known and Unknown, units, range, description
    const int NUM_NAMES=20;
    string names[NUM_NAMES]={"Collins, Bill","Smith, Bart","Allen, Jim","Griffin, Jim","Stamey, Marty",
                             "Rose, Geri","Taylor, Terri","Johnson, Jill","Allison, Jeff","Looney, Joe",
                             "Wolfe, Bill","James, Jean","Weaver, Jim","Pore, Bob","Rutherford, Greg",
                             "Javens, Renee","Harrison, Rose","Setzer, Cathy","Pike, Gordon","Holland, Beth"};
    
    //Initialize Variables
    
    //Map inputs to outputs -> i.e. process the inputs
    
    //Display the outputs
    
    //Clean up - File closing, memory de-allocation, etc....

    //Exit Stage Correctly
    
    return 0;
}

//Function Implementations
int BinarySearch(string names[], const int num, string name){
    int first=0, last=num-1, mid, pos=-1;
    bool found=false;
    
    while (!found && first <= last ){
        mid=(first+last)/2;
        if (names[mid]==names){
            found=true;
            pos=mid;
        }
        else if (names[mid]>)
    }
}