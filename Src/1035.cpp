#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

bool mod(string &A){
    bool is_modified=false;

    for(int i=0; i<A.size(); i++){
        switch(A[i]){
            case '1':
                A[i]='@';
                is_modified=true;
                break;
            case '0':
                A[i]='%';
                is_modified=true;
                break;
            case 'l':
                A[i]='L';
                is_modified=true;
                break;
            case 'O':
                A[i]='o';
                is_modified=true;
                break;
            default:
                break;
        }
    }
    return is_modified;
}
int N;
vector<pair<string, string> > res;
int main(){
    cin >> N;
    bool is_mod = false;
    int ok=0;
    for(int i=0; i<N; i++){
        string in,id;
        cin >> id >> in;
        is_mod = mod(in);
        if(is_mod){
            ok=1;
            res.push_back(make_pair(id, in));
        }
    }
    if(ok==0){
        if(N == 1){
            printf("There is 1 account and no account is modified");
        }
        else{
            printf("There are %d accounts and no account is modified", N);
        }
    }
    else{
        printf("%d\n", res.size());
        for(int i=0; i<res.size(); i++){
            cout << res[i].first << " " << res[i].second << endl;
        }
    }
    return 0;
}
