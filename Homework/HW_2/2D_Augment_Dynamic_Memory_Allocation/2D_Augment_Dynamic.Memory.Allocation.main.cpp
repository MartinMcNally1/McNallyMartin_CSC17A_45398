#include <iostream>

using namespace std;

int **getData(int &,int &);//Get the Matrix Data

void printDat(const int * const *,int,int);//Print the Matrix

int **augment(const int * const *,int,int);//Augment the original array

void destroy(int **,int);//Destroy the Matrix, i.e., reallocate memory

int main(){
    int row = 0;
    int col = 0;
    
    cin >> row;
    
    cin >> col;
    
    int **array = nullptr;
    
    int **augArray = nullptr;
    
    array = getData(row, col);
    
    printDat(array, row, col);
    
    cout << endl;
    
    augArray = augment(array, row, col);
    
    printDat(augArray, row + 1, col + 1);
    
    destroy(array,col);
    destroy(augArray,col);
    return 0;
}

int **getData(int &row, int &col)
{
    int **arr = new int*[row];
    
    if(row <=0)
        return nullptr;
    
    
    for(int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }
    
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
        arr[i][j] = NULL;
        }
    }
    
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
        cin >> arr[i][j];
        }
    }
    
    return arr;
    
}

int **augment(const int * const * array, int row, int col)
{
    int plusRow = row + 1;
    int plusCol = col + 1;
    
    int **newArray = new int*[plusRow];
    
    if(plusRow == 0)
    return nullptr;
    
    for(int i = 0; i < plusRow; i++)
    {
        newArray[i] = new int[plusCol];
    }
    
    for(int i = 0; i < plusRow; i++)
    {
        for(int j = 0; j < plusCol; j++)
        {
        newArray[i][j] = NULL;
        }
    }
    
    for(int i = 0; i < plusRow; i++)
    {
        for(int j = 0; j < plusCol; j++)
        {
            if(i == 0 || j == 0)
            {
                newArray[i][j] = 0;
            }
            
            else
            {
                newArray[i][j] = array[i - 1][j - 1];
            }
        }
    }
    
    return newArray;
}

void printDat(const int * const * array, int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(j != 0 && j != col)
            cout << " ";
            
            cout << array[i][j];
        }
        if(i != row - 1)
        cout << endl;
    }
}
void destroy(int **ptr ,int size){
    //Deallocate Step 2 first
    for (int i=0; i<size; i++){
        delete[] ptr[i];
    }
    //Deallocate Step 1 second
    delete[] ptr;
    ptr=nullptr; //Pointer now points to nothing
    
}
