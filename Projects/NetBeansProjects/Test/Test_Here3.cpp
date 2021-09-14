/* 
 * File:   main.cpp
 * Author:Martin McNally
 * Created: 07/2/21
 * Purpose:  Even, Odd Vectors and Array Columns Even, Odd
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <vector>  //vectors
#include <iomanip>

using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=2;//Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &, vector<int> &);
//void copy(vector<int>, vector<int>,int [][COLMAX]);
//void prntVec(vector<int>, vector<int>,int);//int n is the format setw(n)
//void prntAry(const int [][COLMAX],int,int,int);

//Program Execution Begins Here
int main() {
    //Declare all Variables Here
    const int ROW=80;           //No more than 80 rows
    int array[ROW][COLMAX];     //Really, just an 80x2 array, even vs. odd
    vector<int> even(0),odd(0); //Declare even,odd vectors
    
    //Input data and place even in one vector odd in the other
    read(even,odd);
    
    //Now output the content of the vectors
    //          setw(10)
    //prntVec(even,odd,10);//Input even, odd vectors with setw(10);
    
    //Copy the vectors into the 2 dimensional array
//    copy(even,odd,array);
    
    //Now output the content of the array
    //                              setw(10)
//    prntAry(array,even.size(),odd.size(),10);//Same format as even/odd vectors
    
    //Exit
    return 0;
}
void read(vector<int> &even, vector<int> &odd){    //Input data and place even in one vector odd in the other
    int num=0;
    int size=0;
    int Nsize=0;
    
    cout << "enter row size" << endl;
    //Input Values
    cin >> size;
    for (int i=0; i<size; i++){
        cin >> num;
        if (num%2==0){  //num is even, place in even vector
            even.push_back(num);
        }
        else{   //if num is not even, place num in odd vector
            odd.push_back(num);
        }
    }
    //Find row size as Nsize
    if (even.size()>odd.size()){    //if even vector is big, have row be even.size()
        Nsize=even.size();
    }
    else {Nsize=odd.size();}        //if even vector is not bigger, have row size be odd.size()
    
    //fill the rest of the vectors with 0
    for (int i=0; i<Nsize; i++){
        if ( i>=even.size()){
            even.push_back(0);
        }
        if (i>=odd.size()){
            odd.push_back(0);
        }
        cout << even[i] << " " << odd[i] << endl;
    }
    cout << "size of even vector: " << even.size() << " and size of odd vector: " << odd.size();
}
//void copy(vector<int> even, vector<int> odd, int arry[][COLMAX]){ //Copy the vectors into the 2 dimensional array   
//    for (int i=0; i<even.size(); i++){
////        if (i>=even.size()){
////            0=even.at(i);
////            even[i]=arry[i][0];
////        }
////        else{even[i]=arry[i][0];}
//        arry[i][0]=even[i];
//    }
//    for (int i=0; i<odd.size(); i++){
////        if (i>=odd.size()){
////            0=odd.at(i);
////        }
////        else {odd[i]=arry[i][1];}
//        arry[i][1]=odd[i];
//    }
//}
//void prntVec(vector<int> even, vector<int> odd, int width){ //Now output the content of the vectors //int n is the format setw(n)
//    int num=0;
//    int size=0;
//    int Nsize=0;
//    int evenN=0;
//    int oddN=0;
//    if (even.size()>odd.size()){    //if even vector is big, have row be even.size()
//        Nsize=even.size();
//    }
//    else {Nsize=odd.size();}        //if even vector is not bigger, have row size be odd.size()
//    
//    for (int i=0; i<Nsize; i++){
////        evenN=even[i];
////        oddN=odd[i];
////        if ( i>=even.size()){
////            evenN=0;
////        }
////        if (i>=odd.size()){
////            oddN=0;
////        }
//        cout << even[i] << " " << odd[i] << endl;
//    }
//    //    int size=0;
////    int oddN=0;
////    int evenN=0;
////    if (even.size()>odd.size()){
////        size=even.size();
////    }
////    else {size=odd.size();}
////        
////    for (int i=0; i<size; i++){
////        evenN=even[i];
////        oddN=odd[i];
////        if ( i>=even.size()){
////            evenN=0;
////        }
////        if ( i>=odd.size()){
////            oddN=0;
////            }
////        cout << evenN << " " << oddN << endl; 
////    }
////}
//    //    int row=0;
////    if (even.size()>odd.size()){
////        row=even.size();
////    }
////    if (odd.size()>even.size()){
////        row=odd.size();
////    }
////    else( row=even.size());
////    
////    for (int i=0; i<row; i++){
////        cout << even[i] << setw(width) << odd[i] << endl;
////    }
////}
//                                            
//void prntAry(const int array[][COLMAX],int sizeE,int sizeO,int width){ //Now output the content of the array
//    int row=0;
//    if (sizeE>sizeO){
//        row=sizeE;
//    }
//    if (sizeO>sizeE){
//        row=sizeO;
//    }
//    else( row=sizeE);
//    
//    for(int i=0; i<row; i++){
//        cout << array[i][0] << setw(width) << array[i][1] << endl;
//    }
//}