#include "iostream"
#include "unordered_map"
using namespace std;

int main(){
    int n, m, temp;
    unordered_map<int, int> arr;
    arr.clear();
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &temp);
        arr[temp]=1;
    }
    cin >> m;
    for(int i=0;i<m;i++){
        scanf("%d", &temp);
        if(arr[temp]==1) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}