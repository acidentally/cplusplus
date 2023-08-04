#include <bits/stdc++.h>
using namespace std;

int main() {
	string names[5];
	int size[5] = {0};
	int min = 100000, max = 0;
	string dainhat;
	string ngannhat;
	for(int i = 0; i < 5; i++) {
		getline(cin, names[i]);

		for(int j = 0; j < names[i].size(); j++) {
			if(names[i][j] != ' ') size[i] += 1;
		}
		
		if(size[i] > max) {
			max = size[i];
			dainhat = names[i];
		}
		
		if(size[i] < min) {
			min = size[i];
			ngannhat = names[i];
		}
	}
	cout << dainhat << endl << ngannhat;
}