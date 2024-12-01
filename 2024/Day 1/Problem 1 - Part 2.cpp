#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> locationId1;
map<int, int> locationId2;

int main(){
	int id1, id2;
	while(cin >> id1 >> id2){
		locationId1.push_back(id1);
		locationId2[id2]++;
	}
	
	int result = 0;
	for(int i = 0; i < locationId1.size(); i++){
		result += locationId1[i] * locationId2[locationId1[i]];
	}
	
	cout << result;
}
