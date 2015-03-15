#include<stdio.h>
#include<utility>
#include<queue>
using namespace std;
const int INF = 15000 + 9;
priority_queue< pair<int, int> > heap, ansheap;
int l[INF], p[INF], s[INF];
int n, w, i;
int sum, ans = 1e9;
int main()
{
	scanf ("%d", &n);
	for (i = 1; i <= n; ++i){
		scanf ("%d%d%d", &w, l + i, p + i);
		s[i] = s[i - 1] + w;
	}
	for (i = n; i; --i){
		for (; !heap.empty() && heap.top().first > s[i - 1]; heap.pop() )
			sum -= p[heap.top().second];
		heap.push (make_pair (s[i] - l[i], i) );
		sum += p[i];
		if (sum < ans){
			ans = sum;
			ansheap = heap;
		}
	}
	for (; !ansheap.empty(); ansheap.pop() )
		printf ("%d\n", ansheap.top().second);
	return 0;
}
