#include "iostream"
#include "vector"
using namespace std;

int main(){
    int n, m;
    vector<unsigned int> arr;
    cin>>n>>m;
    int temp, sum=0, cnt=0, start=0;
    for(int i=0;i<n;i++){
        cin>>temp;
        arr.push_back(temp);
        sum+=temp;
        while(sum>m) sum-=arr[start++];
        cnt+=sum==m;
    }
    cout<<cnt;
}