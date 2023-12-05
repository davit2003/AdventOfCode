#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int stringToInt(string s) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
        ans += (s[i] - '0') * pow(10, s.size() - i - 1);
    return ans;
}

int main() {
    string s;
    vector<string> vec;
    int ans = 0;
    while (cin >> s) {
        vec.push_back(s);
    }

    string currNum = "";

    for (int i = 0; i < vec.size(); i++) {
        bool ok = 0;
        for (int j = 0; j < vec[i].size(); j++) {
            if (vec[i][j] <= '9' && vec[i][j] >= '0') {
                currNum += vec[i][j];
                for (int p = max(0, i - 1); p <= min((int)vec.size() - 1, i + 1); p++) {
                    for (int q = max(0, j - 1); q <= min((int)vec[i].size() - 1, j + 1); q++) {
                        if (vec[p][q] != '.' && (vec[p][q] > '9' || vec[p][q] < '0'))
                            ok = 1;
                    }
                }
            }
            else {
                if (currNum != "" && ok)
                    ans += stringToInt(currNum);
                currNum = "";
                ok = 0;
            }
        }
        if (currNum != "" && ok)
            ans += stringToInt(currNum);
        currNum = "";
        ok = 0;
    }
    cout << ans;
}