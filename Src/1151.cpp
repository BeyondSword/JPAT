#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

const int MAXN=10001;

int M,N;
int in[MAXN];
int pre[MAXN];

struct treeNode{
    int val;
    int left;
    int right;
}nodes[MAXN];
int g_cnt;

int create(int pre_s, int pre_e, int in_s, int in_e){
    if(pre_s >= pre_e){
        return -1;
    }
    int root_val = pre[pre_s];
    int root = g_cnt;
    g_cnt++;
    nodes[root].val = root_val;
    int offset=0;
    while(in[in_s+offset] != root_val){
        offset ++;
    }
    nodes[root].left = create(pre_s+1, pre_s+1+offset, in_s, in_s+offset);
    nodes[root].right = create(pre_s+1+offset, pre_e, in_s+offset+1, in_e);
    return root;
}

int first_found;
int LCA=-1;
void find_x(int root, int U, int V, bool &find_u, bool &find_v){
    if(root == -1){
        find_u = false;
        find_v = false;
        return;
    }
    bool found_UL=false;
    bool found_UR=false;
    bool found_VL=false;
    bool found_VR=false;

    find_x(nodes[root].left, U, V, found_UL, found_VL);
    find_x(nodes[root].right, U, V, found_UR, found_VR);

    /* 两个节点在不同的子树找到 */
    if((found_UL&&found_VR) || (found_UR&&found_VL)){
        LCA = nodes[root].val;
    }
    /* 当前子树找到某一节点 */
    if(nodes[root].val == U || nodes[root].val == V){
        LCA = nodes[root].val;
    }

    find_u = found_UL || found_UR || nodes[root].val == U;
    find_v = found_VL || found_VR || nodes[root].val == V;
    return;
}

int main(){
    cin >> M >> N;
    for(int i=0; i<N; i++){
        cin >> in[i];
    }
    for(int i=0; i<N; i++){
        cin >> pre[i];
    }

    int root = -1;
    root = create(0, N, 0, N);
    //重建树

    for(int i=0; i<M; i++){
        int U,V;
        cin >> U >> V;
        bool find_u=false, find_v=false;
        find_x(root, U, V, find_u, find_v);

        //output
        //都没找到
        if(!find_u && !find_v){
            printf("ERROR: %d and %d are not found.\n", U,V);
        }
        else if(!find_u || !find_v){
            if(!find_v){
                swap(U,V);
            }
            printf("ERROR: %d is not found.\n", U);
        }
        //全找到了
        else{
            if(LCA!=U && LCA!=V){
                printf("LCA of %d and %d is %d.\n", U, V, LCA);
            }
            else{
                if(LCA==V){
                    swap(U,V);
                }
                printf("%d is an ancestor of %d.\n", U, V);
            }
        }
    }
    return 0;
}
