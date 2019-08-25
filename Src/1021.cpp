#include<iostream>


using namespace std;
const int MAXN = 20002;
int N;
int G[MAXN][MAXN];
bool vis[MAXN];

int g_cnt = 0;
int g_component = 1;
int g_root = 0;
bool g_loop;
int g_max_depth;
vector<int> res;

bool DFS(int s, int depth){
    bool is_loop = false;
    bool is_leaf = true;
    //g_cnt ++;
    //int height = 0;

    vis[s] = true;
    for(int i=1; i<=N; i++){
        if(i!=s && G[i][s] && G[s][i]){
            if(vis[i] == true){
                g_loop = true;
                continue;
            }
            //is_leaf = false;
            G[i][s] = G[s][i] = 0;
            DFS(i, depth+1);
            G[i][s] = G[s][i] = 1;
        }
    }

    if(is_leaf){
        /*
        if(depth > g_max_depth){
            g_max_depth = depth;
            res.clear();
            res.push_back(g_root);
        }
        else if(depth == g_max_depth){
            res.push_back(g_root);
        }*/
    }
    return is_loop;
}

int dfs(){

    if(is_leaf){

    }
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        int u,v;
        cin >> u >> v;
        G[u][v] = G[v][u] = 1;
    }
    //input end
    //root
    for(int i=1; i<=N; i++){
        fill(vis, vis+MAXN, false);
        g_cnt = 0;
        DFS(i, 0);//以i为root
        g_root = i;
        //非全连通或成环
        if(g_cnt < N || g_loop == true){
            for(int j=1; j<=N; j++){
                if(vis[j] == false){
                    DFS(j, 0);
                    g_component++;
                }
            }
            break;
        }
        //g_cnt++;
    }

    if(g_cnt < N || g_loop == true){
        printf("Error: %d components", g_component);
    }
    else{
        for(int i=0; i<res.size(); i++){
            cout << res[i] << endl;
        }
    }
}
