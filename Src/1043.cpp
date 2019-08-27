#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int MAXN=1001;
int N;
int pre[MAXN];
int in[MAXN];

struct TreeNode{
    int val;
    int left;
    int right;
}node[MAXN];

int g_index=0;
int g_cnt=0;

//前中重建树,前闭后开
int recreate(int s_pre, int e_pre, int s_in, int e_in){
    if(s_pre >= e_pre){
        return -1;
    }
    //根
    int root_val = pre[s_pre];
    int root;

    int index = s_in;
    bool ok = true;

    //左子树全小于根，右子树全大于等于根
    while(in[index] != root_val){
        if(in[index] >= root_val){
            ok = false;
            break;
        }
        index++;
    }
    int offset = index;
    while(index < e_in){
        if(in[index] < root_val){
            ok=false;
            break;
        }
        index++;
    }

    //无法重建
    if(!ok){
        return -1;
    }
    //重建
    else{
        root = g_index;
        node[g_index].val = root_val;
        node[g_index].left = recreate(s_pre+1, s_pre+offset+1, s_in, s_in+offset);
        node[g_index].right = recreate(s_pre+offset+1, e_pre, s_in+offset+1, e_in);
        g_cnt ++;
        g_index ++;
    }
    return root;
}

vector<int> res;
void post_traverse(int root){
    if(root == -1){
        return;
    }
    post_traverse(node[root].left);
    post_traverse(node[root].right);
    res.push_back(node[root].val);
    return;
}

int main(){
    int ok=1;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> pre[i];
        in[i] = pre[i];
    }
    //BST
    sort(in, in+N);

    int root = recreate(0, N, 0, N);
    //重建失败
    if(g_cnt < N){
        ok = 0;
    }
    else{
        //后序遍历
        cout << "YES";
        post_traverse(root);
        for(int i=0; i<res.size(); i++){
            if(i>0){
                cout << " ";
            }
            cout << res[i];
        }
        return 0;
    }

    g_cnt = 0;
    //mirror BST
}

