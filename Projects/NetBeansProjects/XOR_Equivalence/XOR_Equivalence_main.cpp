
#include <iostream>   //I/O Library

using namespace std;  //Library Scope

//Main
int main(){

    bool x,y;
    
    //Heading for Table One
    cout<<"X Y  (X&&Y)||~(X||Y) = !(X^Y)"<<endl; // ^ is different from &&
    
    //First Row, X is True and Y is True
    x=true;
    y=true;
    
    cout<<(x?'T':'F')<<" "       
        <<(y?'T':'F')<<"  "      
        <<"       "<<((x&&y)||!(x||y)?'T':'F')
        <<"            "<<(!(x^y)?'T':'F')
    <<endl;
    
    //Second Row, X is True and Y is False
    x=true;
    y=false;
    
    cout<<(x?'T':'F')<<" "       
        <<(y?'T':'F')<<"  "      
        <<"       "<<((x&&y)||!(x||y)?'T':'F')
        <<"            "<<(!(x^y)?'T':'F')
    <<endl;
    
    //Third Row, X is False and Y is True
    x=false;
    y=true;
    
    cout<<(x?'T':'F')<<" "       
        <<(y?'T':'F')<<"  "      
        <<"       "<<((x&&y)||!(x||y)?'T':'F')
        <<"            "<<(!(x^y)?'T':'F')
    <<endl;
    
    //Final Row, X is False and Y is False
    x=false;
    y=false;
    
    cout<<(x?'T':'F')<<" "       
        <<(y?'T':'F')<<"  "      
        <<"       "<<((x&&y)||!(x||y)?'T':'F')
        <<"            "<<(!(x^y)?'T':'F')
    <<endl;
 
    
    //Second Table
    cout<<"\n            And\n"
        <<endl;
    //Heading for Table Two
    cout<<"X Y  (X||Y)&&~(X&&Y) = (X&&Y)"<<endl;
    
    //First Row, X is True and Y is True
    x=true;
    y=true;
    
    cout<<(x?'T':'F')<<" "             
        <<(y?'T':'F')<<"          "    
        <<((x||y)&&!(x&&y)?'T':'F')<<"          "
        <<(x^y?'T':'F')
        <<endl;
    
    //Second Row, X is True and Y is False
    x=true;
    y=false;
    
    cout<<(x?'T':'F')<<" "             
        <<(y?'T':'F')<<"          "    
        <<((x||y)&&!(x&&y)?'T':'F')<<"          "
        <<(x^y?'T':'F')
        <<endl;
    
    //Third Row, X is False and Y is True
    x=false;
    y=true;
    
    cout<<(x?'T':'F')<<" "              
        <<(y?'T':'F')<<"          "     
        <<((x||y)&&!(x&&y)?'T':'F')<<"          "
        <<(x^y?'T':'F')
        <<endl;
    
    //Final Row, X is False and Y is False
    x=false;
    y=false;
    
    cout<<(x?'T':'F')<<" "              
        <<(y?'T':'F')<<"          "     
        <<((x||y)&&!(x&&y)?'T':'F')<<"          "
        <<(x^y?'T':'F')
        <<endl;
    
    return 0;
}


