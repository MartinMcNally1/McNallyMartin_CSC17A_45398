/* 
 * File:   Sum_Dynamic.Memory.Allocation.main.cpp
 * Author: Martin McNally
 * Created: Oct 2, 2021
 * Purpose: Create a parallel array that represents the 
 *          successive sum of preceding members in the array.
 */
#include <iostream>

using namespace std;
int *getData(int &);          //Return the array size and the array from the inputs

int *sumAry(const int *,int); //Return the array with successive sums

void prntAry(const int *,int);//Print the array

int main(){
    
    int size=0;
    int *ptr=getData(size);
    int *ptrSum=sumAry(ptr,size);
    
    prntAry(ptr,size);
    cout << endl;
    prntAry(ptrSum,size);
    
    
    delete[] ptr;
    delete[] ptrSum;
    cout << "Works on Code-E";
    
    
    return 0;
}

int *getData(int &size){         //Fill the array and get array size
    cin >> size;
    
    int *ptr = new int [size];
    for (int i; i<size; i++){
        cin >> *(ptr+i);
    }
    return ptr;
}

int *sumAry(const int *ptr, int size){//Return the array with successive sums
    int *ptrSum = new int [size];   //Allocate memory to ptrSum array 
    
    *(ptrSum+0) = *(ptr+0);
    for (int i=1; i<size; i++){
        *(ptrSum+i) = *(ptrSum+(i-1)) + *(ptr+i);
    }
    
    return ptrSum;
}

void prntAry(const int *ptr, int size){//Print the array
    int indx=1;
    cout << *(ptr+0); 
    while ( *(ptr+indx) != '\0' ){
        cout << " " << *(ptr+indx);
        indx++;
    }
}