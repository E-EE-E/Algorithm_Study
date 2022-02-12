// https://programmers.co.kr/learn/courses/30/lessons/92342?language=cpp
#include "iostream"
#include <string>
#include <vector>

using namespace std;

int n_;
vector<bool> check;
vector<int> info_;
vector<int> result;
int gap=0;

// return -1 : a<b | 0 : a==b | 1 : a>b
int compare(vector<int>& a, vector<int>& b){
    for(size_t i=a.size()-1; i>=0; i--){
        if(a[i]>b[i]) return 1;
        else if(a[i]<b[i]) return -1;
    }
    return 0;
}

void calculate(){
    int cnt=0, sum=0;
    int lost=0;
    vector<int> temp;
    temp.assign(11, 0);
    for(size_t i=0;i<info_.size()-1;i++){
        if(check[i]){
            cnt+=info_[i]+1;
            temp[i] = info_[i]+1;
            sum+=10-i;
        }
    }
    temp[10] = n_ - cnt;
    for(size_t i=0;i<check.size()-1;i++){
        if(!check[i] && info_[i]!=0) lost+=10-i;
    }
    if(cnt<=n_ && (sum-lost)>=gap ){
        if((sum-lost)==gap && compare(temp, result)!=1) return;
        result = temp;
        gap = sum - lost;
    }
}

void setter(size_t ind){
    if(ind==10){
        calculate();
        return;
    }
    setter(ind+1);
    check[ind]=!check[ind];
    setter(ind+1);
}

vector<int> solution(int n, vector<int> info) {
    n_ = n;
    info_ = info;
    check.assign(10, false);
    result.assign(11, 0);
    setter(0);
    if(gap==0) return {-1};
    return result;
}

int main(){
    // int n=5;
    // vector<int> info = {2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
    // vector<int> answer = {2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0};

    int n = 9;
    vector<int> info = {0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1};
    vector<int> answer = {0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1};
    vector<int> my_answer = solution(n, info);
    for(auto x : my_answer){
        printf("%d, ", x);
    }
}