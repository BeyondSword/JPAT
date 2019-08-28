#include<iostream>
#include<stdio.h>

using namespace std;

struct Money{
    int G;
    int S;
    int K;
}m[2];

void add(struct Money &A, struct Money &B){
    int ci=0;
    int G,S,K;
    ci = (A.K+B.K+ci)/29;
    K = (A.K+B.K)%29;
    S = (A.S+B.S+ci)%17;
    ci = (A.S+B.S+ci)/17;
    G = A.G+B.G+ci;
    printf("%d.%d.%d",G,S,K);
    return;
}

int main(){
    for(int i=0; i<2; i++){
        scanf("%d.%d.%d", &m[i].G, &m[i].S, &m[i].K);
    }
    add(m[0], m[1]);
    return 0;
}
