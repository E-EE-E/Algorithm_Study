// https://www.acmicpc.net/problem/1002
#include "iostream"

int cal(){
    int  x1, y1, r1, x2, y2, r2;
    scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
    int disSqur = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    int sumLenSqur = (r1+r2)*(r1+r2);
    int delLenSqur = (r1-r2)*(r1-r2);
    if(x1==x2 && y1==y2){
        if(r1==r2) return -1;
        else return 0;
    }
    else if(disSqur==sumLenSqur || disSqur==delLenSqur) return 1;
    else if(disSqur>sumLenSqur || disSqur<delLenSqur) return 0;
    else return 2;
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--)
        printf("%d\n", cal());
}