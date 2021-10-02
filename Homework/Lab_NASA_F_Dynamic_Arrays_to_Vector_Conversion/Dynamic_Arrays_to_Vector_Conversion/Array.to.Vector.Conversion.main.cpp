/* 
 * File:   Array.to.Vector.Conversion.main.cpp
 * Author: Dr. Mark E. Lehr, Martin McNally
 * Created: Sep 27, 2021, 5:00 PM
 * Purpose:  Convert then Compare 1 and 2 Dimensional Vectors
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>

using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions and Array Dimension


//Function Prototypes Here
void prnt1DV(vector<int>, int);    //Prints 1D vector<int>

void prnt2DV(vector<vector<int>>, int, int);  //Prints 2D vector<vector<int>>

void F1DVec(vector<int> &, int, int, int);   //Fills 1D vector<int>

void F2DVec(vector<vector<int>> &, vector<int> &, int, int); //Fills 2D vector<vector<int>>

void swap(int &,int &); //No need to change.

void smlLst(vector<int>, int);

void mrkSort(vector<int> &);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    int rowsize=4;//Row size for both 1 and 2 D arrays, don't need for vectors
    int colsize=3;//The column size for a 2 dimensional Array, don't need for vectors
 
    vector<int> aVec;   //1D vector<int>
    vector<int> bVec;   //1D vector<int>
    vector<int> cVec;   //1D vector<int>
    vector<vector<int>> tVec;   //2D vector<vector<int>>
    
    int lowRng=100,highRng=999;
    int perLine=4;
        
    //Fill each parallel array     
    F1DVec(aVec,rowsize,highRng,lowRng);           //Fill array A with 3 digit number(100-999) change to aV<int> 
    F1DVec(bVec,rowsize,highRng/10,lowRng/10);     //Fill array A with 3 digit number(100-999) change to aV<int>
    F1DVec(cVec,rowsize,highRng/100,lowRng/100);   //Fill array A with 3 digit number(100-999) change to aV<int>
    
    //Sort the array the for all positions
    mrkSort(aVec); //Sorts vectors
    mrkSort(bVec); //Sorts vectors
    mrkSort(cVec); //Sorts vectors 
    
    //Fill the 2-D array
    F2DVec(tVec,aVec,rowsize,0);
    F2DVec(tVec,bVec,rowsize,1);
    F2DVec(tVec,cVec,rowsize,2);
    
    //Print the values in the array
    prnt1DV(aVec,perLine);
    prnt1DV(bVec,perLine);
    prnt1DV(cVec,perLine);
    prnt2DV(tVec,rowsize,colsize);
    //Cleanup
    

    //Exit
    cout<< "test" <<endl;
    return 0;
}

void F2DVec( vector<vector<int>> &tVec, vector<int> &Vec, int rowS, int Col){
    for (int i=0; i<rowS; i++){
        tVec[i][Col]=Vec[i];
    }
}

   //Fills 1D vector<int>
void F1DVec(vector<int> &vec, int rowS, int Hnum, int Lnum){
    for(int indx=0;indx<rowS;indx++){
        vec.push_back( rand()%(Hnum-Lnum+1)+Lnum ); //Fils with a random number between 100-999
    }  
}

void prnt2DV(vector<vector<int>> tVec, int rowsize, int colsize){ //Print 2D vector<vector<int>>
    cout<<endl<<"The Vector Values"<<endl;
    for(int row=0;row<rowsize;row++){
        for(int col=0;col<colsize;col++){
            cout<<setw(4)<<tVec[row][col];
        }cout<<endl;
    }
}

void prnt1DV(vector<int> Vec, int perLine){    //Prints 1D vector<int>
    cout<<endl<<"The Vector Values"<<endl;
    int SIZE=Vec.size();
    
    for(int indx=0;indx<SIZE;indx++){
        cout<<Vec[indx]<<" ";
        if(indx%perLine==(perLine-1))cout<<endl;    //Determines when to start a new line while printing 
    }
    cout<<endl;
}

void mrkSort(vector<int> &Vec){    //Function sorts via Prof. Mark sort method(Dont get his method, too dumb)
    int size=Vec.size();
    for(int pos=0;pos<size-1;pos++){
        smlLst(Vec,pos);
    }
}

void smlLst(vector<int> Vec,int pos){ //Used for mrkSort
    int size=Vec.size();
    for(int i=pos+1;i<size;i++){
        if(Vec[pos]>Vec[i]){
            swap(Vec[pos],Vec[i]);
        }
    }
}

void swap(int &a,int &b){   //Swaps int, used for markSort
    int temp=a;
    a=b;
    b=temp;
}