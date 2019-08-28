#include<iostream>
#include<stdio.h>
using namespace std;

const int MAXN=100001;

struct ListNode{
    int exist;
    int val;
    int next;
}node[MAXN];

//cur2 ͷ�� cur1
void insert(int prev1, int cur1, int prev2, int cur2, int &head){
    //ժcur2,��Ϊͷ�ڵ�ʱ
    if(prev2 != -1){
        node[prev2].next = node[cur2].next;
    }
    //����
    node[cur2].next = cur1;
    if(prev1 != -1){
        node[prev1].next = cur2;
    }
    //cur2 �����ͷ
    else{
        head = cur2;
    }
    return;
}


int N,H;
int main(){
    cin >> N >> H;
    int ok=0;
    for(int i=0; i<N; i++){
        int addr,key,next;
        cin >> addr >> key >> next;
        node[addr].exist = 1;
        node[addr].val = key;
        node[addr].next = next;
        //û��ͷ
        if(addr == H){
            ok=1;
        }
    }
    if(ok == 0){
        printf("0 -1");
        return 0;
    }
    //input end
    int prev = -1, cur = H;
    int prev2 = -1, cur2 = H;
    int new_head = H;
    //�������?
    //��ÿ��Ԫ�ز�������
    int cnt=0;
    while(cur2 != -1){
        prev = -1;
        cur = new_head;
        //�ȼ�¼�¸��ڵ�λ��
        int next_prev = cur2;
        int next = node[cur2].next;
        //���ײ���cur2����
        while(cur != cur2){
            if(node[cur2].val >= node[cur].val){
                prev = cur;
                cur = node[cur].next;
            }
            //����
            else{
                //�ı�����ṹ��
                insert(prev, cur, prev2, cur2, new_head);
                break;
            }
        }
        prev2 = next_prev;
        cur2 = next;
        cnt++;
    }

    printf("%d %05d\n", cnt, new_head);
    while(new_head!=-1){
        printf("%05d %d", new_head, node[new_head].val);
        if(node[new_head].next == -1){
            printf(" -1\n");
        }
        else{
            printf(" %05d\n", node[new_head].next);
        }
        new_head = node[new_head].next;
    }
    return 0;
}
