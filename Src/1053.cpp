#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN=101;

struct TreeNode{
    int id;
    int w;
    vector<int> childs;
}node[MAXN];

int N,M,S;

//½µÐò
bool comparison(vector<int> &A, vector<int> &B){
    for(int i=0; i<min(A.size(), B.size()); i++){
        if(node[A[i]].w != node[B[i]].w){
            return node[A[i]].w > node[B[i]].w;
        }
    }
    return A.size() > B.size();
}


vector<vector<int> > res;
void DFS(int root, int weight, vector<int> &path){
    weight += node[root].w;
    path.push_back(root);
    //Ò¶×Ó
    if(node[root].childs.empty()){
        if(weight == S){
            res.push_back(path);
        }
    }
    //·ÇÒ¶
    else{
        for(int i=0; i<node[root].childs.size(); i++){
            DFS(node[root].childs[i], weight, path);
        }
    }
    path.pop_back();
    return;
}

int main(){
    cin >> N >> M >> S;
    for(int i=0; i<N; i++){
        cin >> node[i].w;
    }
    for(int i=0; i<M; i++){
        int id,K;
        cin >> id >> K;
        for(int j=0; j<K; j++){
            int child;
            cin >> child;
            node[id].childs.push_back(child);
        }
    }
    //input end
    int root = 0;
    vector<int> path;
    DFS(root, 0, path);
    //ÅÅÐò
    sort(res.begin(), res.end(), comparison);

    //output
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            if(j>0){
                cout << " ";
            }
            cout << node[res[i][j]].w;
        }
        cout << endl;
    }

    return 0;
}

