/* 
 * File:   Reverse_Dynamic.Memory.Allocation.main.cpp
 * Author: Martin McNally
 * Created: Oct 2, 2021
 * Purpose: Sort, then Reverse a dynamic pointer array
 *         
 */

#include <iostream>

int *getData(int &);               //Fill the array

int *sort(const int *,int);         //Sort smallest to largest

int *reverse(const int *,int);  //Sort in reverse order

void prntDat(const int *,int); //Print the array

using namespace std;

int main(){
	
	int size=0;
	int *ptr=getData(size);
	
	int *ptrSrt=sort(ptr,size);
	
	int *ptrRev=reverse(ptrSrt,size);
	
	prntDat(ptrSrt,size);
	cout << endl;
	prntDat(ptrRev,size);
	
	delete[] ptr;
	delete[] ptrSrt;
	delete[] ptrRev;
	cout << "Works on Code-E";
	return 0;
}

int *getData(int &size){         //Fill the array and array size
    cin >> size;
    
    int *ptr = new int [size];
    for (int i; i<size; i++){
        cin >> *(ptr+i);
    }
    return ptr;
}

int *sort(const int *ptr, int size){         //Sort smallest to largest, with dynamic memory
    int *ptrSrt= new int [size]; //Allocate memory for ptrSrt
    for (int i=0; i<size; i++){ //Copied variables from ptr to ptrSrt
        *(ptrSrt+i) = *(ptr+i);
    }
    
    for (int indx=0; indx<size-1; indx++ ){
        int small=indx;    //Assigns index of first variable to compare to see if it is the smallest 
        for ( int i=indx+1; i<size; i++){ //Compares small index with the rest of the variables at the pointer array
                                           //We index+1 because we don't want to compare the same array at the same index
            if (*(ptrSrt+small) > *(ptrSrt+i)){ //If the element at *ptr+small is greater then *ptr+i
                small=i;    //Store the index for smallest element in array
            }
        }//Now that we know where the smallest element is of the array, we swap them
        int temp = *(ptrSrt+indx);      //Assign ptr value at index indx
        *(ptrSrt+indx) = *(ptrSrt+small);  //Overide ptr value at index indx wiht value at ptr value at index small
        *(ptrSrt+small)=temp;         //Overide ptr value at index indx with value temp;
        //Swaped
    }
    return ptrSrt;
}

int *reverse(const int * ptr, int size){      //Sort in reverse order
    int *ptrRev = new int [size];    //Alocate memory for integer pointer array ptrRev
    for (int i=0; i<size; i++){ //Copied variables from ptr to ptrSrt
        *(ptrRev+i) = *(ptr+i);
    }
    
    int start=0;    //First index
    int end=size-1; //Last index
    
    while (start < end){    //Swap loop
        int temp = ptrRev[start]; 
        ptrRev[start] = ptrRev[end];
        ptrRev[end] = temp;
        start++;
        end--;
    }
    return ptrRev;
}
void prntDat(const int *ptr, int size){      //Print the array
    cout << *(ptr+0);
    for( int i=1; i<size; i++){
        cout <<" "<< *(ptr+i);
    }
}