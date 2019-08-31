#include<iostream>
#include<map>

using namespace std;

string A,B;
string res;

map<char, int> m;
int main(){
    cin >> A >> B;
    int p1=0,p2=0;

    //哨兵
    B+=' ';
    while(p1<A.size()&&p2<B.size()){
        if(A[p1] == B[p2]){
            p1++;
            p2++;
        }
        //不相等p1++
        else{
            //转大写
            if(A[p1]>='a' && A[p1] <= 'z'){
                A[p1] = A[p1]-'a'+'A';
            }
            if(!m.count(A[p1])){
                res+=A[p1];
                m[A[p1]]=1;
            }
            p1++;
        }
    }
    cout << res;
    return 0;

}
