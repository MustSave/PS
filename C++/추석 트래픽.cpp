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
        // sscanf 방식이 더 느림...
        // int year, month, day, hour, min;
        // float sec, procTime;

        // sscanf(lines[i].c_str(), "%d-%d-%d %d:%d:%f %fs", &year, &month, &day, &hour, &min, &sec, &procTime);

        int hour = stoi(lines[i].substr(11, 2));
        int min = stoi(lines[i].substr(14, 2));
        float sec = stof(lines[i].substr(17, 6));
        float procTime = stof(lines[i].substr(24));

        float finishTime = hour * 3600 + min * 60 + sec;
        float startTime = finishTime - procTime + 0.001f;

        startEnd.push_back(make_pair(startTime, finishTime));
    }

    for (int i = 0; i < startEnd.size(); i++)
    {
        int tmp = 1;
        float eTime = startEnd[i].second + 1 - 0.001f;

        for (int j = i + 1; j < startEnd.size(); j++)
            if (startEnd[j].second <= eTime || startEnd[j].first <= eTime) tmp++;
        
        if (tmp > answer) answer = tmp;
    }

    return answer;
}