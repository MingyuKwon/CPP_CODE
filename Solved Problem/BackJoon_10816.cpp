#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

const int rangeUnit = 10000000;
int cardArray[rangeUnit * 2 + 1];

// 백준 제출용 폼
int main(int argc, char const* argv[]) {
    ios::sync_with_stdio(false); // c와 c++ 입력 동기화 끊어서 속도 향상
    cin.tie(NULL); // cin과 cout의 동기화를 끊어서 속도 향상
    cout.tie(NULL); // cin과 cout의 동기화를 끊어서 속도 향상

    int count;
    cin >> count;

    int inputValue;
    map<int, int> cardMap;

    for (int i = 0; i < count; i++)
    {
        cin >> inputValue;
        cardArray[inputValue + rangeUnit]++;
    }

    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> inputValue;
        cout << to_string(cardArray[inputValue + rangeUnit])  + " ";
    }

    return 0;
}
