#include "iostream"
#include "vector"
using namespace std;
vector<long long> cache;

long long factorial(int x){
    if(cache[x]) return cache[x];
    long long result=1;
    while(x>0) result*=x--;
    cache[x]=result;
    return result;
}

int main(){
    int n, m;
    long long k=0;
    cin>>n>>m;
    vector<int> arr(n,0), visit(n,0);
    cache.assign(n,0);
    if(m==1){
        cin>>k;
        int cnt=0;
        while(cnt<n){
            for(int i=0;i<n;i++){
                if(visit[i]) continue;
                if(k<=factorial(n-cnt-1)){
                    visit[i]=1;
                    arr[cnt++]=i+1;
                    break;
                }
                k-=factorial(n-cnt-1);
            }
        }
        for(auto x : arr) cout<<x<<" ";
    }
    else if(m==2){
        for(int i=0;i<n;i++) cin>>arr[i];
        int cnt=0;
        while(cnt<n){
            for(int i=0;i<n;i++){
                if(visit[i]) continue;
                if(arr[cnt]==i+1){
                    cnt++;
                    visit[i]=1;
                    break;
                }
                k+=factorial(n-cnt-1);
            }
        }
        cout<<++k;
    }
}