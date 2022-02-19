// https://www.acmicpc.net/problem/1052
#include "iostream"
using namespace std;
int main(){
    int ind = 1<<30;
    int cnt=0;
    int N, K;
    scanf("%d %d", &N, &K);
    while(ind>0 && cnt < K){
        if((bool)(N&ind)){
            N-=N&ind;
            cnt++;
        }
        ind >>= 1;
    }
    int result=0;
    while(ind>0){
        result += (-N)&ind;
        ind>>=1;
    }
    printf("%d", result);
}