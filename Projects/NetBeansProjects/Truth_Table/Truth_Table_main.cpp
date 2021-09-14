/* 
 * File: Truth_Table_main.cpp
 * Author: Martin McNally
 * Created on: Netbeans
 * Purpose: Truth table with a while loop for Code-E
 */

//System Libraries Here
#include <iostream> //
#include <iomanip>  //Manipulate cout outputs
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
    //Terminal operators
    //They function like if statements    
        cout<<(x?'T':'F')<<setw(2)  //If x is true output T, else output F        
        <<(y?'T':'F')<<setw(3)      //If y is true output T, else output F
        <<(!x?'T':'F')<<setw(3)     //If !x is true output T, else output F
        <<(!y?'T':'F')<<setw(4)     //If !y is not true output T, else output F
        <<(x&&y?'T':'F')<<setw(5)   //If x AND y are true output T, else output F
        <<(x||y?'T':'F')<<setw(4)   //If x OR y are true output T, else output F
        <<(x^y?'T':'F')<<setw(5)    //If x EOR y are true output T, else output F (EOR => Exclusively Or)
        <<(x^y^x?'T':'F')<<setw(6)  //If x EOR y EOR EOR x are true output T, else output F
        <<(x^y^y?'T':'F')<<setw(8)  //If x EOR y EOR y are true output T, else output F
        <<(!(x&&y)?'T':'F')<<setw(7)//If !(x AND y) are true output T, else output F
        <<(!x||!y?'T':'F')<<setw(9) //If !x OR !y are true output T, else output F
        <<(!(x||y)?'T':'F')<<setw(7)//If !(x OR y) are true output T, else output F
        <<(!x&&!y?'T':'F')<<endl;   //If !x AND !y are true output T, else output F
    }
    cout << endl;
    
    //Exit
    return 0;
}