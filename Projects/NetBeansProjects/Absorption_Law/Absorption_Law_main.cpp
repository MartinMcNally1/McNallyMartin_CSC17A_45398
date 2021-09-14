
#include <iostream>   //I/O Library

using namespace std;  //Library Scope

//Main
int main(){

    bool x,y;
    
    //Absorption Law
    cout<<" Absorption Law Table\n"
        <<"X Y  X||(X&&Y) = X"<<endl;
        
    //First Row, X is true and Y is true
    x=true;
    y=true;
    
    cout<<(x?'T':'F')<<" "     
        <<(y?'T':'F')      
        <<"              "<<(x||(x&&y)?'T':'F')<<endl;

    //Second Row, X is true and Y is false
    x=true;
    y=false;
    
    cout<<(x?'T':'F')<<" "     
        <<(y?'T':'F')      
        <<"              "<<(x||(x&&y)?'T':'F')<<endl;

    //Third Row, X is false and Y is true
    x=false;
    y=true;
    
    cout<<(x?'T':'F')<<" "     
        <<(y?'T':'F')      
        <<"              "<<(x||(x&&y)?'T':'F')<<endl;
    

    //Final Row, X is false and Y is false
    x=false;
    y=false;
    
    cout<<(x?'T':'F')<<" "     
        <<(y?'T':'F')      
        <<"              "<<(x||(x&&y)?'T':'F')<<endl;
    
    return 0;
}

