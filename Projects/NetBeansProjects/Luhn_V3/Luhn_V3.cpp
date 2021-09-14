
//System Level Libraries
#include <cstdlib>
#include <iostream>   //I/O Library
#include <cmath>      //Math Library
#include <ctime>      //Time Library
#include <cstring>    //For strlen(crdcard) data function.

using namespace std;  //Library Scope
enum CrdCard {AE, Visa, MC, Dis, All};
void genCC(char[]);             //Generate the credit card
char rndDgit();                 //Randomly generates digit characters
void prpLuhn(char [],int);      //Fills in Digits for Luhn Alg.
char Luhn(char[],int );         //Perform the Luhn Algo.
void flipDig(char[]);           //Selects a random digit, then flips it
void transpose(char[]);         //transpose 2 digits
bool validCC(char[]);           //Check the Accuracy of the card and generate a percentage of how accurate it is.
CrdCard randType();

//Global variable
const int SIZE = 21;

//Execution Starts Here
int main(){
     //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));  //For Random char
    srand (time(NULL));                         //For Random int
    
    int totalcrdcards = 0;  //Number of CrdCards made 
    int maxcards = 10000;
    char CC[SIZE];          //Char string for Credit Cards
    
    cout <<"Validity of transposing 2 random digits." << endl;
    for (int i = 0; i <= maxcards; i++) {
        genCC(CC);
        transpose(CC);
        if (validCC(CC)) 
        {
        totalcrdcards++;
        }
    }
    cout << "Total number of valid cards: " << totalcrdcards << endl;
    cout << "Total number of invalid cards: " << maxcards-totalcrdcards << endl;
    
    totalcrdcards = 0;       //Number of CrdCards made, assigned 0 again to wipe for a fresh run.
    cout << "\nValidity of flipping 2 digits." << endl;
    for (int i = 0; i <= maxcards; i++) {
        genCC(CC);
        flipDig(CC);    
        flipDig(CC);    //Done twice to basically switch two digits
        if (validCC(CC)) 
        {
        totalcrdcards++;
        }
    }
    cout << "Total number of valid cards: " << totalcrdcards << endl;
    cout << "Total number of invalid cards: " << maxcards-totalcrdcards << endl;

    
    //Parameters for Credit Cards:
    //(0)American Express cards begin with 34 or 37, with 16 digits total
    //(1)Visa cards have between 16 digits total
    //(2)MasterCards start with digit 4 and have 16 digits total
    //(3)Discover cards start with 65, 644, 6011, with 16 digits total
    //(4)All: Choose a number between 0 or 3 and make that card    

    return 0;
}
void genCC ( char CC[]){
    CrdCard randCard = randType(); 
    int maxdigits = 0;    //all card sizes start with 0 digits
    
    if (randCard==AE){
        maxdigits=16;   //American Express has 15 digits total
        int r =rand()%2;
        char rdigit;
        prpLuhn(CC, maxdigits-1);
        //Place starting digits after prpLuhn to override elements
        CC[0]=51;    //ASCII number for '3'
        if(r=0)         //If r=0, then the ASCII number is '4'
        rdigit=52;
        else if(r=1)    //If r=1, then the ASCII number is '7'
        rdigit=55;
        CC[1]=rdigit;    //Gives it either a 4 or 7
            }
    
    else if (randCard==Visa){
        maxdigits=16;   //Visa has 13 digits total
        prpLuhn(CC, maxdigits-1);
            }
    
    else if (randCard==MC){
        maxdigits=16;
        prpLuhn(CC, maxdigits-1 );
        //Place starting digits after prpLuhn to override elements
        CC[0]=52;   //ASCII number for '4' in char
            }
    
    else if (randCard==Dis){
        maxdigits=16;   //Discovery cards have 16 digits
        int r = rand()%3;
        char rdigit;
        prpLuhn(CC, maxdigits-1);
        //Place starting digits after prpLuhn to override elements
        if ( r==0 ){
            CC[0]=54;   //ASCII number for '6' in char
            CC[1]=53;   //ASCII number for '5' in char
        }
        else if ( r==1){
            CC[0]=54;   //ASCII number for '6' in char
            CC[1,2]=52; //ASCII number for '4' in char
        }
        else if ( r==2 ){
            CC[0]=54;   //ASCII number for '6' in char
            CC[1]=48;   //ASCII number for '0' in char
            CC[2,3]=49; //ASCII number for '1' in char
        }
            }
    CC[maxdigits-1]= Luhn(CC, maxdigits-1);   //Generates the Checking number and places it on the end
}                                             //The -1 is to avoid counting the null terminator
CrdCard randType(){
    CrdCard ACard;
    int randcrdtype;
    randcrdtype = rand()%4; //create random number, 0-4 to chose type of Credit Card
    switch (randcrdtype)
    {
        case (0):{
            ACard = AE; //American Express Credit Card
            break;
        }
        case (1):{
            ACard = Visa; //Visa Card Credit Card
            break;
        }
        case (2):{
            ACard = MC;  //MasterCard Credit Card
            break;
        }
        case (3):{
            ACard = Dis; //Discovery Credit Card
            break;
        }
        case (4):{
            ACard = All; //Randomly Choose 1 of the 4 credit card Types
            break;
        }
    }
    return ACard;    //Return A type of Card
}

void flipDig(char crdcard[]){   //Randomly chooses and flips that digit
    
    int flipdigit = rand()%strlen(crdcard);   //Create a random element between 0-16
                                              //strlen(crdcard) Identifies the number of elements in the array
     crdcard[flipdigit] = rndDgit();
}

void prpLuhn(char cc[],int n){    //Create a random Credit Card for Luhn Algorithm 
    for(int i=0;i<n;i++){
        cc[i]=rndDgit();
    }
    //Put null terminator at the end
    for(int i=n;i<=n+2;i++){       
        cc[i]='\0';     //This will output nothing when displaying number
    }
}

void transpose ( char crdcard[]){
    
    int flipdigit = rand()%(strlen(crdcard)-1);   //Create a random element between 0-16
    int flipdigit2 =flipdigit+1;                  //strlen(crdcard) Identifies the number of elements in the array
    char temp = crdcard[flipdigit];               //Save flipped digit in a temp char data type
    crdcard[flipdigit]= crdcard[flipdigit2];      //Override digit with with new one
    crdcard[flipdigit2]=crdcard[flipdigit];       //Override the 2nd digit now  
}

char Luhn(char ccc[],int n){
    int TempArray[n];
    char CheckingN = 0;
    for ( int i = 0; i < n ; i++ ){
        TempArray[i]=ccc[i]-'0';    //returns value of 48 in ASCII, converting char to int
        if ( i % 2 ){                   //0 is even, never first, and 1 is odd which would be second. Finds every other number in the array.
        TempArray[i] *= 2;
        TempArray[i] = TempArray[i]/10 + TempArray[i]%10;   //Creates my checking number.
        }
        CheckingN += TempArray[i];  //Assigns my checking number to CheckingN
    }
    CheckingN = (CheckingN*9)%10 + '0';     //Convert back to char using ASCII
    
    return CheckingN;
}

bool validCC(char ccc[]){
    int tempcrdSIZE = strlen(ccc);
    int TempArray[tempcrdSIZE];
    char CheckingN = 0;
    
    for ( int i = 0; i <tempcrdSIZE-1 ; i++ ){
        TempArray[i]=ccc[i]-'0';    //returns value of 48 in ASCII, converting char to int
        if ( i % 2 ){                   //0 is even, never first, and 1 is odd which would be second. Finds every other number in the array.
        TempArray[i] *= 2;
        TempArray[i] = TempArray[i]/10 + TempArray[i]%10;   //Creates my checking number.
        }
        CheckingN += TempArray[i];  //Assigns my checking number to CheckingN
    }
    CheckingN = (CheckingN*9)%10 + '0';     //Convert back to char using ASCII

    
    return ( ccc[tempcrdSIZE-1] == CheckingN)?true:false; 
}   //The -1 is to everything except the null terminator

char rndDgit(){
    return rand()%10+48;//Ascii Code for numbers '0'=48 and '9'=57
}


