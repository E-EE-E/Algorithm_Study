#include "stdio.h"
#include "vector"
using namespace std;

class biTree{
private:
    vector<int> arr;
    int size;
public:
    biTree():size(0){}
    void push(int x){
        size++;
        if(arr.size()<size){
            if(!arr.size()) arr.resize(2, 0);
            else{
                arr.resize(arr.size()<<1, 0);
                arr[arr.size()-1]+=arr[arr.size()/2-1];
            }
        }
        arr[size-1]+=x;
        int ind=(size&(-size))+size;
        while(ind<=arr.size()){
            arr[ind-1]+=x;
            ind=(ind&(-ind))+ind;
        }
    }

    int sum(int ind){
        int result=0;
        while(ind>0){
            result+=arr[ind-1];
            ind-=ind&(-ind);
        }
        return result;
    }

    int rangeSum(int a, int b){
        return sum(b)-sum(a-1);
    }

};

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    int temp;
    biTree arr;
    for(int i=0;i<N;i++){
        scanf("%d", &temp);
        arr.push(temp);
    }
    int a, b;
    while(M--){
        scanf("%d %d", &a, &b);
        printf("%d\n", arr.rangeSum(a, b));
    }
}