// BEGIN CUT HERE

// END CUT HERE
#line 5 "PaintTheRoom.cpp"
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <cstdio>
#include <string>
#include <utility>
#include <map>
#include <set>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define LL long long
#define se second
#define fi first
class PaintTheRoom {
	public:
	string canPaintEvenly(int R, int C, int K) {
		if(K==1) return "Paint";
		if((R*C)%2==0) return "Paint";
		return "Cannot paint";
	}
};
