// substr garbage생성하는지?
#include <string>
#include <vector>
#include <map>

using namespace std;
map<string, int> strToInt = { {"ze", 0}, {"on", 1}, {"tw", 2}, {"th", 3}, {"fo", 4}, {"fi", 5}, {"si", 6}, {"se", 7}, {"ei", 8}, {"ni", 9} };
int strCount[] = {4, 3, 3, 5, 4, 4, 3, 5, 5, 4};

int solution(string s) {
    int i = 0;
    int length = s.length();
    int answer = 0;

    while (i < length)
    {
        int n = (int)s[i] - '0';
        if (0 <= n && n <= 9)
        {
            i++;
        }
        else
        {
            n = strToInt[s.substr(i, 2)];
            i += strCount[n];
        }
        answer = answer * 10 + n;
    }
    return answer;
}

// 정규표현식 사용.. 속도 느림
// #include <bits/stdc++.h>

// using namespace std;

// int solution(string s)
// {
//     s = regex_replace(s, regex("zero"), "0");
//     s = regex_replace(s, regex("one"), "1");
//     s = regex_replace(s, regex("two"), "2");
//     s = regex_replace(s, regex("three"), "3");
//     s = regex_replace(s, regex("four"), "4");
//     s = regex_replace(s, regex("five"), "5");
//     s = regex_replace(s, regex("six"), "6");
//     s = regex_replace(s, regex("seven"), "7");
//     s = regex_replace(s, regex("eight"), "8");
//     s = regex_replace(s, regex("nine"), "9");

//     return stoi(s);
// }