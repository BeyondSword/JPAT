#include<iostream>

using namespace std;

const int MAXN=1001;
float A[MAXN];
float B[MAXN];
float PD[2*MAXN];
int used[2*MAXN];

int main(){
    int K;
    cin >> K;
    for(int i=0; i<K; i++){
        int exp;
        float co;
        cin >> exp >> co;
        A[exp] = co;
    }
    cin >> K;
    for(int i=0; i<K; i++){
        int exp;
        float co;
        cin >> exp >> co;
        B[exp] = co;
    }
    //input end
    int cnt=0;
    for(int i=0; i<MAXN; i++){
        for(int j=0; j<MAXN; j++){
            float co = A[i]*B[j];
            int exp = i+j;
            /*
            if((co != 0.0)&&!used[exp]){
                cnt ++;
                used[exp] = 1;
            }*/
            PD[exp] += co;
        }
    }

    for(int i=2*MAXN-1; i>=0; i--){
        if(PD[i] != 0.0)
            cnt++;
    }
    //output
    cout << cnt;
    for(int i=2*MAXN-1; i>=0; i--){
        if(PD[i] != 0.0)
            printf(" %d %.1f", i, PD[i]);
    }
    return 0;
}
