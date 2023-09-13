#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;


// 백준 제출용 폼
int main(int argc, char const* argv[]) {
    ios::sync_with_stdio(false); // c와 c++ 입력 동기화 끊어서 속도 향상
    cin.tie(NULL); // cin과 cout의 동기화를 끊어서 속도 향상
    cout.tie(NULL); // cin과 cout의 동기화를 끊어서 속도 향상

    map<string, string, greater<>> isInOffice;

    int logcount;
    cin >> logcount;

    string People;
    string isEnterLeave;

    for (int i = 0; i < logcount; i++)
    {
        cin >> People >> isEnterLeave;
        isInOffice[People] = isEnterLeave;
    }


    // 이거로 출력하면 시간 안에 잘 들어왔지만,
    map<string, string>::iterator it;
    for (it = isInOffice.begin(); it != isInOffice.end(); it++) {
        if (it->second == "enter") {
            cout << it->first << "\n";
        }
    }

    // 이걸로 출력하면 바로 시간 오버가 났다 왜 일까?

    for (auto item : isInOffice)
    {
        if (item.second == "enter")
        {
            cout << item.first << endl;
        }
    }
    
    return 0;
}






