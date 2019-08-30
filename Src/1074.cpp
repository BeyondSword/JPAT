#include<iostream>
#include<stdio.h>

using namespace std;

const int MAXN=100001;
struct ListNode{
    int addr;
    int val;
    int next;
}nodes[MAXN];

int reverse(int h, int K){
    //int pre = h;
    //int cur = nodes[h].next;
    //int cnt = 0;
    if(h == -1){
        return -1;
    }
    int pre = -1;
    int cur = h;
    int cnt = 0;
    //找到尾巴和下一节点
    while(cnt < K && cur != -1){
        pre = cur;
        cur = nodes[cur].next;
        cnt++;
    }
    //已经来到最后一组链表,翻转链表
    if(cur == -1){
        //数量不足K个，直接返回
        if(cnt < K){
            return h;
        }
        pre = h;
        cur = nodes[pre].next;
        nodes[pre].next = -1;
        cnt = 0;
        while(cnt < K-1 && cur != -1){
            int n_pre = cur;
            int n_cur = nodes[cur].next;
            nodes[cur].next = pre;
            pre = n_pre;
            cur = n_cur;
            cnt++;
        }
        return pre;
    }
    //还未来到最后一组
    else{
        //先翻转后面的组
        int new_head = reverse(cur, K);
        //翻转当前组
        pre = h;
        cur = nodes[pre].next;
        nodes[pre].next = new_head;
        cnt = 0;
        while(cnt < K-1 && cur != -1){
            int n_pre = cur;
            int n_cur = nodes[cur].next;
            nodes[cur].next = pre;
            pre = n_pre;
            cur = n_cur;
            cnt++;
        }
        return pre;
    }
}


//first node 要存在
int main(){
    int Head,N,K;
    cin >> Head >> N >> K;
    int ok=0;
    for(int i=0; i<N; i++){
        int add;
        cin >> add;
        if(add == Head){
            ok=1;
        }
        cin >> nodes[add].val >> nodes[add].next;
    }
    //头节点有没有
    if(ok == 0){
        printf("-1");
        return 0;
    }

    int new_head = reverse(Head, K);

    //output
    while(new_head != -1){
        printf("%05d %d ", new_head, nodes[new_head].val);
        if(nodes[new_head].next != -1){
            printf("%05d\n", nodes[new_head].next);
        }
        else{
            printf("-1\n");
        }
        new_head = nodes[new_head].next;
    }

    return 0;
}
