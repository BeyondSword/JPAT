#include<iostream>
#include<stdio.h>

using namespace std;

const int MAXN=100001;
int H1, H2, N;

struct Node{
    char Ch;
    int next;
}node[MAXN];

int main(){
    //cin >> H1 >> H2 >> N;
    scanf("%d %d %d", &H1, &H2, &N);
    for(int i=0; i<N; i++){
        int addr,next;
        char Ch;
        scanf("%d %c %d", &addr, &Ch, &next);
        node[addr].Ch = Ch;
        node[addr].next = next;
    }
    //input end

    int ok=0;
    int p1=H1, p2=H2;
    int alter_A=0, alter_B=0;
    while(p1!=-1){
        if(p1 == p2){
            ok=1;
            break;
        }
        p1 = node[p1].next;
        p2 = node[p2].next;
        if(p1==-1&&alter_A==0){
            p1 = H2;
            alter_A=1;
        }
        if(p2==-1&&alter_B==0){
            p2 = H1;
            alter_B=1;
        }
    }
    if(ok == 1){
        printf("%05d", p1);
    }
    else{
        printf("-1");
    }

    return 0;
}
