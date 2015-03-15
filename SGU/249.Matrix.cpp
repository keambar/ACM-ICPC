#include <cstdio>
using namespace std;
int n, m, x;
int main() {
	scanf("%d %d",&n,&m);
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < (1 << m); j++)
            printf("%d ",(i ^ i >> 1) << m | (j ^ j >> 1) );
			putchar(10);
	}
}
