/* 
 * File:    Prime_Factors.main.cpp
 * Problem: 7
 * Task:    Factor an input integer into it’s prime numbers. Create a structure to hold
 *          the array of prime numbers. Any number between [265000] will be a valid number to
 *          check for prime factors.
 * Created: 10/20/2021
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <iomanip>    //Output Manipulation Library
#include <cstdlib>    //C Standard Library
#include <string>     //String Library
#include <ctime>      //Time library, for rand
#include <cmath>      //Math library(Think of your own functions for math)
#include <vector>     //Vector library

using namespace std;  //STD Name-space where Library is compiled

//User Libraries
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
int ValidN();       //Input number and number validation
int *FindPF( int, int &);   //Finds all factors, and returns all factors to a pointer array in order
Primes Data( int *, int );  //Creates Dynamic struct 

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));  //Random Number Seed
    
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



    return 0;
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