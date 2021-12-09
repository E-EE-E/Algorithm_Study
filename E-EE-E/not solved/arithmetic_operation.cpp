//https://programmers.co.kr/learn/courses/30/lessons/1843
#include "iostream"
#include <vector>
#include <string>
using namespace std;

int solution(vector<string> arr)
{
    vector<int> numArr;
    vector<bool> operArr ={true};
    for(int i=0;i<arr.size();i+=2) numArr.push_back(stoi(arr[i]));
    for(int i=1;i<arr.size();i+=2) operArr.push_back(arr[i]=="+"?true:false);
    vector<int> spot;
    for(int i=0;i<operArr.size();i++) if(!operArr[i]) spot.push_back(i);

    int answer = -1;
    return answer;
}

int main(){
    vector<string> arr = {"1", "-", "3", "+", "5", "-", "8"};
    cout<<solution(arr);
}