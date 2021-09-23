/*   
 * Author: Martin McNally
 * Purpose: Examples of Searching algorithms
 * Date: 09/14/21
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <ctime>      //Time library, for rand()
#include <iomanip>    //Cout library
#include <cmath>      //Math Library
using namespace std;  //Library Scope

//User Libraries

//Global Constants

//Science and Math, Conversions, Higher Dimensions

//const to follow

//Function Prototypes
int LinearSearch(const int[], int, int);
int BinarySearch(const int[], int, int);

void LinearSearchPosition(const int[], int, int);

void fillArray(int [], int);    //Fills Array with random numbers
void printArray(int [], int);   //Outputs Array contents


//Execution Starts Here
int main(){
    //Set Random Number Seed Here
    srand(static_cast<unsigned int>(time(0)));   //Random Number Generator Seed for rand() number
    
    //Declare Variables 
    const int size=50;  //Size of array
    int array[size];    //Array holding int variables  
    int Findvalue;

    
    //Initialize Variables
    Findvalue=0;
    cout << "What value do you wish to find?" << endl;
    cin >> Findvalue;
    cout << endl;
    
    fillArray(array, size);     //Calls fillArray function
    printArray(array, size);    //Outputs array contents
    //Find Desired Array
    cout << endl << Findvalue << " was found " << LinearSearch(array,size,Findvalue) << " time in the array" << endl;
    cout << "in the ";
    LinearSearchPosition(array,size,Findvalue);
    cout << " positions" << endl;
    //Display the outputs
    //Clean up - File closing, memory de-allocation, etc....

    //Exit Stage Correctly
    
    return 0;
}

//Function Implementations
void fillArray(int array[], int size){  //Fills Array with a random numbers
    int index=0;
    while (index<size){             
        array[index]=rand()%10+1; //Fills each element of array with a random number, [1,10]
        index++;
    }
}

void printArray(int array[], int size){   //Outputs Array contents
    int index=0;
    while(index<size){
        if ( index != 0 && index%10==0){    //If index mod 5 equals 0(divisible by 5) AND if index equals 0
            cout << endl;
        }else{
            cout << setw(3) << array[index]; //Outputs each element
        }
        index++;
    }
}

//Linear Search Algorithm
int LinearSearch ( const int array[], int size, int value){    //Looks for a number, and counts how many times its repeated.
    int index=0;
    for (int i=0; i<size; i++){ //Passes through the whole array
        if(value==array[i]){    //If array[i] is EQUAL to value searched
            index++;            //Increment index by 1
        }   
    }

    return index;   //Return the number of times the value was found
}

void LinearSearchPosition( const int array[], int size, int value){    //Looks for a number, and counts how many times its repeated.
    int index=0;
    for (int i=0; i<size; i++){ //Passes through the whole array
        if(value==array[i]){    //If array[i] is EQUAL to value searched
            cout << i+1 << ", ";
            //index++;            //Increment index by 1
        }   
    }

}