#include "iostream"
#include "vector"
using namespace std;

void print(char *str, vector<vector<int>> arr){
    printf("%s\n", str);
    for(auto x : arr){
        for(auto y : x) printf("%d ", y);
        printf("\n");
    }
}

int main(){
    int n;
    int arr[2][3], min_arr[2][3], max_arr[2][3], way[3]={-1, 0, 1};
    scanf("%d", &n);
    for(int j=0;j<3;j++){
        scanf("%d", &arr[0][j]);
        min_arr[0][j]=max_arr[0][j]=arr[0][j];
        min_arr[1][j]=max_arr[1][j]=-1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++) scanf("%d", &arr[1][j]);
        for(int j=0;j<3;j++){
            for(auto w : way){
                if(j+w<0 || j+w>2) continue;
                if(min_arr[1][j]==-1 || min_arr[1][j]>min_arr[0][j+w]+arr[1][j])
                    min_arr[1][j]=min_arr[0][j+w]+arr[1][j];
                if(max_arr[1][j]==-1 || max_arr[1][j]<max_arr[0][j+w]+arr[1][j])
                    max_arr[1][j]=max_arr[0][j+w]+arr[1][j];
            }
        }
        for(int j=0;j<3;j++){
            arr[0][j]=arr[1][j];
            arr[1][j]=-1;
            min_arr[0][j]=min_arr[1][j];
            min_arr[1][j]=-1;
            max_arr[0][j]=max_arr[1][j];
            max_arr[1][j]=-1;
        }
    }
    int min=-1, max=-1;
    for(int i=0;i<3;i++){
        if(min==-1 || min>min_arr[0][i]) min=min_arr[0][i];
        if(max==-1 || max<max_arr[0][i]) max=max_arr[0][i];
    }
    printf("%d %d\n", max, min);
}