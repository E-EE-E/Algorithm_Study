#include "iostream"
#include "vector"
using namespace std;

int main(){
    int x, y, z=-1;
    cin>>x>>y;
    for(int i=0;i<99;i++){
        if(x*((double)i/100)<=y && y<x*(((double)i+1)/100)){
            z=i;
            break;
        }
    }
    if(z==-1){
        cout<<"-1\n";
        return 0;
    }
    double k=(double)((z+1)*x-100*y)/(99-z);
    if((double)(int)k<k) k++;
        cout<<(int)k;
    return 0;
}