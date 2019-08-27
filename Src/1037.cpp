#include<iostream>
#include<algorithm>

using namespace std;
const int MAXN=100001;

int co[MAXN];
int pdt[MAXN];

long long tot;
int N1, N2;
int p1, p2;
int n1, n2;

bool comparison(int a, int b){
    return a>b;
}
int main(){
    cin >> N1;
    for(int i=0; i<N1; i++){
        cin >> co[i];
    }
    cin >> N2;
    for(int i=0; i<N2; i++){
        cin >> pdt[i];
    }
    p1=0, p2=0;
    sort(co, co+N1, comparison);
    sort(pdt, pdt+N2, comparison);
    //均为正数
    while(p1<N1&&p2<N2 && co[p1]>0&&pdt[p2]>0){
        tot += co[p1]*pdt[p2];
        p1++;
        p2++;
    }
    p1=N1-1, p2=N2-1;
    //均为负数
    while(p1>=0&&p2>=0 && co[p1]<0&&pdt[p2]<0){
        tot += co[p1]*pdt[p2];
        p1--;
        p2--;
    }
    cout << tot;
    return 0;
}
