#include "iostream"
#include "string"
#include "set"
using namespace std;

int main(){
    int n, k, max=0;
    scanf("%d %d", &n, &k);
    int size=to_string(n).size();
    set<string> thisarr;
    thisarr.insert((string)to_string(n));
    while(k--){
        set<string> nextarr;
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                for(auto x : thisarr){
                    swap(x[i], x[j]);
                    if(x[0]=='0') continue;
                    nextarr.emplace(x);
                }
            }
        }
        thisarr=nextarr;
    }
    if(thisarr.size()>0) cout<<*prev(thisarr.end());
    else cout<<"-1";
}