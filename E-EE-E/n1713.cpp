#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

bool compare(vector<int> x, vector<int> y){
    if(x[1]==y[1]) return x[2]>y[2];
    return x[1]>y[1];
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> array;
    int temp, flag=0;
    for(int i=0;i<m;i++){
        flag=0;
        cin>>temp;
        for(int j=0;j<array.size();j++){
            if(temp==array[j][0]) {array[j][1]++; flag=1;}
        }
        if(flag==1) continue;
        sort(array.begin(), array.begin()+array.size(), compare);
        if(array.size()==n) array.pop_back();
        array.push_back({temp, 1, i});
        //for(int j=0;j<array.size();j++) printf("%d %d %d\\", array[j][0], array[j][1], array[j][2]);
        //printf("\n");
    }
    sort(array.begin(), array.begin()+array.size());
    for(auto x : array){
        printf("%d ", x[0]);
    }
}