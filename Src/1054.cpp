#include<iostream>
#include<map>

using namespace std;
const int MAXH = (1<<24);

int col_hash[MAXH];

int dominant=0;
int main(){
    int M,N;
    cin >> M >> N;
    for(int row=0; row<N; row++){
        for(int col=0; col<M; col++){
            int color;
            cin >> color;
            col_hash[color]++;
            if(col_hash[color]*2>M*N){
                dominant = color;
            }
        }
    }
    cout << dominant;
    return 0;
}
