#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

int result;
vector<vector<int> > reports;
string line;

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

    for(int i = 0; i < reports.size(); i++){
    	bool increasing = false, safe = false;
    	int firstEl = reports[i][0], secondEl = reports[i][1];
    	
    	if(abs(firstEl - secondEl) < 4 && abs(firstEl - secondEl) > 0){
    		increasing = firstEl < secondEl ? true: false;
			
	    	for(int j = 2; j < reports[i].size(); j++){
	    		int diff = abs(reports[i][j] - reports[i][j - 1]);
	
	            if (diff > 3 || diff == 0 || 
	                (increasing && reports[i][j] < reports[i][j - 1]) || 
	                (!increasing && reports[i][j] > reports[i][j - 1])) {
	                break;
	            }
				if(j == reports[i].size() - 1){
					safe = true;
				}
			}
		
			if(safe){
				result++;
			}
		}
	}
	
	cout << result;
}

