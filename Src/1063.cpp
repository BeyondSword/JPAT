#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
const int MAXM=10001;
const int MAXN=51;
int sets[MAXN][MAXM];

int N;
const int INF=0x7fffffff;
int main(){
    cin >>N;
    for(int i=0; i<N; i++){
        int M;
        cin >> M;
        for(int j=0;j<M;j++){
            scanf("%d", &sets[i][j]);
        }
        //哨兵 sentry
        sets[i][M] = INF;
        sort(sets[i], sets[i]+M);
    }

    int K;
    cin >> K;
    for(int i=0; i<K; i++){
        int s1, s2;
        scanf("%d%d",&s1, &s2);
        s1--;
        s2--;
        int* set1 = sets[s1];
        int* set2 = sets[s2];
        float Nc=0.0, Nt=0.0;
        //比较
        int p1=0,p2=0;
        while(set1[p1]!=INF||set2[p2]!=INF){
            if(set1[p1] < set2[p2]){
                int tmp=set1[p1];
                p1++;
                Nt++;
                while(tmp == set1[p1]){
                    p1++;
                }
            }
            else if(set1[p1] > set2[p2]){
                int tmp=set2[p2];
                p2++;
                Nt++;
                while(tmp == set2[p2]){
                    p2++;
                }
            }
            //相同
            else{
                Nc++;
                Nt++;
                int tmp1=set1[p1];
                int tmp2=set2[p2];
                p1++;
                p2++;
                while(tmp1 == set1[p1]){
                    p1++;
                }
                while(tmp2 == set2[p2]){
                    p2++;
                }
            }
        }
        //
        printf("%.1f", 100*(Nc/Nt));
        cout << "%" << endl;
    }
    return 0;
}
