// 2021_2022_LA_Regional
// InvestedMoney 
// URL: https://codeforces.com/gym/103640/problem/I
// Date: Monday March 20, 2023
//
// Author: Erick Saúl
// Github: @Erick3900
// Twitter: @Erick_Alcachofa
// Mastodon: @alcachofa@social.linux.pizza

#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
    std::ios_base::sync_with_stdio(false), 
        std::cin.tie(nullptr), 
        std::cout.tie(nullptr);

    int n, t;
    std::string day;

    std::cin >> day >> n;
    
    const int dayId = [&] {
        const std::array<std::string, 7> days { "Sat", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri" };
        return std::find(days.begin(), days.end(), day) - days.begin();
    }();

    auto waitingTime = [] (int wDay, int cDay) {
        bool canRetire = false;
        int waiting = 0;
 
        while (! canRetire) {
            if (wDay < 2) {
                waiting += (2 - wDay);
                wDay = 2;
            }
 
            if (waiting < cDay) {
                waiting += 30;
                wDay = (wDay + 30) % 7;
            }
            else {
                canRetire = true;
            }
        }
 
        return waiting - cDay;
    };

    const std::array<int, 7> dumc { 0, 3, 6, 2, 5, 1, 4 };

    auto ans =  std::numeric_limits<int>::max();

    for (int i = 0; i < n; ++i) {
        std::cin >> t;

        const int iDay = ((dayId - (t % 7)) + 7) % 7;
        
        const auto dumSat = dumc[iDay] * 30 + 2;
        const auto dumSun = dumc[iDay == 0 ? 6 : (iDay - 1)] * 30 + 1;
        
        const auto mc = std::min(dumSat, dumSun);

        const auto resDays = [&] {
            int offset = 0;
            int cDay = iDay;
            int lastCycle = t;

            if (t > mc) {
                cDay = 2;
                lastCycle = (t - mc) % 91;
            }
            
            if (lastCycle == 0) {
                offset = 30;
            }

            return waitingTime(cDay, lastCycle + offset) + offset;
        }();

        ans = std::min(ans, resDays);
    }

    std::cout << ans << '\n';
}
