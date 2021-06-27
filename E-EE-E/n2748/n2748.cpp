#include "iostream"
#include "vector"
using namespace std;

int main(){
    vector<long long> arr={0, 1};
    int n;
    cin>>n;
    for(int i=2;i<=n;i++) arr.push_back(arr[i-1]+arr[i-2]);
    cout<<arr[arr.size()-1];
}