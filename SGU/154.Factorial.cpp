#include <iostream>
using namespace std;
int  check (int x) {
	int s = 0;
	while(x){
              s+=x/5;
              x/=5;
	}
	return s;
}
int n;
int main() {
	cin >> n;
	int l = 1, r = n *5, k, mid;
	int last = -1;
	if(n==0) last=1;
	while (l <= r) {
		mid = l + (r - l) / 2;
		k = check (mid);
		if (k == n) {
			last = mid;
			r = mid - 1;
		}
		else if (k > n) r = mid - 1;
		else if (k < n) l = mid + 1;
	}
	if (last != -1 ) cout << last;
	else
		cout << "No solution";
}
