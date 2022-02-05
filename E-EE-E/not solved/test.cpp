#include "iostream"
using namespace std;
int main(){
    string temp = "123";
    int num = atoi(temp.c_str()+1);

    //printf("%d ", num);
    cout<<num;
}