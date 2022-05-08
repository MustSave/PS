#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";

    char lowerCase[] = "abcdefghijklmnopqrstuvwxyz";
    char upperCase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < s.length(); i++)
    {
        if(islower(s[i]))
        {
            answer += lowerCase[(s[i]-'a'+n)%26];
        }
        else if (isupper(s[i]))
        {
            answer += upperCase[(s[i]-'A'+n)%26];
        }
        else
        {
            answer += ' ';
        }
    }

    return answer;
}