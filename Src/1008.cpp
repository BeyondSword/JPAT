#include<iostream>

using namespace std;


int main(){
    int N;
    cin >> N;
    int cnt = 0;
    int cur = 0;
    for(int i=0; i<N; i++){
        int tar;
        cin >> tar;
        if(tar > cur){
            cnt += 6*(tar-cur);
        }
        else{
            cnt += 4*(cur-tar);
        }
        //stay
        cnt += 5;
        cur = tar;
    }
    cout << cnt;
    return 0;
}
