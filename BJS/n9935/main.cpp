//stack이용 (vector)
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<char> v;
string s, bomb;

int main(){

    cin >> s >> bomb;
    int s_size = (int)s.size();
    int bomb_size = (int)bomb.size();

    for (int i = 0; i < s_size; i++)
    {
        v.push_back(s[i]);

        if((int)v.size() >= bomb_size){
            bool flag = true;
            for (int i = 0; i < bomb_size; i++)
            {
                // 문자열폭탄인지 판별
                if(v[v.size()-bomb_size+i] != bomb[i]){
                    flag = false;
                    break;
                }
            }
            
            // 문자열 폭발
            if(flag){
                for (int i = 0; i < bomb_size; i++){
                    v.pop_back();
                }
            }
        }
    }
    
    if(v.empty()){
        cout << "FRULA";
    }else{
        for (int i = 0; i < (int)v.size(); i++){
           cout << v[i];
        }
    }
}
