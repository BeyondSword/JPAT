#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN=11111;
const int MAXK=11;
struct Per{
    int id;
    string name;
    int height;
}per[MAXN];

int pos[MAXK][MAXN];

bool cmp(struct Per &A, struct Per &B){
    if(A.height == B.height){
        return A.name < B.name;
    }
    return A.height > B.height;
}

int main(){
    int N, K;
    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> per[i].name >> per[i].height;
    }
    //从高到矮
    sort(per, per+N, cmp);
    int m = N/K;
    int first_m = N/K+N%K;
    if(N < K){
        m=1;
        K = N;
        first_m = 1;
    }
    //每行
    int cnt=0;
    for(int row=0; row<K; row++){
        int size;
        //第一行人多
        if(row == 0){
            size = first_m;
        }
        else{
            size = m;
        }

        //从高到矮
        int s = size/2;
        int cur = s;
        int row_cnt = 0;
        while(row_cnt < size){
            //根据奇偶排左和右
            if(row_cnt%2 == 0){
                cur = s+(row_cnt+1)/2;
            }
            else{
                cur = s-(row_cnt+1)/2;
            }
            pos[row][cur] = cnt;
            cnt++;
            row_cnt ++;
        }
    }
    //output
    for(int row=0; row<K; row++){
        int size;
        if(row == 0)
            size = first_m;
        else
            size = m;
        for(int col=0; col<size; col++){
            if(col > 0)
                cout << " ";
            cout << per[pos[row][col]].name;
        }
        cout << endl;
    }
    return 0;
}
