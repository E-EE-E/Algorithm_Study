//https://programmers.co.kr/learn/courses/30/lessons/1843
#include "iostream"
#include <vector>
#include <string>
using namespace std;

int funcMin(int x, int y) {return x<y?x:y;}
int funcMax(int x, int y) {return x>y?x:y;}

int solution(vector<string> arr)
{
    int ind=arr.size(), temp=0;
    vector<int> buffer={0,0};
    while(--ind>=0){
        if(ind%2==0) temp+=stoi(arr[ind]);
        else if(arr[ind]=="-"){
            vector<int> tempBuffer=buffer;
            buffer[0]=funcMin(-(tempBuffer[1]+temp), tempBuffer[0]-temp);
            buffer[1]=funcMax(-(tempBuffer[0]+temp), tempBuffer[1]+temp-2*stoi(arr[ind+1]));
            temp=0;
        }
    }
    return buffer[1]+temp;
}

int main(){
    vector<string> arr = {"1", "-", "3", "+", "5", "-", "8"};
    cout<<solution(arr);
}