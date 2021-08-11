#include "iostream"
#include "vector"
#include "map"
using namespace std;

int main(){
    int n;
    vector<int> arr;
    cin>>n;
    map<int, long long> cache[99];
    arr.assign(n, 0);
    for(int i=0;i<n;i++) cin>>arr[i];
    cache[0][arr[0]]=1;
    int ind=1;
    while(ind<n-1){
        if(ind==n-1) break;
        for(auto x : cache[ind-1]){
            if(x.first+arr[ind]<=20) cache[ind][x.first+arr[ind]]+=cache[ind-1][x.first];
            if(x.first-arr[ind]>=0) cache[ind][x.first-arr[ind]]+=cache[ind-1][x.first];
        }
        ind++;
    }
    cout<<cache[ind-1][arr[ind]];
}
