#include<iostream>
#include<vector>
#include<math.h>

int N,K,P;
using namespace std;

vector<int> res;
int max_sum = 0;

//调用自己写的power，t2不过
//t2 已过，考察找较大序列 ;pow自己定义 不会出错
int Pow(int cur, int P){
    int num=1;
    for(int i=0; i<P; i++){
        num*=cur;
    }
    return num;
}

void DFS(int cur, int left_num, int depth, vector<int> &seq, int sum){
    left_num = left_num-Pow(cur, P);
    seq.push_back(cur);

    if(left_num<0 || depth > K-1){
        seq.pop_back();
        return;
    }
    if(left_num == 0 && depth != K-1){
        seq.pop_back();
        return;
    }
    //拆成功,比较优先级
    if(depth == K-1 && left_num == 0){
        if(sum > max_sum){
            max_sum = sum;
            res = seq;
        }
        else if(sum == max_sum){
            int ok = 0;
            for(int i=0; i<seq.size(); i++){
                if(seq[i] < res[i]){
                    break;
                }
                if(seq[i] > res[i]){
                    ok=1;
                    break;
                }
            }
            if(ok == 1){
                res = seq;
            }
        }
        seq.pop_back();
        return;
    }

    for(int i=cur; i>=1; i--){
        DFS(i, left_num, depth+1, seq, sum+i);
    }

    seq.pop_back();
    return;
}

int main(){
    cin >>N>>K>>P;

    int i=1;
    while(i*i<=N){
        i++;
    }
    i=i-1;
    vector<int> seq;
    while(i>=1){
        DFS(i, N, 0, seq, i);
        i--;
    }
    if(!res.size()){
        cout << "Impossible" ;
    }
    else{
        cout << N << " = ";
        for(int j=0; j<res.size(); j++){
            cout << res[j] << "^" << P;
            if(j < res.size()-1){
                cout << " + ";
            }
        }
    }
    return 0;
}
