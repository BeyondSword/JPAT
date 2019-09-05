#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cmath>
using namespace std;
const int MAXN=10001;

double seg[MAXN];

int N;
double tot=0.0;
int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> seg[i];
    }

    sort(seg, seg+N);
    tot = seg[0]/2 + seg[1]/2;
    for(int i=2; i<N; i++){
        tot = tot/2 + seg[i]/2;
    }
    int res = (int)floor(tot);
    cout << res;
    return 0;
}
