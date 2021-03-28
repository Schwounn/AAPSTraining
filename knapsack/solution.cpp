#include <iostream>
#include <utility>
#include <vector>

int main() {
    int C;
    int n;
    while (std::cin >> C >> n) {
        int sack[2001][2001] = {};
        std::pair<int,int> items[2000];
        for(int i = 0; i < n; ++i) {
            std::cin >> items[i].first >> items[i].second; 
        }

        for (int i = 1; i <= n; ++i) {
            for (int cap = 0; cap <= C; ++cap) {
                int value = items[i-1].first;
                int weight = items[i-1].second;
                sack[i][cap] = sack[i-1][cap];
                if (weight <= cap && sack[i][cap] < sack[i - 1][cap - weight] + value) {
                    sack[i][cap] = sack[i-1][cap - weight] + value;
                }
            }
        }
        std::vector<int> chosen;
        while (n != 0) {
            if (sack[n][C] != sack[n - 1][C]) {
                chosen.push_back(n-1);
                C -= items[n-1].second;
            }
            --n;
        }
        std::cout << chosen.size() << std::endl;
        for(auto i : chosen) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}