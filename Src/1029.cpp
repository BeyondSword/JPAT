#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
const int MAXN = 200001;

int A[MAXN];
int B[MAXN];

//vector<int> A;
//vector<int> B;

int p1,p2;

int N1, N2;
int main(){
    scanf("%d", &N1);
    //A.resize(N1, 0);
    for(int i=0; i<N1; i++){
        scanf("%d", &A[i]);
    }
    scanf("%d", &N2);
    //B.resize(N2, 0);
    for(int i=0; i<N2; i++){
        scanf("%d", &B[i]);
    }
    int mid = (N1+N2)/2;
    bool odd = ((N1+N2)%2);
    int cnt = 0;
    int cur = -1;
    int pre_cur = -1;
    //数组很小时特殊处理
    if(N1==1 && N2==1){
        if(A[0] > B[0]){
            printf("%d", B[0]);
        }
        else{
            printf("%d", A[0]);
        }
        return 0;
    }
    //一般处理
    while(p1<N1 && p2<N2 && cnt<=mid){
        if(A[p1] <= B[p2]){
            pre_cur = cur;
            cur = A[p1];
            p1++;
        }
        else{
            pre_cur = cur;
            cur = B[p2];
            p2++;
        }
        cnt++;
    }
    //找到中位数
    if(cnt > mid){
        if(odd){
            printf("%d", cur);
            //cout << cur;
        }
        else{
            printf("%d", pre_cur);
        }
    }
    else{
        while(p1<N1&&cnt<=mid){
            pre_cur = cur;
            cur = A[p1];
            p1++;
            cnt++;
        }
        while(p2<N2&&cnt<=mid){
            pre_cur = cur;
            cur = B[p2];
            p2++;
            cnt++;
        }
        //output
        if(odd){
            printf("%d", cur);
            //cout << cur;
        }
        else{
            printf("%d", pre_cur);
        }
    }
    return 0;
}
