#include<iostream>
#include<vector>
using namespace std;

char Ch[4] = {'S', 'H', 'C', 'D'};
int shuffle[55];

vector<int> start(55, 0);
vector<int> end_st(55, 0);
int K;
int main(){
    cin >> K;
    //��ʼ���� 0~53 ��ʾ54����
    for(int i=0; i<54; i++){
        start[i] = i;
    }

    //����ϴ��˳�� in ��ԭλ�� 0~53 shuffle ϴ��λ�� 1~54
    for(int i=0; i<54; i++){
        int in;
        cin >> in;
        shuffle[i] = in;
    }

    //ϴ��K��
    for(int i=0; i<K; i++){
        for(int j=0; j<54; j++){
            end_st[shuffle[j]-1] = start[j];
        }
        start = end_st;
    }

    //output
    for(int i=0; i<54; i++){
        if(i>0){
            cout << " ";
        }
        if(end_st[i] == 52){
            cout << "J1";
        }
        else if(end_st[i] == 53){
            cout << "J2";
        }
        else{
            cout << Ch[end_st[i]/13] << end_st[i]%13+1;
        }
    }

    return 0;
}
