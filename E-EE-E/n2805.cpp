#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

bool comp(int x, int y){
    return x>y;
}

int main(){
    int N, M, temp;
    vector<int> arr;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.begin()+arr.size(), comp);

    int k=arr[0], cnt=0, sum=0;
    while(k>-1){
        if(cnt<arr.size() && k<arr[cnt]){
            cnt++;
            continue;
        }
        sum+=cnt;
        if(sum>=M){
            printf("%d\n", k);
            break;
        }
        k--;
    }
}