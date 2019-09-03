#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
const int MAXN=201;

int G[MAXN][MAXN];
int vis[MAXN];
const int INF = 0x7fffffff;


int N,M,K;
vector<int> path;

bool traverse(int s){
    int cur = s;
    for(int i=1; i<path.size(); i++){
        //路走不通，返回
        if(G[cur][path[i]] == INF){
            return false;
        }
        vis[path[i]] ++;
        cur = path[i];
    }
    //没有回到出发点
    if(cur != s){
        return false;
    }
    for(int i=1; i<=N; i++){
        //有点走了不止一次 || 有点没有走
        if(vis[i] != 1){
            return false;
        }
    }
    return true;
}


int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        fill(G[i], G[i]+MAXN, INF);
    }

    for(int i=0; i<M; i++){
        int u,v;
        cin >> u >> v;
        G[u][v] = G[v][u] = 1;
    }
    cin >> K;
    for(int i=0; i<K; i++){
        int n;
        cin >> n;
        path.clear();
        for(int j=0; j<n; j++){
            int vertex;
            cin >> vertex;
            path.push_back(vertex);
        }
        //路径输入完,初始化
        fill(vis, vis+MAXN, 0);

        //无路可走 N>2
        if(path.size() <= 2){
            printf("NO\n");
            continue;
        }
        if(traverse(path[0])){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }

    return 0;
}
