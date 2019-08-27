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

    //��ʼ��
    for(int i=0; i<MAXN; i++){
        index[i] = -1;
    }
    for(int i=0; i<M; i++){
        cin >> color[i];
        //��¼������ɫ��λ��
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
        //��i��Ԫ�ز���ϲ������ɫ
        if(index[A[i]] == -1){
            dp[i] = 0;
            continue;
        }
        int len=0;
        //��0 - i-1 �����
        int indice = -1;
        for(int j=0; j<i; j++){
            //���ɴ�
            if(dp[j] == 0){
                continue;
            }
            //��ɫ˳�򲻶�
            if(index[A[j]] > index[A[i]]){
                continue;
            }

            //���
            if(indice == -1){
                indice = j;
            }
            else{
                if(dp[j] > dp[indice]){
                    indice = j;
                }
            }
        }
        //�Ҳ�����,�Լ��ɴ�
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
