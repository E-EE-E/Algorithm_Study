#include "iostream"
#include "vector"
using namespace std;

class heap {
private:
    vector<int> arr;
public:
    int pop(){
        int result=0, ind=1, temp=2;
        if(arr.size()==0) return result;
        result=arr[0];
        swap(arr[0], arr[arr.size()-1]);
        arr.pop_back();
        while(temp<=arr.size()){
            if(temp+1<=arr.size() && arr[temp]<arr[temp-1]) temp++;
            if(arr[ind-1]<arr[temp-1]) break;
            swap(arr[ind-1], arr[temp-1]);
            ind=temp;
            temp=ind<<1;
        }
        return result;
    }
    void add(int x){
        arr.push_back(x);
        int ind=arr.size();
        while(ind>1 && arr[(ind>>1)-1]>arr[ind-1]){
            swap(arr[(ind>>1)-1], arr[ind-1]);
            ind>>=1;
        }
    }
};

int main(){
    int n, temp;
    heap arr;
    vector<int> ans;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &temp);
        if(!temp) ans.push_back(arr.pop());
        else arr.add(temp);
    }
    for(auto x : ans) printf("%d\n", x);
}