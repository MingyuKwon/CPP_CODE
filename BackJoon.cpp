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

    vector<string> resultVector;
   
    int input;
    int count;

    vector<int> LINE;
    stack<int> STACK;

    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> input;
        LINE.push_back(input);
    }

    int currentTurn = 1;

    int vectorOutIndex = 0;

    bool flag = true;

    while (currentTurn <= count)
    {

        if (vectorOutIndex >= LINE.size() && STACK.top() != currentTurn)
        {
            flag = false;
            break;
        }

        if (vectorOutIndex < LINE.size() && LINE[vectorOutIndex] == currentTurn)
        {
            vectorOutIndex++;
            currentTurn++;
        }
        else if(!STACK.empty() && STACK.top() == currentTurn)
        {
            STACK.pop();
            currentTurn++;
        }
        else
        {
            STACK.push(LINE[vectorOutIndex]);
            vectorOutIndex++;
        }
    }

    if (flag)
    {
        cout << "Nice";
    }
    else
    {
        cout << "Sad";
    }
    


    
    return 0;
}
