#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    string text;
    int sum = 0;
    while (cin >> text) {
        regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
        smatch match;

        auto matches_begin = sregex_iterator(text.begin(), text.end(), pattern);
        auto matches_end = sregex_iterator();

        for (auto it = matches_begin; it != matches_end; ++it) {
            match = *it;
            int num1 = stoi(match[1].str());
            int num2 = stoi(match[2].str());
            int product = num1 * num2;
            sum += product;
        }

    }
    cout << sum;

    return 0;
}
