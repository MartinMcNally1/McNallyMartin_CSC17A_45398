/* 
 * File:   main.cpp
 * Author: Martin McNally   
 * Created: 06/30/21
 * Purpose:  Sorting an array of characters if specified correctly
 */

//System Libraries Here
#include <iostream>//cout,cin
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int  read(char []);
void sort(char [],int);
void print(const char [],int);
void swap(int&, int&);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;//Larger than needed
    char array[SIZE]; //Character array larger than needed
    int sizeIn,sizeDet;//Number of characters to be read, check against length
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of characters and sort"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of characters and determine it's size
    cout<<"Now read the Array"<<endl;
    cin>>array;
    sizeDet=read(array);//Determine it's size
    cout << sizeDet << endl;
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size to sort
    if(sizeDet==sizeIn){
        sort(array,sizeIn); //Sort the array
        print(array,sizeIn);//Print the array
    }else{
        cout<<(sizeDet<sizeIn?"Input size less than specified.":
            "Input size greater than specified.")<<endl;
    }
    //Exit
    return 0;
}
//Determines the length of the array to compare.
int read( char ary[]){
    int count=0;
    while (ary[count]!='\0'){
        count++;
    }
    int a=count;
//    int a=strlen(ary);
    return a;
    }
//Sort the array
void sort(char array[],int size){
    int max;    //Max elements in subscript
    int i;      //Index for counting
    for (max=size-1; max>0; max--){
        for (i=0; i<max; i++){
            if (array[i]>array[i+1]){   //compares first element a with element a+1 in ascending order
                int temp=array[i];
                array[i]=array[i+1];
                array[i+1]=temp;
//                swap(array[i], array[i+1]);
            }
        }
    }
    
}
//Output the sorted array
void print(const char array[],int size){
    for (int i=0; i<=size; i++){
        cout << array[i];
    }
}

//Swap function
//Remember this for future projects.
//void swap( int &a, int &b){
//    int temp=a;
//    a=b;
//    b=temp;
//}