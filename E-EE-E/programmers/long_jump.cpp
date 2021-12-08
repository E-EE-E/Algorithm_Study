//https://programmers.co.kr/learn/courses/30/lessons/12914
#include "iostream"
#include <vector>

using namespace std;

vector<long long> cache;

long long dp(int x){
    if(cache[x]!=0) return cache[x];
    if(x-1>=0) (cache[x]+=dp(x-1))%=1234567;
    if(x-2>=0) (cache[x]+=dp(x-2))%=1234567;
    return cache[x];
}

long long solution(int n) {
    long long answer = 0;
    
    cache.assign(n+1,0);
    cache[0]=1;
    answer=dp(n);
    return answer;
}

int main(){
    int n=10;
    cout<<solution(n);
}