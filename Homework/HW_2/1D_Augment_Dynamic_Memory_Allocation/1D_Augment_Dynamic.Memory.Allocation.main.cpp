#include <iostream>

using namespace std;
int *getData(int &);//Read the array

int *augment(const int *,int);//Augment and copy the original array

void prntAry(const int *,int);//Print the array

int main(){
    int size=0;
    int *ptr=getData(size);
    int *ptrAug=augment(ptr,size);
    prntAry(ptr,size);
    cout << endl;
    prntAry(ptrAug, size+1);
    delete[] ptr;
	return 0;
}

int *getData(int &size){//Read the array
    cin >> size;
    
    int *ptr = new int [size];
    for (int i; i<size; i++){
        cin >> *(ptr+i);
    }
    return ptr;
}
int *augment(const int *ptr, int size){//Augment and copy the original array
    int *ptrAug= new int [size+1];
    
    ptrAug[0]=0;
    for (int i=0; i<size; i++){
        ptrAug[i+1]=ptr[i];
    }

    return ptrAug;
}
void prntAry(const int *ptr, int size){//Print the array
    for (int i=0; i<size; i++){
        if( i<(size-1) ){
            cout << ptr[i] << " "; 
        }
        else{ cout << ptr[i];}
    }

}