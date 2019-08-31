#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int MAXN=101;
struct treeNode{
    int val;
    int left;
    int right;
}nodes[MAXN];
int N;
int seq[MAXN];
int indi;

void DFS(int root){
    if(root == -1){
        return;
    }
    DFS(nodes[root].left);
    nodes[root].val = seq[indi];
    indi ++;
    DFS(nodes[root].right);
    return;
}


int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        int left, right;
        cin >> left >> right;
        nodes[i].left = left;
        nodes[i].right = right;
    }
    for(int i=0; i<N; i++){
        cin >> seq[i];
    }
    sort(seq, seq+N);
    DFS(0);
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int n=q.front();
        q.pop();
        if(n != 0){
            cout << " ";
        }
        cout << nodes[n].val;
        if(nodes[n].left != -1){
            q.push(nodes[n].left);
        }
        if(nodes[n].right != -1){
            q.push(nodes[n].right);
        }
    }
    return 0;
}
