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
    stack<char> STACK;

    string input;
    while (true) {

        getline(cin, input);
        if (input == ".")
            break;

        while (!STACK.empty()) {
            STACK.pop();
        }

        bool flag = true;

        for (char ch : input)
        {
            if (ch == '(')
            {
                STACK.push('(');
            }
            else if (ch == '[')
            {
                STACK.push('[');
            }
            else if (ch == ')')
            {
                if ((!STACK.empty()) && (STACK.top() == '('))
                {
                    STACK.pop();
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            else if (ch == ']')
            {
                if ((!STACK.empty()) && (STACK.top() == '['))
                {
                    STACK.pop();
                }
                else
                {
                    flag = false;
                    break;
                }
            }
        }

        if (flag && STACK.empty())
        {
            cout << "yes" << endl;
            //resultVector.push_back("yes");
        }
        else
        {
            cout << "no" << endl;
            //resultVector.push_back("no");
        }
    }



    //for (auto ans : resultVector)
    //{
       // cout << ans << endl;
    //}

    return 0;
}
