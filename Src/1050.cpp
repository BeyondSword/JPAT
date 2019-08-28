#include<iostream>
#include<stdio.h>
using namespace std;

int ch_hash[1000];

int main(){
    string S1,S2;
    getline(cin, S1);

    getline(cin, S2);
    for(int i=0; i<S2.size(); i++){
        ch_hash[S2[i]]++;
    }

    for(int i=0; i<S1.size(); i++){
        if(!ch_hash[S1[i]]){
            printf("%c", S1[i]);
        }
    }
    return 0;
}
