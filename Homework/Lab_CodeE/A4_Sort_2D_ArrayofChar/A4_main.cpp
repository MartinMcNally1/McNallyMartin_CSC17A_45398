/* 
 * File:   main.cpp
 * Author: Martin McNally       
 * Created on 09/18/21
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
    int maxR=0; //Number of Rows detected to compare    
    int maxC=0; //Number of Col detected to compare
    int temp=0;
    while(cin >> arr[maxR]){
        temp=strlen(arr[maxR]);
        maxC=maxC<temp?temp:maxC;   //If maxR is less then temp, set maxR to temp, else keep maxR
                                    //from lab aide, remember for future projects
        maxR++;
    }
    rowDet=maxR;
    return maxC;   //Numer of colums(numbr of digits/character)
}
void sort(char array[][COLMAX],int row,int col){ //Sort by row
    int max=0;    //Max elements in subscript
    int i=0;      //Index for counting
    for (int r=0; r<=row; r++){     //Starts from row 0 and continues 
        for (max=col-1; max>0; max--){  //Selection Sort, compareing first with Last, last+1, etc.
            for (i=0; i<max; i++){
                if (array[i][r] > array[i+1][r]){  
                    char temp=array[i][r];
                    array[i][r]=array[i+1][r];
                    array[i+1][r]=temp;
                }
            }
        }
    }
}
void print(const char array[][COLMAX],int row, int col){  //Print the sorted 2-D array
    for (int r=0; r<row; r++){
        for (int c=0; c<col; c++){
            cout << array[r][c];
            if (c==col-1){
                cout << endl;
            }
        }
    }
} 