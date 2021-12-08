//https://programmers.co.kr/learn/courses/30/lessons/43105
#include "iostream"
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    vector<vector<int>> cache=triangle;
    int cnt=0;
    while(cnt<triangle.size()-1){
        for(int i=0;i<cnt+1;i++){
            for(int j=0;j<2;j++)
                if(cache[cnt+1][i+j]<cache[cnt][i]+triangle[cnt+1][i+j]) cache[cnt+1][i+j]=cache[cnt][i]+triangle[cnt+1][i+j];
        }
        cnt++;
    }
    int answer = 0;
    for(auto x : cache[triangle.size()-1]) if(answer<x) answer=x;
    return answer;
}

int main(){
    vector<vector<int>> triangle={{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};
    cout<<solution(triangle);
    return 0;
}