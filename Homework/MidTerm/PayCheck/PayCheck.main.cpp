/* 
 * File:    PayCheck.main.cpp
 * Problem: 2
 * Purpose: Develop an application using an array of structures created dynamically that
            will determine the gross pay for any number of employees input. i.e. ask up front how
            many employees you are inputting. The company pays ”straight-time” for the first 40
            hours worked, double time for all hours worked in excess of 40 hours but less than 60
            hours, and triple time for any hours worked over 60 hours.
 *          The program should be able to loop and input the employee’s name, hours worked, and
            the rate of pay. Once this has been done then output this information including the
 *          gross pay in the form of a paycheck. The process starts all over again until you input
            an invalid rate of pay or hours worked. This means a negative rate of pay or negative
            number of hours worked is not acceptable.   
 *          Print it out like an actual paycheck with English language representing the check amount.
 * Created: 10/21/21        
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <iomanip>    //Output Manipulation Library
#include <cstdlib>    //C Standard Library
#include <string>     //String Library



using namespace std;  //STD Name-space where Library is compiled

//User Libraries
struct PayChk{
    string name;    //Name of Employee
    int hours;    //Hours worked
    int payR;     //Pay-rate for said employee
};
//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
int NumEmp();                  //Gets the number of Employees from user
PayChk *Data(int);             //Returns a filled struct from user
void TestData(PayChk*, int);   //Print test for data structure
int Pay(PayChk*, int);         //Returns amount for money
void PrntChk(PayChk*, int);    //Print Check 
void EngChk (int);             //Print pay in english

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));  //Random Number Seed
    
    //Declare variables here
    int empNum;     //Number of employees
    PayChk *data;   //Emplpyee Dynamic Struct data
    int pay;
    //Initialize variables here
    empNum = NumEmp();  
    data = new PayChk[empNum];  //Allocates memory for data struct array
    data = Data(empNum);        //Fill and return struct into data
    //TestData(data,empNum);      //TEST
    pay = Pay(data, empNum);    //Returns pay for employee
    PrntChk(data,empNum);       //Prints check With info;
 
    
    
    //Display the results
    delete[] data;

    return 0;
}
int NumEmp(){   //Returns the number if employees from user
    int num;
    
    cout << "Enter the number of employees:";
    cin >> num;
    while ( num < 0){
        cout << "Invalid Input, must be greater than 1." << endl;
        cout << "Enter the number of employees:";
        cin>>num;
    }
    
    return num;
}
PayChk *Data (int empN){    //Returns the data filled out by user
    PayChk *temp;                //Temp data struct
    temp = new PayChk[empN];    //Allocates memory for temp data struct array
    
    for (int i=0; i<empN; i++){ //Loop gets info from user
        cout << "Enter info for employee number " << i+1 << endl;
        cout << "Name:";
        cin.ignore();
        getline(cin, temp[i].name);
        
        cout << "Hours worked:";
        cin>>temp[i].hours;
        while ( temp[i].hours < 0){
            cout << "Invalid Input, must be greater than 0." << endl;
            cout << "Enter the number of employees:";
            cin>>temp[i].hours;
        }
        
        cout << "Employee pay rate:";
        cin>>temp[i].payR;
        while ( temp[i].payR < 0){
            cout << "Invalid Input, must be greater than 0." << endl;
            cout << "Enter the number of employees:";
            cin>>temp[i].payR;
        }
    }

    return temp;
}
void TestData( PayChk *data, int size){
    for (int i=0; i<size; i++){             //Since data is derefenced in the arguments( *data), we do not used ->
        cout << "Enter employee " << i+1 <<"'s info:" << endl;
        cout << "Name:" << data[i].name << endl;
        cout << "Hours:" << data[i].hours << endl;
        cout << "Pay Rate:" << data[i].payR << endl;
        cout << endl;
    }
}

int Pay(PayChk *data, int empN){    //Calculates the pay for Check, and English conversion
                                    //Use sting functions later
    int hours;  //hours             //Since its dereferenced in the argument, we dont use ->
    int payR;   //pay rate
    int pay=0;  //final pay
//    cin >> empN; //TEST
//    empN-=1;
    hours = data[empN].hours;
    payR = data[empN].payR;
//    cout << "hours:" << hours << endl;    //TEST
//    cout << "Pay Rate:" << payR << endl;  //TEST
    
    if (hours<=40){
        pay = hours*payR;
        //cout << pay << endl;  //TEST
    }
    if( hours >40 && hours <=60 ){
        pay+=40*payR;
        //cout << pay << endl;  //TEST
        pay+=(hours-40)*(payR*2);
        //cout << pay << endl;  //TEST
    }
    if( hours >60) {
        pay +=(40*payR);
        //cout << pay << endl;  //TEST
        pay +=(20*(payR*2));
        //cout << pay << endl;  //TEST
        pay +=((hours-60)*(payR*3));
        //cout << pay << endl;  //TEST
    }
    return pay;
}

void PrntChk(PayChk *data, int size){   //Prints check
    int cnvrtN=0;
    cout << endl << "Something-Somewhere Industries" << endl;
    cout << "Hugh Dick Road, 66686, CA, USA" << endl;
    for (int i=0; i<size; i++){
        cout << data[i].name << endl;
        cout << "$" << Pay(data,i) << endl;
        cnvrtN = Pay(data,i);
        EngChk(cnvrtN);
        cout << " DOLLARS" << endl;
    }
}

void EngChk (int pay){
    bool flag=true;   
    if( pay >= 1){
        //Determine 1000's, 100's, 10's, 1's
        char n100000s,n10000s,n1000s,n100s,n10s,n1s; //We dont pay more then 9999 
        //n100000s=pay/100000;        //Shifts 5 places to the left
        //n10000s=pay%100000/10000;   //Remainder of division of 100000 then shift 4 left
        n1000s=pay%10000/1000;      //Remainder of division of 10000 then shift 3 left
        n100s=pay%1000/100;         //Remainder of division of 1000 then shift 2 left
        n10s=pay%100/10;            //Remainder of division of 100 then shift 1 left
        n1s=pay%10;                 //Remainder of division by 10
       
        
        if(n1000s==1)cout<<"One Thousand ";
        if(n1000s==2)cout<<"Two Thousand ";
        if(n1000s==3)cout<<"Three Thousand ";
        if(n1000s==4)cout<<"Four Thousand ";
        if(n1000s==5)cout<<"Five Thousand ";
        if(n1000s==6)cout<<"Six Thousand ";
        if(n1000s==7)cout<<"Seven Thousand ";
        if(n1000s==8)cout<<"Eight Thousand ";
        if(n1000s==9)cout<<"Nine Thousand ";
        
        if(n100s==1)cout<<"One Hundred ";
        if(n100s==2)cout<<"Two Hundred ";
        if(n100s==3)cout<<"Three Hundred ";
        if(n100s==4)cout<<"Four Hundred ";
        if(n100s==5)cout<<"Five Hundred ";
        if(n100s==6)cout<<"Six Hundred ";
        if(n100s==7)cout<<"Seven Hundred ";
        if(n100s==8)cout<<"Eight Hundred ";
        if(n100s==9)cout<<"Nine Hundred ";
        
        if(n10s==1 && n1s%10 == 0)cout<<"Ten ";
        if(n10s==1 && n1s%10 != 0){
            flag=false;
            if(n1s==1)cout<<"Eleven ";
            if(n1s==2)cout<<"Twelve ";
            if(n1s==3)cout<<"Thirteen ";
            if(n1s==4)cout<<"Fourteen";
            if(n1s==5)cout<<"Fifteen";
            if(n1s==6)cout<<"Sixteen";
            if(n1s==7)cout<<"Seventeen";
            if(n1s==8)cout<<"Eighteen";
            if(n1s==9)cout<<"Nineteen";
        }
        
        if (flag==true){
            if(n10s==2)cout<<"Twenty ";
            if(n10s==3)cout<<"Thirty ";
            if(n10s==4)cout<<"Forty ";
            if(n10s==5)cout<<"Fifty ";
            if(n10s==6)cout<<"Sixty ";
            if(n10s==7)cout<<"Seventy ";
            if(n10s==8)cout<<"Eighty ";
            if(n10s==9)cout<<"Ninety ";
        }
        
        if (flag==true){
            if(n1s==1)cout<<"One";
            if(n1s==2)cout<<"Two";
            if(n1s==3)cout<<"Three";
            if(n1s==4)cout<<"Four";
            if(n1s==5)cout<<"Five";
            if(n1s==6)cout<<"Six";
            if(n1s==7)cout<<"Seven";
            if(n1s==8)cout<<"Eight";
            if(n1s==9)cout<<"Nine";
        }
    
    }
}
