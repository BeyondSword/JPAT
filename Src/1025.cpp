#include<iostream>
#include<algorithm>

using namespace std;

const int MAXNK = 101*301;

struct Testee{
    string ID;
    int score;
    int local;
    int l_rank;
    int f_rank;
}testee[MAXNK];

int N,K;
int index = 1;
int tag = 0;

bool comparison(struct Testee &A, struct Testee &B){
    //local rank
    if(tag == 0){
        if(A.local == B.local){
            return A.score > B.score;
        }
        return A.local < B.local;
    }
    //cal final rank
    else if(tag == 1){
        return A.score > B.score;
    }
    //sort final rank
    else{
        if(A.f_rank == B.f_rank){
            return A.ID < B.ID;
        }
        return A.f_rank < B.f_rank;
    }

}

int main(){
    cin >> N;
    int tot_cnt=0;
    for(int i=1; i<=N; i++){
        cin >> K;
        tot_cnt += K;
        for(int j=0; j<K; j++){
            cin >> testee[index].ID >> testee[index].score;
            testee[index].local = i;
            index++;
        }
    }
    cout << tot_cnt << endl;
    //local rank
    sort(testee+1, testee+1+tot_cnt, comparison);
    int l_rank=1;
    for(int i=1; i<=tot_cnt; i++){
        //switch location
        if(testee[i].local != testee[i-1].local){
            l_rank = 1;
            testee[i].l_rank = 1;
            //l_rank++;
        }
        else{
            l_rank++;
            if(testee[i].score == testee[i-1].score){
                testee[i].l_rank = testee[i-1].l_rank;
            }
            else{
                testee[i].l_rank = l_rank;
            }
        }
    }

    //final rank
    tag = 1;
    sort(testee+1, testee+1+tot_cnt, comparison);
    int f_rank=1;
    testee[1].f_rank = f_rank;
    for(int i=2; i<=tot_cnt; i++){
        f_rank++;
        if(testee[i].score == testee[i-1].score){
            testee[i].f_rank = testee[i-1].f_rank;
        }
        else{
            testee[i].f_rank = f_rank;
        }
    }

    //output
    tag = 2;
    sort(testee+1, testee+1+tot_cnt, comparison);
    for(int i=1; i<=tot_cnt; i++){
        cout << testee[i].ID << " ";
        cout << testee[i].f_rank << " ";
        cout << testee[i].local << " ";
        cout << testee[i].l_rank << endl;
    }
    return 0;
}


