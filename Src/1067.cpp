#include<iostream>

using namespace std;

const int MAXN=100001;

int nums[MAXN];
int index[MAXN];


int main(){
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> nums[i];
        index[nums[i]] = i;
    }
    int pos = index[0];
    int cnt=0;
    int rec=0;
    while(1){
        if(pos != 0){
            int cur = pos;
            nums[cur] = cur;
            nums[index[cur]] = 0;
            pos = index[cur];
            index[cur] = cur;
            cnt++;
        }
        else{
            pos = rec;
            while(pos<N && pos == nums[pos]){
                pos++;
            }
            if(pos >= N){
                break;
            }
            rec = pos;
            int cur = pos;
            nums[0] = nums[cur];
            index[nums[cur]] = 0;
            nums[cur] = 0;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
