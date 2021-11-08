/* 
 * File:    CheckingAccount.main.cpp
 * Problem: 1 
 * Task:  
 *           
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <iomanip>    //Output Manipulation Library
#include <cstdlib>    //C Standard Library
#include <cstring>     //String Library

using namespace std;  //STD Name-space where Library is compiled

//User Libraries
struct ChkInfo{
    string numA;     //String Account Number
    string name;     //Name
    string addr;     //Address
    int blnce;       //Balance
    int *chks;       //Checks signed
    int numChk;      //Number of Checks
    int *deposit;    //Deposit
    int numDp;       //Number of deposits
};
//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
void Data(ChkInfo*);        //Fills in data for check;
string AccntN();  //Validates Account number
string RtrnStr();       //Return string
void ChkS(ChkInfo* , int);    //Inputs array of checks
void Deposit(ChkInfo* , int); //Inputs array of deposits
bool NewB(ChkInfo*);     //Return new Balance, and inform if they have overdrawn
//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    bool overD;
    ChkInfo *data;
    Data(data);
    
    //Initialize variables here
    overD=NewB(data);
    //Map inputs to outputs here, i.e. the process
    
    //Display the results
    cout << "Account Number: " << data->numA << endl;
    cout << "Name: " << data->name << endl;
    cout << "Address: " << data->addr << endl;
    
    if ( overD=true){
        cout << "You were charged an overdraw of 25$" << endl;
        cout << "making you balance of " << data->blnce << endl;
        cout << "a total of " << data->blnce - 25 << endl;
    }
    else{
        cout << "Balance: " << data->blnce << endl;
    }
    
    delete[] data->chks;
    delete[] data->deposit; 
    delete data;
    
    return 0;
}
void Data(ChkInfo *temp){
    *temp;
    
    temp->numA=AccntN();                //Get account number and validate
    cout << "Account:" << temp->numA;
    
    cout << "Enter name:";
    cin.ignore();
    getline(cin, temp->name);
//    cout << "Test input name" << endl;
//    cin.clear();
    //cin.ignore();
    //temp->name=RtrnStr();
    
    cout << "Enter Address:";
//    cin.ignore();
    //getline(cin, temp->addr);
//    cout << "Test input addres" << endl;
    //cin.ignore();
    temp->addr=RtrnStr();
    
    
    cout << "Enter Month Balance:";
    cin>>temp->blnce;
    cout << "Test Balance" << endl;
    
    cout << "Check Signed" << endl; 
    int numChk; //For size
    cout << "How many checks would you like to sign:";
    cin>>numChk;
    temp->chks = new int[numChk];
    ChkS(temp,numChk);    //returns array of ints 
    
    cout << "Deposits Made" << endl;
    int numD;
    cout << "How many deposits will you make:";
    cin>>numD;
    temp->deposit = new int[numD];
    Deposit(temp,numD);  //returns array of ints

}

string RtrnStr(){
    string Rtrnstr;
    //cin.ignore();
    getline(cin,Rtrnstr);
    
    return Rtrnstr;
}

string AccntN (){
    bool pass;
    string number;
    
    while(pass==false){
        pass=true;
        //string test;
        cout << "Enter account number:";
        getline(cin,number);
        
        //cout << number << " " << "Length:" << number.length() << endl;
        if( number.length() != 5){
            pass=false;
            cout << "Number digit count failed" << endl;
        }
        
        for (int i=0; i<5 && pass==true; i++){
            if (number[i]<'0' || number[i]>'9'){
                pass=false;
                cout << "Number digit check failed" << endl;
            }
        }
        //test=number;
    }
    cout << "Get Account Info Works" << endl;
    return number;
}

void ChkS(ChkInfo *data, int num){    //Inputs array of checks
    cout << "Test ChkS"<< endl;
    data->chks = new int[num];
    data->numChk =num;
    for (int i=0; i<num; i++){
        cout << "Enter Check " << i <<":";
        cin>>data->chks[i];
    }
}
void Deposit(ChkInfo *data, int num){ //Inputs array of deposits
    cout << "Test Deposit" << endl;
    data->chks = new int[num];
    data->numDp=num;
    
    for (int i=0; i<num; i++){
        cout << "Enter Deposit " << i <<":";
        cin>>data->deposit[i];
    }    
}

bool NewB(ChkInfo *data){     //Return new Balance, and inform if they have overdrawn
    cout << "Test NewB" << endl;
    bool overD=false;   //Sets overdrawn bool to false, true is you have.
        
    for (int i=0; i<data->numChk; i++){ //Subtract checks from balance
        data->blnce-=data->chks[i];
    }
    if (data->blnce<0){  //Checks to see if you've over drawn money
        overD=true;
    }
    
    for( int i=0; i<data->deposit[i]; i++){ //Adds deposits from balance 
        data->blnce+=data->deposit[i];
    }
    return overD;   //return bool
}




