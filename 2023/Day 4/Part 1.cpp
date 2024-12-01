#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> split(string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

int main() {
    int ans = 0;
    string s;
    while (getline(std::cin, s)) {
        vector<string> winNums = split(split(split(s, ": ")[1], " | ")[0], " ");
        vector<string> nums = split(split(split(s, ": ")[1], " | ")[1], " ");

        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] != "")
            for (int j = 0; j < winNums.size(); j++) {
                if (winNums[j] != "" && nums[i] == winNums[j])
                        cnt++;
            }
        }

        if (cnt > 0)
            ans += pow(2.0, cnt - 1);
    }
    cout << ans;
}