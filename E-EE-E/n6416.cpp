#include "iostream"
#include "map"
using namespace std;

map<int, int> from; //from[v]=u -> 'u' node fan out to 'v' node
map<int, int> check;

int find(int x){
    if(from[x]==0) return x;
    check[x]=1;
    return check.find(from[x])==check.end()?find(from[x]):x;
}

int main(){
    int u, v, k=0, root, temp;
    
    bool isTree=true;
    while(scanf("%d %d", &u, &v)){
        if(u<0 && v<0) break;
        if(u==0 && v==0){
            k++;
            root=0;
            //if root cnt is more than 2 -> isTree=false || find root
            for(auto x : from){
                if(x.second==0){
                    if(root==0) root=x.first;
                    else isTree=false;
                }
            }
            //is all node can reach to root?
            for(auto x : from){
                check.clear();
                if(x.first!=root && find(x.first)!=root) isTree=false;
            }
            //print
            printf("Case %d is %sa tree.\n", k, isTree?"":"not ");
            //clean
            isTree=true;
            from.clear();
        }
        else{
            if(from.find(v)!=from.end() && from[v]!=0) isTree=false;
            from[v]=u;
            if(from.find(u)==from.end()) from[u]=0;
        }
    }
}