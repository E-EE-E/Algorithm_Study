//run time out
#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;

int N, K, max_cnt=0;
vector<string> arr;
vector<char> alphabet{'b','d','e','f','g','h','j','k','l','m','o','p','q','r','s','u','v','w','x','y','z'}, def{'a','c','i','n','t'};
unordered_map<char, int> ind;
vector<vector<int>> cnt;
vector<int> check(22), check_arr(22);

void count(int cn, int po){
    if(cn==K-5){
        int max_local=0, flag;
        for(auto temp : cnt){
            flag=0;
            for(int i=0;i<21;i++) if(check[i]<temp[i]) flag=1;
            if(flag==0) max_local++;
        }
        if(max_local>max_cnt) max_cnt = max_local;
        return;
    }

    for(int i=po+1;i<22;i++){
        if(check_arr[i]==1){
            check[i]=1;
            count(cn+1, i);
            check[i]=0;
        }
    }
    return;
}

int main(){
    cin>>N>>K;
    for(int i=0;i<N;i++){
        string temp;
        cin>>temp;
        arr.push_back(temp);
        cnt.push_back({});
        cnt[i].assign(22, 0);
    }
    if(K<5){ cout << max_cnt; return 0; }
    if(K==26){ cout << N; return 0; }
    for(int i=0;i<alphabet.size();i++) ind[alphabet[i]]=i;
    for(int i=0;i<def.size();i++) ind[def[i]]=21;
    for(int i=0;i<N;i++){
        for(int j=4;j<arr[i].size()-4;j++){
            cnt[i][ind[arr[i][j]]]=1;
            check_arr[ind[arr[i][j]]]=1;
        }
    }
    count(0, -1);
    cout<<max_cnt;
}