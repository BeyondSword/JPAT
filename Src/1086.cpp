#include<iostream>
#include<stack>
#include<vector>
using namespace std;

const int MAXN=31;
int pre[MAXN];
int in[MAXN];
int pre_cnt,in_cnt,N;
stack<int> s;
string cmd[2*MAXN];

int ok=0;
//前闭后开
void post_traverse(int pre_s, int pre_e, int in_s, int in_e){
    if(pre_s >= pre_e){
        return;
    }
    int root_val = pre[pre_s];
    int offset = 0;
    while(in[in_s+offset] != root_val){
        offset++;
    }

    post_traverse(pre_s+1,pre_s+1+offset,in_s,in_s+offset);
    post_traverse(pre_s+1+offset,pre_e,in_s+offset+1,in_e);

    if(ok){
        cout << " ";
    }
    cout << root_val;
    ok=1;
    return;
}

int main(){
    cin >> N;
    for(int i=0; i<2*N; i++){
        cin >> cmd[i];
        if(cmd[i] == "Push"){
            cin >> pre[pre_cnt];
            s.push(pre[pre_cnt]);
            pre_cnt++;
        }
        else{
            in[in_cnt] = s.top();
            in_cnt++;
            s.pop();
        }
    }
    //input end
    //根据先序中序，还原后序
    post_traverse(0, N, 0, N);
    return 0;
}
