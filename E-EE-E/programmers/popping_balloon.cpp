//https://programmers.co.kr/learn/courses/30/lessons/68646
#include "iostream"
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    vector<int> check(a.size(), 0);
    int min=1000000001;
    for(int i=0;i<a.size();i++){
        if(a[i]<min){
            min=a[i];
            check[i]++;
        }
    }
    min=1000000001;
    for(int i=a.size()-1;i>=0;i--){
        if(a[i]<min){
            min=a[i];
            check[i]++;
        }
    }
    for(int i=0;i<a.size();i++)
        if(check[i]>0) answer++;
    return answer;
}

int main(){
    vector<int> a;
    a={-16,27,65,-2,58,-92,-71,-68,-61,-33};
    cout<<solution(a);
    return 0;
}