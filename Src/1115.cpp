#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
const int MAXN=1001;

vector<int> v_dep;

struct TreeNode{
    int val;
    int left;
    int right;
    int depth;
}nodes[MAXN];
int g_cnt;

int create_BST(int root, int tar, int depth){
    if(root == -1){
        int in = g_cnt;
        g_cnt++;
        nodes[in].val = tar;
        nodes[in].left = nodes[in].right = -1;
        if(v_dep.size() < depth+1){
            v_dep.push_back(1);
        }
        else{
            v_dep[depth]++;
        }
        return in;
    }
    if(nodes[root].val >= tar){
        nodes[root].left = create_BST(nodes[root].left, tar, depth+1);
    }
    else{
        nodes[root].right = create_BST(nodes[root].right, tar, depth+1);
    }
    return root;
}

int N;
int main(){
    int root = -1;
    cin >> N;
    for(int i=0; i<N; i++){
        int target;
        cin >> target;
        root = create_BST(root, target, 0);
    }
    //输出最后两层
    int n1 = 0;
    int n2 = 0;
    if(v_dep.size()>=1){
        n1 = *(v_dep.end()-1);
    }
    if(v_dep.size()>=2){
        n2 = *(v_dep.end()-2);
    }
    printf("%d + %d = %d", n1, n2, n1+n2);
    return 0;
}
