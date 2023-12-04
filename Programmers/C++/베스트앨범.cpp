#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    }
};

class GenrePlayList {
private:
    priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> playList;
    int minPlayTime = 0;

public:
    int totalPlayTime = 0;

    GenrePlayList() {}

    void addSong(int id, int playTime) {
        totalPlayTime += playTime;
        if (playList.size() < 2 || playTime >= minPlayTime) {
            playList.push({playTime, id});
            if (playList.size() > 2) playList.pop();
            minPlayTime = playList.top().first;
        }
    }

    vector<int> getPlayList() {
        vector<int> ret;
        while (!playList.empty()) {
            ret.push_back(playList.top().second);
            playList.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,GenrePlayList> genrePlaylist;
    map<string, int> genrePlayTime;

    for (int i = 0; i < genres.size(); i++) {
        genrePlaylist[genres[i]].addSong(i, plays[i]);
    }

    vector<pair<string,GenrePlayList>> vec(genrePlaylist.begin(), genrePlaylist.end());
    sort(vec.begin(), vec.end(), [](pair<string,GenrePlayList>& a, pair<string,GenrePlayList>& b) {
        return a.second.totalPlayTime > b.second.totalPlayTime;
    });

    for (auto& kv: vec) {
        auto res = kv.second.getPlayList();
        for (const auto& id: res) {
            answer.push_back(id);
        }
    }
    
    return answer;
}