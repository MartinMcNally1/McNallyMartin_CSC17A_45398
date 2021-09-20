/*   
 * Author: Martin McNally
 * Purpose: Examples of Sorting Algorithms
 * Date: 09/01/2021
 */

//System Level Libraries
#include <iostream> //I/O Library
#include <string>   //String Library 
#include <ctime>    //Time library, fpr random number generator
#include <iomanip>  //Output Library

using namespace std;  //Library Scope

//Function Prototypes
void BubbleSort(int[], int);     //Bubble Sorting Algorithm
void SelectionSort(int[], int);  //Selection Sorting Algorithm
void MarkSort(int [], int);      //Prof. Mark Sorting Algorithm

void fillArray(int [], int);    //Fills Array with random numbers
void printArray(int [], int);   //Outputs Array contents

//Execution Starts Here
int main(){
    //Set Random Number Seed Here
    srand(static_cast<unsigned int>(time(0)));   //Random Number Generator Seed for rand() number
    
    //Declare Variables 
    const int size=50;  //Size of array
    int array[size];    //Array holding int variables      
    
    //Initialize Variables
    fillArray(array, size);     //Calls fillArray function
    printArray(array, size);    //Outputs array contents
   
    //  Sort Array
    //BubbleSort(array,size);   //Calls Bubble Sort Algorithm
    SelectionSort(array, size); //Calls Selection Sort Algorithm
    
    //Output Array
    printArray(array, size);    //Outputs array contents
    
    //Exit Stage 
    
    return 0;
}

//Function Prototypes

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

//Bubble Sort Algorithm with descriptions
void BubbleSort(int array[], int size){     //Plus upgrades form Prof. Lehr
    bool swap; //If True, then swap has occurred. 
    do{
        --size;     //Solves issue were first element had a 0
        swap=false;
        for (int i=0; i<size; i++){     //Starts from element 0 to the last element
            if (array[i] > array[i+1]){ //If element i of array is greater then element i+1 of array
                int temp = array[i];    //Assign a[i] in temp
                array[i] = array[i+1];  //Assign a[i+1] in a[i], overriding it with new variable   
                array[i+1] = temp;      //Assign temp in a[i+1], swapping a[i] and a[1+1]
                swap = true;            //If a swap occurred, bool swap is true
            }
        }
    } while(swap);  //Perform do-while loop while swap is true
}

//Selection Sort Algorithm
void SelectionSort(int array[], int size){  //Plus upgrades from  Prof. Lehr
    for (int index=0; index<size-1; index++ ){
        int SmallestI=index;    //Assigns index of first array to compare to see if it is the smallest 
        for ( int i=index+1; i<size; i++){ //Compares Smallest index with the rest of the array variables 
                                           //We index+1 because we don't want to compare the same array at the same index
            if (array[SmallestI]>array[i]){ //If the element is array[SmallestI] is greater then array[i]
                SmallestI=i;    //Store the index for smallest element in array
            }
        }//Now that we know where the smallest element is of the array, we swap them
        int temp=array[index]; 
        array[index]=array[SmallestI];
        array[SmallestI]=temp;
    }
}