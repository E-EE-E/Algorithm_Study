#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int main(){
    int n, temp;
    vector<vector<int>> arr, comb;
    cin>>n;
    arr.assign(4, {});
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            cin>>temp;
            arr[j].push_back(temp);
        }
    }
    comb.assign(2, {});
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            comb[0].push_back(arr[0][i]+arr[1][j]);
            comb[1].push_back(arr[2][i]+arr[3][j]);
        }
    }
    sort(comb[0].begin(), comb[0].end());
    sort(comb[1].rbegin(), comb[1].rend());
    long long a_ind=0, b_ind=0, cnt=0, a_same=1, b_same=1;
    while(b_ind<comb[1].size()-1 && comb[1][b_ind]==comb[1][b_ind+1]){
        b_ind++;
        b_same++;
    }
    while(a_ind<comb[0].size()){
        a_same=1;
        while(a_ind<comb[0].size()-1 && comb[0][a_ind]==comb[0][a_ind+1]){
            a_ind++;
            a_same++;
        }
        while(b_ind<comb[1].size()-1 && comb[0][a_ind]+comb[1][b_ind]>0){
            b_ind++;
            b_same=1;
            while(b_ind<comb[1].size()-1 && comb[1][b_ind]==comb[1][b_ind+1]){
                b_ind++;
                b_same++;
            }
        }
        cnt+=a_same*b_same*(comb[0][a_ind]+comb[1][b_ind]==0);
        a_ind++;
    }
    cout<<cnt;
}