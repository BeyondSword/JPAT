#include<iostream>
#include<stack>
#include<vector>

using namespace std;
int M,N,K;
int main(){
    cin >> M >> N >> K;
    //query
    for(int i=0; i<K; i++){
        //读入seq
        vector<int> seq;
        stack<int> s;
        for(int j=0; j<N; j++){

            int tmp;
            cin >> tmp;
            seq.push_back(tmp);
        }
        int indi=0;
        int num=1;
        //模拟栈操作, num==N+1时，所有元素均已入栈，但可能尚未全部出栈
        while(s.size()<=M && num<=N+1 && indi<N){
            //栈顶元素和序列相同，pop
            if(!s.empty()&&s.top() == seq[indi]){
                s.pop();
                indi++;
            }
            else{
                s.push(num);
                num++;
            }
        }
        //全部pop成功
        if(indi == N){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
