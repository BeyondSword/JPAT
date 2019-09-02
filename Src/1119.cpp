#include<iostream>
#include<vector>
using namespace std;

const int MAXN = 31;

struct treeNode{
    int val;
    int left;
    int right;
}nodes[MAXN];
int cnt;

int pre[MAXN];
int post[MAXN];
int N;

int ok=0;
void DFS(int root){
    if(root == -1){
        return;
    }
    DFS(nodes[root].left);
    if(ok == 1){
        cout << " ";
    }
    cout << nodes[root].val;
    DFS(nodes[root].right);
    ok =1;
    return;
}

vector<int> in;

//����ҿ�
int checked=0;
void recreate(int pre_s, int pre_e, int post_s, int post_e){
    //ֻ��һ���ڵ���
    if(pre_s+1 >= pre_e){
        if(pre_s+1 == pre_e){
            in.push_back(pre[pre_s]);
        }
        return;
    }

    int root_val = pre[pre_s];
    //����Ҫ�������ڵ�
    int tar = pre[pre_s+1];
    //�ں�����������ڵ�
    int offset = 0;
    while(post[post_s+offset] != tar){
        offset++;
    }
    //�ҵ��˺�����tar��λ��

    if(offset == pre_e-pre_s-2){
        checked = 1;
    }
    //��
    recreate(pre_s+1, pre_s+1+offset+1, post_s, post_s+offset+1);

    in.push_back(root_val);
    //��
    recreate(pre_s+offset+2, pre_e, post_s+offset+1, post_e);
    return;
}



int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> pre[i];
    }
    for(int i=0; i<N; i++){
        cin >> post[i];
    }
    recreate(0, N, 0, N);
    //DFS(root);
    cout << (checked==0?"Yes":"No")<<endl;
    for(int i=0; i<in.size(); i++){
        if(i>0)
            cout << " ";
        cout << in[i];
    }
    cout << endl;
    return 0;
}
