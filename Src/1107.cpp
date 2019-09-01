#include<iostream>
#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;

const int MAXN=1001;

//每个人的爱好
vector<int> man[MAXN];
//每个爱好喜欢的人
vector<int> hobby[MAXN];
int father[MAXN];
int G[MAXN][MAXN];
int vis[MAXN];

int N;

int BFS(int s){
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    int cnt=0;
    while(!q.empty()){
        int n= q.front();
        q.pop();
        cnt++;
        for(int i=1; i<=N; i++){
            if(!vis[i]&&G[n][i]){
                vis[i] = 1;
                q.push(i);
            }
        }
    }
    return cnt;
}

bool cmp(int a, int b){
    return a>b;
}
//建图
int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        int K;
        scanf("%d:", &K);
        for(int j=0; j<K; j++){
            int hob;
            scanf("%d", &hob);
            for(int k=0; k<hobby[hob].size(); k++){
                G[i][hobby[hob][k]] = 1;
                G[hobby[hob][k]][i] = 1;
            }
            hobby[hob].push_back(i);
        }
    }
    //得到图,遍历图
    int g_cnt=0;
    vector<int> res;
    for(int i=1; i<=N; i++){
        if(!vis[i]){
            res.push_back(BFS(i));
            g_cnt++;
        }
    }
    sort(res.begin(), res.end(), cmp);
    cout << g_cnt << endl;
    for(int i=0; i<res.size(); i++){
        if(i>0)
            cout << " ";
        cout << res[i];
    }
    return 0;
}
