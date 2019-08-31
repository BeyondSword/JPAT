#include<map>
#include<iostream>
#include<vector>

using namespace std;

string shop, eva;

int char_hash(char ch){
    if(ch>='0' && ch<='9'){
        return ch-'0';
    }
    if(ch>='a' && ch<='z'){
        return ch-'a'+100;
    }
    if(ch>='A' && ch<='Z'){
        return ch-'A'+200;
    }
}

int hash_table[300];

int main(){
    cin >> shop >> eva;
    for(int i=0; i<shop.size(); i++){
        hash_table[char_hash(shop[i])]++;
    }
    for(int i=0; i<eva.size(); i++){
        hash_table[char_hash(eva[i])]--;
    }

    int pos=0;
    int neg=0;
    int ok=1;
    for(int i=0; i<300; i++){
        if(hash_table[i]<0){
            ok=0;
            neg += hash_table[i];
        }
        else{
            pos += hash_table[i];
        }
    }

    if(ok == 1){
        cout << "Yes " << pos;
    }
    else{
        cout << "No " << -neg;
    }
    return 0;
}
