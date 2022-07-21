#include <string>
#include <vector>
#include <regex>
#include <iostream>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<float, float>> startEnd;
    int* cnt = new int[lines.size()];

    for (int i = 0; i < lines.size(); i++)
    {
        int h = stoi(lines[i].substr(11, 2));
        int m = stoi(lines[i].substr(14, 2));
        float s = stof(lines[i].substr(17, 6));
        float procTime = stof(lines[i].substr(24));

        float finishTime = h * 3600 + m * 60 + s;
        float startTime = finishTime - procTime + 0.001f;

        for (int j = startEnd.size(); j >= 0; j--)
        {

        }

        startEnd.push_back(make_pair(startTime, finishTime));
    }

    for (int i = 0; i < startEnd.size(); i++)
    {
        int tmp = 1;
        float sTime = startEnd[i].second;
        float eTime = startEnd[i].second + 1 - 0.001f;

        for (int j = i + 1; j < startEnd.size(); j++)
            if (startEnd[j].second <= eTime || startEnd[j].first <= eTime) tmp++;
        
        if (tmp > answer) answer = tmp;
    }

    return answer;
}