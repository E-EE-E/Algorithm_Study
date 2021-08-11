#include "iostream"
#include "vector"
using namespace std;

int main(){
    int N, S;
    cin>>N>>S;
    int min_len=100001, min=0, cnt=0, temp, sum=0;
    vector<int> arr;
    while(cnt++<N){
        cin>>temp;
        arr.push_back(temp);
        sum+=temp;
        while(sum>=S){
            if(min_len>cnt-min) min_len=cnt-min;
            sum-=arr[min];
            min++;
        }
    }
    if(min_len==100001) min_len=0;
    cout<<min_len;
}