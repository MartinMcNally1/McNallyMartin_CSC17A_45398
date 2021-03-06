
//System Level Libraries
#include <cstdlib>
#include <iostream>   //I/O Library
#include <cmath>      //Math Library
#include <ctime>      //Time Library, for random number
#include <cstring>    //For string functions

using namespace std;  //Library Scope
//Function Prototypes
int GenLength();                            //Get The Code length
bool Duplicates();                          //Allow or not Allow Duplicates
string GenCode(int, bool);                  //Generate an char array with letters a,b,c,d,e,f,g,h
void Shuffle(char [], int);                 //Shuffle function for GenCode
string PlayerC(int);                        //Generates an code from player inputs
void FindL(string, string, int, int&, int&);//Find the number of letters both correct used and in the right position

//Main
//The game process will take place here.
int main(){
    //Set Random Number Seed Here
    srand(static_cast<unsigned int>(time(0)));  //For Random char, don't think ill need.
    srand (time(NULL));                         //For Random int
    
    int length=0;
    bool dup;       //If true, allow duplicates, if false no not allow duplicates
    string gameC="";//String array generated for game.
    string plrC=""; //String array generated by player
    
    
    cout << "Welcome to Master Mind\n\n";
    //short description of game
    cout << "You have 10 attempts to guess the code below.\n";
    cout << "Enter letters 'a' through 'h' in the\n";
    cout << "order you believe is correct to win the game.\n";
    cout << "You will only be told how many of the correct letters\n";
    cout << "were used, and how many letters were in the correct order.\n";
    cout << "However, you will not be told which of said letters\n";
    cout << "were in the correct order. Be attentive about your\n";
    cout << "previous attempts to solve the code. Best of luck.\n\n";
    
    //Game Options
    cout << "-------Difficulty-------" << endl;
    cout << "Enter the difficulty options you would\n";
    cout << "like to play with.\n" << endl;
    
            
    //Get code Length
    length = GenLength();   //Works, kinda. I enter a letter an infinite loop occurs.
        
    //Allow or Not Allow Duplicates
    dup = Duplicates();     //works
   
    //Generate Code for Game
    gameC=GenCode(length, dup); //Works, kinda, code length at 8 adds more characters then it should
    
    cout << "\nWhat do you think the code is?\n\n";
    cout << "Your code must " << length << " long, lowercase and\n";
    cout << "letters used must be between a through h, without spacing.\n" << endl;
    
    int index=0;
    bool won = false;
    int cl;  //Number of letters found in both
    int ml; //Number of letters in matching order
    
    do{        
        plrC=PlayerC(length);   //Generate the players code
        FindL(gameC, plrC, length,ml,cl);
        
        if ( ml==length){
            cout << "Congrats, " << plrC << "was correct!!!" << endl;
            cout << "You've cracked the code." << endl;
            won=true;   //Valid, win Game
        }
        else{
            index+=1;
            cout << "Attempt " << index << ": " << plrC << endl;
            cout << "Number of Correct Letters Used: " << cl << endl;
            cout << "Number of Letters in Correct Position: " << ml << endl;
            cout << "Game code: " << gameC << endl;
            cout << endl;
            
        }
        if ( index==10){
            cout << "The correct Code was: " << gameC << endl;
            cout << "Failed to figure out the code, good luck next time.";
            return 0;
        }
        }while (!won);
        
    return 0;
}

//Prototype Functions

//Generate Code for player to guess as well as compare for answers
string GenCode (int size, bool dup ){    //Fill array with 'a' through 'h', can repeat
    static char L[]={'a','b','c','d','e','f','g','h'};
    static int sz=8;
    char l;                        
    int r;                          
    string code="        ";

    if (dup==true){     //If dup is true(1), allow duplicates
        for (int i=0; i<size; i++){ 
        r = rand()%8;   //Generate a random number
        l = 'a' + r;      //Convert to a character from a-h
        code[i]=l;
        }
    return code;
    }
    else if(dup==false){ //If dup is false(0), do not allow duplicates
        Shuffle(L,sz);
        for (int i=0; i<size; i++){ 
            code[i]=L[i];
        }
    return code;
    }         
    return code;
} 

int GenLength(){    //Code Length Variable
    int len = 0;   
    
    cout << "1) Enter the Code Length you would like to play with.\n";
    cout << "   4 is easy, 6 is medium, and 8 is hard.\n";
    cout << "   Enter Code Length: ";
    cin >> len;
        while (len!=4 && len!=6 && len!=8){
            cout << "\nInvalid Number, try again.\n";
            cout << "   You can only enter either 4, 6, or 8.\n";
            cout << "   Enter Code Length: ";
            cin >> len;
            if(cin.fail()){exit(1);} 
        }
    return len;
}   //works

bool Duplicates(){  //Determine whether or not to allow duplicates in players code
    bool duplicate;
    string answer;      
    
    cout << "\n2) Allow Letters to repeat in your code?\n";
    cout << "   Allowing duplicates will make the game harder.\n";
    cout << "   Input yes or no.\n   (y or n is valid as well.)\n";
    cout << "   Enter here: ";
    cin >> answer;
    
    while ( answer!="yes" && answer!= "no" && answer!="y" && answer!="n" ){
        cout << "   Invalid Input, can only accept yes, y, no, or n.\n";
        cout << "   Try again. Enter here: ";
        cin >> answer;
    }
    
    if ( answer == "yes" || answer == "y")
        duplicate = true;
    else if ( answer == "no" || answer == "n")
        duplicate = false;
    
    return duplicate;
}  //works

void Shuffle( char L[], int size){        
   for ( int i=0; i<size ; i ++){
        int r = rand()%size;        //random number from 0 to number to number of letters
        char tempL=L[r];            //safe the variable to swap
        int r2= rand()%size;        //random number from 0 to number to number of letters
        L[r]=L[r2];                 
        L[r2]=tempL;
    }
}   //works

string PlayerC(int size){ //Input players code
    bool checkc = false;
    int len=size;
    string test;
        
    do{
        cout << "Enter Code: ";
        cin >> test;    
        for (int i=0; i<size; i++){
            if ( test.size() == size && test[i] >= 'a' && test[i] <= 'h' ) //Corrects invalid input.
                checkc=true; //Passes
            else{
                checkc=false; //Invalid
            }
        }if (!checkc) cout << "Invalid Code, try again.\n" << "Enter Code: ";
    }while (!checkc);
    return test;
}   //works

string CnvrtChartoStr(char arr[], int size){

    string str = "";
    for (int i = 0; i < size; i++) {
        str = str + arr[i];
    }
    return str;
}

void FindL(string game, string player, int size,int &rr,int &rw){    //Find the number of letters both codes contain
    int num=0;  
    int index=0;
    string temp=player;
    string temp2=game;
    rr=0;   //Correct Letter Used
    rw=0;   //Correct Letter in right position
    
    for ( int i=0; i<size; i++){
        if (temp[i]==temp2[i]){
            rr+=1;
            temp[i]='X';    //Overrides temp string element to not double count letters.
            temp2[i]='Y';
        }
    }

    while (index<size){
        for (int i=0; i<size; i++){
                if (temp[i]==temp2[index]){
                rw+=1;  //Overrides temp string element to not double count letters.
                temp[i]='X';
                temp2[index]='Y';
                }
        }
        index+=1; 
    }
}







