//https://programmers.co.kr/learn/courses/30/lessons/43165?language=cpp
#include "iostream"
#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> numbers, int target) {
    map<int, int> arr, temp;
    arr[0]=1;
    for(auto x : numbers){
        temp.clear();
        for(auto y : arr){
            temp[y.first+x]+=y.second;
            temp[y.first-x]+=y.second;
        }
        arr=temp;
    }
    int answer = arr[target];
    return answer;
}

int main (){
    vector<int> numbers = { 1, 1, 1, 1, 1};
    int target = 3;
    cout<<solution(numbers, target);    // == 5
}