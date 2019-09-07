#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
const int MAXN = 11111;
int N,M;

vector<int> edge[MAXN];

vector<int> V(MAXN, -1);
//int color_cnt[MAXN];

bool judge(vector<int> C){
    for(int i=0; i<N; i++){
        int u=i;
        for(int j=0; j<edge[i].size(); j++){
            int v=edge[i][j];
            if(C[u] == C[v]){
                return false;
            }
        }
    }
    return true;
}
map<int, int> col;

int main(){
    scanf("%d%d", &N,&M);
    for(int i=0; i<M; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    int K;
    scanf("%d", &K);
    for(int i=0; i<K; i++){
        //fill(color_cnt, color_cnt+MAXN, 0);
        vector<int> v=V;
        col.clear();
        int color;
        int k=0;
        for(int j=0; j<N; j++){
            scanf("%d", &color);
            if(!col.count(color)){
                k++;
                col[color] = 1;
            }
            v[j] = color;
        }
        if(judge(v)){
            printf("%d-coloring\n", k);
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}
