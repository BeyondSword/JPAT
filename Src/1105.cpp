#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdio.h>
using namespace std;
const int MAXN=10010;
int N;

int nums[MAXN];
int matrix[MAXN][MAXN];
int dir_row[4] = {0,1,0,-1};
int dir_col[4] = {1,0,-1,0};
int m,n;

bool in(int row, int col){
    return row>=0&&row<m&&col>=0&&col<n&&matrix[row][col]==0;
}
bool cmp(int a, int b){
    return a>b;
}

int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &nums[i]);
    }
    sort(nums, nums+N, cmp);
    int cnt = 0;
    //创建矩阵
    m = (int)ceil(sqrt(1.0*N));
    n = (int)floor(sqrt(1.0*N));
    while(n>=1 && m*n != N){
        m++;
        n--;
    }
    //素数，只有一列
    if(n == 0){
        m = N;
        n = 1;
    }
    int row=0, col=0;
    int dir=0;

    matrix[0][0] = nums[cnt];
    cnt ++;
    while(cnt < N){
        int new_row = row+dir_row[dir];
        int new_col = col+dir_col[dir];
        //不碰壁
        if(in(new_row, new_col)){
            matrix[new_row][new_col] = nums[cnt];
            cnt++;
            col = new_col;
            row = new_row;
        }
        //碰壁
        else{
            //转向
            dir=(dir+1)%4;
        }
    }

    //output
    for(int row=0; row<m; row++){
        for(int col=0; col<n; col++){
            if(col > 0){
                printf(" ");
            }
            printf("%d", matrix[row][col]);
        }
        printf("\n");
    }
    return 0;
}
