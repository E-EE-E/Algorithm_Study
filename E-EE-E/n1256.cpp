#include "iostream"
#include "vector"
using namespace std;

#define MAX 1000000000
vector<vector<long long>> cache;

long long comb(int n, int k){
    k=k<(n-k)?k:(n-k);
    if(k<0) return 0;
    if(k==0) return 1;
    if(cache[n][k]) return cache[n][k];
    cache[n][k]=comb(n-1, k-1)+comb(n-1, k);
    if(cache[n][k]>MAX) cache[n][k]=MAX+1;
    return cache[n][k];
}
int main(){
    int n,m;
    long long k;
    scanf("%d %d %d", &n,&m,&k);
    cache.assign(n+m, {});
    for(int i=0;i<n+m;i++) cache[i].assign(i+1, 0);
    int position=0;
    vector<char> ans;
    while(position<n+m){
        if((n==0 || m==0) && k>1){
            ans={'-', '1'};
            break;
        }
        //printf("k=%d comb(%d, %d)=%d\n", k, n+m-1, n-1, comb(n+m-1, n-1));
        if(k>comb(n+m-1, n-1)){
            ans.push_back('z');
            k-=comb(n+m-1, n-1);
            m--;
        }
        else if(k<comb(n+m-1, n-1)){
            ans.push_back('a');
            n--;
        }
        else{
            ans.push_back('a');
            n--;
            position++;
            while(n+m>0){
                if(m>0){
                    ans.push_back('z');
                    m--;
                }
                else if(n>0){
                    ans.push_back('a');
                    n--;
                }
                position++;
            }
        }
    }
    for(auto x : ans)printf("%c", x);
}