#include<iostream>
#include<queue>
#include<stdio.h>

using namespace std;

const int MAXN=1001;
const int MAXM=10;
const int INF=0x3fffffff;
//test 3 failed => mei kao lv jiayouzhan > Ds de qingkuang
int N,M,K,Ds;
vector<vector<int> > G;
int dp[MAXN+MAXM];
bool vis[MAXN+MAXM];

class comparison{
public:
    bool operator()(int &a, int &b){
        return dp[a] > dp[b];
    }
};

priority_queue<int, vector<int>, comparison> pq;

int g_min_dist;
int g_sum_dist;
int g_index;

bool djikstra(int s){
    dp[s] = 0;
    pq.push(s);

    bool ok = true;

    int sum_dist=0;
    //for(int i=0; i<N+M; i++){
    //while(!pq.empty()&&dp[pq.top()]!=INF){
        /*int indice = pq.top();
        pq.pop();*/

    for(int i=0; i<M+N; i++){
        int indice = -1;
        int Min = INF;
        for(int j=0; j<M+N; j++){
            if(vis[j]==false && Min>dp[j]){
                indice = j;
                Min = dp[j];
            }
        }

        if(indice == -1){
            if(indice<N){
                ok = false;
            }
            break;
        }
        if(dp[indice] > Ds&&indice<N){
            ok = false;
            break;
        }
        if(indice<N){
            sum_dist+=dp[indice];
        }
        vis[indice] = true;
        for(int j=0; j<N+M; j++){
            if(vis[j]==true || G[indice][j] == INF){
                continue;
            }
            if(dp[j] > dp[indice] + G[indice][j]){
                dp[j] = dp[indice] + G[indice][j];
            }
        }
    }

    if(ok == false){
        return ok;
    }

    int min_dist=INF;
    for(int i=0; i<N; i++){
        if(min_dist>dp[i]){
            min_dist = dp[i];
        }
    }
    //find
    if(min_dist > g_min_dist){
        g_min_dist = min_dist;
        g_index = s;
        g_sum_dist = sum_dist;
    }
    else if(min_dist == g_min_dist){
        if(g_sum_dist > sum_dist){
            g_sum_dist = sum_dist;
            g_index = s;
        }
    }
    return ok;
}

int convert2indi(string s){
    int num=0;
    if(s[0] == 'G'){
        for(int i=1; i<s.size(); i++){
            num = num*10+s[i]-'0';
        }
        return num-1+N;
    }
    else{
        for(int i=0; i<s.size(); i++){
            num = num*10+s[i]-'0';
        }
        return num-1;
    }
}

int main(){
    cin>>N>>M>>K>>Ds;

    //initialize
    vector<int> tmp(N+M, INF);
    G.resize(N+M, tmp);

    for(int i=0; i<K; i++){
        string c1,c2;
        int len;
        cin >> c1 >> c2 >> len;
        int u,v;
        u = convert2indi(c1);
        v = convert2indi(c2);
        G[u][v] = G[v][u] = len;
    }
    //input end
    //int start = N;
    bool flag = false;
    for(int i=N; i<N+M; i++){
        fill(dp, dp+N+M, INF);
        fill(vis, vis+N+M, false);
        flag |= djikstra(i);
    }

    if(flag == true){
        cout << "G" << g_index+1-N << endl;
        printf("%.1f %.1f", (float)g_min_dist, (float)(g_sum_dist)/N);
    }
    else{
        printf("No Solution");
    }
    return 0;
}
