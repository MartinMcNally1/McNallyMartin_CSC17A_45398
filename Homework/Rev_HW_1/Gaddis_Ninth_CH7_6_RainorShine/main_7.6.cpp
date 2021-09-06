/*   
 * Author: Martin McNally
 * Purpose: Rain or Shine, create a report for how may Sunny, Cloudy, and Rainy days there were during a 3 month period
 * Date: 09/02/2021
 * Code: Successful use of inputFile to read in data from file
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <iomanip>    //Formating Output
#include <fstream>    //Input File streaming Object

using namespace std;  //Library Scope

//Prototype Functions
int ttlWdata(char[][30], int, char); //Counts the number of S, C, R from all 3 months.
//int MnthWdata(char[][], int, int );//Counts the number of S, C, R days for each month.
void MstRain(int, int, int);  //Find the month with the most amount of rainy days.
//Execution Starts Here
int main(){

    const int mnth=3;       //0=June, 1=July, 2=August
    const int days=30;      //30 days max
    char Wdata[mnth][days]; //3x30 array to hold characters S, C, R
    int JUL, JUN, AUG, JUNs, JUNc, JUNr, JULs, JULc, JULr, AUGs, AUGc, AUGr;   //Number of Sunny days, Cloudy days, Rainy Days 
    char S, C, R;           //S=sunny, C=cloudy, R=rainy, W=weather
    ifstream inputFile;     //File Operations

    //Read in data from file into my char array
    inputFile.open("RainOrShine.txt");  //Opens RainOrShine.txt file

    for (int ii=0 ;ii<mnth;ii++){   //For Loop that reads data into 3x30 char array
        for (int i=0 ;i<days; i++){
            inputFile >> Wdata[ii][i];
        }
    }   //Works great
    
    inputFile.close();  //Closes File
    //Assigns number to int variable for For Loop
    JUN=0;  
    JUL=1;
    AUG=2;
    JUNs, JUNc, JUNr, JULs, JULc, JULr, AUGs, AUGc, AUGr=0; //Initialize Data to 0
    
    //char Weather types
    S='S';
    C='C';
    R='R';
    
    //Gets the individual number days/weather for each month
    JUNs=ttlWdata(Wdata, JUN, S);   //Total Sunny days in June
    JUNc=ttlWdata(Wdata, JUN, C);   //Total Cloudy days in June
    JUNr=ttlWdata(Wdata, JUN, R);   //Total Rainy days in June
    JULs=ttlWdata(Wdata, JUL, S);   //Total Sunny days in July
    JULc=ttlWdata(Wdata, JUL, C);   //Total Cloudy days in July
    JULr=ttlWdata(Wdata, JUL, R);   //Total Rainy days in July
    AUGs=ttlWdata(Wdata, AUG, S);   //Total Sunny days in August
    AUGc=ttlWdata(Wdata, AUG, C);   //Total Cloudy days in August
    AUGr=ttlWdata(Wdata, AUG, R);   //Total Rainy days in August
    
    //Output Results from report RainOrShine.txt file
    cout << "Month of June" << endl;
    cout << "Sunny Days: " << JUNs << endl;
    cout << "Cloudy Days: " << JUNc << endl;
    cout << "Rainy Days: " << JUNr << endl << endl;
    cout << "Month of July" << endl;
    cout << "Sunny Days: " << JULs << endl;
    cout << "Cloudy Days: " << JULc << endl;
    cout << "Rainy Days: " << JULr << endl << endl;
    cout << "Month of August" << endl;
    cout << "Sunny Days: " << AUGs << endl;
    cout << "Cloudy Days: " << AUGc << endl;
    cout << "Rainy Days: " << AUGr << endl << endl;  
    cout << "Total 3 Month Period" << endl;
    cout << "Sunny Days: " << JUNs+JULs+AUGs << endl;
    cout << "Cloudy Days: " << JUNc+JULc+AUGc << endl;
    cout << "Rainy Days: " << JUNr+JULr+AUGr << endl << endl;
    cout << "The month with the most amount of Rainy days was ";
    MstRain(JUNr, JULr, AUGr);
    
    
    return 0;
}
//Adds the number of chars a char appears in an char array
 int ttlWdata( char data[][30], int month, char W){
    int count=0; 
    for (int i=0; i<30; i++){
        if (data[month][i]==W){
            count++;
        }
    }
    return count;
}
 //Simple, and fails if 2 or more months have the same amount of days.
 //Compares numbers to find greatest number.
 void MstRain( int jun, int jul, int aug){
     if (jun>jul && jun>aug){
         cout << "June";
     }
     else if (jul>jun && jul>aug){
         cout << "July";
     }
     else if (aug>jun && aug>jun){
         cout << "August";
     }
 }
