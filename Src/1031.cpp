#include<iostream>

using namespace std;


int main(){
    string in;
    cin >> in;
    int N = in.size();
    int n1,n2;
    for(n2=3; n2<=N; n2++){
        //int n1=(N+2-n2)/2;
        if((N+2-n2)%2 == 1){
            continue;
        }
        n1 = (N+2-n2)/2;
        if(n1 <= n2){
            break;
        }
    }

    //output
    int head=0, tail=N-1;
    //Êä³ö²à±ß
    while(head < n1-1){
        cout << in[head];
        for(int i=0; i<n2-2; i++){
            cout << " ";
        }
        cout << in[tail] << endl;
        head++;
        tail--;
    }
    //Êä³öµ×±ß
    for(int i=0; i<n2; i++){
        cout << in[head];
        head++;
    }
    return 0;
}
