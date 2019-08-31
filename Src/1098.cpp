#include<iostream>
#include<algorithm>

using namespace std;
const int MAXN=101;
int num1[MAXN];
int num2[MAXN];
int num_back[MAXN];

int N;
bool same_num(int A[], int B[]){
    for(int i=1; i<=N; i++){
        if(A[i] != B[i]){
            return false;
        }
    }
    return true;
}

void output(int A[]){
    for(int i=1; i<=N; i++){
        if(i>1){
            cout << " ";
        }
        cout << A[i];
    }
}

//从非叶节点开始
void down(int root, int num[], int size){
    int left = root*2;
    int right = root*2+1;

    //至少有左叶子
    while(root*2 <= size){
        left = 2*root;
        right = 2*root+1;
        int larger_node = left;
        if(right<=size&&num[right]>num[larger_node]){
            larger_node = right;
        }
        if(num[larger_node] > num[root]){
            swap(num[larger_node], num[root]);
            root = larger_node;
        }
        else{
            break;
        }
    }
}

void heap_create(int num[]){
    for(int i=N; i>=1; i--){
        down(i, num, N);
    }
}

//单步
void heap_sort(int num[], int &size){
    if(size <= 1){
        return;
    }
    swap(num[1], num[size]);
    size--;
    down(1, num, size);
}


int main(){
    int type=1;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> num1[i];
        num_back[i] = num1[i];
    }
    for(int i=1; i<=N; i++){
        cin >> num2[i];
    }

    //input end
    int i;
    for(i=1; i<=N+1; i++){
        sort(num1, num1+i);
        if(same_num(num1, num2)){
            type++;
            break;
        }
    }

    //insertion
    if(type == 2){
        i++;
        sort(num1, num1+i);
        cout << "Insertion Sort" << endl;
        output(num1);
    }

    //heap
    else{
        int* n_num = num_back;
        //heap sort
        int size = N;
        heap_create(n_num);
        while(size>0){
            heap_sort(n_num, size);
            if(same_num(n_num, num2)){
                heap_sort(n_num, size);
                cout << "Heap Sort" << endl;
                output(n_num);
                break;
            }
        }

    }
    return 0;
}
