/* 
 * File:   Median_Dynamic.Memory.Allocation.main.cpp
 * Author: Martin McNally
 * Created: Oct 2, 2021
 * Purpose: Find the Median of a 1D pointer array
 *          and output accordingly 
 */


#include <iostream>
#include <iomanip>

using namespace std;
int *getData(int &);         //Return the array size and the array

void prntDat(int *,int);    //Print the integer array

float *median(int *,int);  //Fill the median Array with the Float array size, the median, and the integer array data

void prntMed(float *);     //Print the median Array

int main(){
    
    int size=0;
    int *ptr = getData(size);   //Fills in 1D pointer array, returns pointer with size of pointer
    float *ptrMed=median(ptr,size); //Finds median, size of float pointer array and copies integer array in correct order
	
	prntDat(ptr,size);  //Prints pointer array
	prntMed(ptrMed);    //Prints float array
	
	
	delete[] ptr;       //Deallocate  ptr   
	delete[] ptrMed;    //Deallocate  ptrMed
	return 0;
}

int *getData(int &size){         //Return the array size and the array
    cin >> size;
    
    int *ptr = new int [size];
    for (int i; i<size; i++){
        cin >> *(ptr+i);
    }
    return ptr;
}

void prntDat(int *ary, int size){    //Print the integer array
    
    for (int i=0; i<size-1; i++){
        cout << *(ary+i) << " ";
    } cout <<*(ary+size-1) << endl;
}
float *median(int *ary, int size){  //Fill the median Array with the Float array size, the median, and the integer array data
    float total=0.00;
    for (int i=0; i<size; i++){
        total+=*(ary+i);    //Adds the sum of variables into total
    }
    
    float *med = new float[size+2]; //Allocates size+2 floats of memory for float pointer array
    *(med+0)=size+2;    //Assigns the number size of float pointer array to index 0
    *(med+1)=total/size;    //Assigns the median to index  
    
    for (int i=0; i<size; i++){
        *(med+(i+2)) = *(ary+i);
    }
    return med;
}
void prntMed(float *ptrM){  //Print the median Array
    cout << *(ptrM+0);
    int indx=1;
    while( *(ptrM+indx)!='\0'){ //While the pointer does not pointer to a null
    cout << fixed << setprecision(2) << " " << *(ptrM+indx);
    indx++;
        }
}    
