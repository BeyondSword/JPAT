#include<iostream>
#include<queue>
using namespace std;

const int MAXN=21;

struct treeNode{
    int height;
    int val;
    int left;
    int right;
}nodes[MAXN];
int cnt;

int comp_trees[MAXN];

int N;

int H(int root){
    return root==-1?0:nodes[root].height;
}

void update(int root){
    if(root != -1){
        nodes[root].height = max(H(nodes[root].left), H(nodes[root].right))+1;
    }
    return;
}

int right_rotation(int root){
    int left = nodes[root].left;
    nodes[root].left = nodes[left].right;
    nodes[left].right = root;
    update(root);
    update(left);
    return left;
}

int left_rotation(int root){
    int right = nodes[root].right;
    nodes[root].right = nodes[right].left;
    nodes[right].left = root;
    update(root);
    update(right);
    return right;
}

int left_right_rotation(int root){
    nodes[root].left = left_rotation(nodes[root].left);
    return right_rotation(root);
}

int right_left_rotation(int root){
    nodes[root].right = right_rotation(nodes[root].right);
    return left_rotation(root);
}


int create_tree(int root, int tar){
    if(root == -1){
        root = cnt;
        cnt++;
        nodes[root].left = nodes[root].right = -1;
        nodes[root].height = 1;
        nodes[root].val = tar;
        return root;
    }
    if(tar < nodes[root].val){
        nodes[root].left = create_tree(nodes[root].left, tar);
    }
    else{
        nodes[root].right = create_tree(nodes[root].right, tar);
    }
    //是否平衡
    //做高右低
    int L = nodes[root].left;
    int R = nodes[root].right;
    if(H(L) - H(R)>=2){
        int LL = nodes[L].left;
        int LR = nodes[L].right;
        if(H(LL) >= H(LR)){
            root = right_rotation(root);
        }
        else{
            root = left_right_rotation(root);
        }
    }
    else if(H(R) - H(L)>=2){
        int RR = nodes[R].right;
        int RL = nodes[R].left;
        if(H(RR) >= H(RL)){
            root = left_rotation(root);
        }
        else{
            root = right_left_rotation(root);
        }
    }
    update(root);
    return root;
}

int g_cnt;
void is_complete(int i, int root){
    if(i > N || root == -1){
        return;
    }
    comp_trees[i] = nodes[root].val;
    g_cnt++;
    is_complete(2*i, nodes[root].left);
    is_complete(2*i+1, nodes[root].right);
}

int main(){
    cin >> N;
    int root = -1;
    for(int i=0; i<N; i++){
        int tar;
        cin >> tar;
        root = create_tree(root, tar);
    }
    //建树结束
    //输出层序
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int n= q.front();
        q.pop();
        if(n != root)
            cout << " ";
        cout << nodes[n].val;
        if(nodes[n].left != -1){
            q.push(nodes[n].left);
        }
        if(nodes[n].right != -1){
            q.push(nodes[n].right);
        }
    }

    //判断是否完全二叉树
    cout << endl;
    is_complete(1, root);
    if(g_cnt == N){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}
