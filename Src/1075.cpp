#include<iostream>
#include<algorithm>
#include<stdio.h>

using namespace std;

const int MAXN=10001;

struct Stu{
    int id;
    int p[6];
    int sub[6];
    int ac;
    int tot;
    int need_sort;
    int rank;
}stu[MAXN+1];


bool comparison(struct Stu &A, struct Stu &B){
    if(A.need_sort == B.need_sort){
        if(A.tot == B.tot){
            if(A.ac == B.ac){
                return A.id < B.id;
            }
            return A.ac > B.ac;
        }
        return A.tot > B.tot;
    }
    return A.need_sort > B.need_sort;

}

int p[6];
int main(){
    int N,K,M;
    cin >> N >> K >> M;
    for(int i=1; i<=K; i++){
        cin >> p[i];
    }
    //submission
    for(int i=0; i<M; i++){
        int id, p_id, score;
        cin >> id >> p_id >> score;
        //��һ����ͨ��������������
        if(score != -1){
            stu[id].need_sort = 1;
        }
        //֮ǰ���ύû���֣���һ������ac++
        if(stu[id].p[p_id]!=p[p_id] && score == p[p_id]){
            stu[id].ac += 1;
        }
        //������֮ǰ�ߣ�����
        if(stu[id].p[p_id] < score){
            if(stu[id].p[p_id] > 0){
                stu[id].tot -= stu[id].p[p_id];
            }
            stu[id].p[p_id] = score;
            stu[id].tot += score;
        }
        stu[id].id = id;
        stu[id].sub[p_id] = 1;
    }
    //�������
    sort(stu+1, stu+MAXN+1, comparison);

    //output
    int rank = 1;
    stu[1].rank = rank;
    stu[0].tot = -1;
    for(int i=1; i<MAXN; i++){
        if(!stu[i].need_sort){
            break;
        }
        if(stu[i].tot == stu[i-1].tot){
            printf("%d", stu[i-1].rank);
            stu[i].rank = stu[i-1].rank;
        }
        else{
            printf("%d", rank);
            stu[i].rank = rank;
        }
        rank++;

        //���������Ϣ
        printf(" %05d %d", stu[i].id, stu[i].tot);
        for(int j=1; j<=K; j++){
            //δ�ύ
            if(!stu[i].sub[j]){
                printf(" -");
            }
            else{
                //�ύûͨ������������ʾ0��
                if(stu[i].p[j] == -1){
                    printf(" 0");
                }
                else{
                    printf(" %d", stu[i].p[j]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
