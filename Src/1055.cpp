#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN=100001;
const int MAXK=1001;

struct Person{
    char name[10];
    int age;
    int worth;
}Per[MAXN];


bool str_cmp(char a[], char b[]){
    for(int i=0; i<min(strlen(a), strlen(b)); i++){
        if(a[i] != b[i]){
            return a[i] < b[i];
        }
    }
    return strlen(a) < strlen(b);
}

bool comparison(int a, int b){
    if(Per[a].worth == Per[b].worth){
        if(Per[a].age == Per[b].age){
            return str_cmp(Per[a].name, Per[b].name);
        }
        return Per[a].age < Per[b].age;
    }
    return Per[a].worth > Per[b].worth;
}

bool comparison2(int a, int b){
    return Per[a].age < Per[b].age;
}
int N,K;
int binary_search(int v[], int age){
    int low=0, hi=N;
    int mid;

    //ǰ�պ�
    while(low<hi){
        mid = (low+hi)/2;
        if(Per[v[mid]].age < age){
            low = mid+1;
        }
        else if(Per[v[mid]].age > age){
            hi = mid;
        }
        //�ҵ�������
        else{
            return mid;
        }
    }
    return low;
}




int ori[MAXN];
int qua_per[MAXN];

int main(){
    scanf("%d%d", &N, &K);
    for(int i=0; i<N; i++){
        scanf("%s%d%d", Per[i].name, &Per[i].age, &Per[i].worth);
        ori[i] = i;
    }
    //����������,��ֵK������
    sort(ori, ori+N, comparison2);

    for(int i=0; i<K; i++){
        int out_num, min_age, max_age;
        scanf("%d%d%d", &out_num, &min_age, &max_age);

        //ǰ�պ�
        memcpy(qua_per, ori, sizeof(int)*N);
        int low = binary_search(qua_per, min_age);
        //������Ҫ��ͬ���������λ�õ�Ԫ��
        if(Per[qua_per[low]].age == min_age){
            while(low>=0&&Per[qua_per[low]].age == min_age){
                low--;
            }
            low++;
        }

        int hi = binary_search(qua_per, max_age);
        //��������������,�����1
        while(hi<N&&Per[qua_per[hi]].age == max_age){
            hi++;
        }
        sort(qua_per+low, qua_per+hi, comparison);

        /*
        vector<int> qua_per;
        //�ҵ��������䷶Χ�ڵ���������
        for(int j=0; j<N; j++){
            if(Per[j].age>=min_age && Per[j].age<=max_age){
                qua_per.push_back(j);
            }
        }
        //����
        sort(qua_per.begin(), qua_per.end(), comparison);
        */

        printf("Case #%d:\n", i+1);
        int j;
        for(j=low; j<hi&&j<low+out_num; j++){
            printf("%s %d %d\n", Per[qua_per[j]].name, Per[qua_per[j]].age, Per[qua_per[j]].worth);
        }
        //�������
        if(j == low){
            printf("None\n");
        }
    }

    return 0;
}

