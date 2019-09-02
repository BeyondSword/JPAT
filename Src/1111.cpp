#include<iostream>
#include<vector>
#include<stdio.h>
//先用临界矩阵

const int MAXN = 501;
int G[MAXN][MAXN];
int Time[MAXN][MAXN];
int len[MAXN][MAXN];

int dp_time[MAXN];
int dp_len[MAXN];
const int INF = 0x7fffffff;
int vis[MAXN];

//有单向,能用dijkstra么？
int pre_time[MAXN];
int pre_len[MAXN];
int node_num[MAXN];

int path_time[MAXN];
int S,D;


int N,M;

void len_djikstra(int S, int* dp, int* pre){
    dp[S] = 0;
    dp_time[S] = 0;
    for(int i=0; i<N; i++){
        int index=-1;
        //找最小值
        for(int j=0; j<N; j++){
            if(!vis[j]&&(index==-1 || dp[j] < dp[index])){
                index = j;
            }
        }
        vis[index] = 1;
        for(int j=0; j<N; j++){
            if(vis[j]==0 && len[index][j] != INF){
                //松弛
                if(dp[index] + len[index][j] < dp[j]){
                    dp[j] = dp[index] + len[index][j];
                    dp_time[j] = dp_time[index] + Time[index][j];
                    pre[j] = index;
                }
                //更新路径，距离不变
                else if(dp[index] + len[index][j] == dp[j]){
                    if(dp_time[index] + Time[index][j] < dp_time[j]){
                        dp_time[j] = dp_time[index] + Time[index][j];
                        pre[j] = index;
                    }
                }
            }
        }
    }
    return;
}

void time_djikstra(int S, int* dp, int* pre){
    dp[S] = 0;
    std::fill(node_num, node_num+MAXN, INF);
    node_num[S] = 1;
    for(int i=0; i<N; i++){
        int index=-1;
        //找最小值
        for(int j=0; j<N; j++){
            if(!vis[j] && (index==-1 || dp[j] < dp[index])){
                index = j;
            }
        }
        vis[index] = 1;
        for(int j=0; j<N; j++){
            if(vis[j]==0 && Time[index][j] != INF){
                //松弛会使节点变多
                if(dp[index] + Time[index][j] < dp[j]){
                    dp[j] = dp[index] + Time[index][j];
                    node_num[j] = node_num[index] + 1;
                    pre[j] = index;
                }
                else if(dp[index] + Time[index][j] == dp[j]){
                    if(node_num[index] + 1 < node_num[j]){
                        node_num[j] = node_num[index] + 1;
                        pre[j] = index;
                    }
                }
            }
        }
    }
}

void output_path(int dist, int Time){
    std::vector<int> time_path;
    std::vector<int> dist_path;
    int time_indi = D;
    int dist_indi = D;
    int same = 1;
    while(time_indi != -1 && dist_indi != -1){
        if(time_indi != dist_indi){
            same = 0;
        }
        time_path.push_back(time_indi);
        time_indi = pre_time[time_indi];
        dist_path.push_back(dist_indi);
        dist_indi = pre_len[dist_indi];
    }
    while(time_indi != -1){
        same = 0;
        time_path.push_back(time_indi);
        time_indi = pre_time[time_indi];
    }
    while(dist_indi != -1){
        same = 0;
        dist_path.push_back(dist_indi);
        dist_indi = pre_len[dist_indi];
    }
    if(same == 0){
        printf("Distance = %d: ", dist);
        for(int i=dist_path.size()-1; i>=0; i--){
            if(i < dist_path.size()-1){
                printf(" -> ");
            }
            printf("%d", dist_path[i]);
        }
        printf("\n");
        printf("Time = %d: ", Time);
        for(int i=time_path.size()-1; i>=0; i--){
            if(i < time_path.size()-1){
                printf(" -> ");
            }
            printf("%d", time_path[i]);
        }
    }
    else{
        printf("Distance = %d; Time = %d: ", dist, Time);
        for(int i=dist_path.size()-1; i>=0; i--){
            if(i < dist_path.size()-1){
                printf(" -> ");
            }
            printf("%d", dist_path[i]);
        }
        printf("\n");
    }
    return;
}


int main(){
    std::cin >> N >> M;
    for(int i=0; i<N; i++){
        std::fill(G[i], G[i]+N, INF);
        std::fill(Time[i], Time[i]+N, INF);
        std::fill(len[i], len[i]+N, INF);
    }
    for(int i=0; i<M; i++){
        int u,v,one,l,t;
        std::cin >> u >> v >> one >> l >> t;
        G[u][v] = 1;
        Time[u][v] = t;
        len[u][v] = l;
        if(one != 1){
            G[v][u] = G[u][v];
            Time[v][u] = Time[u][v];
            len[v][u] = len[u][v];
        }
    }
    std::cin >> S >> D;
    std::fill(pre_time, pre_time+N, -1);
    std::fill(pre_len, pre_len+N, -1);
    std::fill(vis, vis+N, 0);
    std::fill(dp_time, dp_time+N, INF);
    std::fill(dp_len, dp_len+N, INF);
    len_djikstra(S, dp_len, pre_len);
    std::fill(dp_time, dp_time+N, INF);
    std::fill(vis, vis+N, 0);
    time_djikstra(S, dp_time, pre_time);
    output_path(dp_len[D], dp_time[D]);
    return 0;
}

