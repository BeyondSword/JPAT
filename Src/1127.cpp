#include<iostream>
#include<vector>
#include<stack>

using namespace std;

const int MAXN=31;

struct treeNode{
    int val;
    int left;
    int right;
}nodes[MAXN];
int cnt;
stack<int> s1,s2;

int post[MAXN];
int in[MAXN];

int recreate(int post_s, int post_e, int in_s, int in_e){
    if(post_s >= post_e){
        return -1;
    }
    int root_val = post[post_e-1];
    int offset = 0;

    //create node
    int root = cnt;
    cnt ++;
    nodes[root].val = root_val;

    while(in[in_s+offset] != root_val){
        offset++;
    }
    nodes[root].left = recreate(post_s, post_s+offset, in_s, in_s+offset);
    nodes[root].right = recreate(post_s+offset, post_e-1, in_s+offset+1,in_e);
    return root;
}

void zigzag(int root){
    int alter=0;//left
    stack<int> s1;
    stack<int> s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            int n = s1.top();
            s1.pop();
            if(n != root)
                cout << " ";
            cout << nodes[n].val;
            //先左后右
            if(alter==1){
                if(nodes[n].left != -1)
                    s2.push(nodes[n].left);
                if(nodes[n].right != -1)
                    s2.push(nodes[n].right);
            }
            //先右后左
            else{
                if(nodes[n].right != -1)
                    s2.push(nodes[n].right);
                if(nodes[n].left != -1)
                    s2.push(nodes[n].left);
            }
        }
        s1 = s2;
        while(!s2.empty())
            s2.pop();
        alter = (alter==0);
    }
    return;
}

int N;
int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> in[i];
    }
    for(int i=0; i<N; i++){
        cin >> post[i];
    }
    int root = -1;
    root = recreate(0, N, 0, N);
    //建树结束
    zigzag(root);
    return 0;

}
