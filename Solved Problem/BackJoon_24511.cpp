#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>

// stack -> 있으나 마나 결과가 똑같음
// queue -> 결과에 영향을 미친다


using namespace std;

// 백준 제출용 폼
int main(int argc, char const* argv[]) {
    ios::sync_with_stdio(false); // c와 c++ 입력 동기화 끊어서 속도 향상
    cin.tie(NULL); // cin과 cout의 동기화를 끊어서 속도 향상
    cout.tie(NULL); // cin과 cout의 동기화를 끊어서 속도 향상

    vector<string> resultVector;
    vector<int> stackQueueSerial;
    vector<int> values;
   
    int num;
    cin >> num;

    int inputInt;

    for (int i = 0; i < num; i++)
    {
        cin >> inputInt;
        stackQueueSerial.push_back(inputInt);
    }

    for (int i = 0; i < num; i++)
    {
        cin >> inputInt;
        if (stackQueueSerial[i] == 0)
        {
            values.push_back(inputInt);
        }
    }

    reverse(values.begin(), values.end());

    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> inputInt;
        values.push_back(inputInt);
    }

    for (int i = 0; i < num; i++)
    {
        cout << values[i] << " ";
    }
 
    return 0;
}
