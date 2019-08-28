#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

const int MAXN=100001;
int N;

//vector<int> st;
int st[MAXN];
int size=0;
int sorted[MAXN];

vector<int> pos[MAXN];
//int top_indi;


int binary_search(int low, int hi, int target){
    int mid;
    while(low<hi){
        mid = (low+hi)/2;
        if(sorted[mid] > target){
            hi = mid;
        }
        else if(sorted[mid] < target){
            low = mid+1;
        }
        else{
            return mid;
        }
    }
    return low;
}

void push(int val){
    st[size] = val;
    if(size == 0){
        sorted[size] = val;
        size++;
        //top_indi = 0;
    }
    //插入元素
    else{
        int index = binary_search(0, size, val);
        //index位置元素>=target
        int pre_val = val;

        //记录栈顶元素位置
        //top_indi = index;
        while(index<=size){
            int tmp=sorted[index];
            sorted[index] = pre_val;
            pre_val = tmp;
            index ++;
        }
        size++;
    }
}

void peek(){
    if(size == 0){
        printf("Invalid\n");
    }
    else{
        if(size%2 == 0){
            printf("%d\n", sorted[(size)/2-1]);
        }
        else{
            printf("%d\n", sorted[(size+1)/2-1]);
        }
    }
}

void pop(){
    if(size == 0){
        printf("Invalid\n");
    }
    else{
        //删除元素
        int val = st[size-1];
        //删除有序队列中的对应元素
        int index = binary_search(0, size, val);
        //后方元素前移
        while(index+1<size){
            sorted[index] = sorted[index+1];
            index++;
        }
        size--;
        printf("%d\n", val);
    }
}


int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        string cmd;
        cin >> cmd;
        //push
        if(cmd[1] == 'u'){
            int val;
            cin >> val;
            push(val);
        }
        //pop
        else if(cmd[1] == 'o'){
            pop();
        }
        //peek
        else{
            peek();
        }
    }
    return 0;
}
