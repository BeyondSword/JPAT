#include<iostream>
#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;

int N;

vector<int> p_hash;

//0表质数 1表合数
int main(){
    int N;
    scanf("%d", &N);
    int size = sqrt(N);

    p_hash.resize(size+1, 0);
    p_hash[1] = 1;
    int num=N;
    printf("%d=", N);
    int first = 1;
    for(int i=2; i<size+1; i++){
        //是质数
        if(p_hash[i] == 0){
            for(int j=i; j<size+1; j+=i){
                p_hash[j] = 1;
            }
            //能否被除
            int cnt = 0;
            while(num>1&&num%i==0){
                num /= i;
                cnt++;
            }
            //一个质因数
            if(cnt==1){
                if(!first){
                    printf("*");
                }
                first=0;
                printf("%d",i);
            }
            //两个质因数
            else if(cnt>1){
                if(!first){
                    printf("*");
                }
                first=0;
                printf("%d^%d",i,cnt);
            }
        }
    }
    if(num > 1){
        if(!first){
            printf("*");
        }
        printf("%d", num);
    }
    else if(N==1){
        printf("1");
    }

    return 0;
}
