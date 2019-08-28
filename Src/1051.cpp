#include<iostream>
#include<stack>
#include<vector>

using namespace std;
int M,N,K;
int main(){
    cin >> M >> N >> K;
    //query
    for(int i=0; i<K; i++){
        //����seq
        vector<int> seq;
        stack<int> s;
        for(int j=0; j<N; j++){

            int tmp;
            cin >> tmp;
            seq.push_back(tmp);
        }
        int indi=0;
        int num=1;
        //ģ��ջ����, num==N+1ʱ������Ԫ�ؾ�����ջ����������δȫ����ջ
        while(s.size()<=M && num<=N+1 && indi<N){
            //ջ��Ԫ�غ�������ͬ��pop
            if(!s.empty()&&s.top() == seq[indi]){
                s.pop();
                indi++;
            }
            else{
                s.push(num);
                num++;
            }
        }
        //ȫ��pop�ɹ�
        if(indi == N){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
