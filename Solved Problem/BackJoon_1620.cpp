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

    map<string, int> pokemon;
    map<int, string> num;

    int monsterCount;
    int quesCount;

    cin >> monsterCount >> quesCount;

    string MonsterName;

    for (int i = 0; i < monsterCount; i++)
    {
        cin >> MonsterName;
        pokemon[MonsterName] = i+1;
        num[i + 1] = MonsterName;
    }

    string answer;

    vector<string> result;

    for (int i = 0; i < quesCount; i++)
    {
        cin >> answer;

        if ((answer[0] >= 'a' && answer[0] <= 'z') || (answer[0] >= 'A' && answer[0] <= 'Z'))
        {
            result.push_back(to_string(pokemon[answer]));
        }
        else
        {
            result.push_back(num[stoi(answer)]);
        }
    }

    for (int i = 0; i < result.size();i++) {
        cout << result[i] << '\n'; // 출력
    }
    
    return 0;
}






