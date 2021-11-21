#include "iostream"
#include "vector"
using namespace std;

class heap {
private:
    vector<int> arr;
public:
    int pop(){
        if(arr.size()==0) return 0;
        int result, ind=1, temp;
        result=arr[0];
        arr[0]=arr[arr.size()-1];
        arr.pop_back();
        while(2*ind<arr.size()){
            temp=ind;
            for(int i=0;i<2;i++){
                if(arr[temp-1]<arr[2*ind-i]){
                    temp=2*ind-i+1;
                }
            }
            if(ind==temp) break;
            else{
                swap(arr[ind-1], arr[temp-1]);
                ind=temp;
            }
        }
        if(2*ind==arr.size() && arr[ind-1]<arr[2*ind-1]) swap(arr[ind-1], arr[2*ind-1]);
        return result;
    }
    void add(int x){
        arr.push_back(x);
        int ind=arr.size(), temp;
        while(ind>1 && arr[ind-1]>arr[(ind/2)-1]){
            swap(arr[ind-1], arr[(ind/2)-1]);
            ind/=2;
        }
    }
};

int main(){
    int n, temp;
    heap arr;
    vector<int> ans;
    scanf("%d", &n);
    for(int i=0; i<n;i++){
        scanf("%d", &temp);
        if(temp==0) ans.push_back(arr.pop());
        else arr.add(temp);
    }
    for(auto x : ans) printf("%d\n", x);
}