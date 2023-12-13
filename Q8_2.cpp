#include<bits/stdc++.h>
using namespace std;
void towerOfHanoi(char s,char d,char h,int disc){
    if(disc==1){
        cout<<"Disc "<<disc<<" moves from "<<s<<" to "<<d<<endl;
    }
    else{
        towerOfHanoi(s,h,d,disc-1);
        cout<<"Disc "<<disc<<" moves from "<<s<<" to "<<d<<endl;
        towerOfHanoi(h,d,s,disc-1);
    }
}
int main(){
    char source='A',destination='C',helper='B';
    int disc;
    cout<<"Enter the number of disk "<<endl;
    cin>>disc;
    towerOfHanoi(source,destination,helper,disc);
    return 0;
}