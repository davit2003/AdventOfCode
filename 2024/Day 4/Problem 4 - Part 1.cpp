#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <string> vec;
int main() {
    string text;
    int result = 0;
    while (cin >> text) {
        text = "..." + text + "...";
        vec.push_back(text);
    }

    string dots(vec[0].size(), '.');
    vec.insert(vec.begin(), { dots, dots, dots });
    vec.insert(vec.end(), { dots, dots, dots });

    for (int i = 3; i < vec.size() - 3; i++) {
        for (int j = 3; j < vec[i].size() - 3; j++) {
            if (vec[i][j] == 'X') {
                if (vec[i - 1][j] == 'M' && vec[i - 2][j] == 'A' && vec[i - 3][j] == 'S')
                    result++;
                if (vec[i + 1][j] == 'M' && vec[i + 2][j] == 'A' && vec[i + 3][j] == 'S')
                    result++;
                if (vec[i][j - 1] == 'M' && vec[i][j - 2] == 'A' && vec[i][j - 3] == 'S')
                    result++;
                if (vec[i][j + 1] == 'M' && vec[i][j + 2] == 'A' && vec[i][j + 3] == 'S')
                    result++;


                if (vec[i - 1][j - 1] == 'M' && vec[i - 2][j - 2] == 'A' && vec[i - 3][j - 3] == 'S')
                    result++;
                if (vec[i + 1][j - 1] == 'M' && vec[i + 2][j - 2] == 'A' && vec[i + 3][j - 3] == 'S')
                    result++;
                if (vec[i - 1][j + 1] == 'M' && vec[i - 2][j + 2] == 'A' && vec[i - 3][j + 3] == 'S')
                    result++;
                if (vec[i + 1][j + 1] == 'M' && vec[i + 2][j + 2] == 'A' && vec[i + 3][j + 3] == 'S')
                    result++;
            }
        }
    }

    cout << result;
    return 0;
}
