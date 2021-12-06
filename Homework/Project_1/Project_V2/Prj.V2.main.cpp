/* 
 *File:     Prj.V1.main.cpp
 *Purpose:  Create a black-jack game using structures.
 *          V1 holds the basics of the game. Player inputs how much 
 *          money he/she has in the bank. Then he/she inputs the
 *          starting bet. First round of cards, faced up are dealt. 
 *          Then the player gets another face card, the the dealer gets 
 *          one faced down.
 *Rules:    - Don't go over 21, if you do you bust(includes dealer)
 *          - Dealer gets one face up card, then one face down card.
 *          All other players get face up cards
 *          - Player should have the option, when available, to 
 *          Double-Down or Split Pairs (maybe insurance if possible)
 *          - When given an ace, player must chose whether to value
 *          it as 1 or 11(automatically value it 1 if 11 busts)
 *          - Betting starts once before cards are given out, then 
 *          continues after the first 2 cards are given. The typical 
 *          rounds of betting continue.
 * 
 *Version 2
 *  -   Divided functions into prototypes (Clean up)
 *  -   Combined variables into struct for simplicity
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
struct Plr{ //Include this in next version
    string id;
    int balance;
};
struct Info         //Struct Info holds player info
{    
    Plr player;     //Holds player info, Balance and ID
    string hand;    //Hand accumulated during game, resets each new game
    int handV;      //Value of the cards combined, resets each new game
    bool ace;       //Notes whether you have an ace in your hand, changes stuff for hand value
    int plrBet;     //How much the player wants to bet each round
    bool bust;      //If flag is true, player or dealer has bust(over 21)
    bool nat21;     //If flag is true, player got a natural 21
    
};
struct House{   //Struct Info for dealer
    string hand;
    int handV;
    bool ace;
};

//Global Constants not Variables
const char card[]={'2','3','4','5','6','7','8','9','1','J','Q','K', 'A'};   //These are all the cards being given out, ACE if only valued at 1 for now
const int cardV[]={ 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10, 10, 10, 10, 11 };     //Index numbers for each card, will be used for random
enum card{ TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };  //Have to use enum data types some how

//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
    //Player Fucntions
void GetBank(Info&);    //Gets the amount the player wants to play with
void plrHit(Info&);     //Adds a random card to hand, and adds value of said card to handV
bool Bust(Info);        //Check players hand for 21           //Can include all flags in struct for simplicity
bool Nat21(Info);       //Check players hand for a bust
void AceChk(Info&);     //If the player bust but has a 21 card, minus 10
bool BlnChk(Info);      //Checks Balance of player, returns flag if player can continue
void GetBet(Info&);     //Gets the betting amount from player 

    //Dealer functions
void dlrHit(House&);    //Adds another card to dealer hand, handV
void AceChk(House&);    //If the player bust but has a 21 card, minus 10
bool Nat21(int);        //Check dealers hand for a bust(over 21)
bool Bust(int);         //Check dealers hand for 21
void reset(House&);     //Resets hands for next round of betting

void Reset(Info&, House&);     //Resets flags and clear hand for next round of betting for both dealer and player
int RandNum();                 //Returns a random number for card selection, between 0-13 (When including the ACE, 0-13)

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));  //Random Number Seed
    
    //Declare variables here
    Info player;    //Struct variable of Player
    House dealer;   //Struct variable for Dealer
    bool plrH;      //If flag is true, player hits another card
    bool game;      //If the flag is true, betting part is over
    int HorS;       //Stay is 1 and Hit is 2 for option select

    bool strtrnd;    //Player must get two cards to start, helps counter
    
    
    //Initialize variables here     //This is where we grab, or if not ID not found create the user info for playing and store balance
    GetBank(player);    //Get the total bank of player.
    
    //Map inputs to outputs here, i.e. the process
    do{
        //Reset flag values
        game=false;     //Runs for whole game
        strtrnd=true;   //First round of betting flag
        
        //Reset hand and hand value for player and dealer for loop, for each new round of betting
        Reset(player,dealer);

        //Initial bet from player
        GetBet(player); //Gets bet from player, and validates it

        //Begin player-loop
        do{
            plrH=false; //Resets for player round

            plrHit(player); //First card dealt to player
                //Take another Hit for the first round of betting
                if (strtrnd==true){
                dlrHit(dealer);  //1st dealer card, will show
                dlrHit(dealer);  //2nd dealer card, wont show
                plrHit(player);  //2nd card dealt to player
                strtrnd=false;
                }

            //These checks must always be passed through
            AceChk(player);                //Checks if the hand has bust and has an ace, and corrects it
            player.nat21=Nat21(player);    //Check if the player got a natural 21
            player.bust=Bust(player);      //Check if the player has bust
            
            
            //Check for 21 or Bust (later check for the option of splitting pairs and the option for doubling)
            if(player.nat21==true){    //Check if player hand is 21
                //cout << "Player wins with 21" << endl;
                plrH=true;
            }
            else if(player.bust==true){ //Check if player bust
                //cout << "Player busts and loses with " << player.hand << " with a value of " << player.handV << endl;
                plrH=true;
            }else{
                        //Stay or Hit?
                //If Stay, exit loop, else hit again
                cout << endl << "Dealers first card is " << dealer.hand[0] << "(Hidden Value of full hand " << dealer.hand << " = " << dealer.handV << ")" << endl; 
                cout << "Players Hand: " << player.hand << "(value = " << player.handV << ")" << endl;
                if ( plrH==false){
                    cout << "Enter 1 to Stay, or 2 to Hit again: "<< endl;
                    cin>>HorS; 
                    while(HorS>2 || HorS<1){
                        cout << "Invalid Input, try again" << endl;
                        cout << "Enter 1 to Stay, or 2 to Hit again: ";
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
        
        //These 2 if statements only activate if player busts or has a natural 21 due to flags
        if (player.nat21==true){   //Check for Natural 21 in player hand from flag
            cout << "Player wins $" << player.plrBet << " with a natural 21 hand of " << player.hand << "(" << player.handV << ")" << endl;
            player.player.balance+=player.plrBet;
        }
        else if (player.bust==true){   //Check for player bust from flag
            cout << "Bust, player losses $" << player.plrBet << " with a hand of " << player.hand << "(" << player.handV << ")" << endl;
            player.player.balance-=player.plrBet;
        }else{
            //Dealer loop if a natural 21 or bust isn't found
                //Hit until hand value it 17 or less
            while ( dealer.handV < 17){   //If cards value at greater or equal to 17, stay, else loop back
                dlrHit(dealer);
                AceChk(dealer); //Checks dealer hand if bust and has an ACE
            }
        
            //Print house hand, compare cards, find winner. Add or Take from balance
            cout << endl << "Dealers hand: " << dealer.hand << "(" << dealer.handV << ")" << endl;
            
            if (dealer.handV==player.handV){    //If both hands are even, no one wins
                cout << "House and player tie, no one wins" << endl;
            }
            else if (dealer.handV>player.handV && dealer.handV<=21){    //If dealers hand is greater and less then or equal to 21, dealer wins
                cout << "Dealers hand of " << dealer.hand << "(" << dealer.handV << ")" << " beats player hand of " << player.hand << "("<< player.handV <<")"<<endl;
                cout << "Player loses $" << player.plrBet << endl;
                player.player.balance-=player.plrBet;
                // break;
            }
            else if (dealer.handV>21){  //If dealer hand is over 21, he busts
                cout << "Dealer bust with " << dealer.hand << "(" << dealer.handV << ")" << endl;
                cout << "Player wins $" << player.plrBet << endl;
                player.player.balance+=player.plrBet;
            }
            else{   //Else the player wins
                cout << "Player hand of " << player.hand << "(" << player.handV << ") beats dealers hand of " << dealer.hand << "(" << dealer.handV << ")" << endl;
                player.player.balance+=player.plrBet;
            }
        }
        
        game=BlnChk(player);    //Checks Balance of Player for more bets, then asks if player wants to bet again or cash out.
            
    }while(game==false);
    
    //Display the results
        //Print cash out money,
    cout << "You cashed out with " << player.player.balance << " dollars." << endl;

    return 0;
}


void GetBank(Info &user){   //Gets the balance of user for betting 
    //Passing user data in by reference using '&' sign
    cout << "Enter the your starting balance before betting: $";
    cin>>user.player.balance;
    while (user.player.balance < 10){
        cout << "Invalid Input, must enter a number greater than or equal to $10." << endl;
        cout << "Enter again: $";
        cin>>user.player.balance;
    }
 }

bool BlnChk(Info plr){  //Checks Balance of Player, and if player wants to stay or bet again
    int HorS=0;
    bool temp;
        cout << endl << "Player balance: $" << plr.player.balance << endl;
        if (plr.player.balance<=0){
        cout << "Out of money, cannot bet.\nLeave." << endl;
        temp=true;
        }
        else{
        cout << "Place another bet or cash out?" << endl;
        cout << "Enter 1 to bet again or 2 to cash out:";
        cin>>HorS;
        if(HorS==1){
            temp=false;
        }
        else{
            temp=true;
        }
    } 
    return temp;
}

void GetBet(Info &plr){
    
    cout << "Starting bet: $";
    cin>>plr.plrBet;
    while ( plr.plrBet>plr.player.balance || plr.plrBet<0){
        cout << "Invalid betting amount, try again/" << endl;
        cout << "Starting bet: $";
        cin>>plr.plrBet;
        cout << endl;
    }
}

void Reset(Info &plr, House &dlr){   //Reset hand and hand value for player and dealer for loop
       //Player Flags and Variables 
    plr.hand="";
    plr.handV=0;
    plr.ace=false;   
    plr.plrBet=0;
    plr.bust=false;
    plr.nat21=false;
        //Dealer Flags and variables           
    dlr.hand="";         //Reset House hand
    dlr.handV=0;         //Reset House hand value.
    dlr.ace=false;
}

void AceChk(Info &player){  //If player has the ace flag true and has bust, minus 10 to hand value
    if ( player.ace==true && player.handV>21){
        player.handV-=10;   //This results in turning the value of the Ace to a one
        player.ace=false;   //Reverts the flag back to false in case the player gets another Ace
        cout << "(Player Bust, ace is now valued as 1 " << player.handV << endl;
    }       
}

void AceChk(House &dlr){  //If player has the ace flag true and has bust, minus 10 to hand value
    if ( dlr.ace==true && dlr.handV>21){
        dlr.handV-=10;   //This results in turning the value of the Ace to a one
        dlr.ace=false;   //Reverts the flag back to false in case the player gets another Ace
        cout << "(Dealer Bust, ace is now valued as 1 " << dlr.handV << ")" << endl;
    }
}

bool Nat21(Info player){    //Checks for Natural 21
    bool temp;
    if (player.handV==21){
        temp=true;
    }else{
        temp=false;
    }
    return temp;
}

bool Bust(Info player){ //Checks for a Bust
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
    if (num==TEN){
        user.hand+=card[TEN];
        user.hand+='0';
        user.handV+=cardV[TEN];        
    }
    else if (num==ACE){
        user.hand+=card[ACE];
        user.handV+=cardV[ACE];
        user.ace=true;  //If true, player hand holds an Ace
    }
    else{
        user.hand+=card[num];
        user.handV+=cardV[num];
    }
}

void dlrHit(House &dlr){   //adds a card to house hand(hH) and adds up hand value(hV)
    int num=RandNum();
    if (num==TEN){
        dlr.hand+=card[TEN];
        dlr.hand+='0';
        dlr.handV+=cardV[TEN];        
    }
    else if (num==ACE){
        dlr.hand+=card[ACE];
        dlr.handV+=cardV[ACE];
        dlr.ace=true;  //If true, player hand holds an Ace
    }
    else{
        dlr.hand+=card[num];
        dlr.handV+=cardV[num];
    }
}