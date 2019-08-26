#include<iostream>
#include<stdio.h>
using namespace std;


char Ch[14] = {'0','1','2','3','4','5','6','7','8','9','A','B','C'};

void cov(int num){
    int a = num%13;
    int b = (num/13)%13;
    printf("%c%c", Ch[b], Ch[a]);
}

int main(){
    int R,G,B;
    cin >> R >> G >> B;

    cout << "#";
    cov(R);
    cov(G);
    cov(B);
    return 0;
}
