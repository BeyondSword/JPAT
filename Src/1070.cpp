#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

const int MAXN=1001;

struct MoonCake{
    float amount;
    float price;
    float val;
}moon[MAXN];

bool comparison(struct MoonCake &A, struct MoonCake &B){
    return A.val > B.val;
}

int N;
float D;

int main(){
    cin >> N >> D;
    for(int i=0; i<N; i++){
        cin >> moon[i].amount;
    }
    for(int i=0; i<N; i++){
        cin >> moon[i].price;
        moon[i].val = moon[i].price*1000/moon[i].amount;
    }
    sort(moon, moon+N, comparison);
    float tot = 0.0;
    int p=0;
    while(D>0&&p<N){
        if(D >= moon[p].amount){
            D -= moon[p].amount;
            tot += moon[p].price;
        }
        else{
            tot += (float)D/(float)moon[p].amount*moon[p].price;
            D = 0;
        }
        p++;
    }

    printf("%.2f", tot);

    return 0;
}
