//시간초과(string 사용해서 insert하면 하나씩 밀리면서 O(M*M)인듯함
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//int main(int argc, const char * argv[]) {
//    string a;
//    cin>>a;
//    int curpos = (int)a.size();
//    int m;
//    cin>>m;
//    for(int i = 0; i < m; ++i) {
//        char cmd;
//        cin>>cmd;
//        if(cmd == 'L') {
//            if(curpos == 0) continue;
//            curpos = max(0, curpos-1);
//        }
//        else if(cmd == 'D') {
//            if(curpos == (int)a.size()) continue;
//            curpos = min((int)a.size(), curpos+1);
//        }
//        else if(cmd == 'B') {
//            if(curpos == 0) continue;
//            curpos -= 1;
//            a.erase(a.begin()+curpos);
//        }
//        else if(cmd == 'P') {
//            char s;
//            cin>>s;
//            a.insert(a.begin()+curpos, s);
//            curpos += 1;
//        }
//    }
//
//    cout<<a<<'\n';
//
//    return 0;
//}
