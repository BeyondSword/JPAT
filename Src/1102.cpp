#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

const int MAXN = 11;

int not_root[MAXN];
struct treeNode{
    int val;
    int left;
    int right;
}nodes[MAXN];

void invert(int root){
    if(root == -1)
        return;
    invert(nodes[root].left);
    invert(nodes[root].right);
    int tmp = nodes[root].left;
    nodes[root].left = nodes[root].right;
    nodes[root].right = tmp;
    //swap(nodes[root].left, nodes[root].right);
    return;
}

int ok=0;
void DFS(int root){
    if(root == -1){
        return;
    }
    DFS(nodes[root].left);
    if(ok == 1)
        cout << " ";
    cout << nodes[root].val;
    ok=1;
    DFS(nodes[root].right);
    return;
}

int main(){
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        char l,r;
        cin >> l >> r;
        if(l == '-'){
            nodes[i].left = -1;
        }
        else{
            nodes[i].left = l-'0';
            not_root[l-'0']++;
        }

        if(r == '-'){
            nodes[i].right = -1;
        }
        else{
            nodes[i].right = r-'0';
            not_root[r-'0']++;
        }
        nodes[i].val = i;
    }

    //find root
    int root;
    for(int i=0; i<N; i++){
        if(not_root[i] == 0){
            root = i;
            break;
        }
    }
    invert(root);
    //BFS
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int n= q.front();
        q.pop();
        if(n != root)
            cout << " ";
        cout << nodes[n].val;
        if(nodes[n].left!=-1){
            q.push(nodes[n].left);
        }
        if(nodes[n].right!=-1){
            q.push(nodes[n].right);
        }
    }
    cout << endl;
    DFS(root);
    return 0;
}
