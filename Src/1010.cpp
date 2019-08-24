#include<iostream>

using namespace std;

const int INF=0x7fffffff;

//radix

int toNum(const char&c){
    if(c>='0'&&c<='9'){
        return c-'0';
    }
    else{
        return c-'a'+10;
    }
}

long long toInt(string &X, int r){
    long long sum=0;
    for(int i=0; i<X.size(); i++){
        sum = sum*r + toNum(X[i]);
    }
    return sum;
}
int main(){
    string A,B;
    int ra;
    int tag;
    cin >> A >> B >> tag >> ra;

    if(tag == 2){
        swap(A,B);
    }
    //A is known
    int low,hi;
    bool is_larger = true;


    if(A == B){
        //输出可能最小
        long long MAX = toNum(A[0]);
        for(int i=0; i<A.size(); i++){
            if(toNum(A[i]) > toNum(MAX)){
                MAX = toNum(A[i]);
            }
        }
        cout << MAX+1;
        return 0;
    }

    low = 1;
    //hi = 37;
    long long a_int = toInt(A, ra);
    hi = a_int+1;
    int ok = 0;
    int mid;
    while(low < hi){
        mid = (low+hi)/2;
        if(toInt(B, mid) > a_int){
            hi = mid;
        }
        else if(toInt(B,mid) < a_int){
            low = mid+1;
        }
        else{
            ok = 1;
            break;
        }
    }

    if(ok){
        cout << mid;
    }
    else{
        cout << "Impossible";
    }

    //cout << INF;
    return 0;
}
