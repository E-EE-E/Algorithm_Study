//시간초과
//ananant , ant -> 반례(무한루프)
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//string arr, boom;
//int x=0;
//
//void boomboom(int po){
//    int it=1;
//    while(it<boom.length() && po+it<arr.length()){
//        if(arr[po+it]==boom[0]) {
//            boomboom(po+it);
//            break;
//        }
//        else if(arr[po+it]==boom[it]) it++;
//        else break;
//    }
//    if(it!=boom.length()) x = x < po? po : x;
//    else arr.erase(po, it);
//    return;
//}
//
//void find(){
//    while(x<arr.length()){
//        if(arr[x]==boom[0]) boomboom(x);
//        else    x++;
//    }
//}
//
//int main(){
//    cin>>arr>>boom;
//    find();
//    if(arr=="") cout<<"FRULA";
//    else cout<<arr;
//}
