//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random Function Library
#include <ctime>     //Time Library
using namespace std;

//Global Constants

//Function Prototypes
char rndDgit();           //Randomly generates digit characters
void prpLuhn(char[],int); //Creates char array for Luhn.
int  cnvrt(char);         //Convert 1 digit char to integer
char cnvrt(int);          //Convert 1 digit integer to a char
void output(char[],int);  //Output the sequence as integers
char Luhn(char[],int);    //Calculate for Checking number.

int main() {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Set the Credit Card size
    const int SIZE=12;
    char crdCard[SIZE];
    crdCard[SIZE-1] = '\0';     //'\0' is the null terminator for the char conversion.
    //Prepare for Luhn encoding
    cout<<"A random number generated:"<<endl;
   
    prpLuhn(crdCard,SIZE-2);
    
    //Output the preLuhn credit card
    cout<<crdCard<<endl;
    
    output(crdCard,SIZE-2);
    
    //Now create a function that fills the last digit
    //using the Luhn Algorithm
    crdCard[SIZE-2] = Luhn(crdCard,SIZE-2);   //-2 because you DO NOT want to fill your string yet,
                                              //You need one more digit for the checking number
    cout<<"The random number with Luhn checking number:"<<endl;
    cout<<crdCard<<endl;
    
    //Exit Stage Right
    return 0;
}

char Luhn(char ccc[],int n){
    int TempArray[n];
    char CheckingN = 0;
    for ( int i = 0; i < n ; i++ ){
        TempArray[i]=ccc[i]-'0';    //returns value of 48 in ASCII, converting char to int
        if ( i % 2 ){                   //0 is even, never first, and 1 is odd which would be second. Finds every other number in the array.
        TempArray[i] *= 2;
        TempArray[i] = TempArray[i]/10 + TempArray[i]%10;   //Finds my checking number.
        }
        CheckingN += TempArray[i];  //Assigns my checking number to CheckingN
    }
    
    CheckingN = (CheckingN*9)%10 + '0';     //Convert back to char using ASCII
    
    return CheckingN;
}

void output(char cc[],int n){
    cout<<"The char array output as each integer digit:"<<endl;
    for(int i=0;i<n;i++){
        cout<<cnvrt(cc[i]);
    }
    cout << endl;
}

char  cnvrt(int digit){
    if(digit<0||digit>9){
        exit(0);
    }
    return digit+48;
}

int  cnvrt(char digit){
    if(digit<'0'||digit>'9'){
        exit(0);
    }
    return digit-'0';
}

void prpLuhn(char cc[],int n){
    //Create a random cc in prep for Luhn checksum
    for(int i=0;i<n;i++){
        cc[i]=rndDgit();
    }
    //Put null terminator at the end
    for(int i=n;i<=n+1;i++){       
        cc[i]='\0';     //This will output nothing when displaying number
    }
}

char rndDgit(){
    return rand()%10+48;//Ascii Code for numbers '0'=48 and '9'=57
}