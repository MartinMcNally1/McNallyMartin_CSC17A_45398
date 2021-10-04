/* 
 * File:   PointerPractice.main.cpp
 * Purpose:  Practice Pointers with examples
 * Note: You don't need all the System Libraries, only <iostream> would be needed         
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <iomanip>    //Output Manipulation Library
#include <string>     //String Library
#include <ctime>      //Time library, for rand
#include <cmath>      //Math library(Think of your own functions for math)
#include <vector>     //Vector library

using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
void Basic_Pointers();
void Pointer_Arrays();
void Print_Arrays(int*, int);
int *ReturnPointerArywithCount(int &);
int **Dynamic_2D_Arrays(int &, int &);
void DELETE_2D_MEMORY_CRITICAL( int**, int, int);
void DELETE_MEMORY_CRITICAL( int*);

//Code Begins Execution Here with function main
int main(int argc, char** argv) {

    //Basic_Pointers(); //Basic Idea of pointers, with memory address, referencing and dereferencing pointers for variables
    
    //Pointer_Arrays();

    //Returns a Pointer Array and Count of Pointer
//    int size=0;   
//    int *ary=ReturnPointerArywithCount(size);
//    for(int i=0; i<size; i++){
//        cout << *(ary+i);
//    }
//    cout << endl << size;
//    DELETE_MEMORY_CRITICAL(ary);
    

    return 0;
}

void DELETE_MEMORY_CRITICAL( int* pointer ){
    delete[] pointer;
    cout << endl << "Memory allocated to pointer at address " << pointer << " is deleted" << endl;
}

void Basic_Pointers(){
    
    int num=8;              //Assign 8 to int num
    int* ptr=nullptr;       //Makes ptr a pointer and 
                            //gives it a address of zero(nothing)
                            //(This step is not necessary)    
    ptr = &num;             //Assigns ptr to hold the address of num
    cout << "Output num memory address from 'ptr': "; 
    cout << ptr <<endl;     //Output the address of num held in ptr
    cout << "Output value of num: ";
    cout << num << endl;    //Output num
    cout << "Value held at pointer 'ptr' address: ";
    cout << *ptr << endl;   //Dereference ptr to access its memory
                            //In this case to Output 
    cout<< "Increment dereferenced pointer '*ptr' by 1" << endl;
    *ptr+=1;                //Dereference ptr to access its memeroy
                            //Add 1
    cout << "Output num after pointer access increment: ";
    cout << num << endl;     //Output num, after it has been manipulated by pointers
    cout << "Output memory address of num from 'ptr': ";
    cout << ptr <<endl;     //Output the address of num held in ptr
    cout << "Value held after pointer access: ";
    cout << *ptr << endl;
}

void Pointer_Arrays(){  //Works
    int aryStd[5];  //Standard array
    for (int i=0; i<5; i++){
        aryStd[i]=i+1;    //Fills standard array at index i with i
    }
    
    int* aryP= new int[5]; //Allocates 5 integer memory spaces to pointer 
    for (int i=0; i<5; i++){
        *(aryP+i)=i+2;    //Assigns i at the array pointer aryP at index i
                        //Remember syntax for this. 
    }
    
    cout << "Here are the variables in array 'aryStd'," << endl;
    cout << "Printed with the use of pointers: ";
    Print_Arrays(aryStd,5);
    cout << endl;
    
    cout << "Here are the variables pointer array 'aryP': ";
    Print_Arrays(aryP,5);
    cout << endl;
    
    DELETE_MEMORY_CRITICAL(aryP);   //Deletes the allocated memory for other use
                                    //CRITICALLY IMPORTANT
}

void Print_Arrays(int* array, int size){ //Works
    int indx=0;
    while (indx<size){
        cout << *(array+indx);
        indx++;
    }

}

int* ReturnPointerArywithCount( int &count){ //Returns a integer pointer array with an inputted size;
                                             //Note: The & sign references count so we can access its date and mess with it 
    cin >> count;    //Input count of pointer array
    int *ptr = new int [count];  //Allocates 'count' amount of Integer spaces of memory for pointer ptr
    
    for(int i=0; i<count; i++){  //For loop for inputting data in integer pointer array
        cin >> *(ptr+i);         //Input each variable at index i
    }
    return ptr;                  //Returns ptr
                                 //Note: No need for * in front of Pointer name
}

int **Dynamic_2D_Arrays(int &rows, int &cols){
    int rows, cols;
    cin>>rows>>cols;
    
    //Step 1
    int **ptr2D = new int *[rows];  //Allocate memory to the pointer-pointer 
    //Step 2
    for (int i=0; i<rows; i++){     //Allocates memory to to each pointer the pointer points to
        ptr2D[i]= new int[cols];
    }
    //Step 1 and 2 Allocate and initialize the 2D dynamic array for use. 
    //Remember to delete it all
    
    for(int r=0; r<rows; r++){
        for (int c=0; c<cols; c++){
            cin >> ptr2D[r][c];
        }
    }
    
    return ptr2D; 
}

void DELETE_2D_MEMORY_CRITICAL( int **ptr, int rows, int cols){ //Dealloacte dynamic memory from back to forward to avoid deleting the address to memory
    //Deallocate Step 2
    for (int i=0; i<cols; i++){
        delete[] ptr[i];
    }
    //Deallocate Step 1
    delete[] ptr;
    
    ptr=nullptr;    //pointer points to nothing
}
