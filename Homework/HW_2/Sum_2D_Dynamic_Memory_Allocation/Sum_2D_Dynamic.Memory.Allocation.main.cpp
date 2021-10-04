#include <iostream>

using namespace std;

int **getData(int &,int &);        //Return the 2-D array and its size.

void prntDat(const int * const *,int,int);//Print the 2-D Array

void destroy(int **,int,int);       //Deallocate memory

int sum(const int * const *, int,int);    //Return the Sum

int main(){
	
    int rows=0;
    int cols=0;
    int **ptr2D=getData(rows,cols);
    
    prntDat(ptr2D,rows,cols);
    cout << sum(ptr2D,rows,cols);
    
    destroy(ptr2D,rows,cols);
    
    return 0;
}
int **getData(int &rows, int &cols ){        //Return the 2-D array and its sizes(rows and cols).
    cin>>rows>>cols;
    //Step 1
    int **ptr2D = new int *[rows];  //Allocate memory to the pointer-pointer 
    //Step 2
    for (int i=0; i<rows; i++){     //Allocates memory to the pointer the pointer points to
        ptr2D[i]= new int[cols];
    }

    for(int r=0; r<rows; r++){      //Fill in dynamic 2D array
        for (int c=0; c<cols; c++){
            cin >> ptr2D[r][c];
        }
    }
    return ptr2D;
}
void prntDat(const int * const *ptr, int rows, int cols){   //Print the 2-D Array
    for(int r=0; r<rows; r++){                        //There are two const because we do not want 
        for (int c=0; c<cols; c++){                   //to alter the contents of the array    
            if ( c!=0 && c!=cols)//if( c<(cols-1) ){
                cout << " ";
                cout<<ptr[r][c];
                
            //    cout << ptr[r][c] << " "; 
            //}
            //else{ cout << ptr[r][c];}
        }cout << endl;
    }                                                 
}
void destroy(int **ptr,int rows,int cols){       //Deallocate memory, do so in opposite order of allocating memory
    //Deallocate Step 2 first
    for (int i=0; i<cols; i++){
        delete[] ptr[i];
    }
    //Deallocate Step 1 second
    delete[] ptr;
    ptr=nullptr; //Pointer now points to nothing
}
int sum(const int * const *ptr, int rows, int cols){    //Return the Sum
    int sum=0;  //Initialize sum                  //There are two const because we do not want     
    for(int r=0; r<rows; r++){                    //to alter the contents of the array   
        for (int c=0; c<cols; c++){                    
            sum+= ptr[r][c];
        }
    } 
    return sum;
}