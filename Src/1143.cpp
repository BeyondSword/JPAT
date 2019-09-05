#include<iostream>
#include<vector>
#include<stdio.h>
#include<map>
const int MAXN=10001;

using namespace std;

struct treeNode{
    int val;
    int left;
    int right;
}nodes[MAXN];
int g_cnt;

map<int, int> in;
int create(int root, int tar){
    if(root == -1){
        root = g_cnt;
        g_cnt++;
        nodes[root].val = tar;
        nodes[root].left = nodes[root].right = -1;
        return root;
    }

    if(tar < nodes[root].val){
        nodes[root].left = create(nodes[root].left, tar);
    }
    else{
        nodes[root].right = create(nodes[root].right, tar);
    }
    return root;
}

int M,N;
int LCA;

void find_double(int root, int U, int V){
    if(nodes[root].val == U){
        LCA = U;
        printf("%d is an ancestor of %d.\n", U, V);
    }
    else if(nodes[root].val == V){
        LCA = V;
        printf("%d is an ancestor of %d.\n", V, U);
    }
    else{
        if(U < nodes[root].val && V < nodes[root].val){
            find_double(nodes[root].left, U, V);
        }
        else if(U >= nodes[root].val && V >= nodes[root].val){
            find_double(nodes[root].right, U, V);
        }
        else{
            printf("LCA of %d and %d is %d.\n", U, V, nodes[root].val);
        }
    }
    return;
}



int main(){
    //cin >> M >> N;
    scanf("%d%d", &M, &N);
    int root=-1;
    for(int i=0; i<N; i++){
        int key;
        //cin >> key;
        scanf("%d", &key);
        root = create(root, key);
        in[key] = 1;
    }
    for(int i=0; i<M; i++){
        int U,V;
        //cin >> U >> V;
        scanf("%d%d", &U, &V);
        //bool find_u=false,find_v=false;

        if(!in.count(U)&&!in.count(V)){
            printf("ERROR: %d and %d are not found.\n", U,V);
        }
        else{
            if(!in.count(U)){
                printf("ERROR: %d is not found.\n", U);
            }
            else if(!in.count(V)){
                printf("ERROR: %d is not found.\n", V);
            }
            else{
                find_double(root, U, V);
            }
        }
    }
    return 0;
}
