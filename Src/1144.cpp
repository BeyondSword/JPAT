#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<map>

using namespace std;
const int MAXN=100001;

int nums[MAXN];

int N;
int g_cnt;
map<int, int> in;
int main(){
    scanf("%d", &N);
    int smallest = 0x7fffffff;
    for(int i=0; i<N; i++){
        //scanf("%")
        int n;
        scanf("%d", &n);
        if(n>0){
            in[n] = 1;
            smallest = min(smallest, n);
        }
        /*if(n>0){
            in[n] = 1;
            //while(smallest)

            while(in.count(n)){
                n++;
            }
            //smallest = min(n, smallest);

        }*/
    }
    int cur = smallest;
    //没找到大于0的数
    if(smallest == 0x7fffffff){
        cout << "1";
        return 0;
    }
    while(in.count(cur)){
        cur++;
    }
    cout << cur;
    return 0;
    //sort(nums, nums+g_cnt);
    //排序
    //for(int i=0; i<g_cnt; i++){
    //}

}
