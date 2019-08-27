#include<iostream>
#include<vector>

using namespace std;

int main(){
    string A;
    getline(cin, A);
    //getline(cin, A);
    if(A.size() == 1){
        cout << "1";
        return 0;
    }
    if(A.size() == 2){
        if(A[0] == A[1]){
            cout << "2";
        }
        else{
            cout << "1";
        }
        return 0;
    }

    //��ά����
    vector<vector<int> > dp(A.size(), vector<int>(A.size(),0));
    //��ʼ������Ϊ1�Ĵ�
    for(int i=0; i<A.size(); i++){
        dp[i][i] = 1;
    }
    //��ʼ������Ϊ2�Ĵ�
    int longest=1;
    for(int i=0; i+1<A.size(); i++){
        //dp[i][i+1] = (A[i] == A[i+1]);
        if(A[i] == A[i+1]){
            longest = 2;
            dp[i][i+1] = (A[i] == A[i+1]);
        }
    }
    //���ճ��ȴӶ���������
    for(int step=2; step<A.size(); step++){
        for(int i=0; i+step<A.size(); i++){
            if(A[i] == A[i+step] && dp[i+1][i+step-1]){
                longest = step+1;
                dp[i][i+step] = 1;
            }
        }
    }
    cout << longest;
    return 0;
}
