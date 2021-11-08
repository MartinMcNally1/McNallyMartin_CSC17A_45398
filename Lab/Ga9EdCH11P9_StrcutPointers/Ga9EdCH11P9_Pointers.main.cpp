/* 
 * Author: Martin McNally
 * Created: 10/13/21
 * Purpose:  Print and edit a Speaker Info dynamic struct array, 
 *           and allow individual member edits.
 *           Now made with dynamic memory( pointers).
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Speaker //Struct Variable
{
    char *name;         //Dynamic char array
    string telNumber;
    char *topic;        //Dynamic char array
    float fee;
};

//function prototypes
int NumSpkr();                    //Returns the number of speakers for Dynamic allocation of memory
void EditSpkr(Speaker *, int, int, int);    //Edit struct info
                                   //Turning this function to dynamically create a struct array.
    
void PrintSpkr(Speaker[], int);   //Print struct info
                                  //Alterto allow a dynapmic struct array to be passed in.

//String Function to validate Phone number and Name, topic
//Float return Function to Validate Fee, must not be a negative number.

int main(){
    
    //Declare Variables
    int spkrlst=0;          //Number of speakers
    int NamSize=15;
    int TopicSize=25;
    bool quit;
    
    //Initialize Variables
    spkrlst=NumSpkr();  //Get the number of Speakers
    Speaker *speaker = new Speaker[spkrlst];    //Allocates user entered number for dynamic struct array pointer
                                                //making the pointer a pointer struct array.
    //speaker->name = new char[NamSize];      //Dynamically Allocating Memory to struct member
    //speaker->topic = new char[TopicSize];   //Dynamically Allocating Memory to struct member
    
    
    
    do{
        quit=true;
        int spkrnum = 0;    //Speaker Number for Struct array
        int selspkr = 0;    //Select num to Edit or Return
        cout << "List of Speakers:" << endl;;
        for ( int i=0; i < spkrlst; i++){   //Prints put the amount of Speakers the User inputs
            cout << "Speaker " << i+1 << endl;
        }
        cout << endl << "Enter Speaker number or '0' to Quit: ";
        cin>>spkrnum;
        //Input Validation
        while (spkrnum <0 || spkrnum >10){
            cout <<"Invalid input, enter number between 1 and 10." << endl;
            cout << "Enter Speaker number: ";
            cin>>spkrnum;
        }
        if (spkrnum == 0){
            break;
        }
        PrintSpkr(speaker, spkrnum);    //Prints info of selected speaker
        cout << "Edit Members or return to Speaker Selection?" << endl;
        cout << "Enter 1 to edit a member," << endl;
        cout << "or 0 to return to Speaker Selection:";
        cin >> selspkr;
        //Input Validation
        while (selspkr != 1 && selspkr != 0){
            cout << "Invalid input, enter 1 to Edit or 0 to Return." << endl;
            cout << "Enter:";
            cin>>selspkr;
        }
        EditSpkr(speaker, spkrnum, TopicSize, NamSize); //Calls EditSpkr fucntion, to edit struct members
        
        cout << endl <<"Quit or Edit another Speaker?" << endl;
        cout <<"Enter 1 to edit another Speaker," <<endl;
        cout <<"and 0 to quit the program." << endl;
        cout <<"Enter here:";
        cin>>spkrnum;
        while ( spkrnum <0 || spkrnum >10){
            cout << "Invalid input, enter number between 1 and 10." << endl;
            cout << "Enter Speaker number: ";
            cin>>spkrnum;
        }
        if (spkrnum == 0){
            break;
        }

    }while (quit==true);    //Ive set this to repeat until the user breaks out of it. 
                            //It is technically infinite.
    
    cout << "Thank you and goodbye.";
    //Delete/Deallocate memory from dynamic arrays
    
	
return 0;
}

int NumSpkr(){  //Returns the number of speakers
    int num=0;
    cout << "Enter the number of speakers: ";
    cin>>num;
    
    return num;
}

void EditSpkr(Speaker *spkr, int num, int namsize, int topicsize){    //Edit struct members
    bool quit;
    do{
        quit = true;
        int selmem=0;           //Select Member number
        cout << "Enter 1 to edit Name." << endl;
        cout << "Enter 2 to edit Phone Number." << endl;
        cout << "Enter 3 to edit Speakers Topic." << endl;
        cout << "Enter 4 to edit Speaker Fee amount in $." << endl;
        cout << "Enter 0 to return to Speaker Selection." << endl;
        cin >> selmem;
        //Input Validation
        while ( selmem!=0 && selmem!= 1 && selmem!=2 && selmem!=3 && selmem!=4){
            cout << "Invalid Input." << endl;
            cout << "Enter a number between 0 and 4: ";
            cin>>selmem;
        }
        if (selmem == 0){
            break;
        }
        
        if(selmem==1){
            cout << "Current Name: " << spkr[num].name << endl;
            cout << "New Name: ";
            cin.ignore();
            spkr[num].name = new char[namsize];    //Allocate memory for member
            getline( cin, *spkr[num].name);

        }
        else if(selmem==2){
            cout << "Current Phone Number: " << spkr[num].name << endl;
            cout << "New Phone Number: ";
            getline( cin, *spkr[num].telNumber);
        }
        else if(selmem==3){
            cout << "Current Speaker Topic: " << spkr[num].topic << endl;
            cout << "New Speaker Topic: ";
            cin.ignore();
            spkr[num].topic = new char[topicsize];
            getline( cin, *spkr[num].topic);
        }
        else if(selmem==4){
            cout << "Current Fee in dollars: $" << spkr[num].fee << endl;
            cout << "New Fee in dollars: $";
            getline( cin, *spkr[num].fee);

        }
        cout << "Want to edit another Member?" << endl;
        cout << "Enter 1 to edit another member," << endl;
        cout << "or  0 to return to Speaker Selection" << endl;
        cout << "Enter here: ";
        cin>>selmem;
        while (selmem!=1 && selmem!=0){
            cout << "Invalid Input." << endl;
            cout << "Enter a number between 0 and 4: ";
            cin>>selmem;
        }
        if (selmem == 0){
            quit=false;
        }
        
    } while( quit==true );

}

void PrintSpkr(Speaker *spkr, int num){    //Print Struct info
    cout << "Speaker " << num+1 << " Info:" << endl;
    cout << spkr[num]->name << endl;
    cout << spkr[num]telNumber << endl;
    cout << spkr[num]->topic << endl;
    cout << spkr[num].fee << endl;
}

