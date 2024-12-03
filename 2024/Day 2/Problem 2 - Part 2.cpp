#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

int result;
vector<vector<int> > reports;
string line;

bool CheckIncreasing(vector<int> vec) {
    int cntDecreasing = 0, cntIncreasing = 0;
    for (int j = 1; j < vec.size(); j++) {
        if (vec[j - 1] < vec[j])
            cntIncreasing++;
        else
            cntDecreasing++;
    }
    return cntDecreasing < cntIncreasing ? true : false;
}

bool CheckVector(vector<int> vec, bool increasing) {
    bool safe = false;

    for (int j = 1; j < vec.size(); j++) {
        int diff = abs(vec[j] - vec[j - 1]);

        if (diff > 3 || diff == 0 ||
            (increasing && vec[j] < vec[j - 1]) ||
            (!increasing && vec[j] > vec[j - 1])) {
            break;
        }
        if (j == vec.size() - 1) {
            safe = true;
        }
    }

    return safe;
}

int main() {
    while (std::getline(std::cin, line)) {
        if (line.empty()) break;

        stringstream ss(line);
        vector<int> row;
        int num;

        while (ss >> num) {
            row.push_back(num);
        }

        reports.push_back(row);
    }

    for (int i = 0; i < reports.size(); i++) {
        bool increasing = false, safe = false;
        increasing = CheckIncreasing(reports[i]);

        if (CheckVector(reports[i], increasing)) {
            result++;
        }
        else {
            for (int j = 0; j < reports[i].size(); j++) {
                vector<int> temp;
                for (int k = 0; k < reports[i].size(); k++) {
                    if (j != k) {
                        temp.push_back(reports[i][k]);
                    }
                }
                if (CheckVector(temp, increasing)) {
                    result++;
                    break;
                }
            }
        }
    }

    cout << result;
}

