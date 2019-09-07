#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

const int MAXN=10001;

struct Edge{
    int u;
    int v;
}edge[MAXN];
int g_cnt;


int in_set[MAXN];


int N,M;

void judge(){
    //±éÀúËùÓĞ±ß
    int ok=1;
    for(int i=0; i<g_cnt; i++){
        int u = edge[i].u;
        int v = edge[i].v;
        if(!in_set[u] && !in_set[v]){
            ok=0;
            break;
        }
    }
    if(ok == 0){
        printf("No\n");
    }
    else{
        printf("Yes\n");
    }
    return;
}

int main(){
    scanf("%d%d", &N, &M);
    for(int i=0; i<M; i++){
        int indi = g_cnt;
        g_cnt ++;
        scanf("%d%d", &edge[indi].u, &edge[indi].v);
    }
    int K,Nv;
    scanf("%d", &K);

    for(int i=0; i<K; i++){
        scanf("%d", &Nv);
        fill(in_set ,in_set+MAXN, 0);
        for(int j=0; j<Nv; j++){
            int num;
            scanf("%d", &num);
            in_set[num] = 1;
        }
        judge();
    }
    return 0;
}
