#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

// 백준 제출용 폼
int main(int argc, char const* argv[]) {
    ios::sync_with_stdio(false); // c와 c++ 입력 동기화 끊어서 속도 향상
    cin.tie(NULL); // cin과 cout의 동기화를 끊어서 속도 향상
    cout.tie(NULL); // cin과 cout의 동기화를 끊어서 속도 향상

    int notHearCount;
    int notSeeCount;

    cin >> notHearCount >> notSeeCount;

    vector<string> resultVector;
    map<string, int> MAP;

    string input;

    for (int i = 0; i < notHearCount; i++)
    {
        cin >> input;
        MAP[input] = 1;
    }

    int Count = 0;

    for (int i = 0; i < notSeeCount; i++)
    {
        cin >> input;
        if (MAP.find(input) != MAP.end())
        {
            Count++;
            resultVector.push_back(input);
        }
        
    }

    sort(resultVector.begin(), resultVector.end());
    
    cout << Count << endl;
    for (auto ans : resultVector)
    {
        cout << ans << endl;
    }

    return 0;
}
