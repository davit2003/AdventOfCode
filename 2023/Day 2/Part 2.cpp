#include <iostream>
#include <vector>
#include <cmath>
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

int stringToInt(string s) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
        ans += (s[i] - '0') * pow(10, s.size() - i - 1);
    return ans;
}

int main() {
    string s;
    int curr = 0, ans = 0;
    while (getline(std::cin, s)) {
        curr++;
        vector <string> tries = split(split(s, ": ")[1], "; ");

        int red = 0, green = 0, blue = 0;
            
        for (int j = 0; j < tries.size(); j++) {
            vector <string> balls = split(tries[j], ", ");
            for (int i = 0; i < balls.size(); i++) {
                if(balls[i].find(" b") != string::npos)
                    blue = max(blue, stringToInt(balls[i].substr(0, balls[i].find(" b"))));
                else if (balls[i].find(" r") != string::npos)
                    red = max(red, stringToInt(balls[i].substr(0, balls[i].find(" r"))));
                else if (balls[i].find(" g") != string::npos)
                    green = max(green, stringToInt(balls[i].substr(0, balls[i].find(" g"))));
            }
        }
        ans += blue * red * green;
        //cout << blue * red * green << endl;
    }
    cout << ans;
}