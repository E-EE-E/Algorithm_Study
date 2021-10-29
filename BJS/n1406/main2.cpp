#include <iostream>
#include <string>
#include <list> //연결리스트
#include <algorithm>
using namespace std;

int M;
string s = "";
string ans = "";
list<char> li;
list<char>::iterator it;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    // 연결리스트에 원소 할당
    li = list<char>(s.begin(), s.end());
    it = li.end();
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        char cmd, c;
        cin >> cmd;

        if (cmd == 'L')
        {
            if(it != li.begin())
                it--;
        }
        else if (cmd == 'D')
        {
            if(it != li.end())
                it++;
        }
        else if (cmd == 'B')
        {
            if(it != li.begin())
            {
                it--;
                it = li.erase(it);         // 삭제 //return : 지운자리
            }
        }
        else if (cmd == 'P')
        {
            cin >> c;
            li.insert(it, c); // 문자 c 삽입 //insert : 문제P와 같은동작
        }
    }

    // 연결리스트 출력
    for (it = li.begin(); it != li.end(); it++)
        cout << *it;
    cout<<'\n';
    
    return 0;
}
