#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

// 백준 제출용 폼
int main(int argc, char const* argv[]) {
    ios::sync_with_stdio(false); // c와 c++ 입력 동기화 끊어서 속도 향상
    cin.tie(NULL); // cin과 cout의 동기화를 끊어서 속도 향상
    cout.tie(NULL); // cin과 cout의 동기화를 끊어서 속도 향상

    vector<string> resultVector;
   
    int num;
    cin >> num;

    queue<int> QUEUE;

    for (int i = 1; i <= num; i++)
    {
        QUEUE.push(i);
    }

    while (QUEUE.size() > 1)
    {
        QUEUE.pop();
        int temp = QUEUE.front();
        QUEUE.pop();
        QUEUE.push(temp);
    }
    
    cout << QUEUE.front();

 
    return 0;
}
