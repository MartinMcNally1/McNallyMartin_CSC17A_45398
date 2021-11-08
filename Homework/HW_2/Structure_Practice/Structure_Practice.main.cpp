/* 
 * File:   Structure_Practice.main.cpp
 * Purpose:  Practicing with Structured Data
 * Note: Note all libraries are needed  
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

//User Libraries, Structures
struct Budget
{
    float house = 500.00;
    float util = 150.00;
    float houseExp = 65.00;
    float trans = 50.00;
    float food = 250.00;
    float med = 30.00;
    float insur = 100.00;
    float ent = 150.00;
    float cloths = 75.00;
    float mis = 50.00;
};

struct VideoGame 
{
    string title;
    int release;
    string studio;  //Include Spaces
    int soldcopies; //In millions
    int revscore;   //1-5 rating
};
struct BookInfo
{
    string title;
    string author;
    int release;
};

enum Day { MON, TUE, WED, THUR, FRI };
//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
void PrintStructVar(VideoGame);    //When passing a structure into a function, include the structure type
                                   //This is the same as for a 'int', 'float', 'char', etc...
void InputStructVar(VideoGame&);   //Void Function that fills in members of structure variable 
void PrintVideoGameStruct(VideoGame, VideoGame ,VideoGame); //Passes 3 VideoGame Struct's into a fucntion

void InputStructAry(BookInfo[], int);
void PrintStructAry(BookInfo[], int);
//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare Struct Variable
    //VideoGame game2, game3;    //Declares game2 as a structure variable, but its members are not filled.
    //Initialize, and Declare Struct variable and each member
    //Note: You don't need to declare all members, but you must do so in the correct order. Check you Structure Library.
    //VideoGame game1 = {"Halo 3", 2007, "Bungie", 200, 5};  //This initializes structure variable game1; 
    
    //PrintVideoGameStruct(game1, game2, game3); //Calls InputStructVar and PrintStructVar in one function call;
    
    int SIZE=2;
    BookInfo book[SIZE];  //Declared a struct array with 5 elements
    
    InputStructAry(book,SIZE);
    PrintStructAry(book,SIZE);

    return 0;
}
void PrintVideoGameStruct( VideoGame game1, VideoGame game2, VideoGame game3){
    PrintStructVar(game1);
    cout << endl;
    InputStructVar(game2);
    cout << endl;
    PrintStructVar(game2);
    InputStructVar(game3);
    cout << endl;
    PrintStructVar(game3);
};
void PrintStructVar(VideoGame game){   //Pass it into the function the same as any other variable
    cout << "Title of Game: " << game.title << endl;
    cout << "Release Date: " << game.release << endl;
    cout << "Developer/Studio: " << game.studio << endl;
    cout << "Copies Sold: " << game.soldcopies << " million" << endl;
    cout << "Average Review Score: " << game.revscore << endl;
}

void InputStructVar( VideoGame &game){ //Pass in an initialized Struct variable, then filled its members.
    
    cout << "Enter Title of Game: ";
    cin.ignore();   //to skip any '\n' characters(spaces) 
    getline(cin, game.title );
    cout << "Enter the Release Date(year): ";
    cin >> game.release;
    cout << "Enter the Developer/Studio behind the game: ";
    cin.ignore();   //to skip any '\n' characters(spaces)
    getline(cin, game.studio );
    cout << "Enter the number of copies sold(in million): ";
    cin >> game.soldcopies;
    cout << "Enter the Average Review Score(1-5): ";
    cin >> game.revscore;
}

void InputStructAry( BookInfo b[], int SIZE){
    for (int i=0; i<SIZE; i++){
       cout << "    Input info for Book " << i+1 <<endl;
       cout << "Enter title: ";
       //cin.ignore();    //to skip any '\n' characters(spaces)
       getline(cin, b[i].title );  //May skip first input, ticker a bit
       cout << "Enter Author: ";
       //cin.ignore();    //to skip any '\n' characters(spaces)
       getline(cin, b[i].author );  //May skip first input, ticker a bit
       cout << "Enter Release Date: ";
       cin >> b[i].release;
    }
}
void PrintStructAry(BookInfo b[], int SIZE ){
    for (int i=0; i<SIZE; i++){
        cout << "Title of Book " << i+1 << ": " << b[i].title << endl;
        cout << "Author of Book " << i+1 << ": " << b[i].author << endl;
        cout << "Release Date of Book " << i+1 << ": " << b[i].release << endl << endl;
    }
}    