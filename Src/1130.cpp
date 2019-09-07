#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;
const int MAXN=21;
int not_root[MAXN];

int N;
struct TreeNode{
    string val;
    int type;
    int right;
    int left;
}nodes[MAXN];

int g_root;
string DFS(int root){
    if(root == -1){
        return "";
    }
    //Ò¶×Ó
    if(nodes[root].left==-1&&nodes[root].right==-1){
        return nodes[root].val;
    }
    string L = DFS(nodes[root].left);
    string R = DFS(nodes[root].right);
    if(g_root == root){
        return L+nodes[root].val+R;
    }
    return "("+L+nodes[root].val+R+")";
}


int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        string data;
        int left, right;
        cin >> data >> left >> right;
        not_root[left]=not_root[right]=1;
        nodes[i].val = data;
        nodes[i].left = left;
        nodes[i].right = right;
    }
    g_root=-1;
    for(int i=1; i<=N; i++){
        if(!not_root[i]){
            g_root = i;
            break;
        }
    }
    //ÕÒµ½root
    string res=DFS(g_root);
    cout << res;
    return 0;
}
