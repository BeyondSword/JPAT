#include<iostream>
#include<queue>
#include<map>
#include<vector>

using namespace std;

const int MAXN=20;
const int MAXM=10;
const int MAXK=1001;

struct Cust{
    int s_time;
    int e_time;
    int proc_time;
}cus[MAXK];

queue<int> q[MAXN];
queue<int> wait_q;


int N,M,K,Q;


int index=0;
int main(){
    cin >> N >> M >> K >> Q;
    for(int i=1; i<=K; i++){
        cin >> cus[i].proc_time;
    }

    int proc_cnt = 0;
    int cur_time = 8*60;
    int close_time = 17*60;

    //8:00��������Ԫ��
    index = 1;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            //update����
            if(i == 0){
                cus[index].s_time = cur_time;
                cus[index].e_time = cur_time + cus[index].proc_time;
            }
            q[j].push(index);
            index++;
        }
    }
    //����ķ�����ж���
    while(index<=K){
        wait_q.push(index);
        index++;
    }
    //cout << wait_q.size();
    //�������
    while(proc_cnt < K){
        int first_leave=-1;

        //���������
        for(int i=0; i<N; i++){
            if(!q[i].empty()){
                if(first_leave==-1 || cus[q[i].front()].e_time < cus[q[first_leave].front()].e_time){
                    first_leave=i;
                }
            }
        }

        //�ȴ������
        cur_time = cus[q[first_leave].front()].e_time;
        q[first_leave].pop();
        proc_cnt++;
        //�ȴ����в�Ϊ�գ�����
        if(!wait_q.empty()){
            q[first_leave].push(wait_q.front());
            wait_q.pop();
        }
        //���в�Ϊ�գ�update����Ԫ��
        if(!q[first_leave].empty()){
            cus[q[first_leave].front()].s_time = cur_time;
            cus[q[first_leave].front()].e_time = cur_time + cus[q[first_leave].front()].proc_time;
        }
    }

    //query
    for(int i=0; i<Q; i++){
        int query;
        cin >> query;
        //������,�����֣�һ���ڻ����һ���ڻ�����
        if(cus[query].s_time>=close_time){
            printf("Sorry\n");
        }
        else{
            printf("%02d:%02d\n", cus[query].e_time/60, cus[query].e_time%60);
        }
    }
    return 0;
}
