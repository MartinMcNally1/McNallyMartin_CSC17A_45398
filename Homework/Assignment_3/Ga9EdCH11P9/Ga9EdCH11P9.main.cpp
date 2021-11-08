/* 
 * Author: Martin McNally
 * Created: 10/13/21
 * Purpose:  Print and edit a Speaker Info struct array of 10. 
 *           and allow individual member edits.
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Speaker
{
    string name = "Empty";
    string telNumber = "Empty"; 
    string topic="Empty";
    string fee = "Empty";
};

//function prototypes
void EditSpkr(Speaker [], int);    //Edit struct info
void PrintSpkr(Speaker[], int);   //Print struct info

int main(){
    
    //Initialize Variables
    
    Speaker speaker[10];    //Struct array of 10 speakers
    bool quit;
    do{
        quit=true;
        int spkrnum = 0;    //Speaker Number for struct array
        int selspkr = 0;    //Select num to Edit or Return
        cout << "List of Speakers:" << endl;;
        cout << "Speaker 1" << endl;
        cout << "Speaker 2" << endl;
        cout << "Speaker 3" << endl;
        cout << "Speaker 4" << endl;
        cout << "Speaker 5" << endl;
        cout << "Speaker 6" << endl;
        cout << "Speaker 7" << endl;
        cout << "Speaker 8" << endl;
        cout << "Speaker 9" << endl;
        cout << "Speaker 10" << endl;
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
        EditSpkr(speaker, spkrnum); //Calls EditSpkr fucntion, to edit struct members
        
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

    }while (quit==true);

    cout << "Thank you and goodbye.";
	
return 0;
}

void EditSpkr(Speaker spkr[], int num){    //Edit struct members
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
            getline( cin, spkr[num].name);

        }
        else if(selmem==2){
            cout << "Current Phone Number: " << spkr[num].name << endl;
            cout << "New Phone Number: ";
            string phone= "";
            getline( cin, phone);
            spkr[num].telNumber = phone;
        }
        else if(selmem==3){
            cout << "Current Speaker Topic: " << spkr[num].topic << endl;
            cout << "New Speaker Topic: ";
            string topic= "";
            getline( cin, topic);
            spkr[num].topic = topic;
        }
        else if(selmem==4){
            cout << "Current Fee in dollars: $" << spkr[num].fee << endl;
            cout << "New Fee in dollars: $";
            string fee= "";
            getline( cin, fee);
            spkr[num].fee = fee;
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


void PrintSpkr(Speaker spkr[], int num){    //Print Struct info
    cout << "Speaker " << num << " Info:" << endl;
    cout << spkr[0].name << endl;
    cout << spkr[0].telNumber << endl;
    cout << spkr[0].topic << endl;
    cout << spkr[0].fee << endl;
}