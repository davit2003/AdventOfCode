#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> locationId1, locationId2;

int main(){
	int id1, id2;
	while(cin >> id1 >> id2){
		locationId1.push_back(id1);
		locationId2.push_back(id2);
	}
	
	sort(locationId1.begin(), locationId1.end());
	sort(locationId2.begin(), locationId2.end());
	
	int result = 0;
	for(int i = 0; i < locationId1.size(); i++){
		result += abs(locationId1[i] - locationId2[i]);
	}
	
	cout << result;
}
