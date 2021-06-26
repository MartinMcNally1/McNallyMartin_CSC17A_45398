/*   
 * Author: Martin McNally
 * Purpose: Rain or Shine
 * Date: 06/24/2021
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cmath>      //Math Library
#include <iomanip>    //Formating Output
#include <fstream>    //Input File streaming Object

using namespace std;  //Library Scope

//Execution Starts Here
int main(){

    int mnth=3;     //0=June, 1=July, 2=August
    int days=30;    //30 days max
    int numS;       //Number of Sunny days recorded
    int numC;       //Number of Cloudy days recorded
    int numR;       //Number of Rainy days recorded
    int i=0;
    ifstream inputFile;
 
    char Wdata[mnth][days];  //3x30 array to hold characters S, C, R
    
    inputFile.open("RainOrShine.txt");  //Opens RainOrShine.txt file
    
    for (int i2=0; i2<=mnth; i2++){     //Reads data into array
        while ( i <= days && inputFile >> Wdata[i2][i]){
            i++;
        }
    } 
    
    inputFile.close();  //Closes File

    cout << Wdata[0][0] << endl;
    
    return 0;
}
