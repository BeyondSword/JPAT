#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

const int MAXN=100001;

int int_hash[10001];
struct listNode{
    int key;
    int next;
}nodes[MAXN];

int N,H;

void output_node(int addr){
    if(nodes[addr].next != -1){
        printf("%05d %d %05d\n", addr, nodes[addr].key, nodes[addr].next);
    }
    else{
        printf("%05d %d -1\n", addr, nodes[addr].key);
    }
}

int main(){
    cin >> H >> N;
    for(int i=0; i<N; i++){
        int addr;
        cin >> addr;
        cin >> nodes[addr].key >> nodes[addr].next;
    }
    int pre=-1;
    int cur=H;
    int new_head = -1;
    int new_tail = -1;
    while(cur != -1){
        //dup
        if(int_hash[(int)abs(nodes[cur].key)]){
            //remove
            nodes[pre].next = nodes[cur].next;
            int in_node = cur;
            cur = nodes[cur].next;

            //add to remove list
            if(new_head == -1){
                new_head = in_node;
            }
            else{
                nodes[new_tail].next = in_node;
            }
            new_tail = in_node;
            nodes[in_node].next = -1;
        }
        //not dup
        else{
            int_hash[(int)abs(nodes[cur].key)]=1;
            pre = cur;
            cur = nodes[cur].next;
        }
    }
    //output
    int addr = H;
    while(addr != -1){
        output_node(addr);
        addr = nodes[addr].next;
    }
    addr = new_head;
    while(addr != -1){
        output_node(addr);
        addr = nodes[addr].next;
    }
    return 0;
}
