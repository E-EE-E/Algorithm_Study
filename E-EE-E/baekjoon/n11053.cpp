// https://www.acmicpc.net/problem/11053

#include "iostream"
#include "vector"
using namespace std;
int main(){
    int N;
    scanf("%d", &N);
    vector<int> arr;
    for(size_t i = 0 ; i < N ; i++){
        int temp;
        scanf("%d", &temp);
        arr.emplace_back(temp);
    }
    vector<int> len;
    len.emplace_back(1);
    for(size_t i = 1 ; i < N ; i++){
        len.emplace_back(1);
        for(size_t j = 0 ; j < i ; j++){
            if(arr[j] < arr[i] && len[j] >= len[i]){
                len[i]=1+len[j];
            }
        }
    }
    int max = 0;
    for(auto temp : len) max=temp>max?temp:max;
    printf("%d", max);
}