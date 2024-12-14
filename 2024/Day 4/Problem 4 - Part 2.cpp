#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <string> vec;
int main() {
    string text;
    int result = 0;
    while (cin >> text) {
        text = ".." + text + "..";
        vec.push_back(text);
    }

    string dots(vec[0].size(), '.');
    vec.insert(vec.begin(), { dots, dots });
    vec.insert(vec.end(), { dots, dots });

    for (int i = 2; i < vec.size() - 2; i++) {
        for (int j = 2; j < vec[i].size() - 2; j++) {
            if (vec[i][j] == 'A') {
                if (vec[i - 1][j - 1] == 'M' && vec[i + 1][j - 1] == 'M' && vec[i - 1][j + 1] == 'S' && vec[i + 1][j + 1] == 'S')
                    result++;

                if (vec[i - 1][j - 1] == 'S' && vec[i + 1][j - 1] == 'S' && vec[i - 1][j + 1] == 'M' && vec[i + 1][j + 1] == 'M')
                    result++;

                if (vec[i - 1][j - 1] == 'S' && vec[i + 1][j - 1] == 'M' && vec[i - 1][j + 1] == 'S' && vec[i + 1][j + 1] == 'M')
                    result++;

                if (vec[i - 1][j - 1] == 'M' && vec[i + 1][j - 1] == 'S' && vec[i - 1][j + 1] == 'M' && vec[i + 1][j + 1] == 'S')
                    result++;
            }
        }
    }

    cout << result;
    return 0;
}
