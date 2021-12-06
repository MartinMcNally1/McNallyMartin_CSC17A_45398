/* 
 *File:     Prj.V5.main.cpp
 *Purpose:  Create a black-jack game using structures.
 *          V1 holds the basics of the game Player inputs how much 
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
 * Version 5:
 * 
 */         

//System Libraries
#include <iostream>   //Input/Output Library
#include <iomanip>    //Output Manipulation Library
#include <cstdlib>    //C Standard Library
#include <cstring>    //String Library
#include <ctime>      //Time library, for rand() function



using namespace std;  //STD Name-space where Library is compiled

//User Libraries
struct Plr{     //Struct info for player
    int balance;    //Balance that player bets with
    string hand="";    //Hand accumulated during game, resets each new game
    int handV=0;      //Value of the cards combined, resets each new game
    int plrBet=0;     //How much the player wants to bet
    bool stay=false;      //If flag is true, player has chosen to stay
    bool cashout=false;   //Determines if a player has cashed out or is still betting
    bool ace=false;       //Notes whether you have an ace in your hand, changes stuff for hand value
    bool bust=false;      //If flag is true, player or dealer has bust(over 21)
    bool nat21=false;     //If flag is true, player got a natural 21
};

struct House{       //Struct Info for dealer
    string hand="";
    int handV=0;  
    bool ace=false;       //Flag is true if there is an ACE in dealer deck
    int balance;    //How much the dealer has won from players
};

struct Info         //Struct Info holds player info and dealer info
{    
    Plr *player;    //Holds player info (dynamic struct array)
    House dealer;   //Holds info of dealer
    int size=0;       //Size of array
    int table=0;      //Table number (row)
    int floor=0;      //Floor number of table (colomn)
    bool end=false;       //Once all players have cashed out, flag is true.   
    
};


//Global Constants not Variables
const char card[]={'2','3','4','5','6','7','8','9','1','J','Q','K', 'A'};   //These are all the cards being given out, ACE if only valued at 1 for now
const int cardV[]={ 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10, 10, 10, 10, 11 };     //Index numbers for each card, will be used for random
enum card{ TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };  //Have to use enum data types some how

//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
void GetGame(Info*);     //Dynamically creates the number of players
    //Player Fucntions
void plrHit( Info*, int);     //Adds a random card to hand, and adds value of said card to handV
bool Bust(Info*,int);        //Check players hand for 21           //Can include all flags in struct for simplicity
bool Nat21(Info*, int);       //Check players hand for a bust
void AceChkP( Info*,int);     //If the player bust but has a 21 card, minus 10
void GetBet(Info*,int);     //Gets the betting amount from player 

    //Dealer functions
void DlrHit(Info*);    //Adds another card to dealer hand, handV
void AceChkD(Info*);    //If the player bust but has a 21 card, minus 10
bool Nat21(int);      //Check dealers hand for a bust(over 21)
bool Bust(int);        //Check dealers hand for 21

    //Game Sections
void Betting(Info*,int); //Initial betting before more cards are given out.
void PlrsHit(Info*,int); //Player decideds to hit or stay
void Compare(Info*, int); //Compare with dealers hand, see if they win or loose against dealer
void Cashout(Info*,int);     //If player chooses to cash out or bet again
bool EndGame(Info*);        //Returns true flag if all players have cashed out

void Reset(Info*, int);     //Resets flags and clear hand for next round of betting for both dealer and player
int RandNum();                //Returns a random number for card selection, between 0-13 (When including the ACE, 0-13)
void Delete(Info*);

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));  //Random Number Seed
    
    //Declare variables here, most other variables are held withn the struct
    Info *Game;     //Struct variable for all info on game
    //cout << Game->player[0].balance << endl;
    Game->dealer.balance+=12800;    //I dont know why, but dealer balance always starts with -12800
    //cout << Game->dealer.balance << endl;
    //Initialize variables here     //This is where we grab, or if not ID not found create the user info for playing and store balance
    GetGame(Game); //Get Table number, floor, and the number of players and balance of each player
    
    do{
        //Reset Data for new round of betting
        for (int i=0; i<Game->size && Game->player[i].cashout==false; i++){  //Game.player[i].cashout==false checks whether or not the player has cashed out
            Reset(Game,i);   //Resets Game data for new round of betting
        }
        
        //Each player makes a starting bet.
        for(int i=0; i<Game->size && Game->player[i].cashout==false; i++){ //Same check done 
            GetBet(Game,i); //This gets a bet from each player, also checks if their balance can handle a bet and cashes them out if its 0
        }
        
        //Each player now gets 2 cards, and continues to hit until they choose to stay
        DlrHit(Game); //1st card, will show
        DlrHit(Game); //2nd card, wont show
        for (int i=0; i<Game->size && Game->player[i].cashout==false; i++ ){
            PlrsHit(Game,i);    //Players see their two cards, and one dealer card. Calls to hit or stay
                                //Also checks for bust, Nat 21.
        }
        
        //Once players have chosen to stay, dealer go's. House rules that he stops hitting at >17
        while ( Game->dealer.handV < 17){   //If cards value at greater then 17, stay, else loop back
            DlrHit(Game);   //Adds another card
            AceChkD(Game);  //Checks dealer hand if bust and has an ACE
        }
        if (Game->dealer.handV>21){ //If dealer busts, all remaining players win no matter their hand value
            cout << endl << "Dealer has bust with " << Game->dealer.hand << "(" << Game->dealer.handV << ")" << endl;
            for( int i=0; i<Game->size && Game->player[i].cashout==false && Game->player[i].bust==false && Game->player[i].nat21==false; i++){
                cout << "Player " << i+1 << " wins $" << Game->player[i].plrBet << endl;
                Game->player[i].balance+=Game->player[i].plrBet;  //Add bet to balance
                Game->dealer.balance-=Game->player[i].plrBet;     //Subtract bet from dealer balance
            }
        }
        else{   //Find which player has won, calculate winnings
            cout << endl << "Dealers Full Hand: " << Game->dealer.hand << "(" << Game->dealer.handV << ")" << endl;
            for( int i=0; i<Game->size && Game->player[i].cashout==false && Game->player[i].bust==false && Game->player[i].nat21==false; i++){
                Compare(Game,i);    //Tie, player wins, or dealer wins
            }
        }
        
        //Cash out or Bet again?
        for(int i=0; i<Game->size && Game->player[i].cashout==false; i++){ //Same check done 
            Cashout(Game,i); //Asks if player wants to cash out, remaining players start a new round of betting without those who have cashed out
        }
        
        //Check if all players have cashed out to tall total winnings or loses
        Game->end=EndGame(Game); //Check if each player has cashed out
        if(Game->end==true){
            cout << "All players have cashed out, come back soon." << endl;
        }
        
    }while(Game->end==false);    //Once all players have cashed out, flag is set to true
    
    //Open Binary file
    
    //Save data by floor and table where game was had(2D array to a binary file
    
    //Close Binary file
    
    //Deallocate memory
    Delete(Game);
    
    //End Game
    
    
   
    
                //Process
    //Create Dynamic Struct array. Which floor and table, and players starting balance?   
    //Get Balance of each player  (for binary files, save how much the house made or loss that table game 
    //Game Do-While
        //Reset all data(handV,hand,bets,flags,etc.)
        //Check balance before betting more
        //Get bets from each player playing
            //Begin Player Hit-Card 
                //Deal cards, 2 each player, 2 for dealer (Happens Once)
                //Show First card of dealer for all player
                //Player For-loop
                    //Check for Natural 21 or Bust and set flags if found
                    //Inform players that have 21 or bust.
                    //Ask remaining players if they want to hit or stay
                    //Once all players have ended, exit loop
                //Player Compare For loop
                    //Compare players hand with dealers.
                    //If player runs out of money, cash player out(can no longer vote)
                    //If player has money min balance to bet, ask if player wants to bet again or cash out
                    //Cash out players who decide cash out.
    //When all players cash out, exit loop.
    //Calculate money lost/won for house
    //Open binary file
    //Save data info binary file(2D file)
    //Close binary file
    //End Game

    cout << "Work End" << endl;
    return 0;
}
void GetGame(Info *temp){  //Creates the Struct that Will be used for the whole game(Players involved)

    //Info *temp;
    //Enter Info for binary file saving
    cout << "There are 20 floors." << endl;
    cout << "Enter Floor Number:";
    cin>>temp->floor;
    while(temp->floor<1 || temp->floor>20){
        cout << "Invalid Input, enter a floor between 1 and 20: ";
        cin>>temp->floor;
    }
    cout << "There are 20 tables on floor " << temp->floor << "." << endl;
    cout << "Enter Table Number:";
    cin>>temp->table;
    while(temp->table<1 || temp->table>20){
        cout << "Invalid Input, enter a floor between 1 and 20: ";
        cin>>temp->table;
    }
    cout << "Enter the the amount of players." << endl;
    cout << "Table limit is 5." << endl;
    cout << "Enter here: ";
    cin>>temp->size;
    while (temp->size<1 || temp->size>5){
        cout << "Invalid Input, try again." << endl;
        cout << "Table size limit is 5:";
        cin>>temp->size;
    }
    
    //Temp struct array, must delete later
    temp->player = new Plr[temp->size]; //Allocates Dynamic Memory for struct array of players
    
    cout << "Enter balance of each player at the table." << endl;
    cout << "Table limit is $10-$500." << endl;
    for ( int i=0;i<temp->size;i++){
        cout << "Player " << i+1 << ": $";
        cin >> temp->player[i].balance;
        while (temp->player[i].balance < 10 || temp->player[i].balance > 500){
            cout << "Invalid Input, must enter a number greater than or equal to $10." << endl;
            cout << "Enter again: $";
            cin>>temp->player[i].balance;
        }
    }
    //Delete(temp);
    //return tempH;
    //Must delete everything here again after returning temp struct 
}

bool EndGame(Info *game){   //Checks if all players have cashed out to end game.
    bool temp;
    int count=0;
    for (int i=0; i<game->size; i++){   //Counts the number of those cashed out
        if ( game->player[i].cashout == true){
            count++;
        }
    }
    if (count == game->size){   //If the number if those cashed out is the same if the size of party, all have cashed out
        temp=true;
    }
    else{
        count=0;    //Resets count to zero for loop
    }
    return temp;
}

void Delete(Info *data){  //Deallocate dynamic struct memory 
    cout << "Works" << endl;
    delete[] data->player;  //Deallocate pointer to pointer array
    cout << "Works" << endl;
    delete data;          //Deallocate pointer struct
    cout << "Works" << endl;
    //delete data;            //Deallocate pointer
    //cout << "Works" << endl;
}

void GetBet(Info *game, int i){
    if(game->player[i].balance==0){
        cout << "Sorry player " << i+1 << ", you have no more money to bet." << endl;
        cout << "You are forced to cash out.";
        game->player[i].cashout=true;
    }else{
        cout << "Starting bet for player " << i+1 << " : $";
        cin>>game->player[i].plrBet;
        while ( game->player[i].plrBet > game->player[i].balance || game->player[i].plrBet < 0){
            cout << "Invalid betting amount, try again." << endl;
            cout << "Starting bet: $";
            cin>>game->player[i].plrBet;
            cout << endl;
        }
    }
}

void Reset(Info *game, int i){   //Reset hand and hand value for player and dealer for loop
    
    //Player Flag and Variable Reset
        game->player[i].hand="";       //Empty players hand
        game->player[i].handV=0;       //Reset hand value to 0
        game->player[i].ace=false;     //If flag is true, player has an ACE in players hand
        game->player[i].plrBet=0;      //Reset bet amount to 0
        game->player[i].bust=false;    //If flag is true, players hand has bust
        game->player[i].nat21=false;   //If flag is true, player has scored a Natural 21
        game->player[i].stay=false;    //If flag is true, player has chosen to stay
    
    //Dealer Flags and Variables Reset          
    game->dealer.hand="";         //Reset House hand
    game->dealer.handV=0;         //Reset House hand value.
    game->dealer.ace=false;       //Reset house ACE flag
}

void AceChkP(Info *game, int i){  //If player has the ace flag true and has bust, minus 10 to hand value
    if ( game->player[i].ace==true && game->player[i].handV>21){
        game->player[i].handV-=10;   //This results in turning the value of the Ace to a one
        game->player[i].ace=false;   //Reverts the flag back to false in case the player gets another Ace
        cout << "Player Bust, ace is now valued as 1, making hand value = " <<game->player[i].handV << endl;
    }       
}

void AceChkD(Info *game){  //If dealer has the ace flag true and has bust, minus 10 to hand value
    if ( game->dealer.ace==true && game->dealer.handV>21){
        game->dealer.handV-=10;   //This results in turning the value of the Ace to a one
        game->dealer.ace=false;   //Reverts the flag back to false in case the player gets another Ace
        cout << "(Dealer Bust, ace is now valued as 1, making hand value = " << game->dealer.handV << endl;
    }
}

bool Nat21(Info *game, int i){    //Checks for Natural 21
    bool temp;
    if (game->player[i].handV==21){
        temp=true;
    }else{
        temp=false;
    }
    return temp;
}

bool Bust(Info *game, int i){ //Checks for a Bust
    bool temp;
    if (game->player[i].handV>21){
        temp=true;
    }else{
        temp=false;
    }
    return temp;
}

int RandNum(){
    return rand()%13;   //Returns a number between 0-13
}

void plrHit(Info *game, int i){   //Adds another card to the user hand, and adds value to handV to check is bust
    int num=RandNum();
    //cout << card[num] << " " << cardV[num] << endl;
    if (num==TEN){
        game->player[i].hand+=card[TEN];
        game->player[i].hand+='0';
        game->player[i].handV+=cardV[TEN];        
    }
    else if (num==ACE){
        game->player[i].hand+=card[ACE];
        game->player[i].handV+=cardV[ACE];
        game->player[i].hand=true;  //If true, player hand holds an Ace
    }
    else{
        game->player[i].hand+=card[num];
        game->player[i].handV+=cardV[num];
    }
}

void DlrHit(Info *game){   //adds a card to house hand(hH) and adds up hand value(hV)
    int num=RandNum(); //Retrun
    if (num==TEN){
        game->dealer.hand+=card[TEN];  
        game->dealer.hand+='0';    //Adds an extra '0' for string to make it '10' rather then '1'
        game->dealer.handV+=cardV[TEN];        
    }
    else if (num==ACE){
        game->dealer.hand+=card[ACE];
        game->dealer.handV+=cardV[ACE];
        game->dealer.ace=true;  //If true, player hand holds an Ace
    }
    else{
        game->dealer.hand+=card[num];
        game->dealer.handV+=cardV[num];
    }
}

void PlrsHit(Info *game, int i){ //Player decideds to hit or stay
    //bool strtrnd=true;   //First round of betting flag 
    int HorS;       //1 to stay or 2 to hit
    plrHit(game,i); //1st card
    plrHit(game,i); //2nd card
    do{
        HorS=0;
        //These checks must always be passed through
            AceChkP(game,i);                //Checks if the hand has bust and has an ace, and corrects it
            game->player[i].nat21=Nat21(game,i);    //Check if the player got a natural 21
            game->player[i].bust=Bust(game,i);      //Check if the player has bust
            
            //Check for 21 or Bust flags (later check for the option of splitting pairs and the option for doubling)
            if(game->player[i].nat21==true){    //Check if player hand is 21
                cout << "Player " << i+1 << " scored a natural 21 " << game->player[i].hand << "(" << game->player[i].handV << ")" << endl;
                cout << "Player wins $" << game->player[i].plrBet << endl;
                game->player[i].balance+=game->player[i].plrBet;  //Player wins bet
                game->dealer.balance-=game->player[i].plrBet;     //House loses money
                game->player[i].stay=true;  //And and skip the rest
            }
            else if(game->player[i].bust==true){ //Check if player bust
                cout << "Player " << i+1 << " has bust with " << game->player[i].hand << "(" << game->player[i].handV << ")" << endl;  
                cout << "Player wins $" << game->player[i].plrBet << endl;
                game->player[i].balance-=game->player[i].plrBet;  //Player loses bet
                game->dealer.balance+=game->player[i].plrBet;     //House wins money
                game->player[i].stay=true;  //And we skip the rest
            }
            else{  //Stay or Hit? If Stay exit loop, else hit again and return to loop
                cout << endl << "Dealers first card is " << game->dealer.hand[0] << "(Full Hand " << game->dealer.hand << " = " << game->dealer.handV << ")" << endl; 
                cout << "Player " << i+1 << " Hand: " << game->player[i].hand << "(value = " << game->player[i].handV << ")" << endl;
                cout << "Enter 1 to Stay, or 2 to Hit again: "<< endl;
                cin>>HorS; 
                while(HorS>2 || HorS<1){
                    cout << "Invalid Input, try again" << endl;
                    cout << "Enter 1 to Stay, or 2 to Hit again: ";
                    cin>>HorS;
                }
                if (HorS == 1){
                    game->player[i].stay=true;
                }else if (HorS == 2){
                    game->player[i].stay=false;
                    plrHit(game,i);   //Hit for another card
                    }
                }
             
        }while(game->player[i].stay==false);   //Once player has chosen to stay, the next player is up
}

void Compare(Info *game, int i){ //Compare with dealers hand, see if they win or loose against dealer
    //Don't check for player Natural 21 or Busts, that's done in PlrsHit already
    
    //Player Dealer Tie. Bet is returned.
    if (game->dealer.handV == game->player[i].handV){
        cout << "Player " << i+1 << "'s hand of " << game->player[i].handV << " has tied with dealer.\n No one wins, bet returned." << endl;
    }
    //Dealer Wins. Add bet to dealer balance, subtract bet from player balance.
    if (game->dealer.handV > game->player[i].handV){
        cout << "Player " << i+1 << "'s hand of " << game->player[i].handV << " loses to dealers hand." << endl;
        cout << "Player loses $" << game->player[i].plrBet << endl;;
        game->player[i].balance-=game->player[i].plrBet;  
        game->dealer.balance+=game->player[i].plrBet;     
    }
    //Player Wins. Add bet to player balance, subtract bet from dealer balance.
    if (game->dealer.handV < game->player[i].handV){
        cout << "Player " << i+1 << "'s hand of " << game->player[i].handV << " beats dealers hand." << endl;
        cout << "Player wins $" << game->player[i].plrBet << endl;
        game->player[i].balance+=game->player[i].plrBet;  //Add bet to balance
        game->dealer.balance-=game->player[i].plrBet;     //Subtract bet from dealer balance
    }
}

void Cashout(Info *game, int i){     //If player chooses to cash out or bet again
    int num=0;
    if( game->player[i].balance==0){
        cout << "Player " << i+1 << " is out of money and is forced to cash out.\nUntill next time" << endl;
        game->player[i].cashout=true;  //Set to true, wont be able to play.
    }
    else{
        cout << "Would player " << i+1 << " like to cash or or bet again?" << endl;
        cout << "Enter 1 to stay, or 2 to cash out: ";
        cin>>num;
        while(num>2 || num<1){
            cout << "Invalid Input, try again" << endl;
            cout << "Enter 1 to stay, or 2 to cash out: ";
            cin>>num;
        }
        if (num==2){
            cout << "Player " << i+1 << " has cashed out with $" << game->player[i].balance << endl;
            game->player[i].cashout=true;
        }else{
            game->player[i].cashout=false; 
        }
    }
}