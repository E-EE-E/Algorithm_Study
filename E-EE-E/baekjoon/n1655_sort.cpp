#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int main(){
    int n, temp;
    vector<int> arr, ans;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &temp);
        arr.push_back(temp);
        sort(arr.begin(), arr.end());
        if(arr.size()==1) ans.push_back(arr[0]);
        else ans.push_back(arr[(arr.size()-1)>>1]);
    }
    for(auto x:ans) printf("%d\n", x);
}