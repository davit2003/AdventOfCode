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
    while (cin >> s)
        vec.push_back(s);

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            int cnt = 1, numcnt = 0;
            if (vec[i][j] == '*') {
                // Check Left
                string currNum = "";
                if (j > 0 && vec[i][j - 1] != '.') {
                    for (int p = j - 1; p >= 0; p--) {
                        if (vec[i][p] < '0' || vec[i][p] > '9')
                            break;
                        else
                            currNum = vec[i][p] + currNum;
                    }
                    cnt *= stringToInt(currNum);
                    numcnt++;
                }

                // Check Right
                if (j < vec[i].size() - 1 && vec[i][j + 1] != '.') {
                    currNum = "";
                    for (int p = j + 1; p < vec[i].size(); p++) {
                        if (vec[i][p] < '0' || vec[i][p] > '9')
                            break;
                        else
                            currNum += vec[i][p];
                    }
                    cnt *= stringToInt(currNum);
                    numcnt++;
                }

                // Check Top
                if (i > 0) {
                    if (vec[i - 1][j] < '0' || vec[i - 1][j] > '9') {
                        currNum = "";
                        for (int p = j + 1; p < vec[i - 1].size(); p++) {
                            if (vec[i - 1][p] < '0' || vec[i - 1][p] > '9')
                                break;
                            else
                                currNum += vec[i - 1][p];
                        }
                        if (currNum != "")
                            numcnt++, cnt *= stringToInt(currNum);

                        currNum = "";

                        for (int p = j - 1; p >= 0; p--) {
                            if (vec[i - 1][p] < '0' || vec[i - 1][p] > '9')
                                break;
                            else
                                currNum = vec[i - 1][p] + currNum;
                        }
                        if (currNum != "")
                            numcnt++, cnt *= stringToInt(currNum);
                    }
                    else {
                        currNum = "";
                        for (int p = j + 1; p < vec[i - 1].size(); p++) {
                            if (vec[i - 1][p] < '0' || vec[i - 1][p] > '9')
                                break;
                            else
                                currNum += vec[i - 1][p];
                        }
                        for (int p = j; p >= 0; p--) {
                            if (vec[i - 1][p] < '0' || vec[i - 1][p] > '9')
                                break;
                            else
                                currNum = vec[i - 1][p] + currNum;
                        }
                        if (currNum != "")
                            numcnt++, cnt *= stringToInt(currNum);
                    }
                }
                // Check bottom
                if (i < vec.size() - 1) {
                    if (vec[i + 1][j] < '0' || vec[i + 1][j] > '9') {
                        currNum = "";
                        for (int p = j + 1; p < vec[i + 1].size(); p++) {
                            if (vec[i + 1][p] < '0' || vec[i + 1][p] > '9')
                                break;
                            else
                                currNum += vec[i + 1][p];
                        }
                        if (currNum != "")
                            numcnt++, cnt *= stringToInt(currNum);

                        currNum = "";

                        for (int p = j - 1; p >= 0; p--) {
                            if (vec[i + 1][p] < '0' || vec[i + 1][p] > '9')
                                break;
                            else
                                currNum = vec[i + 1][p] + currNum;
                        }
                        if (currNum != "")
                            numcnt++, cnt *= stringToInt(currNum);
                    }
                    else {
                        currNum = "";
                        for (int p = j + 1; p < vec[i + 1].size(); p++) {
                            if (vec[i + 1][p] < '0' || vec[i + 1][p] > '9')
                                break;
                            else
                                currNum += vec[i + 1][p];
                        }
                        for (int p = j; p >= 0; p--) {
                            if (vec[i + 1][p] < '0' || vec[i + 1][p] > '9')
                                break;
                            else
                                currNum = vec[i + 1][p] + currNum;
                        }
                        if (currNum != "")
                            numcnt++, cnt *= stringToInt(currNum);
                    }
                }
            }
            if (numcnt == 2)
                ans += cnt;
        }
    }

    cout << ans;
}