#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;
const int MAXN=101;
const int INF=0x7fffffff;
int line[MAXN*MAXN];
int st[MAXN*MAXN];
int vis[MAXN*MAXN];
int dp[MAXN*MAXN];
int pre[MAXN*MAXN];
int swi[MAXN*MAXN];

//vector<int> G[MAXN*MAXN];

int id2indi[MAXN*MAXN];
int indi2id[MAXN*MAXN];
int G[MAXN][MAXN];
int g_cnt=1;

int N,M,K;

//换乘是否一定要用DFS来比较?不用试试看(估计会有问题)
void dijkstra(int S){
    fill(vis, vis+MAXN*MAXN, 0);
    fill(dp, dp+MAXN*MAXN, INF);
    fill(pre, pre+MAXN*MAXN, INF);
    fill(swi, swi+MAXN*MAXN, INF);

    dp[S] = 0;
    for(int i=0; i<MAXN; i++){
        int index=-1;
        for(int j=0; j<MAXN; j++){
            if(!vis[j]){
                if(index==-1 || dp[j] < dp[index]){
                    index = j;
                }
            }
        }
        vis[index] = 1;
        for(int j=0; j<MAXN; j++){
            if(!vis[j]){
                if(dp[index] + G[index][j] < dp[j]){
                    dp[j] = dp[index] + G[index][j];
                }
                else if(dp[index] + G[index][j] == dp[j]){

                }
            }
        }
    }
}

//10000*10000太慢
int main(){
    scanf("%d", &N);
    fill(id2indi, id2indi+MAXN*MAXN, -1);
    for(int i=0; i<MAXN; i++){
        fill(G[i], G[i]+MAXN, INF);
    }

    for(int i=1; i<=N; i++){
        scanf("%d", &M);
        int u,v;
        scanf("%d", &id_u);
        //判断是否已经出现过
        if(id2indi[id_u] == -1){
            id2indi[id_u] = g_cnt;
            indi2id[g_cnt] = id_u;
            g_cnt++;
        }
        u = id2indi[id_u];
        for(int j=2; j<=M; j++){
            scanf("%d", &id_v);
            if(id2indi[id_v] == -1){
                id2indi[id_v] = g_cnt;
                indi2id[g_cnt] = id_v;
                g_cnt++;
            }
            v = id2indi[id_v];
            G[u][v] = G[v][u] = 1;

            /*
            G[u].push_back(v);
            G[v].push_back(u);
            //scanf("%d", &st[i][j]);
            u = v;
            if(!line[u]){
                line[u] = i;
            }
            if(!line[v]){
                line[v] = i;
            }*/
            //处理环站?
        }
    }
    scanf("%d", &K);
    for(int i=0; i<K; i++){
        int S,D;
        int s_id, d_id;
        scanf("%d%d",&s_id,&d_id);
        S = id2indi[s_id];
        D = id2indi[d_id];
        dijkstra(S);
    }
}
