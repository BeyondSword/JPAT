#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

const int MAXN=201;
const int INF=0x7fffffff;

int G[MAXN][MAXN];
int vis[MAXN];


int N,M;
vector<int> path;

int g_closest = INF;
int g_indi;
int traverse(int index){
    if(path.size() <= 1){
        printf("Path %d: 0 (Not a TS cycle)\n", index);
        return 0;
    }
    int s = path[0];
    int cur = path[0];
    int tot = 0;
    int ok = 1;
    for(int i=1; i<path.size(); i++){
        if(G[cur][path[i]] == INF){
            ok=0;
            break;
        }
        tot += G[cur][path[i]];
        vis[path[i]] ++;
        cur = path[i];
    }
    //不可达
    if(ok == 0){
        printf("Path %d: NA (Not a TS cycle)\n", index);
    }
    //可达
    else{
        //不成环,没回到起点
        if(cur != s){
            printf("Path %d: %d (Not a TS cycle)\n", index, tot);
        }
        else{
            int not_simple = 0;
            int not_cycle = 0;
            for(int i=1; i<=N; i++){
                if(vis[i] == 0){
                    not_cycle = 1;
                }
                else if(vis[i] > 1){
                    not_simple = 1;
                }
            }
            if(not_cycle){
                printf("Path %d: %d (Not a TS cycle)\n", index, tot);
            }
            else{
                if(not_simple){
                    printf("Path %d: %d (TS cycle)\n", index, tot);
                }
                else{
                    printf("Path %d: %d (TS simple cycle)\n", index, tot);
                }
                //更新最短路径
                if(tot < g_closest){
                    g_indi = index;
                    g_closest = tot;
                }
            }
        }
    }
    return tot;
}

int main(){
    for(int i=0; i<MAXN; i++){
        fill(G[i], G[i]+MAXN, INF);
    }
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int u,v,len;
        cin >> u >> v >> len;
        G[u][v] = G[v][u] = len;

    }
    int K;
    cin >> K;
    for(int i=1; i<=K; i++){
        path.clear();
        int n;
        cin >> n;
        for(int j=0; j<n; j++){
            int city;
            cin >> city;
            path.push_back(city);
        }
        //path 输入完
        fill(vis, vis+MAXN, 0);
        traverse(i);
    }
    printf("Shortest Dist(%d) = %d", g_indi, g_closest);
    return 0;
}
