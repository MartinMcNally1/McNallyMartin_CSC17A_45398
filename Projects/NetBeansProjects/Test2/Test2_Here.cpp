/* 
 * File:   main.cpp
 * Author: Martin McNally       
 * Created on 06/30/21
 * Purpose:  Sorting a 2-D array of characters if row and columns match
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int);//Sort by row
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    
    //Input the size of the array you are sorting
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    cout << colDet << endl;
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    }else{
        if(rowDet!=rowIn)
        cout<<(rowDet<rowIn?"Row Input size less than specified.":
            "Row Input size greater than specified.")<<endl;
        if(colDet!=colIn)
        cout<<(colDet<colIn?"Column Input size less than specified.":
            "Column Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}
int read(char arr[][COLMAX],int &rowDet){   //Outputs row and columns detected from input
    int i=0;
    while (cin >> arr[i]){
        i++;
    }
    return 0;
}
void sort(char array[][COLMAX],int row,int col){ //Sort by row
    int max;    //Max elements in subscript
    int i;      //Index for counting
    for (int r=0; r<=row; r++){
        for (max=col-1; max>0; max--){
            for (i=0; i<max; i++){
                if (array[i][r]>array[i+1][r]){   //compares first element a with element a+1 in ascending order
                    char temp=array[i][r];
                    array[i][r]=array[i+1][r];
                    array[i+1][r]=temp;
                }
            }
        }
    }
}
void print(const char array[][COLMAX],int row, int col){  //Print the sorted 2-D array
    for (int r=0; r<=row; r++){
        for (int c=0; c<=col; c++){
            cout << array[r][c];
            if (c==col){
                cout << endl;
            }
        }
    }
} 