#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    string text;

    int sum = 0;
    bool mulEnabled = true;

    while (cin >> text) {
        regex mulPattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
        regex doPattern(R"(do\(\))");
        regex dontPattern(R"(don't\(\))");

        std::regex tokenPattern(R"(mul\(\d{1,3},\d{1,3}\)|do\(\)|don't\(\))");
        auto matches_begin = std::sregex_iterator(text.begin(), text.end(), tokenPattern);
        auto matches_end = std::sregex_iterator();

        for (auto it = matches_begin; it != matches_end; ++it) {
            string token = it->str();

            if (regex_match(token, doPattern)) {
                mulEnabled = true;
            }
            else if (regex_match(token, dontPattern)) {
                mulEnabled = false;
            }
            else if (regex_match(token, mulPattern)) {
                if (mulEnabled) {
                    smatch match;
                    regex_match(token, match, mulPattern);
                    int num1 = stoi(match[1].str());
                    int num2 = stoi(match[2].str());
                    int product = num1 * num2;
                    sum += product;
                }
            }
        }
    }

    cout << sum;

    return 0;
}

