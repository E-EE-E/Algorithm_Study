#include<stdio.h>
using namespace std;
class vector{
    public:
    int x, y;
};

int abs(int x){
    if(x<0) return x*(-1);
    return x;
}

vector events[1002];
vector cache[1002][1002];
int n, w;

int getMin(int car1, int car2){
    if(car1==w+1 || car2==w+1) return 0;
    if(cache[car1][car2].x!=-1) return cache[car1][car2].x;

    int maxNum=car1>car2 ? car1 : car2;
    vector way1, way2;
    way1.y=1; way2.y=2;
    way1.x=getMin(maxNum+1, car2)+abs(events[maxNum+1].x-events[car1].x)+abs(events[maxNum+1].y-events[car1].y);
    way2.x=getMin(car1, maxNum+1)+abs(events[maxNum+1].x-events[car2].x)+abs(events[maxNum+1].y-events[car2].y);
    cache[car1][car2]=way1.x<way2.x ? way1 : way2;
    return cache[car1][car2].x;
}

void getWay(int car1, int car2){
    if(car1==w+1 || car2==w+1) return;
    int maxNum = car1>car2 ? car1 : car2;
    int minWay = cache[car1][car2].y;
    printf("%d\n", minWay);
    minWay==1 ? getWay(maxNum+1, car2) : getWay(car1, maxNum+1);
}

int main (){
    for(int i=0;i<1002;i++){
        for(int j=0;j<1002;j++){
            cache[i][j].x=-1;
        }
    }
    scanf("%d %d", &n, &w);
    events[0].x=1; events[0].y=1;
    events[1].x=n; events[1].y=n;
    for(int i=2;i<w+2;i++){
        scanf("%d %d", &events[i].x, &events[i].y);
    }
    printf("%d\n", getMin(0,1));
    getWay(0,1);
}