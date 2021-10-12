\
/* 
 * Author: Martin McNally
 * Created: 10/11/2021
 * Purpose: Calculate the average rainfall and temps with enumerated data type
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
struct Weather {
   float total;     // Total rainfall of the Month
   float hTemp;       // High temp of the month. 
   float lTemp;       // Low temp of the month. 
};
enum Month { JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE };

//Function Prototypes
void getData(Weather [], Month);
void Output(Weather [], Month);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    const int MONTHS = 12;      // Number of months.
    Weather Wdata[MONTHS];
    
    Month currnt;                // To denote current month.
  
    getData(Wdata, currnt);      // Retrieve data

    Output(Wdata, currnt);      // Display results.

    return 0;
}

void getData(Weather data[], Month index) {
    for (index = JANUARY; index <= JUNE; index = static_cast<Month>(index + 1)) {
        cout << "Enter the total rainfall for the month:" << endl;
        cin >> data[index].total;
        cout << "Enter the high temp:" << endl;
        cin >> data[index].hTemp;
        cout << "Enter the low temp:" << endl;
        cin >> data[index].lTemp;
    }
}

void Output(Weather data[], Month index) {
    float avgRain = 0.00;      //Average monthly rain 
    float avgTemp = 0.00;      //Average temperature
    float tempH = -100.00;     //High temp 
    float tempL = 140.00;      //Low temp
    
    for (index = JANUARY; index <= JUNE; index = static_cast<Month>(index + 1)) {   //Using the enumerated data type for for loop
        avgRain += data[index].total;
        avgTemp += data[index].hTemp;
        avgTemp += data[index].lTemp;
        if (data[index].hTemp > tempH) 
            tempH = data[index].hTemp;
        if (data[index].lTemp < tempL)
            tempL = data[index].lTemp;
    }
    avgRain = avgRain/(JUNE+1);
    avgTemp = avgTemp/((JUNE+1)*2);
    //cout << fixed << showpoint << setprecision(2);
    cout << "Average monthly rainfall:" << avgRain << endl;
    cout << "High Temp:" << tempH << endl;
    cout << "Low Temp:" << tempL << endl;
    cout << fixed << showpoint << setprecision(1);    
    cout << "Average Temp:" << avgTemp;
}