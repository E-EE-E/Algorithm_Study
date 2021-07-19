#include "iostream"
#include "vector"
using namespace std;

int main(){
    int temp;
    vector<int> arr, sub, sub_inds;
    while(scanf("%d", &temp)!=EOF) arr.push_back(temp);
    if(arr.size()){
        sub.push_back(arr[0]);
        sub_inds.push_back(sub.size()-1);
    }   
    int ind=1;
    while(ind<arr.size()){
        if(arr[ind]<sub[sub.size()-1]){
            sub.push_back(arr[ind]);
            sub_inds.push_back(sub.size()-1);
        }
        else{
            int sub_ind=sub.size()-1;
            while(sub_ind>=0 && sub[sub_ind]<arr[ind]) sub_ind--;
            sub_ind++;
            while(sub_inds[sub_inds.size()-1]!=sub_ind){
                while(sub.size()>sub_inds[sub_inds.size()-1]){
                    printf("%d\n", sub[sub.size()-1]);
                    sub.pop_back();
                }
                sub_inds.pop_back();
            }
            sub.push_back(arr[ind]);
        }
        ind++;
    }
    for(int i=0;i<sub.size();i++) printf("%d\n", sub[sub.size()-i-1]);
}