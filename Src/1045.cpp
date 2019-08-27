#include<iostream>

using namespace std;

const int MAXN=201;
const int MAXL=10001;


int N,M,L;
int color[MAXN];
int A[MAXL];

int index[MAXN];
int dp[MAXL];

int main(){
    cin >> N >> M;

    //初始化
    for(int i=0; i<MAXN; i++){
        index[i] = -1;
    }
    for(int i=0; i<M; i++){
        cin >> color[i];
        //记录该种颜色的位置
        index[color[i]] = i;
    }
    cin >> L;
    for(int i=0; i<L; i++){
        cin >> A[i];
    }
    //input end
    if(index[A[0]] == -1){
        dp[0] = 0;
    }
    else{
        dp[0] = 1;
    }
    int longest = dp[0];
    for(int i=1; i<L; i++){
        //第i个元素不是喜欢的颜色
        if(index[A[i]] == -1){
            dp[i] = 0;
            continue;
        }
        int len=0;
        //找0 - i-1 中最长的
        int indice = -1;
        for(int j=0; j<i; j++){
            //不成串
            if(dp[j] == 0){
                continue;
            }
            //颜色顺序不对
            if(index[A[j]] > index[A[i]]){
                continue;
            }

            //找最长
            if(indice == -1){
                indice = j;
            }
            else{
                if(dp[j] > dp[indice]){
                    indice = j;
                }
            }
        }
        //找不到串,自己成串
        if(indice == -1){
            dp[i] = 1;
        }
        else{
            dp[i] = dp[indice]+1;
        }
        longest = max(longest, dp[i]);
    }

    //output
    cout << longest;
    return 0;
}
