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
    //�ҵ�β�ͺ���һ�ڵ�
    while(cnt < K && cur != -1){
        pre = cur;
        cur = nodes[cur].next;
        cnt++;
    }
    //�Ѿ��������һ������,��ת����
    if(cur == -1){
        //��������K����ֱ�ӷ���
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
    //��δ�������һ��
    else{
        //�ȷ�ת�������
        int new_head = reverse(cur, K);
        //��ת��ǰ��
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


//first node Ҫ����
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
    //ͷ�ڵ���û��
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
