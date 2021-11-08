/* 
 *File:     Prj.V1.main.cpp
 *Purpose:  Create a black-jack game using structures.
 *          V1 holds the basics of the game. Player inputs how much 
 *          money he/she has in the bank. Then he/she inputs the
 *          starting bet. First round of cards, faced up are dealt. 
 *          Then the player gets another face card, the the dealer gets 
 *          one faced down.
 *Rules:    - Don't go over 21, if you do you bust(includes dealer)
 *          - Dealer gets on face up card, then one face down card.
 *          All other players get face up cards
 *          - Player should have the option, when available, to 
 *          Double-Down or Split Pairs (maybe insurance if possible)
 *          - When given an ace, player must chose whether to value
 *          it as 1 or 11(automatically value it 1 if 11 busts)
 *          - Betting starts once before cards are given out, then 
 *          continues after the first 2 cards are given. The typical 
 *          rounds of betting continue.
 * 
 *Version 1 is still missing
 *  -   ACE number check, whether to apply 11 or 1 to player hand and hand value
 *  -   Detection and option, for player, to Double Down
 *  -   Detection and option, for player, to Split Pairs
 *  -   Player Balance check
 *  -   Project one Requirements, check list
 */         

//System Libraries
#include <iostream>   //Input/Output Library
#include <iomanip>    //Output Manipulation Library
#include <cstdlib>    //C Standard Library
#include <cstring>    //String Library
#include <ctime>      //Time library, for rand() function
#include <cmath>      //Math library(Think of your own functions for math)
#include <vector>     //Vector library

using namespace std;  //STD Name-space where Library is compiled

//User Libraries
struct Info         //Struct Info holds player info
{    
    string hand="";    //Hand accumulated during game, resets each new game
    bool ace=false;    //Notes whether you have an ace in your hand, changes stuff for hand value
    int handV;         //Value of the cards combined, resets each new game
    int balance=0;     //Balance of player, if player reaches 0, he has bust and is ejected
};
//Global Constants not Variables
const char card[]={'2','3','4','5','6','7','8','9','1','J','Q','K', 'A'};   //These are all the cards being given out, ACE if only valued at 1 for now
const int cardV[]={ 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10, 10, 10, 10, 11 };     //Index numbers for each card, will be used for random
enum card{ TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };  //Have to use enum data types some how
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
void GetBank(Info&);  //Gets the amount the player wants to play with
    //Player Fucntions
//void Player(Info);    //Player loop on how he/she wants to play
void plrHit(Info&);   //Adds a random card to hand, and adds value of said card to handV
bool Bust(Info);      //Check players hand for 21
bool Nat21(Info);     //Check players hand for a bust

    //Dealer fucntions
void dlrHit(string&, int&); //Adds another card to dealer hand, handV
bool Nat21(int);      //Check dealers hand for a bust(over 21)
bool Bust(int);       //Check dealers hand for 21

int RandNum();        //Returns a random number for card selection, between 0-13 (When including the ACE, 0-13)

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));  //Random Number Seed
    
    //Declare variables here
    Info player;    //Struct variable to hod info
    int plrBet;     //How much the player wants to bet
    string houseH;  //Holds the hand of the dealer
    int houseV;     //Holds the hand value of the leader, same rules apply
    bool plrH;      //If flag is true, player hits another card
    bool bust;      //If flag is true, player or dealer has bust(over 21)
    bool nat21;     //If flag is true, player got a natural 21
    bool game;      //If the flag is true, betting part is over
    int HorS;       //Stay is 1 and Hit is 2 for option select

    bool strtrnd;    //Player must get two cards to start, helps counter
    
    
    //Initialize variables here
    GetBank(player);    //Get the total bank of player.
    //plrBet=0;
    
    //Map inputs to outputs here, i.e. the process
    do{
        //Reset flag values
        game=false; //Runs for whole game
        bust=false;
        nat21=false;
        //Reset hand and hand value for player and dealer for loop
        player.hand="";
        player.handV=0;
        plrBet=0;
        strtrnd=true;   //First round of betting flag
        houseH="";      //Reset House hand
        houseV=0;       //Reset House hand value.
        //Check Balance for betting
        
        //Initial bet from player
        cout << "Starting bet: $";
        cin>>plrBet;
        while (plrBet>player.balance || plrBet<0){
            cout << "Invalid betting about, try again" << endl;
            cout << "Starting bet: $";
            cin>>plrBet;
            cout << endl;
        }
        
        //Begin player-loop
        do{
            plrH=false; //Resets for player round
            //nat21=false;
            //bust=false;
            //Hit
            plrHit(player); 
                //Take another Hit for the first round of betting
                if (strtrnd==true){
                dlrHit(houseH,houseV);  //1st dealer card, will show
                dlrHit(houseH,houseV);  //2nd dealer card, wont show
                plrHit(player); 
                strtrnd=false;
                }
            
            //cout << "Hand: " << player.hand << " with a value at " << player.handV << endl;
            //Check for natural 21 for player and Bust
            nat21=Nat21(player); //Check if the player got a natural 21
            bust=Bust(player);  //Check if the player has bust

            //Check for 21 or Bust (later check for the option of splitting pairs and the option for doubling)
            if(nat21==true){    //Check if player hand is 21
                //cout << "Player wins with 21" << endl;
                plrH=true;
            }
            else if(bust==true){ //Check if player bust
                //cout << "Player busts and loses with " << player.hand << " with a value of " << player.handV << endl;
                plrH=true;
            }else{
                        //Stay or Hit?
                //If Stay, exit loop, else hit again
                cout << endl << "Dealers first card is " << houseH[0] << "(and the hidden card is " << houseH[1] << ")" << endl; 
                cout << "Players Hand: " << player.hand << "(value = " << player.handV << ")" << endl;
                if ( plrH==false){
                    cout << "Enter 1 to Stay, or 2 to Hit again: "<< endl;
                    cin>>HorS; 
                    while(HorS>2 || HorS<1){
                        cout << "Invalid Input, try again" << endl;
                        cout << "Enter 1 to Stay, or 2 to Hit again: "<< endl;
                        cin>>HorS;
                        cout << endl;
                    }
                    if (HorS == 1){
                        plrH=true;
                    }else{
                        plrH=false;
                    }
                }
            }
        }while(plrH==false);
        
        if (nat21==true){
            cout << "Player wins $" << plrBet << " with a natural 21 hand of " << player.hand << endl;
            player.balance+=plrBet;
        }
        else if (bust==true){
            cout << "Bust, player losses $" << plrBet << " with hand " << houseH << endl;
            player.balance-=plrBet;
        }else{
        //Dealer loop if a natural 21 or bust isn't found
            //Hit until hand value it 17 or less
            while ( houseV < 17){   //If cards value at greater or equal to 17, stay, else loop back
                dlrHit(houseH,houseV);
            }
        //Print house hand, compare cards, find winner. Add or Take from balance
            cout << endl << "Dealers hand: " << houseH << "(" << houseV << ")" << endl;
            if (houseV==player.handV){
                cout << "House and player tie, no one wins" << endl;
            }
            if (player.handV>houseV){
                cout <<"Players hand of" << player.hand << "(" << player.handV << ")" << " beats dealers hand of " << houseH << "("<<houseV<<")"<<endl;
                cout << "Player wins $" << plrBet << endl;
                player.balance+=plrBet;
                //break;
            }
            if (houseV>21){
                cout << "Dealer bust with " << houseH << "(" << houseV << ")" << endl;
                cout << "Player wins $" << plrBet << endl;
                player.balance+=plrBet;
            }
            if (houseV>player.handV){
                cout << "Dealers hand of " << houseH << "(" << houseV << ")" << " beats player hand of " << player.hand << "("<< player.handV <<")"<<endl;
                cout << "Player loses $" << plrBet << endl;
                player.balance+=plrBet;
                // break;
            }
        }
     
        //Check if player money to bet(must be greater than 0)
        //Cash out or bet again?
        if (player.balance>0){
            cout << endl << "Player balance: $" << player.balance << endl;
            cout << "Place another bet or cash out?" << endl;
            cout << "Enter 1 to bet or 2 to cash out:";
            cin>>HorS;
            if(HorS==1){
                game=false;
            }
            else{
                game=true;
            }
        }else{
            cout << "Player balance is 0, come back later" << endl;
        }
        
    }while(game==false);
    
    //Display the results
        //Print cash out money,
    cout << "You cashed out with " << player.balance << " dollars." << endl;

    return 0;
}

void GetBank(Info &user){   //Gets the balance of user for betting 
    //Passing user data in by reference using '&' sign
    //CREATE A VALIDATION LOOP, NO NUMBER UNDER 0 OR GREATER THAN 10000
    cout << "Enter the your starting balance before betting: $";
    cin>>user.balance;
 }

bool Nat21(Info player){
    bool temp;
    if (player.handV==21){
        temp=true;
    }else{
        temp=false;
    }
    return temp;
}
bool Bust(Info player){
    bool temp;
    if (player.handV>21){
        temp=true;
    }else{
        temp=false;
    }
    return temp;
}

int RandNum(){
    return rand()%13;   //Returns a number between 0-13
}

void plrHit(Info &user){   //Adds another card to the user hand, and adds value to handV to check is bust
    int num=RandNum();
    //cout << card[num] << " " << cardV[num] << endl;
    if (num==9){
        user.hand+=card[9];
        user.hand+='0';
        user.handV+=cardV[9];        
    }else{
        user.hand+=card[num];
        user.handV+=cardV[num];
    }
}
void dlrHit(string &hH, int &hV){   //adds a card to house hand(hH) and adds up hand value(hV)
    int num=RandNum();
    hH+=card[num];
    hV+=cardV[num];
}