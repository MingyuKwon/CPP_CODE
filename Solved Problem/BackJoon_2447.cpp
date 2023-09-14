#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

string** Paper;

void Recursive(int startX, int startY, int size)
{
    if (size == 3)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                Paper[startY + i][startX + j] = "*";
            }
        }

        Paper[startY + 1][startX + 1] = " ";
    }
    else
    {
        int unit = size / 3;

        Recursive(startX, startY, unit);
        Recursive(startX + unit, startY, unit);
        Recursive(startX + unit * 2, startY, unit);
        
        Recursive(startX, startY + unit, unit);
        for (int i = 0; i < unit; i++)
        {
            for (int j = 0; j < unit; j++)
            {
                Paper[startY + unit + i][startX + unit + j] = " ";
            }
        }
        Recursive(startX + unit * 2, startY + unit, unit);

        Recursive(startX, startY + unit * 2, unit);
        Recursive(startX + unit, startY + unit * 2, unit);
        Recursive(startX + unit * 2, startY + unit * 2, unit);
    }
}


// 백준 제출용 폼
int main(int argc, char const* argv[]) {
    ios::sync_with_stdio(false); // c와 c++ 입력 동기화 끊어서 속도 향상
    cin.tie(NULL); // cin과 cout의 동기화를 끊어서 속도 향상
    cout.tie(NULL); // cin과 cout의 동기화를 끊어서 속도 향상
   
    int num;
    //while (cin >> num) {}
    cin >> num;

    Paper = new string* [num];
    for (int i = 0; i < num; i++)
    {
        Paper[i] = new string[num];
    }

    Recursive(0,0, num);

    string str = "";

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            str += Paper[i][j];
        }

        str += "\n";
    }

    cout << str;

    for (int i = 0; i < num; i++)
    {
        delete [] Paper[i];
    }
    delete[] Paper;

    return 0;
}
