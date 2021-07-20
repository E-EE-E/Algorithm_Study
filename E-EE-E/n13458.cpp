#include "iostream"
#include "vector"
using namespace std;

int main(){
    int n, b, c;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cin>>b>>c;
    long long sum=0;
    for(auto x : arr) sum+=1+(((x-b+c-1)/c)>0?((x-b+c-1)/c):0);
    cout<<sum;
}