#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

char* STRING;



void Recursive(int startIndex, int endIndex)
{
    int count = endIndex - startIndex + 1;

    if (count > 3)
    {
        int unit = count / 3;

        Recursive(startIndex, startIndex + unit-1);
        for (int i = startIndex + unit; i <= endIndex - unit; i++)
        {
            STRING[i] = ' ';
        }
        Recursive(endIndex - unit + 1, endIndex);
    }
    else
    {
        STRING[startIndex+1] = ' ';
    }
}

void cantor(int N)
{

    if (N != 0)
    {
        int RealNum = pow(3, N);
        STRING = new char[RealNum];
        for (int i = 0; i < RealNum; i++)
        {
            STRING[i] = '-';
        }

        Recursive(0, RealNum - 1);

        for (int i = 0; i < RealNum; i++)
        {
            cout << STRING[i];
        }

        cout << "\n";

        delete[] STRING;
    }
    else
    {
        cout << "-" << "\n";
    }
    
}

// 백준 제출용 폼
int main(int argc, char const* argv[]) {
    ios::sync_with_stdio(false); // c와 c++ 입력 동기화 끊어서 속도 향상
    cin.tie(NULL); // cin과 cout의 동기화를 끊어서 속도 향상
    cout.tie(NULL); // cin과 cout의 동기화를 끊어서 속도 향상
   
    int num;
    while (cin >> num) {
        cantor(num);
    }

    return 0;
}
