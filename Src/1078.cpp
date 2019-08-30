#include<iostream>
#include<vector>
using namespace std;

const int MAXM=11111;

//��ǰһ������

int prime[MAXM];

//Ԥ����������
void pre(){
    for(int i=2; i<MAXM; i++){
        if(prime[i] == 0){
            for(int j=i+i; j<MAXM; j+=i){
                prime[j] = 1;
            }
        }
    }
    return;
}

int M,N;
int main(){
    cin >> M >> N;
    prime[1] = 1;
    pre();
    int size = M;
    //����M�ĵ�һ������
    while(prime[size]){
        size++;
    }

    vector<int> hash_table(size, 0);

    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        int H = num%size;
        if(i > 0){
            cout << " ";
        }
        int incre = 1;
        int ok=0;
        int ori_H = H;
        while(incre <= size){
            //hashΪ��,����
            if(!hash_table[H]){
                hash_table[H] = 1;
                cout << H;
                ok=1;
                break;
            }
            H = (ori_H + incre*incre)%size;
            incre++;
        }
        //����ʧ��
        if(!ok){
            cout << '-';
        }
    }
    return 0;
}
