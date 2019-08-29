#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;


int d[4];
bool comparison(int a, int b){
    return a>b;
}

int cov(){
    int sum=0;
    sum = d[0]*1000+d[1]*100+d[2]*10+d[3];
    return sum;
}

int main(){
    int N;
    cin >> N;
    do{
        d[0] = N/1000;
        d[1] = N%1000/100;
        d[2] = N%1000%100/10;
        d[3] = N%1000%100%10/1;
        sort(d, d+4);
        int small = cov();
        sort(d, d+4, comparison);
        int big = cov();
        printf("%04d - %04d = %04d\n", big, small, big-small);
        N = big-small;
    }while(N!=0 && N!=6174);

    return 0;
}

