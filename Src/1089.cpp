#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN=111;
int N;
int init[MAXN];
int sorted[MAXN];

bool cmp(){
    for(int i=0; i<N; i++){
        if(sorted[i] != init[i]){
            return false;
        }
    }
    return true;
}

int main(){
    cin >> N;
    for(int i=0; i<N ;i++){
        cin >> init[i];
    }
    for(int i=0; i<N; i++){
        cin >> sorted[i];
    }

    int type = 1;

    int indi = 1;
    while(sorted[indi] >= sorted[indi-1]){
        indi ++;
    }
    //从indi位置序列无序
    if(indi < N){
        int tag=indi;
        while(indi<N&&sorted[indi]==init[indi]){
            indi ++;
        }
        if(indi == N){
            type = 1;
        }
        else{
            type = 2;
        }

        //插排,再排当前数
        if(1 == type){
            cout << "Insertion Sort" << endl;
            indi = tag;
            sort(init, init+indi+1);
        }
        //归排
        else{
            cout << "Merge Sort" <<endl;
            int ok=0;
            for(int step=1; step*2<N; step*=2){
                //排
                for(int i=0; i<N; i+=step){
                    int end = min(i+step, N);
                    sort(init+i, init+end);
                }
                if(ok == 1){
                    break;
                }
                //比较
                if(cmp()){
                    ok=1;
                }
            }
        }
        //output
        for(int i=0; i<N; i++){
            if(i>0){
                cout << " ";
            }
            cout << init[i];
        }
    }
    else{
        cout << "Insertion Sort" << endl;
        for(int i=0; i<N; i++){
            if(i>0){
                cout << " ";
            }
            cout << sorted[i];
        }
    }

    return 0;
}
