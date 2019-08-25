#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;
const int MAXN=10001;
struct Book{
    string ID;
    string title;
    string author;
    vector<string> keys;
    string pub;
    string pub_year;

}books[MAXN];

int N;
int index;

map<string, vector<int> > m[6];

bool comparison(int a, int b){
    return books[a].ID < books[b].ID;
}
//map<int, int> year;
//vector<int> year_hash[3001];

void saveInMap(const string &key, int val, map<string, vector<int> > &m){
    if(!m.count(key)){
        m[key] = vector<int>(1,val);
    }
    else{
        m[key].push_back(val);
    }
}

int main(){
    cin >> N;
    string buf;
    getline(cin, buf);
    for(int i=0; i<N; i++){

        getline(cin, buf);
        books[index].ID = buf;

        //title
        getline(cin, buf);
        books[index].title = buf;
        saveInMap(buf, index, m[1]);
        //auth
        getline(cin, buf);
        books[index].author = buf;
        saveInMap(buf, index, m[2]);

        //keys
        getline(cin, buf);
        stringstream ss(buf);
        string key;
        while(ss >> key){
            books[index].keys.push_back(key);
            saveInMap(key, index, m[3]);
        }

        //publisher
        getline(cin, buf);
        books[index].pub = buf;
        saveInMap(buf, index, m[4]);

        //pub year
        getline(cin, buf);
        books[index].pub_year = buf;
        saveInMap(buf, index, m[5]);
        index++;
    }

    int M;
    cin >> M;
    getline(cin, buf);
    for(int i=0; i<M; i++){
        getline(cin, buf);
        int type = buf[0]-'0';
        cout << buf << endl;
        string query = buf.substr(3,buf.size()-3);
        //cout << query << endl;
        //output
        vector<int> res;
        if(!m[type].count(query)){
            cout << "Not Found" << endl;
        }
        else{
            res = m[type][query];
            sort(res.begin(), res.end(), comparison);
            for(int j=0; j<res.size(); j++){
                cout << books[res[j]].ID << endl;
            }
        }
    }
    return 0;
}
