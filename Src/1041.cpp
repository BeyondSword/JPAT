#include<iostream>

using namespace std;
const int MAXN=100001;

int nums[MAXN];
int bet[MAXN];
//存位置
int index[MAXN];
int N;
int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> nums[i];
        bet[nums[i]]++;
        index[nums[i]] = i;
    }

    //output
    int num=-1;
    for(int i=1; i<MAXN; i++){
        //unique
        if(bet[i] == 1){
            if(num == -1){
                num = i;
            }
            else{
                //找第一个unique数
                if(index[i] < index[num]){
                    num = i;
                }
            }
        }
    }
    if(num == -1){
        cout << "None";
    }
    else{
        cout << num;
    }
    return 0;
}
