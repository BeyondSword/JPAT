#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100001;
int dist[MAXN];
int N;

bool cmp(int a, int b){
    return a>b;
}
int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> dist[i];
    }


    sort(dist+1, dist+N+1, cmp);
    int index = 1;
    //dist[0] = dist[1];
    int cnt=0;
    int MAX=0;
    while(index <= N){
        if(dist[index] > index){
            MAX = index;
        }
        else{
            break;
        }
        index++;
    }
    cout << MAX << endl;
    return 0;
}
