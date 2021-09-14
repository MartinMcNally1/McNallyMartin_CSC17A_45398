
#include <iostream>
using namespace std;

void TT(bool, bool);   //X is True and Y is True Row
void TF(bool, bool);   //X is True and Y is False Row
void FT(bool, bool);   //X is False and Y is True Row
void FF(bool, bool);   //X is False and Y is False Row
//Don't need now, maybe use for other codes for simplicity

//Main
int main() {
    //Declare Variables 
    bool x,y;
    
    //Display the Heading
    cout<<"X Y ~X ~Y X&&Y X||Y X^Y X^Y^X X^Y^Y !(X&&Y) !X||!Y !(X||Y) !X&&!Y"<<endl;
    
    //First Row where X is true and Y is true, tested by logic statements
    x=true;
    y=true;
    cout<<(x?'T':'F')<<" "       //X is true    // : is used as a separator for an if statement !!!FOR CERTAIN CASES!!
        <<(y?'T':'F')<<"  "      //Y is true
        <<(!x?'T':'F')<<"  "     //Not X is false
        <<(!y?'T':'F')<<"   "    //Not Y is false
        <<(x&&y?'T':'F')<<"    "    //X and Y are true
        <<(x||y?'T':'F')<<"   "     //X or Y is true
        <<(x^y?'T':'F')<<"    "    //X and Y is true, X^Y = X&&Y
        <<(x^y^x?'T':'F')<<"     "      //X and Y and X is true
        <<(x^y^y?'T':'F')<<"       "    //X and Y and Y is true
        <<(!(x&&y)?'T':'F')<<"      "     //!X and !Y is false
        <<((!x||!y)?'T':'F')<<"       "     //!X or !Y is false
        <<((!(x||y))?'T':'F')<<"      "     //Not X or Y is false
        <<((!x^!y)?'T':'F')<<""
        <<endl;
    
    //Second Row where X is true and Y is False
    x=true;
    y=false;
    cout<<(x?'T':'F')<<" "       
        <<(y?'T':'F')<<"  "      
        <<(!x?'T':'F')<<"  "     
        <<(!y?'T':'F')<<"   "    
        <<(x&&y?'T':'F')<<"    " 
        <<(x||y?'T':'F')<<"   "  
        <<(x^y?'T':'F')<<"    "  
        <<(x^y^x?'T':'F')<<"     "      
        <<(x^y^y?'T':'F')<<"       "    
        <<(!(x&&y)?'T':'F')<<"      "     
        <<((!x||!y)?'T':'F')<<"       "     
        <<((!(x||y))?'T':'F')<<"      "     
        <<((!x^!y)?'T':'F')<<""
        <<endl;
    
    //Third Row where X is False and Y is true
    x=false;
    y=true;
    cout<<(x?'T':'F')<<" "       
        <<(y?'T':'F')<<"  "      
        <<(!x?'T':'F')<<"  "     
        <<(!y?'T':'F')<<"   "    
        <<(x&&y?'T':'F')<<"    " 
        <<(x||y?'T':'F')<<"   "  
        <<(x^y?'T':'F')<<"    "  
        <<(x^y^x?'T':'F')<<"     "      
        <<(x^y^y?'T':'F')<<"       "    
        <<(!(x&&y)?'T':'F')<<"      "     
        <<((!x||!y)?'T':'F')<<"       "     
        <<((!(x||y))?'T':'F')<<"      "     
        <<((!x^!y)?'T':'F')<<""
        <<endl;

    
    //Final Row where X is False and Y is False
    x=false;
    y=false;
    cout<<(x?'T':'F')<<" "       
        <<(y?'T':'F')<<"  "      
        <<(!x?'T':'F')<<"  "     
        <<(!y?'T':'F')<<"   "    
        <<(x&&y?'T':'F')<<"    " 
        <<(x||y?'T':'F')<<"   "  
        <<(x^y?'T':'F')<<"    "  
        <<(x^y^x?'T':'F')<<"     "      
        <<(x^y^y?'T':'F')<<"       "    
        <<(!(x&&y)?'T':'F')<<"      "     
        <<((!x||!y)?'T':'F')<<"       "     
        <<((!(x||y))?'T':'F')<<"      "     
        <<((!x^!y)?'T':'F')<<""
        <<endl;
    
    return 0;
}
