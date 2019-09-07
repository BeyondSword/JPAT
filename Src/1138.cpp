#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

const int MAXN=50001;
int pre[MAXN];
int in[MAXN];

int N;
int first=0;

    //ÊäÈë½áÊø
void create(int pre_s, int pre_e, int in_s, int in_e){
    if(pre_s >= pre_e){
        return;
    }
    int root_val = pre[pre_s];
    int offset=0;
    while(in[in_s+offset] != root_val){
        offset++;
    }

    create(pre_s+1,pre_s+1+offset,in_s,in_s+offset);
    create(pre_s+1+offset,pre_e,in_s+offset+1,in_e);
    if(!first){
        printf("%d", root_val);
        first = 1;
        return;
    }
    return;
}

int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &pre[i]);
    }
    for(int i=0; i<N; i++){
        scanf("%d", &in[i]);
    }
    create(0,N,0,N);
    return 0;
}
