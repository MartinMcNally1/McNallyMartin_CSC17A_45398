/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Nacho
 *
 * Created on March 19, 2021, 2:12 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

// Global constants
enum CrdCard{AMERICAN_EXPRESS, VISA, MASTER_CARD, DISCOVER, ALL};
const int SIZE = 21;
//Function Prototypes
CrdCard randType();
void genCC(CrdCard card, char* cardIn);
void fpDigit(char[]);  // fpDigit - flip digit
void prpLuhn(char[], int); //Prepares the Luhn Sequence
char Luhn(char cc[], int n);
bool isValid(char cc[]);

/*
 * 
 */
int main(int argc, char** argv) {

    srand(static_cast<unsigned int>(time(0)));
    
    int count1 = 0;     // determines how many times a debit card is true
    int iterate = 10000;
    char rndDbt[SIZE];              // rndDbt - random debit 
    CrdCard dbtType = randType();   // Can hold, VISA, Master, Discover, and American Express
    for (int x = 0; x <= iterate; ++x)
    {
        // dbtType - debit type
        
        genCC(dbtType, rndDbt);
        //cout << "Debit: " << rndDbt << "\n";
        //cout << (tempVar ? "Is valid" : "Not valid") << "\n";
        if (isValid(rndDbt))
        {
            ++count1;
        }
    }
    cout << "No. of valid cards: " << count1 << "\n"
         << "No. of invalid cards: " << (iterate - count1) << "\n";

    return 0;
}

CrdCard randType()
{
    CrdCard temp;

    int value = rand() % 5;
    switch (value)
    {
    case(0):
        {
            temp = AMERICAN_EXPRESS;
            break;
        }
    case(1):
        {
            temp = VISA;
            break;
        }
    case(2):
        {
            temp = MASTER_CARD;
            break;
        }
    case(3):
        {
            temp = DISCOVER;
            break;
        }
    case(4):
        {
            temp = ALL;
            break;
        }
    default:
        {
        temp = ALL;
        break;
        }
    }
    return temp;
}

void genCC(CrdCard card, char* cardIn)
{
    //it will keep total number of digit in card based on their type
    int totalDigit = 0;
    //set first digit based on type
    if (card == VISA) 
    {
        cardIn[0] = '4';
        totalDigit = 16;
    }
    else if (card == MASTER_CARD) 
    {
        cardIn[0] = '5';
        totalDigit = 16;
    }
    else if (card == DISCOVER) 
    {
        cardIn[0] = '6';
        totalDigit = 16;
    }
    else if (card == AMERICAN_EXPRESS) 
    {
        cardIn[0] = '3';
        totalDigit = 15;
    }

    cardIn[totalDigit] = '\0';
    prpLuhn(cardIn, totalDigit);
    cardIn[totalDigit - 1] = Luhn(cardIn, totalDigit-1);
    fpDigit(cardIn);

}

void prpLuhn(char cc[], int n)
{
    // create a random cc in prep for Luhn checksum 
    for (int i = 1; i < n; i++)
    {
        cc[i] = rand() % 10 + 48;
    }
    int difSize = SIZE - n;  
}

//  Step 1: Double every other index 
//  Step 2: After you double, if it's value > 9, strip it 
    // Ex 18 = 1 + 8 = 9
//  Step 3: Sum it 
//  Step 4: Implement this equation
// Equation: sum * 9 mod 10;

char Luhn(char cc[], int n)
{
    int tempArray[SIZE];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        tempArray[i] = cc[i] - '0'; // convert to int 
        if (i % 2)
        {
            tempArray[i] *= 2;
            tempArray[i] = (tempArray[i] % 10) + (tempArray[i] / 10);
        }// 18 -> 1 + 8 
        sum += tempArray[i];
    }
    sum = ((sum * 9) % 10) + '0';
    return sum;
}

void fpDigit(char crd[])
{
    // Determine size of card 
    int length = strlen(crd) - 1;
    int flip = rand() % length;
    crd[flip] = rand() % 10 + '0';
}

bool isValid(char cc[])
{
    int tempArray[SIZE];
    int crdSize = strlen(cc);
    int sum = 0;
    //              i < crdSize - 1
    for (int i = 0; i<crdSize-1; i++)
    {
        tempArray[i] = cc[i] - '0'; // convert to int 
        if (i % 2)
        {
            tempArray[i] *= 2;
            tempArray[i] = (tempArray[i] % 10) + (tempArray[i] / 10);
        }// 18 -> 1 + 8 
        sum += tempArray[i];
    }

    sum = ((sum * 9) % 10) + '0';
    return (cc[crdSize - 1] == sum) ? true : false; 
}
