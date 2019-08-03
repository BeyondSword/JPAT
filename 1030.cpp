#include<iostream>
#include<queue>
#include<stdio.h>
//adjacent matrix + priority_queue
using namespace std;

const int MAXN=501;
const int INF=0x3fffffff;

int dp[MAXN];
int cost[MAXN];
int G[MAXN][MAXN];
int C[MAXN][MAXN];

class  comparison{
public:
    bool operator()(int &a, int &b){
        return dp[a] > dp[b];
    }
};
priority_queue<int, vector<int>, comparison> pq;
bool vis[MAXN];
int before[MAXN];
int N,M,S,D;
void djikstra(int s){
    dp[s] = 0;
    pq.push(s);
    for(int i=0; i<N; i++){
        int indice = pq.top();
        pq.pop();
        if(dp[indice] == INF){
            break;
        }
        vis[indice] = true;
        for(int j=0;j<N;j++){
            if(vis[j]==true||G[indice][j]==INF){
                continue;
            }
            if(dp[j] > dp[indice]+G[indice][j]){
                dp[j] = dp[indice]+G[indice][j];
                //update cost
                cost[j] = cost[indice] + C[indice][j];
                before[j] = indice;
                //
                pq.push(j);
            }
            else if(dp[j] == dp[indice]+G[indice][j]){
                if(cost[j] > cost[indice] + C[indice][j]){
                    cost[j] = cost[indice] + C[indice][j];
                    before[j] = indice;
                }
            }
        }
    }
}


int main(){
        fill(vis, vis+MAXN, false);
        fill(G[0], G[0]+MAXN*MAXN, INF);
        fill(C[0], C[0]+MAXN*MAXN, INF);
        fill(dp, dp+MAXN, INF);
        fill(before, before+MAXN, -1);
        cin >> N >> M >> S >> D;
        for(int i=0; i<M; i++){
            int u,v,dist,cos;
            cin>>u>>v>>dist>>cos;
            G[u][v] = G[v][u] = dist;
            C[u][v] = C[v][u] = cos;
        }
        //input end
        djikstra(S);
        vector<int> res;
        int node=D;
        while(node != -1){
            res.push_back(node);
            node = before[node];
        }
        for(int i=res.size()-1;i>=0;i--){
            printf("%d", res[i]);
            if(i>0){
                printf(" ");
            }
        }
        printf(" %d %d",dp[D],cost[D]);
        return 0;
}
