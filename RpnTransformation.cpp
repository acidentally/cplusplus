#include <bits/stdc++.h>
using namespace std;

void process(vector<int>& numbers, char op) {
	int x1 = numbers.back(); numbers.pop_back();
	int x2 = numbers.back(); numbers.pop_back();
	switch(op) {
		case '+': numbers.push_back(x1 + x2);
		case '-': numbers.push_back(x2 - x1);
		case '*': numbers.push_back(x1 * x2);
		case '/': numbers.push_back(x2 / x1);
	}
}

int priority(char op) {
	return (op == '+' || op == '-') ? 1 : 2;
}
	
int main() {
	string s; cin >> s;
	int temp; char cur_op;
	vector<int> numbers;

	stack<char> operations;

	for(int i = 0; i < s.size(); i++) {
		temp = 0;
		while(s[i] - '0' <= 9 && s[i] - '0' >= 0) {
			// cout << i << ' ';
			// cout << s[i] << endl;
			temp = temp*10 + (int)s[i] - '0';
			i++;

		}
		numbers.push_back(temp);
		if(i < s.size()) {
			cur_op = s[i];
			while(priority(operations.top()) > priority(cur_op)) {
				process(numbers, operations.top());
			}
			operations.push(cur_op);
		}
	}			
	cout << numbers[0];
}


