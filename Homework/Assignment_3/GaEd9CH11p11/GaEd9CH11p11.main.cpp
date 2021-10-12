/* 
 * Author: Martin McNally
 * Created: 10/11/21
 * Purpose:  
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
struct FixedBudget
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
struct NewBudget
{
    float house;
    float util;
    float houseExp;
    float trans;
    float food;
    float med;
    float insur;
    float ent;
    float cloths;
    float mis;
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
NewBudget getBudget();         //Monthly Budget
void ReportB( FixedBudget,NewBudget);   //Compare and report budget

float Total(FixedBudget);   //Total budget
float Total(NewBudget);   //Total budget

//Execution Begins Here
int main(int argc, char** argv) {

    
    //Declare Variable Data Types and Constants
    NewBudget budget;       //New struct to fill
    FixedBudget compBud;    //Budget struct to comapre
    float Fmnth=0.00;       //Fixed total budget
    float Nmnth=0.00;       //New total budget
    
    //Initialize Variables
    budget = getBudget();       //Gets monthly expenses for compare
    
    Nmnth = Total(budget);      //New total budget
    Fmnth = Total(compBud);     //Fixed total budget
    //Process or map Inputs to Outputs
    ReportB(compBud,budget);
    
    if ( Nmnth < Fmnth){
        cout << "You were $" << Fmnth-Nmnth << " under budget";
    }
    else if ( Nmnth > Fmnth ){
        cout << "You were $" << Nmnth-Fmnth << " over budget";
    }
 
    return 0;
}

NewBudget getBudget(){  //Monthly Budget
    NewBudget temp;     //Temp struct
    
    cout << "Enter housing cost for the month:$";
    cin >>temp.house;
    cout << endl;
    
    cout << "Enter utilities cost for the month:$";
    cin >> temp.util;
    cout << endl;
    
    cout << "Enter household expenses cost for the month:$";
    cin >>temp.houseExp;
    cout << endl;
    
    cout << "Enter transportation cost for the month:$";
    cin >> temp.trans;
    cout << endl;
    
    cout << "Enter food cost for the month:$";
    cin >>temp.food;
    cout << endl;
    
    cout << "Enter medical cost for the month:$";
    cin >> temp.util;
    cout << endl;
    
    cout << "Enter insurance cost for the month:$";
    cin >>temp.house;
    cout << endl;
    
    cout << "Enter clothing cost for the month:$";
    cin >> temp.util;
    cout << endl;
    
    cout << "Enter clothing cost for the month:$";
    cin >> temp.house;
    cout << endl;
    
    cout << "Enter miscellaneous cost for the month:$";
    cin >> temp.util;
    cout << endl;
    
    return temp;
}

void ReportB(FixedBudget budget, NewBudget newbud){   //Compare and report budget
    //Housing cost report
    if ( newbud.house == budget.house){
       cout << "Housing Even" << endl; 
    }
    else if ( newbud.house < budget.house){
        cout << "Housing Under"<< endl;
    }
    else{ cout << "Housing Over" << endl;}
    
    //Utilities
    if ( newbud.util == budget.util){
       cout << "Utilities Even" << endl; 
    }
    else if ( newbud.util < budget.util){
        cout << "Utilities Under"<< endl;
    }
    else{ cout << "Utilities Over" << endl;}
    
    //House hold 
    if ( newbud.houseExp == budget.houseExp){
       cout << "Household Expenses Even" << endl; 
    }
    else if ( newbud.houseExp < budget.houseExp){
        cout << "Household Expenses Under"<< endl;
    }
    else{ cout << "Household Expenses Over" << endl;}
    
    //Transportation
    if ( newbud.trans == budget.trans){
       cout << "Transportation Even" << endl; 
    }
    else if ( newbud.trans < budget.trans){
        cout << "Transportation Under"<< endl;
    }
    else{ cout << "Transportation Over" << endl;}
    
    //food
    if ( newbud.food == budget.food){
       cout << "Food Even" << endl; 
    }
    else if ( newbud.food < budget.food){
        cout << "Food Under"<< endl;
    }
    else{ cout << "Food Over" << endl;}
    
    //Medical
    if ( newbud.med == budget.med){
       cout << "Medical Even" << endl; 
    }
    else if ( newbud.med < budget.med){
        cout << "Medical Under"<< endl;
    }
    else{ cout << "Medical Over" << endl;}
    
    //Insurance
    if ( newbud.insur == budget.insur){
       cout << "Insurance Even" << endl; 
    }
    else if ( newbud.insur < budget.insur){
        cout << "Insurance Under"<< endl;
    }
    else{ cout << "Insurance Over" << endl;}
    
    //Entertainment
    if ( newbud.ent == budget.ent){
       cout << "Entertainment Even" << endl; 
    }
    else if ( newbud.ent < budget.ent){
        cout << "Entertainment Under"<< endl;
    }
    else{ cout << "Entertainment Over" << endl;}
    
    //Cloths
    if ( newbud.cloths == budget.cloths){
       cout << "Clothing Even" << endl; 
    }
    else if ( newbud.cloths < budget.cloths){
        cout << "Clothiing Under"<< endl;
    }
    else{ cout << "Clothing Over" << endl;}
    
    //Miscellaneious
        if ( newbud.mis == budget.mis){
       cout << "Miscellaneous Even" << endl; 
    }
    else if ( newbud.mis < budget.mis){
        cout << "Miscellaneous Under"<< endl;
    }
    else{ cout << "Miscellaneous Over" << endl;}
}

float Total( FixedBudget budget ){
    float total=0.00;
    total += budget.house;
    total += budget.util;
    total += budget.houseExp;
    total += budget.trans;
    total += budget.food;
    total += budget.med;
    total += budget.insur;
    total += budget.ent;
    total += budget.cloths;
    total += budget.mis;
    
    return total;
}
float Total( NewBudget budget ){
    float total=0.00;
    total += budget.house;
    total += budget.util;
    total += budget.houseExp;
    total += budget.trans;
    total += budget.food;
    total += budget.med;
    total += budget.insur;
    total += budget.ent;
    total += budget.cloths;
    total += budget.mis;
    
    return total;
}
