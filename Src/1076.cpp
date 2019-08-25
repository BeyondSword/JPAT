#include<iostream>
#include<queue>
#include<vector>


using namespace std;

int N,L,K;
const int MAXN=1001;

int G[MAXN][MAXN];
int vis[MAXN];


queue<pair<int, int> > q;
//depth cnt
int BFS(int s){
    int cnt = 0;
    pair<int, int> p(s, 0);
    q.push(p);
    vis[p.first] = true;
    while(!q.empty()){
        pair<int, int> node = q.front();
        q.pop();

        if(node.second < L){
            for(int i=1; i<=N; i++){
                int u = node.first;
                if(G[u][i] && vis[i]==false){
                    pair<int, int> tmp(i, node.second+1);
                    q.push(tmp);
                    vis[i] = true;
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

int main(){
    cin >> N >> L;
    for(int i=1; i<=N; i++){
        int M, v=i;
        cin >> M;
        for(int j=0; j<M; j++){
            int u;
            cin >> u;
            G[u][v] = 1;
        }
    }
    cin >> K;
    for(int i=0; i<K; i++){
        int query;
        cin >> query;
        fill(vis, vis+MAXN, false);
        cout << BFS(query) << endl;
    }

    return 0;
}
