/* 
 * File: main.cpp
 * Author: Martin McNally
 * Created on: Netbeans
 * Purpose: Truth table with a while loop.
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
using namespace std;

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    bool x,y;
    
    //Display the Heading
    cout<<"X Y !X !Y X&&Y X||Y X^Y X^Y^X X^Y^Y !(X&&Y) !X||!Y "<<
          " !(X||Y) !X&&!Y"<<endl;
    
    //While loop inputting x and y, and outputting bool values.
    while (cin >> x >> y){
    cout<<(x?'T':'F')<<setw(2)
        <<(y?'T':'F')<<setw(3)
        <<(!x?'T':'F')<<setw(3)
        <<(!y?'T':'F')<<setw(4)
        <<(x&&y?'T':'F')<<setw(5)
        <<(x||y?'T':'F')<<setw(4)
        <<(x^y?'T':'F')<<setw(5)
        <<(x^y^x?'T':'F')<<setw(6)
        <<(x^y^y?'T':'F')<<setw(8)
        <<(!(x&&y)?'T':'F')<<setw(7)
        <<(!x||!y?'T':'F')<<setw(9)  
        <<(!(x||y)?'T':'F')<<setw(7)  
        <<(!x&&!y?'T':'F')<<endl;  
    }
    cout << endl;
    
    //Exit
    return 0;
}