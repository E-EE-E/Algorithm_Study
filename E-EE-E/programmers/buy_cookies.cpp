//https://programmers.co.kr/learn/courses/30/lessons/49995
#include "iostream"
#include <string>
#include <vector>

using namespace std;

int search(int x, int y, vector<int> &sum){
    int half=sum[y]-sum[x];
    if(half%2==1) return 0;
    half/=2;
    int left=x, right=y, ind;
    int temp;
    while(left<=right){
        ind=(right+left)/2;
        temp=sum[ind]-sum[x];
        if(temp==half) break;
        else if(temp<half) left=ind+1;
        else right=ind-1;
    }
    if(temp==half) return temp;
    return 0;
}

int solution(vector<int> cookie) {
    int answer = 0;
    vector<int> sum = {0};
    sum.insert(sum.end(), cookie.begin(), cookie.end());
    for(int i=0;i<sum.size()-1;i++) sum[i+1]+=sum[i];
    int temp;
    for(int i=0;i<sum.size()-2;i++){
        for(int j=i+2;j<sum.size();j++){
            temp=search(i, j, sum);
            if(temp>answer) answer=temp;
        }
    }
    return answer;
}

int main(){
    vector<int> cookie={1,1,2,3};
    cout<<solution(cookie);
    return 0;
}