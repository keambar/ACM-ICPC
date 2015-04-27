using namespace std;
const int MAXN = 109;
char m[MAXN][MAXN], ans[MAXN][MAXN];
int n;
int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> m[i][j];

	for (int i = 1; i < 2 * n; ++i)
		for (int j = 1; j < 2 * n; ++j)
			ans[i][j] = 'x';

//遍历不能达到的格子
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (m[i][j] == 'o')
				for (int x = 1; x <= n; ++x)
					for (int y = 1; y <= n; ++y)
						if (m[x][y] == '.')		ans[n + x - i][n + y - j] = '.';

//能到达的格子一定存在某一规则到达
	for (int x = 1; x <= n; ++x)
		for (int y = 1; y <= n; ++y)
			if (m[x][y] == 'x') {
				bool ok = 0;
				for (int i = 1; i <= n; ++i)
					for (int j = 1; j <= n; ++j)
						ok |= (m[i][j] == 'o' && ans[n + x - i][n + y - j] == 'x');
				if (!ok) {
					cout << "NO" << endl;
					return 0;
				}
			}

	cout << "YES" << endl;
	ans[n][n] = 'o';
	for (int i = 1; i < 2 * n; ++i) {
		for (int j = 1; j < 2 * n; ++j)
		cout << endl;
	}
}

