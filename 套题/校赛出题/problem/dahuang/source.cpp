#include <string.h>
#include <stdlib.h>
#include <stdio.h>


#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class node {
public:
	string name;
	int num;
	
	node(string na, int nu) {
		name = na;
		num = nu;
	}
	bool operator < (const node &other) const{
         if (num == other.num) {
		 	return name < other.name;
		 }
		 return num > other.num;
    }
};

string fix(string res) {
	for (int i = 0; i < res.size(); i++) {
		if (res[i] >= 'A' && res[i] <= 'Z') {
			res[i] -= 'A'-'a';
		}
	}
	return res;
}

int main () {
//	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
	int n, m;
	int T;
	cin >> T;
	for (int ti = 1; ti <= T; ti++) {
		cin >> n >> m;
		vector<node> res;
		vector<string> words;
		map<string, int> count;
		
		for (int i = 0; i < n; i++) {
			string tmp;
			cin >> tmp;
			words.push_back(fix(tmp));
		}
		
		for (int i = 0; i < m; i++) {
			string name, data;
			cin >> name >> data;
			data = fix(data);
			for (int j = 0; j < words.size(); j++) {
				if (data.find(words[j]) < data.size() ) {
					count[name]++;
					break;
				}
			}
		}
		
		for (map<string, int>::iterator it = count.begin(); it != count.end(); it++) {
			res.push_back(node(it->first, it->second));
		}
		
		sort(res.begin(), res.end());
		
		vector<node>::iterator it;
		for (int i = 0; i < 3;) {
			for (it = res.begin(); it != res.end() && i < 3; it++, i++) {
				cout << it->name << " " << it->num;
				if (i == 2) {
					cout << endl;
				} else {
					cout << ", ";
				}
			}
		}
	}
}
