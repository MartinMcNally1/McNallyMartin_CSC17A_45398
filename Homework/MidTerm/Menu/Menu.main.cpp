/* 
 * File:    Menu.main.cpp
 * Problem: 8
 * Tack:    Create a Menu system 
 *           
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <iomanip>    //Output Manipulation Library
#include <cstdlib>    //C Standard Library
#include <cstring>     //String Library

using namespace std;  //STD Name-space where Library is compiled

//User Libraries
struct PayChk{  //Problem 2
    string name;    //Name of Employee
    int hours;    //Hours worked
    int payR;     //Pay-rate for said employee
};

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

struct Prime //Holds the prime, and its power
{
    unsigned short prime;   //The prime number
    unsigned char power;    //The power of for said prime number
};

struct Primes //Holds the number of primes to factor the integer
{
    unsigned char nPrimes;  //Number of Prime Factors
    Prime *prime;           //Dynamic Struct-Struct, size depends on nPrime
};

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
void MidT7();   //Problem number 7
    int ValidN();       //Input number and number validation
    int *FindPF( int, int &);   //Finds all factors, and returns all factors to a pointer array in order
    Primes Data( int *, int );  //Creates Dynamic struct 
void MidT6();   //Problem number 6

void MidT5();   //Problem number 5

void MidT4();   //Problem number 4
    char *ValidC();         //Returns and validates code at once
    char *Encrypt(char *);  //Encrypt code
    char *Decrypt(char *);  //Decrypt code
    void Print(char *);     //Print code

void MidT2();   //Problem number 2
    int NumEmp();                  //Gets the number of Employees from user
    PayChk *Data(int);             //Returns a filled struct from user
    void TestData(PayChk*, int);   //Print test for data structure
    int Pay(PayChk*, int);         //Returns amount for money
    void PrntChk(PayChk*, int);    //Print Check 
    void EngChk (int);             //Print pay in english

void MidT1();   //Problem number 1
    void Data(ChkInfo*);        //Fills in data for check;
    string AccntN();  //Validates Account number
    string RtrnStr();       //Return string
    void ChkS(ChkInfo* , int);    //Inputs array of checks
    void Deposit(ChkInfo* , int); //Inputs array of deposits
    bool NewB(ChkInfo*);     //Return new Balance, and inform if they have overdrawn

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    
    //Declare variables here
    int num;
    bool flag;
    
    //Initialize variables here
    do{
        flag=true;
        cout << "Select a problem to access:" << endl;
        cout << "1-Checking Account" << endl;
        cout << "2-Paycheck" << endl;
        cout << "4-Encryption/Decryption" << endl;
        cout << "5-Factorials" << endl;
        cout << "6-NASA format results" << endl;
        cout << "7-Checking Account" << endl;
        cout << "Enter 1-7, or 0 to quit:";
        cin>>num;
        if (num==0){
            flag=false;
        }
        if (num==1){
            MidT1();
        }
        if (num==2){
            MidT2();
        }
        if (num==4){
            MidT4();
        }
        if (num==5){
            MidT4();
        }
        if (num==6){
            MidT6();
        }
        if (num==7){
            MidT7();
        }
        
    }while(flag==true);
    
    int extra;
    cout << "Sorry to see you go, but" << endl;
    cout << "can I get a few extra points?" << endl;
    cout << "Enter 1 for yes, or 2 for: ";
    cin >>extra;
    while( extra != 1){
        cout << "Invalid input, try again: ";
        cin>>extra;
    }
    cout << endl << "Thank you, take care.";
    return 0;
}

void MidT1(){
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

void MidT2(){
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
 
    delete[] data;
 
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


void MidT4(){
    
    //Declare variables here
    char *code;         //User code
    code=new char[4];   //Allocate memory
    int num;

    
    cout << "Are you encrypting or decrypting?" << endl;
    cout << "Enter 1 for Encrypt\nEnter 2 for Decrypt." << endl;
    cout << "Enter here:";
    cin>>num;
    while ( num < 1 || num > 2 ){
        cout << "Invalid, enter 1 or 2: ";
        cin>>num;
    }
    if (num==1){
        code=ValidC();      //Enter code, and validates code
        code=Encrypt(code); //Encrypt and return code
    }
    if (num==2){
        code=ValidC();      //Enter code, and validates code
        code=Decrypt(code); //Encrypt and return code 
    }
    for (int i; i<4; i++){  //Print code
        cout << code[i] << " ";
    }
    //Print(code);

    delete[] code; 
}

char *ValidC(){
    char *code;
    code = new char[4];
    bool valid;
    do{
        valid=true;
        //cout << "flag:" << valid << endl;
        cout << "Enter code:";
        cin>>code;
        
        //cout << "Code length:";
        cout << strlen(code) << endl;
        //cout << "code:";
        //cout << code << endl;
        //cout << "flag:" << valid << endl;
        
        if ( strlen(code) != 4){ //Checks the length of entered code
            valid=false;
        }
        //cout << "flag after length test:" << valid << endl;
        
        for (int i=0; i<4; i++){    //Checks if each number if 0-7
            if ( code[i]<'0' || code[i]>'7' ){
                valid=false;
            }
        }
        //cout << "flag after digit test:" << valid << endl;
        if(valid==false){   //If it fails both flags, re-enter code;
            cout << "Invalid code" << endl;
            cout << "Code must be 4 digits in length," << endl;
            cout << "and each digit must be 0-7." << endl;
        }
        //cout << "flag after flag test:" <<valid << endl;
        
    }while( valid == false);
    
    return code;
}

char *Encrypt(char *code){  //Encrypt code
    //Change to int array
    int numC[4];
    for (int i=0; i<4; i++){
        numC[i]=code[i]-'0';
    }
    //Test
//    for (int i=0; i<4; i++){
//        cout << numC[i] << " ";
//    }
//    cout << endl;
    //Sum each each digit by 3, then mod 8
    for (int i=0; i<4; i++){
        numC[i] = (numC[i]+3)%8; 
    }
    //test
//    for (int i=0; i<4; i++){
//        cout << numC[i] << " ";
//    }
    //Change back to char
    for (int i=0; i<4; i++){
        code[i]=numC[i]+'0';
    }
    
    //First swap
    char temp1;
    char temp2;
    temp1=code[2];
    code[2]=code[0];
    code[0]=temp1;
    
    //Second swap
    temp2=code[1];
    code[1]=code[3];
    code[3]=temp2;
    
    return code;
}
    
        
char *Decrypt(char *code){  //Decrypt code
    
    //Second swap
    int temp2=code[1];
    code[1]=code[3];
    code[3]=temp2;
    
    //First swap
    char temp1=code[2];
    code[2]=code[0];
    code[0]=temp1;
    
    //Change to int array
    int numC[4];
    for (int i=0; i<4; i++){
        numC[i]=code[i]-'0';
    }
    
    //Sum each each digit by 3, then mod 8
    for (int i=0; i<4; i++){
        numC[i] = (numC[i]+3)%8; 
    }
    
    //Change back to char
    for (int i=0; i<4; i++){
        code[i]=numC[i]+'0';
    }
    
    return code;
}

void Print(char *code){ //Print code
    
    for (int i; i<4; i++){
        cout << code[i] << " ";
    }
}

void MidT5(){   //Problem number 5
    //I replaced each variable with a different data type to test for an overflow overflow
    int num;    //Find factorial of num
    int fnum=1; //Factorial of num
    cin>>num;   //Input Factorial to search for
    for (int i=2; i<=num; ++i){
        fnum *= i;
    }
    cout <<"Factorial of " << num << " is " << fnum << endl;
    
    cout << endl << "The largest n for n! of a unsigned char is 5! = 120" << endl;
    cout << "The largest n for n! of a char is 5! = 120" << endl;
    
    cout << "The largest n for n! of a unsigned short is 8! = 40320" << endl;
    cout << "The largest n for n! of a short is 7! = 5040" << endl;
    
    cout << "The largest n for n! of a unsigned int is 33! = 2147483648" << endl;
    cout << "The largest n for n! of a int is 16! = 2004189184 " << endl;
    
    cout << "The largest n for n! of a unsigned long is 65! = 9223372036854775808" << endl;
    cout << "The largest n for n! of a long is 20! = 2432902008176640000" << endl;
    
    cout << "The largest n for n! of a unsigned long long is 65! = 9223372036854775808" << endl;
    cout << "The largest n for n! of a long long is 20! = 2432902008176640000" << endl;
    
    cout << "The largest n for n! of a float is 34! = 2.95233e+38" << endl;
    
    cout << "The largest n for n! of a double is 170! = 7.25742e+306" << endl;
    
}

void MidT6(){
        //Display the results
    cout << "NASA Format" << endl << endl;
    cout << " a) Convert 49.1875, 3.07421875, 0.2 into binary, octal, and hex," << endl;
    cout << "then representing them in NASA format:" <<  endl << endl;
    
    cout << " 49.1875 base 10 = 110001.0011 base 2 = 61.14 base 8 = 31.3 base 16" << endl;
    cout << " NASA format of 49.1875 base 10: 666666EE " << endl << endl;
    
    cout << " 3.07421875 base 10 = 3.13 base 16 = 11.00010011 base 2 = 3.046 base 8" << endl;
    cout << " NASA format of 3.07421875 base 10: 62600006" << endl << endl;
    
    cout << " 0.2 base 10 = 0.3 (.3 is infinite) base 16 = 0.0011 (.0011 is infinite) base 2 = 0.1463 (.1463 is infinite) base 8" << endl;
    cout << " NASA format of 0.2 base 10: 62600002" << endl << endl;
    
    cout << " b) Convert -49.1875, -3.07421875, -0.2 into binary, octal, and hex:" << endl << endl;
    
    cout << " -49.1875 base 10 = 1110.1101 base 2 = E.D base 16 = 16.61 base 8" << endl;
    
    cout << " -3.07421875 base 10 = 0.11101101 base 2 = 0.73" << endl;
    
    cout << " -0.2 base 10 = 1.1101 (.1101 is infinite) base 2 = 1.6735 (.6735 is infinite) base 8 = 1.D (.D is infinite) base 16" << endl << endl;
    
    cout << " c) Convert the float numbers in NASA format in decimal:" << endl << endl;
    
    cout << " 1) 69999902 = 3.296875" << endl;
    cout << " 2) 69999903 = 6.375" << endl;
    cout << " 3) 966667FF = -1.5875000358" << endl;
}

void MidT7(){
    //Declare variables here
    int sizeF;              //Size of all factor array
    int num;                //Number to factor entered by user
    int *factors=nullptr;   //Pointer array for Prim factors used
    Primes data;
    
    //Initialize variables here
    cout << "Test" << endl;
    num=ValidN();           //Inputs number, and validates
    cout << "Test" << endl;
    factors = FindPF(num,sizeF);  //Stores all prime factors used 
    data = Data(factors,sizeF);   //Stores Prime Factor data into struct variable data  

   
    
    //Map inputs to outputs here, i.e. the process
    
    //Display the results
    

    //Delete Allocated Memory
    delete[] factors;   //Deletes Factor pointer array

    
}
int ValidN(){    //Input validation, num must be 0-265000
    int num;    //Number to validate
    
    cout << "Enter a number between 0 and 265000.\nEnter here:";
    cin>>num;
    
    while ( num > 265000 || num < 0){
        cout << "Invalid Number.\nNumber Must be between 0 and 265000.\nEnter again:";
        cin>> num;
    }
    return num;
}
int *FindPF( int num, int &size){
    cout << "Test" << endl;
    int prime=2;    //Starting Prime number
    int SIZE=20;    //NEED TO HAVE THIS BE DYNAMIC
    int temp[SIZE]; //Save all prime numbers used to factor
    int i=0;            //Index for temp array, starts at 0
    
    while ( prime<=num){    //Runs until number inputted equals prime factor 
        while( num%prime == 0 && num%1 == 0){ //Finds prime number
            num = num/prime;    
            temp[i] = prime;    //Stores prime factor used into array
            i++;                //Increments index for array
        }   
        prime++;                //Increments Prime variable
    }

    int *tempF = new int[i]; //Dynamic create a new to fit exact amount of prime numbers used
    
    for (int ii=0; ii<i; ii++){  //Stores prime numbers used into new array
        tempF[ii] = temp[ii];
    }

    size=i; //Returns the size of array
    return tempF; //Return it back to a pointer array
    
    //Deletes allocated memory
    for (int i=0; i<size; i++){
        //delete tempF[i];
    }
    delete[] tempF; //Deletes allocated memory
}

Primes Data( int *ptr, int size){   //Fills in data from struct for 
    
    Primes temp;        //Temp struct to fill
    int numPF=0;        //Number of Prime factors, need to change this into a unsigned char
    unsigned short pf;      //Prime factor
    unsigned char power;    //Power if prime factor
    
    //Checks if they were called through properly
    cout << "List of prime factors used in: ";
    for (int a=0; a<size; a++){   //Double checks my ptr array, dont need
        cout << ptr[a] << " ";
    }
    cout << endl;
    //Calculate the number of prime factors in array (total prime factors used for Data.nPrimes)
    for (int i=0; i<size; i++){ //Works
        for( int ii=0; ii<size; ii++){
            if ( ptr[i] == ptr[ii] ){
                numPF++;    //Increments the number of times number at ptr[i] in its own array
                i=ii;       //Returns a new starting index for search
            }
        }
    }
    temp.nPrimes=numPF;
                                            //Add 48 when outputting so it returns a char value of '0' to '9'(Remember: Cannot have any more matches then 9 if in ASCII format.)
//    cout << numPF << endl;                //Checks to see if i return the correct char number.
//    cout << "Number of factors detected = " << (temp.nPrimes+0);               //Could trick the char value to not print in ASCII format
//    cout << " held in temp.nPrimes" << endl;    //Adding 0 to the char would print its number value, not ASCII format
    
    //Find number of Prime Factors, not the amount of factors used
    bool found=false;    //If factor is already found, skip to next
    bool repeat=false;   //If repeating factor is found, add 1 to power
    int primeN[size];
    int primeP[size];
    
//    for (int i=0; i<size; i++){
//        found=false;
//        for(int ii=0; ii<0; ii++){
//            
//            if (found==false){
//                if (ptr[i]=ptr[ii]){
//                    primeN[i]=ptr[i];
//                    found=true;
//                }
//            }
//            while(ptr[i]=ptr[ii]){
//                primeP[i]+=1;
//            }
//                
//
//        }
//    }
//    
       for (int i=0; i<size; i++){
        
           for(int ii=0; ii<size || found==false || repeat==false ; ii++){
            
                if (ptr[i]==ptr[ii]){
                    primeN[i]=ptr[i];
                    found=true;
                }
                while(ptr[i]==ptr[ii]){
                    primeP[i]++;
                    ii++;
                    repeat=true;
                    }
                
            }
                

        }
    
    for ( int i=0; i<size; i++){
        cout << primeN[i] << "^" << primeP[i] << endl;
    }
    
//    int numF;
//    bool flag=true;
//    int tempchk[size];
//    
//    
//    for(int i=0; i<size; i++){ 
//        if (flag == true){
//            for (int ii=0; ii<size; ii++){
//                if (ptr[i]==ptr[ii]){
//                    numF++;
//                    tempchk[i]++;
//                }
//                else{
//                flag = false;
//                }
//            }
//        }
//    }
//    cout << numF << endl;
    //test
//    for (int i=0; i<size; i++){
//        cout << "Power:" << temp.prime[i].power << endl;
//    }
    //Allocate memory for temp->prime
    //Static struct varialbe to a dynamic member array
    //temp.prime = new Prime [temp.nPrimes+0];     //Static struct 'temp' points to dynamic struct 'Prime prime' to access static members 'prime' and 'power'
    
    
    //Find each prime factor and how many times its used
    //'temp->prime.prime' is an unsigned short
    //'temp->prime.power' is an unsigned char  
//    for (int a=0; a<(temp.nPrimes+0); a++){ //Loop goes through the dynamic struct sruct 'temp->prime'
//        for (int i=0; i<size; i++){
//            for( int ii=0; ii<size; ii++){
//                if ( ptr[i] == ptr[ii] ){
//                    temp.prime[a].prime = ptr[i]; //Assigns the factor used
//                    temp.prime[a].power++;        //Increments how many times that factor was used.
//                                                   //REMEMBER, you need to turn this to the correct ACSII format(add 48 when outputing)
//                    i=ii;                          //Returns a new starting index for search
//                }
//            }
//        }
//    }
//    int index=0;
//    int freqP=0;
//    bool flag=true;
//    while( index < (temp.nPrimes+0)){
//        for (int i=0; i<(temp.nPrimes+0); i++){
//            for (int ii=i+1; ii<(temp.nPrimes+0); ii++){
//                if ( ptr[i]==ptr[ii]){
//                    flag=false;
//                }
//            }
//            if (flag==true){
//                temp.prime[index].prime = ptr[i];
//                        //i=ii;
//            }
//            flag=true;    
//        }
//        
//        
//        temp.prime[index].power = freqP;
//        freqP=0;
//        flag=true;
//        index++;
//    }
    
    
//    for (int i=0; i<(temp.nPrimes+0); i++){
//        cout << "temp.prime[" << i << "].prime = " << temp.prime[i].prime << " ^ (temp.prime[" << i << "].power+0)=" << (temp.prime[i].power+0) << endl;
//    }
    return temp;
    
    delete[] temp.prime;
}
