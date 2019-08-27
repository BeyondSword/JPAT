#include<iostream>
#include<stdio.h>

using namespace std;

const int MAXN=100001;
int length[MAXN];
int S[MAXN];

int main(){
    int N;
    scanf("%d", &N);
    int tot_dist=0;
    S[1] = 0;
    for(int i=1; i<=N; i++){
        scanf("%d", &length[i]);
        S[i+1] = S[i] + length[i];
        tot_dist += length[i];
    }
    //length i ±íÊ¾ i-1 - i
    int M;
    scanf("%d", &M);
    for(int i=0; i<M; i++){
        int c1, c2;
        scanf("%d%d", &c1, &c2);
        if(c1 > c2){
            swap(c1, c2);
        }
        //c1 < c2
        int dist = 0;
        /*
        for(int i=c1; i<c2; i++){
            dist += length[i];
        }*/
        dist = S[c2] - S[c1];
        if(dist*2 < tot_dist){
            printf("%d", dist);
        }
        else{
            printf("%d", tot_dist-dist);
        }
        printf("\n");
    }

    return 0;
}
