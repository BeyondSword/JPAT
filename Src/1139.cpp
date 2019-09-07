#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

const int MAXN=301;
const int INF=0x3fffffff;
int N,M;

struct Per{
    int id;
    int gender;
}per[MAXN];
int g_cnt;

int id2indi[11111];

int G[MAXN][MAXN];
int vis[MAXN];

int S,D;
int s_id, d_id;
vector<vector<int> > res;

bool cmp(vector<int> &A, vector<int> &B){
    if(A[0] == B[0]){
        return A[1] < B[1];
    }
    return A[0] < B[0];
}

void DFS(int root, int depth, vector<int> &path){
    if(3 == depth && root == D){
        res.push_back(path);
    }
    vis[root] = 1;
    if(depth == 1 || depth == 2){
        path.push_back(abs(per[root].id));
    }

    for(int i=0; i<N; i++){
        //找与root同性,同性一直找同性
        if(((s_id>=0&&d_id>=0)||(s_id<0&&d_id<0))||(depth == 0 || depth == 2)){
            if(((per[root].id>=0&&per[i].id>=0)||(per[root].id<0&&per[i].id<0))&&!vis[i]){
                if(G[root][i] != INF){
                    DFS(i, depth+1, path);
                }
            }
        }
        //找与root异性?
        else if(depth == 1){
            if(((per[root].id>=0&&per[i].id<0)||(per[root].id<0&&per[i].id>=0))&&!vis[i]){
                if(G[root][i] != INF){
                    DFS(i, depth+1, path);
                }
            }
        }

    }
    vis[root] = 0;
    if(depth == 1 || depth == 2){
        path.pop_back();
    }
    return;
}

void output(){
    cout << res.size() << endl;
    for(int i=0; i<res.size(); i++){
        cout << res[i][0] << " " << res[i][1] << endl;
    }
    return;
}

int main(){
    fill(id2indi, id2indi+11111, -1);
    for(int i=0; i<MAXN; i++){
        fill(G[i], G[i]+MAXN, INF);
    }

    cin >> N >> M;
    for(int i=0; i<M; i++){
        int id1,id2;
        cin >> id1 >> id2;
        if(id2indi[abs(id1)] == -1){
            per[g_cnt].id = id1;
            id2indi[abs(id1)] = g_cnt;
            g_cnt++;
        }
        if(id2indi[abs(id2)] == -1){
            per[g_cnt].id = id2;
            id2indi[abs(id2)] = g_cnt;
            g_cnt++;
        }
        id1 = abs(id1);
        id2 = abs(id2);
        //建立关系
        G[id2indi[id1]][id2indi[id2]] = G[id2indi[id2]][id2indi[id1]] = 1;
    }
    int K;
    cin >> K;
    for(int i=0; i<K; i++){
        cin >> s_id >> d_id;
        //s_id = abs(s_id);
        //d_id = abs(d_id);
        S = id2indi[abs(s_id)];
        D = id2indi[abs(d_id)];
        if(S == -1 || D == -1){
            cout << "0";
            continue;
        }
        vector<int> path;
        DFS(S, 0, path);
        sort(res.begin(), res.end(), cmp);
        output();
        res.clear();
    }
    return 0;
}
