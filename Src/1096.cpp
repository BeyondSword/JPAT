#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;

int N;
vector<int> seq;

vector<int> res;

int main(){
    int start=-1;
    int len=0;

    int max_len=0;
    int max_start=0;
    cin >> N;
    int tmp = N;
    for(int i=2; i<sqrt(N)+2; i++){
        if(tmp>1&&tmp%i==0){
            if(start == -1){
                start = i;
            }
            len++;
            tmp/=i;
        }
        //½áËã
        else{
            if(len > max_len){
                max_start = start;
                max_len = len;
            }
            while(tmp != N){
                tmp *= start;
                start++;
                len--;
                if(tmp%i==0)
                    break;
            }
            if(tmp%i!=0){
                start = -1;
            }
            else{
                len++;
                tmp/=i;
            }
        }
    }

    //ÖÊÊý
    if(max_len == 0)
    {
        cout << "1" << endl;
        cout << N << endl;
    }
    else{
        cout << max_len << endl;
        for(int i=max_start; i<max_start+max_len; i++){
            if(i>max_start)
                cout << '*';
            cout << i;
        }
    }

    return 0;
}
