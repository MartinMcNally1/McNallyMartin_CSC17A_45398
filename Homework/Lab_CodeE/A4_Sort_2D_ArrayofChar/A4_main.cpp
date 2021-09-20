#include <iostream>
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

const int COLMAX=80;
int read(char[][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int);//Sort by row
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array

int main(int argc, char** argv) {
    const int ROW=30;             
    char array[ROW][COLMAX];      
    int colIn,colDet,rowIn,rowDet;
    
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
        cout << endl << endl;
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
int read(char list[][COLMAX],int &rows){
    int cols = 0;
    //is rows reading 5 or the address of 5 first???
    for(int i=0; i<rows; i++){
        cin >> list[i];
        if(strlen(list[i])>cols){
            cols = strlen(list[i]);
        }
    }
    return cols;
}
void sort(char list[][COLMAX],int rowIn,int colIn){
    char tempArr[colIn];
    char *temp = tempArr;
    
    //check one row...
    for(int i=0; i<rowIn; i++){
        //then check the next row
        for(int j=i+1; j<rowIn; j++){
            //now compare both rows:
            //if string2 is alphabetically <string1, then 
            //it returns a positive #. So, swap string1's location
            //with string2.
            if(strcmp(list[i],list[j])>0){
                strcpy(temp,list[i]);
                strcpy(list[i],list[j]);
                strcpy(list[j],temp);
            }
        }
    }
}
void print(const char list[][COLMAX],int rowIn,int colIn){
    for(int i=0; i<rowIn; i++){
        for(int j=0; j<colIn; j++){
            cout << list[i][j];
        }
        cout << endl;
    }
}