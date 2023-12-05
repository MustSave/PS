#include <string>
#include <vector>
#include <math.h>

using namespace std;

void filter(vector<bool>& primes, int n) {
    for (int i = n * 2; i < primes.size(); i += n)
        primes[i] = false;
}

bool canMakeNumber(vector<int> cardCount, int number) {
    while (number) {
        int remain = number % 10;
        if (cardCount[remain]-- == 0) return false;
        number /= 10;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<bool> primes(pow(10, numbers.size()), true);
    vector<int> cardCount(10, 0);
    for (auto& number: numbers) {
        cardCount[number - '0']++;
    }

    for (int i = 2; i < primes.size(); ++i) {
        if (primes[i] == false) continue;
        filter(primes, i);
        if (canMakeNumber(cardCount, i)){
            ++answer;
        }
    }
    
    return answer;
}