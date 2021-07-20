#include "iostream"
#include "string"
using namespace std;

int n, k, arr[50][26], check[26], result=0;

void dfs(int size, int pos){
    if(size==k){
        int max_local=0, flag;
        for(int i=0;i<n;i++){
            flag=0;
            for(int j=0;j<26;j++){
                if(check[j]==1) continue;
                if(arr[i][j]==1) flag=1;
            }
            if(flag==0) max_local++;
        }
        if(result<max_local) result=max_local;
        return;
    }
    for(int i=pos+1;i<26;i++){
        if(check[i]==1) continue;
        check[i]=1;
        dfs(size+1, i);
        check[i]=0;
    }
}

int main(){
    scanf("%d %d", &n, &k);
    string temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        for(auto tt : temp) arr[i][tt-'a']=1;
    }
    if(k<5){
        printf("0\n");
        return 0;
    }
    else if(k==26){
        printf("%d\n", n);
        return 0;
    }
    check['a'-'a']=check['c'-'a']=check['i'-'a']=check['n'-'a']=check['t'-'a']=1;
    dfs(5, -1);
    printf("%d\n", result);
    return 0;
}