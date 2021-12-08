//https://programmers.co.kr/learn/courses/30/lessons/42895?language=cpp
#include "iostream"
#include <string>
#include <vector>
#include "set"

using namespace std;

int solution(int N, int number) {
    vector<set<int>> check(9);
    int temp=0;
    for(int i=1;i<9;i++){
        temp=temp*10+N;
        check[i].emplace(temp);
    }
    for(int i=1;i<9;i++){
        for(int j=1;j+i<9;j++){
            for(auto x : check[i]){
                for(auto y : check[j]){
                    temp=x+y;
                    if(temp>0 && temp<=32001 && i+j<9) check[i+j].emplace(temp);
                    temp=x-y;
                    if(temp>0 && temp<=32001 && i+j<9) check[i+j].emplace(temp);
                    temp=x*y;
                    if(temp>0 && temp<=32001 && i+j<9) check[i+j].emplace(temp);
                    temp=x/y;
                    if(temp>0 && temp<=32001 && i+j<9) check[i+j].emplace(temp);
                }
            }
        }
    }
    for(int i=1;i<9;i++){
        if(check[i].find(number)!=check[i].end()) return i;
    }
    return -1;
}

int main(){
    int N=8, number=53;
    printf("%d", solution(N, number));
    return 0;
}