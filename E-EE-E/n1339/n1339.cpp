#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
using namespace std;

vector<int> cnt(26);

bool comp(int x, int y){
    return x>y;
}

int pow(int x, int y){
    int result=1;
    while(y-->0) result*=x;
    return result;
}

int main(){
    int n;
    cin>>n;
    string temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        for(int j=0;j<temp.size();j++) cnt[temp[j]-'A']+=pow(10, (temp.size()-j-1));
    }
    sort(cnt.begin(), cnt.begin()+26, comp);
    int result=0;
    for(int i=0;i<9;i++) result+=cnt[i]*(9-i);
    cout << result;
}