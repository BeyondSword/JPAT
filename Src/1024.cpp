#include<iostream>
#include<vector>

using namespace std;


vector<int> rev(vector<int> &A){
    vector<int> B;
    for(int i=A.size()-1; i>=0; i--){
        B.push_back(A[i]);
    }
    return B;
}


vector<int> add(vector<int> &A, vector<int> &B){
    vector<int> S;
    int ci=0;
    for(int i=0; i<A.size(); i++){
        int sum = A[i]+B[i]+ci;
        S.push_back(sum%10);
        ci = sum/10;
    }
    if(ci!=0){
        S.push_back(ci);
    }
    return S;
}

bool is_pal(vector<int> &S){
    int low=0, hi=S.size()-1;
    while(low<hi){
        if(S[low] != S[hi]){
            return false;
        }
        low++;
        hi--;
    }
    return true;
}

string N;
int K;

void output(vector<int> &S, int cnt){
    for(int i=S.size()-1; i>=0; i--){
        cout << S[i];
    }
    cout << endl;
    cout << cnt;
}
int main(){
    cin >> N >> K;
    vector<int> A;
    for(int i=N.size()-1; i>=0; i--){
        A.push_back(N[i]-'0');
    }

    int cnt=0;
    if(is_pal(A)){
        output(A, cnt);
    }
    else{
        int ok=0;
        for(int i=1; i<=K; i++){
            vector<int> B = rev(A);
            vector<int> S = add(A, B);
            if(is_pal(S)){
                output(S,i);
                ok=1;
                break;
            }
            A = S;
        }
        if(!ok)
            output(A,K);
    }
    return 0;
}
