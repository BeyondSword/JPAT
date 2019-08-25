#include<iostream>
#include<stdio.h>

using namespace std;

char res[3] = {'W', 'T', 'L'};
int main(){
    float odds[3];
    float tot_odd = 1;
    for(int i=0; i<3; i++){
        int max_odd_indi=0;
        for(int j=0; j<3; j++){
            cin >> odds[j];
            if(odds[j] > odds[max_odd_indi]){
                max_odd_indi = j;
            }
        }
        cout << res[max_odd_indi] << " ";
        tot_odd *= odds[max_odd_indi];
    }
    printf("%.2f", (tot_odd*0.65-1)*2);
    return 0;
}
