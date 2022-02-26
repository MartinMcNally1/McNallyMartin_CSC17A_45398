/* 
 * File:   TR.Pr1.main.cpp
 * Purpose:  Test realm for project
 *           
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <iomanip>    //Output Manipulation Library
#include <cstdlib>    //C Standard Library
#include <cstring>     //String Library
#include <ctime>      //Time library, for rand
#include <cmath>      //Math library(Think of your own functions for math)
#include <vector>     //Vector library

using namespace std;  //STD Name-space where Library is compiled

//User Libraries
struct TestInfo{
    char *name;
    int age;
    char sex;
};
//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
TestInfo *GetInfo(int&); //Creates Dynamic Struct
void PrintInfo(TestInfo*, int);   //Print Info of dynamic stuct
void Delete(TestInfo*,int); //Deletes Allocated memory
//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));  //Random Number Seed
    
    //Declare variables here
    //enum card {ONE, TWO, THREE};
//    TestInfo *info;
//    int size;
    //vector<int> test();
//    int size;
//    int i=0;
//    
//    cout << "Enter the size of vector:";
//    cin>>size;
//    vector<int> test(size); //sets the size of vector
//    cout << "Vector size set to " << test.size() << endl;
//    cout << "Enter numbers:" << endl;
//    
//    for (i=0; i<=size; i++){
//        cin>>test.at(i);
//    }
//    
//    cout << test.at(0) << endl;
//    
//    for (i=size-1; i>=0; i--){
//        cout << test.at(i) << ",";
//    }
//    
//    vector<char> test(10);
//    test.at(0)='h';
//    test.at(1)='i';
//    
//    cout << test.at(0) << test.at(1) << test.at(2);
    
    int x=4;
    int y=8;
    x=y;
    y=x;
    x=y;
    cout << x << y;
    
    
    
//    info = GetInfo(size);
//    
//    PrintInfo(info,size);
//    
//    Delete(info,size);
//    
//    for (int i=0;i<size;i++){
//        cout << "Enter Name for user " << i+1 << ":";
//        cin>>info->name;
//        cout << "Enter Age for user " << i+1 << ":";
//        cin>>info->age;
//        cout << "Enter Sex(M or F) for user " << i+1 << ":";
//        cin >> info->sex;
//    }
//    
//    for (int i=0; i<size; i++){
//        cout << "User " << i+1 << "Info" << endl;
//        cout << "Name: " << info->name << endl;
//        cout << "Age: " << info->age << endl;
//        cout << "Sex: " << info->sex << endl;
//    }
    //Initialize variables here
    
    //Map inputs to outputs here, i.e. the process
    
    //Display the results
//    for (int i=0;i<size;i++){
//        delete []info[i].name; //Deallocate array fo char
//    }
//    delete []info; //Deallocate array of struct
//    delete info;   //Deallocate struct

    return 0;
}

TestInfo *GetInfo(int &size){ //Creates Dynamic Struct
    TestInfo *temp;
    int namesize;
    
    cout << "Enter the number of users: ";
    cin>>size;
    
    temp = new TestInfo[size];
    
    for (int i=0;i<size;i++){
        cout << "Enter Length of Name for user " << i+1 << " for dynamic memory: ";
        cin>>namesize;
        temp->name = new char[namesize];
        cout << "Enter name of user " << i+1 << ": ";
        cin>>temp->name;
        cout << "Enter Age for user " << i+1 << ":";
        cin>>temp->age;
        cout << "Enter Sex(M or F) for user " << i+1 << ":";
        cin >> temp->sex;
    } 
    
    return temp;
    Delete(temp,size);
    //delete []temp;
}
void PrintInfo(TestInfo *info, int size){   //Print Info of dynamic stuct
    for (int i=0; i<size; i++){
        cout << "User " << i+1 << "Info" << endl;
        cout << "Name: " << info->name << endl;
        cout << "Age: " << info->age << endl;
        cout << "Sex: " << info->sex << endl;
    }
}

void Delete(TestInfo *info, int size){
    
    for (int i=0;i<size;i++){
        delete []info[i].name; //Deallocate array fo char
    }
    cout << "Deleting char array works" << endl;
    delete []info; //Deallocate array of struct
    cout << "Deleteing struct array works" << endl;
    //delete info;   //Deallocate struct
    //cout << "Deleting struct pointer works" << endl;
    
}