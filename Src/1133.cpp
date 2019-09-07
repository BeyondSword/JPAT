#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int MAXN=100001;

struct listNode{
    int addr;
    int key;
    int next;
    int type;
    int seq;
    int exist;
}nodes[MAXN];
int g_cnt;

int N,H,K;

bool cmp(struct listNode &A, struct listNode &B){
    if(A.exist == B.exist){
        if(A.type == B.type){
            return A.seq < B.seq;
        }
        return A.type > B.type;
    }

    return A.exist > B.exist;
}

//遍历一遍标记顺序，再排序，再输出？ 这样反而更快？
int main(){
    cin >> H >> N >> K;
    for(int i=0; i<N; i++){
        int addr,key,next;
        cin >> addr >> key >> next;
        nodes[addr].key = key;
        nodes[addr].next = next;
        nodes[addr].addr = addr;
        //nodes[addr].exist = 1;
        if(key < 0){
            nodes[addr].type = 3;
        }
        else if(key >=0 && key <= K){
            nodes[addr].type = 2;
        }
        else{
            nodes[addr].type = 1;
        }
    }
    int cur = H;
    int seq = 1;
    while(cur != -1){
        nodes[cur].seq = seq;
        nodes[cur].exist = 1;
        seq++;
        cur = nodes[cur].next;
    }
    sort(nodes, nodes+MAXN, cmp);
    for(int i=0; i<MAXN&&nodes[i].exist; i++){
        if(nodes[i].exist){
            printf("%05d %d ", nodes[i].addr, nodes[i].key);
            if(nodes[i+1].exist == 0){
                printf("-1\n");
            }
            else{
                printf("%05d\n", nodes[i+1].addr);
            }
        }
    }

    /*
    int cur = H, pre = -1;
    int a_head=-1, b_head=-1, c_head=-1;
    int a_tail=-1, b_tail=-1, c_tail=-1;
    int tot_head=-1;
    while(cur != -1){
        int new_pre = cur;
        int new_cur = nodes[cur].next;

        if(pre != -1){
            nodes[pre].next = nodes[cur].next;
        }
        nodes[cur].next = -1;

        if(nodes[cur].key < 0){
            if(a_head == -1){
                a_head = cur;
            }
            else{
                nodes[a_tail].next = cur;
            }
            a_tail = cur;
        }
        else if(nodes[cur].key >=0 && nodes[cur].key <=K){
            if(b_head == -1){
                b_head = cur;
            }
            else{
                nodes[b_tail].next = cur;
            }
            b_tail = cur;
        }
        else{
            if(c_head == -1){
                c_head = cur;
            }
            else{
                nodes[c_tail].next = cur;
            }
            c_tail = cur;
        }
        cur = new_cur;
        pre = new_pre;
    }
    //拼接
    if(a_head != -1){
        tot_head = a_head;

        if(b_head != -1){
            nodes[a_tail].next = b_head;
            nodes[b_tail].next = c_head;
        }
        else{
            nodes[a_tail].next = c_head;
        }
    }
    else{
        if(b_head != -1){
            tot_head = b_head;
            nodes[b_tail].next = c_head;
        }
        else{
            tot_head = c_head;
        }
    }

    //输出
    cur = tot_head;
    while(cur != -1){
        printf("%05d %d ", cur, nodes[cur].key);

        if(nodes[cur].next == -1){
            printf("-1\n");
        }
        else{
            printf("%05d\n", nodes[cur].next);
        }
        cur = nodes[cur].next;
    }*/

    return 0;
}
