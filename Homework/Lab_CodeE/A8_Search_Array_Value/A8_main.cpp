/* 
 * Purpose:  Searching for multiple occurrence of patterns
 * Note:  cout proceeds to null terminator, cin reads to end of line
 *        for character arrays
 * 
 */

//System Libraries Here
#include <iostream>//cin,cout,getline()
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//PI, e, Gravity, or conversions

//Function Prototypes Begins Here
//srch1 utility function Input->start position, Output->position found or not
//srch1 is a simple linear search function, repeat in srchAll till all found
//srch1 Input->sentence, pattern, start position Output-> position found
//Remember arrays start at index/position 0
//srchAll Input->sentence, pattern Output->position array
int  srch1(const char [],const char [],int);//Search for 1 occurrence
void srchAll(const char [],const char [],int []);//Search for all occurrences
void print(const char []);//Print the character arrays
void print(const int []); //Print the array of indexes where the pattern found

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int LINE=81;               //Size of sentence or pattern to find
    char sntnce[LINE],pattern[LINE]; //80 + null terminator
    int match[LINE];                 //Index array where pattern was found
    
    //Input a sentence and a pattern to match
    cout<<"Match a pattern in a sentence."<<endl;
    cout<<"Input a sentence"<<endl;
    cin.getline(sntnce,LINE);
    cout<<"Input a pattern."<<endl;
    cin.getline(pattern,LINE);
    
    //Search for the pattern
    //Input the sentence and pattern, Output the matching positions
    //Remember, indexing starts at 0 for arrays.
    srchAll(sntnce,pattern,match);
    
    //Display the inputs and the Outputs
    cout<<endl<<"The sentence and the pattern"<<endl;
    print(sntnce);
    print(pattern);
    cout<<"The positions where the pattern matched"<<endl;
    print(match);
    
    //Exit
    return 0;
}

void srchAll(const char sen[],const char pat[],int posM[]){//Search for all occurrences
    int senL=strlen(sen);   //Length of sentence char array
    int patL=strlen(pat);   //Length of pattern char array
    string strS = "";       //Empty string for sentence char array
    string strP = "";       //Empty string for pattern char array
    bool match = false;     //bool Variable for matches, stays false if there are no matches
    int indx=0;
    
    for ( int i=0; i<senL; i++){
        strS+=sen[i];   //Transfers sentence array into string
    }
    for ( int i=0; i<patL; i++){
        strP+=pat[i];   //Transfers pattern array into string
    }
    
    for (int i=0; i<strS.length(); i++){
        if(strS.substr(i, strP.length()) == strP ){
            posM[indx]=i;
            indx++;
            match=true;
        }
    }
    if (match == false){
        posM[0]=-1;
    }
        
}

void print(const char array[]){ //Print the character arrays
    cout << array << endl;
}

void print(const int pos[]){    //Print the array of indexes where the pattern found
    int size = sizeof(pos) / sizeof(pos[0]);
    
    if ( pos[0] == -1 ){
        cout << "None" << endl;
    }
    else if ( size == 1){
        cout << pos[0] << endl;
    }
    else{
        for( int i=0; i<size; i++){
        cout << pos[i] << endl;
        }
    }
}

//int srch1(const char sen[],const char pat[],int pos1){//Search for 1 occurrence, use this for srchALL 
//    //for (int i=0; i<strlen(sen); i++){
//      //  for(int ii=0; ii<strlen(pat); ii++){
//        //    if (strcmp(pat,sen) == 0){
//            //}
//        //}
//    //}
//    return pos1;   //Return the number of times the value was found
//}
//
//void srchAll(const char sen[],const char pat[],int posM[]){//Search for all occurrences
//    int pindx=0;
//    bool match = true;
//    int size = strlen(sen);
//    int sizep = strlen(pat);
//    for (int i=0; i<size; i++){
//        if (sen[i]==pat[0]){
//            int index=0;    
//            while(match==true){
//                if (sen[i+index]==pat[0+index]){
//                    index++;
//                    match=true;
//                    if (index==sizep){    //index is 
//                        posM[pindx]=i;
//                        pindx++;
//                        match=false;
//                    }
//                } else{ match=false; }
//            }
//        }
//        else{(posM[0]=-0);} //No matches found
//    }
//}
//
//void print(const char array[]){//Print the character arrays
//    cout << array << endl;
//}
//
//void print(const int pos[]){ //Print the array of indexes where the pattern found
//    if ( pos[0] == -0 ){
//        cout << "None" << endl;
//    }
//    else{
//        int size = sizeof pos / sizeof pos[0] ;
//        for( int i=0; i<size; i++){
//        cout << pos[i] << endl;
//        }
//    }
//}
