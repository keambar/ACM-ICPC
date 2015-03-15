#include <stdio.h>
#include <algorithm>
using namespace std;

int n, sum, cnt[101], pos[101];
int win[10001], lose[10001];
bool cmp (int a, int b){
	return (cnt[a] > cnt[b]);
}
int main(){
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i){
		scanf ("%d", &cnt[i]);
		sum += cnt[i];
		pos[i] = i;
	}
	sum /= 2;
	sort (pos + 1, pos + n + 1, cmp);
	int j = 1;
	for (int i = 1; i <= sum; ++i){
		if (cnt[pos[j]] == 1){
			lose[i] = pos[j];
			cnt[pos[j++]]--;
		}
		win[i] = pos[j];
		cnt[pos[j]]--;
	}
	for (int i = 1; i <= sum; ++i){
		if (lose[i]) continue;
		if (!cnt[pos[j]]) j++;
		lose[i] = pos[j];
		cnt[pos[j]]--;
	}
	printf ("%d\n", sum);
	for (int i = 1; i <= sum; ++i)
		printf ("%d %d\n", win[i], lose[i]);
	return 0;
}
