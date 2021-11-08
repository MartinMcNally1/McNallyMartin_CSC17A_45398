/* 
 * File:    Encryption.main.cpp
 * Problem: 4
 * Task:    A company wants to transmit data over the telephone, but they are concerned 
 *          that their phones may be tapped. All of their data is transmitted as four-digit
 *          integers. However, they utilize the digits 0,1,2,3,4,5,6,7 only. They have asked you to
 *          write a program that will encrypt their data so that it may be transmitted more securely.
 *          Your application should read a four-digit integer with the numbers 0 to 7 entered
 *          by the user in an input dialog and encrypt it as follows: Replace each digit by (the
 *          sum of that digit plus 3 modulus 8. Then swap the first digit with the third, and swap
 *          the second digit with the fourth. Then print the encrypted integer. Write a separate
 *          application that inputs an encrypted four-digit integer and decrypts. If you encrypt a
 *          number, you should be able to get the same number decrypted back when the user does
 *          this. 
 *  Note:   Sometimes errors occur and the digits 8, and 9 might appear. Detect this
 *          condition and flag the error. Can’t read in numbers individually. All the digits must be
 *          read with one cin statement. 
 * Created: 10/20/2021
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <iomanip>    //Output Manipulation Library
#include <cstdlib>    //C Standard Library
#include <cstring>    //String Library


using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
char *ValidC();         //Returns and validates code at once
char *Encrypt(char *);  //Encrypt code
char *Decrypt(char *);  //Decrypt code
void Print(char *);      //Print code
//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));  //Random Number Seed
    
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
    return 0;
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
        //cout << strlen(code) << endl;
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