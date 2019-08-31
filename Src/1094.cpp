#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int MAXN=101;

struct treeNode{
    int depth;
    vector<int> childs;
}nodes[MAXN];

int cnt[MAXN];
int N,M;

int g_max=-1;
int g_depth=-1;
int main(){
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int id,K;
        cin >> id >> K;
        for(int j=0; j<K; j++){
            int children;
            cin >> children;
            nodes[id].childs.push_back(children);
        }
    }
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int root = q.front();
        int depth = nodes[root].depth;
        q.pop();
        cnt[depth]++;
        if(cnt[depth] > g_max){
            g_max = cnt[depth];
            g_depth = depth;
        }
        for(int i=0; i<nodes[root].childs.size(); i++){
            nodes[nodes[root].childs[i]].depth = depth+1;
            q.push(nodes[root].childs[i]);
        }
    }

    cout << g_max << " " << g_depth+1;
    return 0;
}

