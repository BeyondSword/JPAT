#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN=10001;
int coins[MAXN];
int dp[MAXN][100];
int M,N;

vector<vector<int> > Res;


bool comparison(vector<int> &A, vector<int> &B){
    for(int i=0; i<min(A.size(),B.size());i++){
        if(A[i] != B[i]){
            return A[i] < B[i];
        }
    }
    return A.size()<B.size();
}

bool cmp(int a, int b){
    return a>b;
}

int main(){
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        cin >> coins[i];
    }
    vector<int> res;
    sort(coins+1, coins+1+N, cmp);

    dp[1][0]=-1;
    dp[1][coins[1]]=1;
    int ok=0;
    //��¼�ϸ�Ӳ��λ��
    for(int i=2; i<=N; i++){
        for(int v=0; v<=M; v++){
            //0����ȡ�����Ҳ���Ҫ��
            if(v == 0){
                dp[i][v] = -1;
                continue;
            }
            //��i����ȡ
            if(v>=coins[i] && dp[i-1][v-coins[i]] != 0){
                dp[i][v] = i;
                //��¼ȡ�����б�
                if(v==M){
                    ok=1;
                    res.clear();
                    int amount=v;
                    int index=i;
                    while(index>0){
                        //ȡ�����Ǯ
                        if(dp[index][amount] == index){
                            res.push_back(coins[index]);
                            amount -= coins[index];
                            index --;
                            index = dp[index-1][amount];
                        }
                        //ûȡ���Ǯ
                        else{
                            index = dp[index-1][amount];
                        }
                    }
                    //reverse(res.begin(), res.end());
                }
            }
            //��i���Ҳ�ȡ
            else if(dp[i-1][v] != 0){
                dp[i][v] = dp[i-1][v];
            }
        }
    }
    if(!ok){
        cout << "No Solution";
    }
    else{
        //sort(Res.begin(), Res.end(), comparison);
        for(int i=0; i<res.size(); i++){
            if(i>0){
                cout << " ";
            }
            cout << res[i];
        }
    }

    return 0;
}
