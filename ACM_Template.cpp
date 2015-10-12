/*
	ACM 模板
*/

/*=======================================================
                 图           论
=======================================================*/


//1.最大流  SAP（加几乎已知所有优化）：
/*
      最大流SAP
      邻接表
      思路：基本源于FF方法，给每个顶点设定层次标号，和允许弧。
      优化:
      1、当前弧优化（重要）。
      1、每找到以条增广路回退到断点（常数优化）。
      2、层次出现断层，无法得到新流（重要）。
      时间复杂度（m*n^2）
*/
//-------------------------------
#include <iostream>
#include <cstdio>
#include <cstring>
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
const int INF = 1111;
struct node {
    int v, c, next;
} edge[INF*INF];
int  pHead[INF], SS, ST, nCnt;
void addEdge (int u, int v, int c) {
    edge[++nCnt].v = v; edge[nCnt].c = c, edge[nCnt].next = pHead[u]; pHead[u] = nCnt;
    edge[++nCnt].v = u; edge[nCnt].c = 0, edge[nCnt].next = pHead[v]; pHead[v] = nCnt;
}
int SAP (int pStart, int pEnd, int N) {
    int numh[INF], h[INF], curEdge[INF], pre[INF];
    int cur_flow, flow_ans = 0, u, neck, i, tmp;
    ms (h, 0); ms (numh, 0); ms (pre, -1);
    for (i = 0; i <= N; i++) curEdge[i] = pHead[i];
    numh[0] = N;
    u = pStart;
    while (h[pStart] <= N) {
        if (u == pEnd) {
            cur_flow = 1e9;
            for (i = pStart; i != pEnd; i = edge[curEdge[i]].v)
                if (cur_flow > edge[curEdge[i]].c) neck = i, cur_flow = edge[curEdge[i]].c;
            for (i = pStart; i != pEnd; i = edge[curEdge[i]].v) {
                tmp = curEdge[i];
                edge[tmp].c -= cur_flow, edge[tmp ^ 1].c += cur_flow;
            }
            flow_ans += cur_flow;
            u = neck;
        }
        for ( i = curEdge[u]; i != 0; i = edge[i].next)
            if (edge[i].c && h[u] == h[edge[i].v] + 1)     break;
        if (i != 0) {
            curEdge[u] = i, pre[edge[i].v] = u;
            u = edge[i].v;
        }
        else {
            if (0 == --numh[h[u]]) continue;
            curEdge[u] = pHead[u];
            for (tmp = N, i = pHead[u]; i != 0; i = edge[i].next)
                if (edge[i].c)  tmp = min (tmp, h[edge[i].v]);
            h[u] = tmp + 1;
            ++numh[h[u]];
            if (u != pStart) u = pre[u];
        }
    }
    return flow_ans;
}
int main() {
    /*
           建图,前向星存边，表头在pHead[],边计数 nCnt.
           SS,ST分别为源点和汇点
    */
    int ans = SAP (SS, ST, n + 1);
    return 0;
}
//---------------------------------


// 2.费用流
/*
       最小费用最大流算法：
       思路：
       以费用为权做最短路算法。
*/
//---------------------------------
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int INF = 1100,Maxn=0x3f3f3f3f;
struct node {
    int u, v, t, c, next;
} edge[INF * INF << 2];
int head[INF], nCnt = 1;

void addEdge (int u, int v, int traffic, int cost) {
    edge[++nCnt].v = v, edge[nCnt].u=u,edge[nCnt].t = traffic, edge[nCnt].c = cost;
    edge[nCnt].next = head[u], head[u] = nCnt;
    edge[++nCnt].v = u, edge[nCnt].u=v,edge[nCnt].t = 0, edge[nCnt].c = -cost;
    edge[nCnt].next = head[v], head[v] = nCnt;
}
int max_flow, min_cost;
int n, m, SS, ST, S, T;
int SPFA() {
    queue<int> ql;
    int vis[INF] = {0}, dis[INF], pre[INF] = {0};
    ql.push (SS);
    memset (dis, 0x3f, sizeof dis);
    vis[SS] = 1, dis[SS] = 0;
    while (!ql.empty() ) {
        int x = ql.front(); ql.pop();
        for (int i = head[x]; i != 0; i = edge[i].next) {
            if (edge[i].t == 0) continue;
            int v = edge[i].v, c = edge[i].c;
            if (dis[v] > dis[x] + c) {
                dis[v] = dis[x] + c;
                pre[v] = i;
                if (!vis[v])
                    ql.push (v), vis[v] = 1;
            }
        }
        vis[x] = 0;
    }
    if (dis[ST] == Maxn) return 0;
    else {
        min_cost += dis[ST];
        int k = pre[ST];
        int cur_flow = Maxn;
        while (k) {
            if (cur_flow > edge[k].t) cur_flow = edge[k].t;
            k = pre[edge[k].u];
        }
        max_flow += cur_flow;
        k = pre[ST];
        while (k) {
            edge[k].t -= cur_flow, edge[k ^ 1].t += cur_flow;
            k = pre[edge[k].u];
        }
        return 1;
    }
}
int MCMF() {
    while (SPFA() );
    printf("%d\n",min_cost);
}
void build() {
    /*   建图    */
}
int main() {
    build();
    MCMF();
    return 0;
}
//----------------------------------


//3.二分图最大匹配     匈牙利算法（n*m）
//-----------------------------------
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int G[309][309];
int link[309], vis[309];
int n, x, y, t;
bool DFS (int x) {
    for (int i = 1; i <= 300; i++)
        if (G[x][i] && !vis[i]) {
            vis[i]=1;
            if (link[i] == -1 || DFS (link[i]) ) {
                link[i] = x;
                return 1;
            }
        }
    return 0;
}
int make() {
     int ans = 0;
     memset (link, -1, sizeof link);
     for (int i = 1; i <= n; i++) {
          memset (vis, 0, sizeof vis);
          if (DFS (i) ) ans++;
     }
return ans;
}
//-----------------------------------


// 4.Hopcroft-Karp 算法（n^1/2*m）
/* *********************************************
二分图匹配（Hopcroft-Carp的算法）。
初始化：g[][]邻接矩阵
调用：res=MaxMatch();  Nx,Ny要初始化！！！
时间复杂大为 O(V^0.5 E)

适用于数据较大的二分匹配
需要ｑｕｅｕｅ头文件
********************************************** */
//----------------------------------
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN=3000;
const int INF=1<<28;
int g[MAXN][MAXN],Mx[MAXN],My[MAXN],Nx,Ny;
int dx[MAXN],dy[MAXN],dis;
bool vst[MAXN];
bool searchP()
{
    queue<int>Q;
    dis=INF;
    memset(dx,-1,sizeof(dx));
    memset(dy,-1,sizeof(dy));
    for(int i=0;i<Nx;i++)
        if(Mx[i]==-1)
        {
            Q.push(i);
            dx[i]=0;
        }
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        if(dx[u]>dis)  break;
        for(int v=0;v<Ny;v++)
            if(g[u][v]&&dy[v]==-1)
            {
                dy[v]=dx[u]+1;
                if(My[v]==-1)  dis=dy[v];
                else
                {
                    dx[My[v]]=dy[v]+1;
                    Q.push(My[v]);
                }
            }
    }
    return dis!=INF;
}
bool DFS(int u)
{
    for(int v=0;v<Ny;v++)
       if(!vst[v]&&g[u][v]&&dy[v]==dx[u]+1)
       {
           vst[v]=1;
           if(My[v]!=-1&&dy[v]==dis) continue;
           if(My[v]==-1||DFS(My[v]))
           {
               My[v]=u;
               Mx[u]=v;
               return 1;
           }
       }
    return 0;
}
int MaxMatch()
{
    int res=0;
    memset(Mx,-1,sizeof(Mx));
    memset(My,-1,sizeof(My));
    while(searchP())
    {
        memset(vst,0,sizeof(vst));
        for(int i=0;i<Nx;i++)
          if(Mx[i]==-1&&DFS(i))  res++;
    }
    return res;
}
//最小点覆盖=最大匹配
//有向无环图的最小路径覆盖=节点数（|V|）-最大匹配（|M*|）
//-----------------------------------

//5.LCA
//倍增法
//-----------------------------------
#include <cstdio>
#include <vector>
#define INF 55555
using namespace std;

int  nPrice[INF], nSnode[INF];
int  nDeep[INF], pNode[INF][18];
bool vis[INF];
const int Pow = 16;
vector<int> g[INF];
void dfs (int u, int fa) {
	vis[u] = true;
	nDeep[u] = nDeep[fa] + 1;
	pNode[u][0] = fa;
	for (int i = 1; i <= Pow; i++) pNode[u][i] = pNode[pNode[u][i - 1]][i - 1];
	int nSize = g[u].size();
	for (int i = 0; i < nSize; i++) {
		int v = g[u][i];
		if (v == fa || vis[v]) continue;
		dfs (v, u);
	}
}
int bzlca (int a, int b) {
	if (nDeep[a] > nDeep[b]) a ^= b, b ^= a, a ^= b;
	if (nDeep[a] < nDeep[b]) {
		int del = nDeep[b] - nDeep[a];
		for (int i = 0; i < Pow; i++) if (del & (1 << i) ) b = pNode[b][i];
	}
	if (a != b) {
		for (int i = Pow - 1; i >= 0; i--)
			if (pNode[a][i] != pNode[b][i])
				a = pNode[a][i], b = pNode[b][i];
		a = pNode[a][0], b = pNode[b][0];
	}
	return a;
}
//-----------------------------------
/*=======================================================
               数    据    结    构
=======================================================*/
 //1.LCT
/*
       LCT Splay
       核心思路：
       上一次访问过的点到根节点的路径上的点做一颗Splay树。
       不同的Splay树之间用单向的指向父节点的“虚边”连接。
       每一次Access操作，选取一段序列
       通过Splay可以维护点的信息

       注意事项：
       1.在翻转过后，要交换具有左右差异的变量
       2.要注意对NIL的判断和处理
       3.注意tag间的关系
*/
//-----------------------
#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 333333;
const int Mod = ( int ) 1e9 + 7;

struct node {
    int val, Min;
    bool rev;
    node *par, *ch[2];
}  dt[MAXN], *NIL = dt;
struct LinkcutTree {
    inline void clear( node *const x )
    {
        if( x == NIL ) {
            return ;
        }
        if( x->rev ) {
            swap( x->ch[0], x->ch[1] );
            for( int i = 0; i < 2; ++i ) {
                if( x->ch[i] != NIL ) {
                    x->ch[i]->rev ^= 1;
                }
            }
            x->rev = 0;
        }
    }
    inline void update( node * x )
    {
        if( x == NIL ) {
            return;
        }
        x->Min = x->val;
        for( int i = 0; i < 2; ++i ) {
            if( x->ch[i] != NIL ) {
                x->Min = min( x->Min, x->ch[i]->Min );
            }
        }
    }
    void Rotate( node *x )
    {
        node *p = x->par, *g = p->par;
        int c = p->ch[0] == x; //0左旋，1右旋
        p->ch[c ^ 1] = x->ch[c];
        if( x->ch[c] != NIL ) {
            x->ch[c]->par = p;
        }
        x->par = g;
        if( g->ch[0] == p ) {
            g->ch[0] = x;
        } else
            if( g->ch[1] == p ) {
                g->ch[1] = x;
            }
        x->ch[c] = p;
        p->par = x;
        update( p );
    }
    void Splay( node *x )
    {
        node *p, *g;
        clear( x );
        while( ( p = x->par ) != NIL && ( p->ch[0] == x || p->ch[1] == x ) ) {
            if( ( g = p->par ) != NIL && ( g->ch[0] == p || g->ch[1] == p ) ) {
                clear( g ), clear( p ), clear( x );
                if( ( g->ch[1] == p ) == ( p->ch[1] == x ) ) {
                    Rotate( p ), Rotate( x );
                } else {
                    Rotate( x ), Rotate( x );
                }
            } else {
                clear( p ), clear( x );
                Rotate( x );
            }
        }
        update( x );
    }
    node *Access( node *u )
    {
        node *v = NIL;
        for( ; u != NIL; u = u->par ) {
            Splay( u );
            u->ch[1] = v;
            update( v = u );
        }
        return v;
    }
    inline void evert( node *x )
    {
        Access( x )->rev ^= 1;
        Splay( x );
    }
    inline void link( node *x, node *y )
    {
        evert( x );
        x->par = y;
        //Access (x);
    }
    inline node* getroot( node *x )
    {
        for( x = Access( x ); clear( x ), x->ch[0] != NIL; x = x->ch[0] );
        Splay( x );
        return x;
    }
    inline void cut( node *x, node *y )
    {
        evert( x );
        Access( y );
        Splay( y );
        y->ch[0]->par = NIL;
        y->ch[0] = NIL;
        update( y );
    }
} LCT;
//-------------------------

//2.树链剖分
/*
	需要用到树上的路径的情况可以使用
	寻找路径时先将两个节点的深度提
*/
//-------------------------
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int MAX = 111111;
//子树结点数,所在链链头,同链儿子,结点深度,节点在区间的位置,父节点
int siz[MAX], top[MAX], son[MAX], dep[MAX], w[MAX], fa[MAX];
//链式前向星记录一颗树（可用双向边）
struct Edge {
    int v, ne, id;
} edge[MAX << 1];

int head[MAX], cnt, num;
int vis[MAX], pos[MAX];;
//第一次dfs,提取基本信息,划分轻重链
void Dfs1 (int u, int v) 
{
    fa[v] = u, dep[v] = dep[u] + 1;
    siz[v] = 1;
    vis[v] = 1;
    int tem = 0, p = -1;
    for (int i = head[v]; i != 0; i = edge[i].ne) {
        int kid = edge[i].v;
        if (!vis[kid]) {
            Dfs1 (v, kid);
            siz[u] += siz[kid];
            if (tem < siz[kid]) tem = siz[kid], p = kid;
        }
    }
    son[v] = p;
}
//第二次DFS,将重链映射到区间
void Dfs2 (int h, int v) 
{
    top[v] = h;
    w[v] = ++num;
    vis[v] = 1;
    if (son[v] != -1) Dfs2 (h, son[v]);
    for (int i = head[v]; i != 0; i = edge[i].ne) {
        int kid = edge[i].v;
        if (son[v] != kid && !vis[kid])
            Dfs2 (kid, kid);
              //pos[edge[i].id] = w[kid]; //边映射(这里向下映射)
    }
}
void init()
{
	cnt=num=0;
	memset(vis,0,sizof vis);//调用dfs2前还需清空一次
}
//------------------------------

//3.线段树
//------------------------------
int tl[MAX << 3], tr[MAX << 3], flag[MAX << 3], sum[MAX << 3][2];
int l, r;
void build ( int x, int l, int r )
{
    flag[x] = sum[x][0] = sum[x][1] = 0;
    tl[x] = l, tr[x] = r;
    if ( l == r ) {
        sum[x][0] = 1;
        return ;
    }
    int mid = ( l + r ) >> 1;
    build ( lson, l, mid ), build ( rson, mid + 1, r );
    sum[x][0] += sum[lson][0] + sum[rson][0];
}

void push ( int x )
{
    if ( flag[x] == 0 ) return;
    flag[x] = 0;
    flag[lson] ^= 1;
    swap ( sum[lson][0], sum[lson][1] );
    flag[rson] ^= 1;
    swap ( sum[rson][0], sum[rson][1] );
}
void updata ( int x )
{
    sum[x][0] = sum[lson][0] + sum[rson][0];
    sum[x][1] = sum[lson][1] + sum[rson][1];
}
void modify ( int x )
{
    if ( tl[x] >= l && tr[x] <= r ) {
        flag[x] ^= 1;
        swap ( sum[x][0], sum[x][1] );
        return ;
    }
    push ( x );
    int mid = ( tl[x] + tr[x] ) >> 1;
    if ( l <= mid ) modify ( lson );
    if ( r > mid ) modify ( rson );
    updata ( x );
}

int query ( int x )
{
    if ( tl[x] >= l && tr[x] <= r ) {
        return sum[x][1];
    }
    push ( x );
    int mid = ( tl[x] + tr[x] ) >> 1, ans = 0;
    if ( l <= mid ) ans += query ( lson );
    if ( r > mid ) ans += query ( rson );
    updata ( x );
    return ans;
}
//------------------------------

//4.splay
//------------------------------
/*
       初始化添加一个key值足够大的结点
       保证每个需要的结点都有后继
*/
#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;

const int MAXN = 1111111, INF = 0x7fffffff;

struct node {
    //需要的记录信息
    ll  key, val, sum, lazy, Size, Cnt;
    //指向儿子和父亲的指针
    node *ch[2], *pre;
    node() {pre = ch[0] = ch [1] = 0; Size = 1; key = 0;}
    node (ll key) : key (key) {pre = ch[0] = ch[1] = 0; Size = 1, Cnt = 1, lazy = 0;}
    void Csize() {
        Size = Cnt;
        if (ch[0] != NULL) Size += ch[0]->Size;
        if (ch[1] != NULL) Size += ch[1]->Size;
    }
    void Csum() {
        sum = val;
        if (ch[0] != NULL) sum += ch[0]->sum + ch[0]->Size * ch[0]->lazy;
        if (ch[1] != NULL) sum += ch[1]->sum + ch[1]->Size * ch[1]->lazy;
    }
} nil (0), *NIL = &nil;

struct Splay {
    node *root, nod[MAXN];
    int ncnt;//计算key值不同的结点数，已去重
    Splay() {
        ncnt = 0;
        root = & (nod[ncnt++] = node (INF) );
        root->pre = NIL;
        root->val = root->sum = 0;
    }
    void Push_Down (node *x) {
        if (x->lazy != 0) {
            if (x->ch[0] != NULL) x->ch[0]->lazy += x->lazy;
            if (x->ch[1] != NULL) x->ch[1]->lazy += x->lazy;
                     x->val+=x->lazy;
        }
        x->lazy = 0;
    }

    void Update (node *x) {
        x->Csize();
        x->Csum();
    }

    void Rotate (node *x, int sta) { //单旋转操作，0左旋，1右旋
        node *p = x->pre, *g = p->pre;
        Push_Down (p), Push_Down (x);
        p->ch[!sta] = x->ch[sta];
        if (x->ch[sta] != NULL)  x->ch[sta]->pre = p;
        x->pre = g;
        if (g != NIL)
            if (g->ch[0] == p)  g->ch[0] = x;
            else g->ch[1] = x;
        x->ch[sta] = p, p->pre = x, Update (p);
        if (p == root ) root = x;
    }

    void splay (node *x, node *y) { //Splay 操作，表示把结点x,转到根
        for (Push_Down (x) ; x->pre != y;) { //将x的标记往下传
            if (x->pre->pre == y) { //目标结点为父结点
                if (x->pre->ch[0] == x)       Rotate (x, 1);
                else   Rotate (x, 0);
            }
            else {
                node *p = x->pre, *g = p->pre;
                if (g->ch[0] == p)
                    if (p->ch[0] == x)
                        Rotate (p, 1), Rotate (x, 1);//   / 一字型双旋转
                    else
                        Rotate (x, 0), Rotate (x, 1);//  < 之字形双旋转

                else if (p ->ch[1] == x)
                    Rotate (p, 0), Rotate (x, 0);//    \ 一字型旋转
                else
                    Rotate (x, 1), Rotate (x, 0); //   >之字形旋转
            }
        }
        Update (x); //维护x结点
    }
    //找到中序便利的第K个结点，并旋转至结点y的下面。
    void Select (int k, node *y) {
        int tem ;
        node *t ;
        for ( t = root; ; ) {
            Push_Down (t) ; //标记下传
            tem = t->ch[0]->Size ;
            if (k == tem + 1 ) break ; //找到了第k个结点 t
            if (k <= tem)
                t = t->ch[0] ; //第k个结点在左子树
            else
                k -= tem + 1 , t = t->ch[1] ;//在右子树
        }
        splay (t, y);
    }
    bool Search (ll key, node *y) {
        node *t = root;
        for (; t != NULL;) {
            Push_Down (t);
            if (t->key > key && t->ch[0] != NULL) t = t->ch[0];
            else if (t->key < key && t->ch[1] != NULL) t = t->ch[1];
            else
                break;
        }
        splay (t, y);
        return t->key == key;
    }
    void Insert (int key, int val) {
        if (Search (key, NIL) ) root->Cnt++, root->Size++;
        else {
            int d = key > root->key;
            node *t = & (nod[++ncnt] = node (key) );
            Push_Down (root);
            t->val = t->sum = val;
            t->ch[d] = root->ch[d];
            if (root->ch[d] != NULL) root->ch[d]->pre = t;
            t->ch[!d] = root;
            t->pre = root->pre;
            root->pre = t;
            root->ch[d] = NULL;
            Update (root);
            root = t;
        }
        Update (root);
    }
} sp;const int MAXN = 1111111, INF = 0x7fffffff;

struct node {
    //需要的记录信息
    ll  key, val, sum, lazy, Size, Cnt;
    //指向儿子和父亲的指针
    node *ch[2], *pre;
    node() {pre = ch[0] = ch [1] = 0; Size = 1; key = 0;}
    node (ll key) : key (key) {pre = ch[0] = ch[1] = 0; Size = 1, Cnt = 1, lazy = 0;}
    void Csize() {
        Size = Cnt;
        if (ch[0] != NULL) Size += ch[0]->Size;
        if (ch[1] != NULL) Size += ch[1]->Size;
    }
    void Csum() {
        sum = val;
        if (ch[0] != NULL) sum += ch[0]->sum + ch[0]->Size * ch[0]->lazy;
        if (ch[1] != NULL) sum += ch[1]->sum + ch[1]->Size * ch[1]->lazy;
    }
} nil (0), *NIL = &nil;

struct Splay {
    node *root, nod[MAXN];
    int ncnt;//计算key值不同的结点数，已去重
    Splay() {
        ncnt = 0;
        root = & (nod[ncnt++] = node (INF) );
        root->pre = NIL;
        root->val = root->sum = 0;
    }
    void Push_Down (node *x) {
        if (x->lazy != 0) {
            if (x->ch[0] != NULL) x->ch[0]->lazy += x->lazy;
            if (x->ch[1] != NULL) x->ch[1]->lazy += x->lazy;
                     x->val+=x->lazy;
        }
        x->lazy = 0;
    }

    void Update (node *x) {
        x->Csize();
        x->Csum();
    }

    void Rotate (node *x, int sta) { //单旋转操作，0左旋，1右旋
        node *p = x->pre, *g = p->pre;
        Push_Down (p), Push_Down (x);
        p->ch[!sta] = x->ch[sta];
        if (x->ch[sta] != NULL)  x->ch[sta]->pre = p;
        x->pre = g;
        if (g != NIL)
            if (g->ch[0] == p)  g->ch[0] = x;
            else g->ch[1] = x;
        x->ch[sta] = p, p->pre = x, Update (p);
        if (p == root ) root = x;
    }

    void splay (node *x, node *y) { //Splay 操作，表示把结点x,转到根
        for (Push_Down (x) ; x->pre != y;) { //将x的标记往下传
            if (x->pre->pre == y) { //目标结点为父结点
                if (x->pre->ch[0] == x)       Rotate (x, 1);
                else   Rotate (x, 0);
            }
            else {
                node *p = x->pre, *g = p->pre;
                if (g->ch[0] == p)
                    if (p->ch[0] == x)
                        Rotate (p, 1), Rotate (x, 1);//   / 一字型双旋转
                    else
                        Rotate (x, 0), Rotate (x, 1);//  < 之字形双旋转

                else if (p ->ch[1] == x)
                    Rotate (p, 0), Rotate (x, 0);//    \ 一字型旋转
                else
                    Rotate (x, 1), Rotate (x, 0); //   >之字形旋转
            }
        }
        Update (x); //维护x结点
    }
    //找到中序便利的第K个结点，并旋转至结点y的下面。
    void Select (int k, node *y) {
        int tem ;
        node *t ;
        for ( t = root; ; ) {
            Push_Down (t) ; //标记下传
            tem = t->ch[0]->Size ;
            if (k == tem + 1 ) break ; //找到了第k个结点 t
            if (k <= tem)
                t = t->ch[0] ; //第k个结点在左子树
            else
                k -= tem + 1 , t = t->ch[1] ;//在右子树
        }
        splay (t, y);
    }
    bool Search (ll key, node *y) {
        node *t = root;
        for (; t != NULL;) {
            Push_Down (t);
            if (t->key > key && t->ch[0] != NULL) t = t->ch[0];
            else if (t->key < key && t->ch[1] != NULL) t = t->ch[1];
            else
                break;
        }
        splay (t, y);
        return t->key == key;
    }
    void Insert (int key, int val) {
        if (Search (key, NIL) ) root->Cnt++, root->Size++;
        else {
            int d = key > root->key;
            node *t = & (nod[++ncnt] = node (key) );
            Push_Down (root);
            t->val = t->sum = val;
            t->ch[d] = root->ch[d];
            if (root->ch[d] != NULL) root->ch[d]->pre = t;
            t->ch[!d] = root;
            t->pre = root->pre;
            root->pre = t;
            root->ch[d] = NULL;
            Update (root);
            root = t;
        }
        Update (root);
    }
} sp;

ll  n, m, x;
int main() {
    scanf ("%lld %lld", &n, &m);
    sp.Insert (0, 0);
    sp.Insert (n + 1, 0);
    for (int i = 1; i <= n; i++) {
        scanf ("%lld", &x);
        sp.Insert (i, x);
    }
    char cmd;
    int l, r;
    for (int i = 1; i <= m; i++) {
        scanf ("\n%c %d %d", &cmd, &l, &r);
        sp.Search (l - 1, NIL);
        sp.Search (r + 1, sp.root);
        if (cmd == 'Q') {
            node *t = sp.root->ch[1]->ch[0];
            ll ans = t->sum + t->Size * t->lazy;
            printf ("%lld\n", ans);
        }
        if (cmd == 'C') {
            ll c;
            scanf ("%lld", &c);
            sp.root->ch[1]->ch[0]->lazy += c;
        }
    }
    return 0;
}
//------------------------------
/*=======================================================
                 字     符     串
=======================================================*/

//1.手速版sa
//------------------------
typedef pair<int , int > ii;
int sa[N], rk[N * 2], p[N * 2];
pair<ii, int> pos[N * 2];
void buildSA ( int tot )
{
    for ( int i = 1; i <= tot; ++i ) rk[i] = p[i];
    for ( int j = 0; j <= ( int ) ( log ( N ) / log ( 2 ) + 1 ); ++j ) {
        for ( int i = 1; i <= tot; ++i )
            pos[i] = mp ( mp ( rk[i], rk[i + ( 1 << j )] ), i );
        sort ( pos + 1, pos + tot + 1 );
        int cnt = 0;
        for ( int i = 1; i <= tot; ++i ) {
            rk[pos[i].se] = cnt;
            cnt += ( pos[i].fi != pos[i + 1].fi );
        }
        if ( cnt == tot ) break;
    }
    for ( int i = 1; i <= tot; ++i ) rk[i]++;
    for ( int i = 1; i <= tot; ++i ) sa[rk[i]] = i;
}
//------------------------

//2.KMP
//------------------------
#include <cstdio>
const int INF = 11111;
int p[INF];
int s[INF], n, a[INF], m;
void get()
{
	p[1] = 0;
	int j = 0;
	for (int i = 2; i <=m; i++)
	{
		while (j && a[j + 1] != a[i])  j = p[j];
		if (a[j + 1] == a[i]) j++;
		p[i] = j;
	}
}
int KMP() {
	int j = 0, ans = 0;
	for (int i = 1; i <=n; i++) {
		while (j && a[j + 1] != s[i]) j = p[j];
		if (a[j + 1] == s[i]) j++;
		if (j == m) {
			ans++;
			j = p[j];
		}
	}
	return ans;
}
//-----------------------

//3.AC自动机
//-----------------------
#include <iostream>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
const int SD = 26;
const int MAXL = 510000;
struct Tire {
    int next[MAXL][SD], fail[MAXL], eofs[MAXL];
    int root, cnt;
    int newnode() {
        for (int i = 0; i < SD; i++)     next[cnt][i] = -1;
        eofs[cnt++] = 0;
        return cnt - 1;
    }
    void init() {
        cnt = 0;
        root=newnode();
    }
    void Ins (char buf[]) {
        int len = strlen (buf);
        int now = root;
        for (int i = 0; i < len; i++) {
            if (next[now][buf[i] - 'a'] == -1)
                next[now][buf[i] - 'a'] = newnode();
            now = next[now][buf[i] - 'a'];
        }
        eofs[now] ++;
    }
    void build() {
        queue<int> ql;
        fail[root] = root;
        for (int i = 0; i < SD; i++) {
            if (next[root][i] == -1)
                next[root][i] = root;
            else {
                fail[next[root][i]] = root;
                ql.push (next[root][i]);
            }
        }
        while (!ql.empty() ) {
            int now = ql.front(); ql.pop();
            for (int i = 0; i < SD; i++)
                if (next[now][i] == -1) {
                    next[now][i] = next[fail[now]][i];
                }
                else {
                    fail[next[now][i]] = next[fail[now]][i];
                    ql.push (next[now][i]);
                }
        }
    }
    int query (char buf[])
    {
        int len = strlen (buf);
        int now = root;
        int res = 0;
        for (int i = 0; i < len; i++) {
            now = next[now][buf[i] - 'a'];
            int temp = now;
            while ( temp != root ) {
                res += eofs[temp];
                eofs[temp] = 0;
                temp = fail[temp];
            }
        }
        return res;
    }
} ACmation;
//-----------------------

//4.manacher
//----------------
const int MAXN=110010;
char Ma[MAXN*2];
int Mp[MAXN*2];
void Manacher(char s[],int len) {
      int l=0;
      Ma[l++]='$';
      Ma[l++]='#';
      for(int i=0; i<len; i++) {
            Ma[l++]=s[i];
            Ma[l++]='#';
      }
      Ma[l]=0;
      int mx=0,id=0;
      for(int i=0; i<l; i++) {
            Mp[i]=mx>i?min(Mp[2*id-i],mx-i):1;
            while(Ma[i+Mp[i]]==Ma[i-Mp[i]])Mp[i]++;
            if(i+Mp[i]>mx) {
                  mx=i+Mp[i];
                  id=i;
            }
      }
}
/*
* abaaba
* i:     0 1 2 3 4 5 6 7 8 9 10 11 12 13
* Ma[i]: $ # a # b # a # a $ b  #  a  #
* Mp[i]: 1 1 2 1 4 1 2 7 2 1 4  1  2  1
*/
char s[MAXN];
int main() {
      while(scanf("%s",s)==1) {
            int len=strlen(s);
            Manacher(s,len);
            int ans=0;
            for(int i=0; i<2*len+2; i++)
                  ans=max(ans,Mp[i]-1);
            printf("%d\n",ans);
      }
      return 0;
}

//----------------
/*=======================================================
		         其           它
=======================================================*/


//1.从1到n的异或和
//--------------------------------
long long xor_n (long long n)
{
	long long t = n & 3;
	if (t & 1) return t / 2u ^ 1;
	return t / 2u ^ n;
}
//--------------------------------- 

//2.ST
//---------------------------------
void ST()
{
    for ( int i = n; i > 0; --i ) {
        for ( int j = 1; i + ( 1 << j ) - 1 <= n; ++j ) {
            S[i][j] = max ( S[i][j - 1], S[i + ( 1 << j - 1 )][j - 1] );
        }
    }

}

LL get ( int l, int r )
{
    int tmp = int ( log ( r - l + 1 ) / log ( 2 ) );
    return max ( S[l][tmp], S[r - ( 1 << tmp ) + 1][tmp] );
}
//---------------------------------

//3.高能版异或高斯消元
//---------------------------------
bitset<N> a[N], mask[N];
int base[N];
int Gauss ( int n )
{
	int i,j;
    for ( i = 1; i <= n; ++i ) {
        for ( j = 1; j <= n; ++j ) {
            if ( a[i][j] ) {
                if ( !~base[j] ) {
                    mask[i][i] = 1;
                    base[j] = i;
                    break;
                }
                a[i] ^= a[base[j]];
                mask[i] ^= mask[base[j]];
            }
        }
    }
	//j>n时 a[i]自身可得，解集在mask
}
//-----------------------------------

//4.素数欧拉函数线性筛
//-----------------------------------
bool com[MAXN];
int primes, prime[MAXN], phi[MAXN];

phi[1] = 1;
for (int i = 2; i <= n; ++i)
{
  if (!com[i])
  {
    prime[primes++] = i;
    phi[i] = i-1;
  }
  for (int j = 0; j < primes && i*prime[j] <= n; ++j)
  {
    com[i*prime[j]] = true;
    if (i % prime[j])
      phi[i*prime[j]] = phi[i]*(prime[j]-1);
    else
      { phi[i*prime[j]] = phi[i]*prime[j]; break; }
  }
}
//-----------------------------------


//5.矩阵快速幂
//-----------------------------------
typedef unsigned long long ll;
const int N = 2;
const int M = (int)1e9+7;
struct Mat {
    ll mat[N + 1][N + 1];
} A, B;

Mat operator * ( Mat a, Mat b )
{
    Mat c;
    memset ( c.mat, 0, sizeof c.mat );
    for ( int k = 0; k <  N; k++ )
        for ( int i = 0; i <  N; i++ )
            for ( int j = 0; j <  N; j++ )
                ( c.mat[i][j] += ( a.mat[i][k] * b.mat[k][j] ) % M ) %= M;
    return c;
}

Mat operator ^ ( Mat a, ll pow )
{
    Mat c;
    for ( int i = 0; i <  N; i++ )
        for ( int j = 0; j <  N; j++ )
            c.mat[i][j] = ( i == j );
    while ( pow ) {
        if ( pow & 1 )     c = c * a;
        a = a * a;
        pow >>= 1;
    }
    return c;
}
//-----------------------------------

//6.高精度
//-----------------------------------
inline string add ( string a, string b )
{
    if ( a.size() < b.size() ) swap ( a, b );
    int la = a.size(), lb = b.size(), x = 0, i = 0;
    for ( i = 0; i < lb; ++i ) {
        x += ( a[i] - '0' + b[i] - '0' );
        a[i] = '0' + x % 10;
        x /= 10;
    }
    while ( x && i < la ) {
        x += ( a[i] - '0' );
        a[i] = '0' + x % 10;
        x /= 10;
        ++i;
    }
    if ( x ) a += '0' + x;
    return a;
}

inline string sub ( string a, string b )
{
    int la = a.size(), lb = b.size(), x = 0, i = 0;
    for ( i = 0; i < lb; ++i ) {
        if ( a[i] - x >= b[i] ) {
            a[i] = a[i] - x - b[i] + '0';
            x = 0;
        } else {
            a[i] = 10 + '0' + a[i] - b[i] - x;
            x = 1;
        }
    }
    while ( x && i < la ) {
        if ( a[i] != '0' ) {
            a[i] = a[i] - 1;
            x = 0;
        } else {
            a[i] = '9';
            ++i;
        }
    }
    i = la - 1;
    while ( a[i] == '0' && i != 0 ) {
        a.erase ( a.begin() + i );
        --i;
    }
    return a;
}

int T, n;

inline bool pd ( string a, string b )
{
    if ( a.size() == b.size() )  {
        for ( int i = a.size() - 1; i >= 0; --i ) {
            if ( a[i] != b[i] ) return a[i] > b[i];
        }
        return 0;
    }
    return a.size() > b.size();
}
//-----------------------------------

//7.读入输出优化
//-----------------------------------
inline void rd (int &xx) {
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    for (xx = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        xx = xx * 10 + (ch - '0');
}
char o[35];
inline void putnum (int x) {
    if (x == 0) {puts("0"); return;}
    int i;
    for (i = 0; x != 0; i++, x /= 10) o[i] = x % 10 + '0' ;
    for (i--; i >= 0; i--) putchar (o[i]);
    putchar (10);
}
//-----------------------------------

//8.凸包
//-----------------------------------
const double eps = 1e-8;
const double pi = acos( -1.0 );
int sgn( double x )
{
    return fabs( x ) < eps ? 0 : x < 0 ? -1 : 1;
}
struct point {
    double x, y;
    point() {}
    point( double x, double y )
    {
        this->x = x;
        this->y = y;
    }
    point operator +( point a )
    {
        return point( x + a.x, y + a.y );
    }
    point operator -( point a )
    {
        return point( x - a.x, y - a.y );
    }
    double operator *( point a )
    {
        return x * a.x + y * a.y;
    }
    double operator /( point a )
    {
        return x * a.y - y * a.x;
    }
    bool operator <( point a )const
    {
        return x != a.x ? x < a.x : y < a.y;
    }
} p[200], q[200];
int covexhull( point p[], int n, point ch[] )
{
    sort( p, p + n );
    int m = 0;
    for( int i = 0; i < n; i++ ) {
        while( m > 1 && sgn( ( ch[m - 1] - ch[m - 2] ) / ( p[i] - ch[m - 2] ) ) <= 0 )
            m--;
        ch[m++] = p[i];
    }
    int k = m;
    for( int i = n - 2; i > -1; i-- ) {
        while( m > k && sgn( ( ch[m - 1] - ch[m - 2] ) / ( p[i] - ch[m - 2] ) ) <= 0 )
            m--;
        ch[m++] = p[i];
    }
    if( n > 1 )
        m--;
    return m;
}
//-----------------------------------
/*=======================================================
		         技            巧
=======================================================*/

//1手动开栈
//----------------------------------
#pragma comment(linker, "/STACK:1024000000,1024000000") 
或
 int size = 256 << 20; // 256MB
 char *p = (char*) malloc (size) + size;
 __asm__ ("movl %0, %%esp\n" :: "r" (p) ); int size = 256 << 20; // 256MB
 char *p = (char*) malloc (size) + size;
 __asm__ ("movl %0, %%esp\n" :: "r" (p) );

 //----------------------------------


/*=======================================================
		         题型模板
=======================================================*/
//1.点分治
//-----------------------------------
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
const int N = 10004;

vector<int> E[N], C[N], tem;
int siz[N], dis[N], mx[N], vis[N], Siz;
int n, m, k;
int root, ans;

void Root ( int u, int fa )
{
    siz[u] = 1;
    mx[u] = 0;
    for ( int i = 0; i < E[u].size(); ++i ) {
        int v = E[u][i];
        if ( v != fa && !vis[v] ) {
            Root ( v, u );
            siz[u] += siz[v];
            mx[u] = max ( mx[u], siz[v] );
        }
    }
    mx[u] = max ( mx[u], Siz - siz[u] );
    if ( mx[u] < mx[root]  ) root = u;
}

void Dis ( int u, int fa  )
{
    tem.push_back ( dis[u] );
    for ( int i = 0; i < E[u].size(); ++i ) {
        int v = E[u][i], c = C[u][i];
        if ( v != fa && !vis[v] ) {
            dis[v] = dis[u] + c;
            Dis ( v, u );
        }
    }
}

int Calc ( int u, int w )
{
    dis[u] = w;
    tem.clear(), Dis ( u, 0 );
    sort ( tem.begin(), tem.end() );
    int ret = 0;
    for ( int i = 0, j = tem.size() - 1; i < j; ) {
        if ( tem[i] + tem[j] <= k && i < j )  ret += ( j - i ), ++i;
        else --j;
    }
    return ret;
}
void make ( int u )
{
    vis[u] = 1;
    ans += Calc ( u, 0 );
    for ( int i = 0; i < E[u].size(); ++i ) {
        int v = E[u][i], c = C[u][i];
        if ( vis[v] ) continue;
        ans -= Calc ( v, c );
        Siz = siz[u];
        Root ( v , root = 0 );
        make ( root );
    }
}

inline void init()
{
    ans = 0;
    for ( int i = 1; i <= n; ++i ) {
        E[i].clear(), C[i].clear();
        siz[i] = 0, vis[i] = 0;
    }
    mx[0] = N;
}

int main()
{
    while ( scanf ( "%d %d", &n, &k ) , n && k ) {
        init();
        for ( int i = 1, u, v, c; i < n; ++i ) {
            scanf ( "%d %d %d", &u, &v, &c );
            E[u].push_back ( v ), C[u].push_back ( c );
            E[v].push_back ( u ), C[v].push_back ( c );
        }
        Siz = n;
        Root ( 1, 0 );
        make ( root );
        printf ( "%d\n", ans );
    }
}
//-----------------------------------

//2.CDQ分治
//-----------------------------------
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#define ll long long
using namespace std;

const int N = 100009;
struct node {
    int l, r, p;
    node ( int l = 0, int r = 0, int p = 0 ) : l ( l ), r ( r ), p ( p ) {}
    bool operator < ( const node &a ) const
    {
        if ( r != a.r ) return r < a.r;
        if ( l != a.l ) return l > a.l;
        return p < a.p;
    }
} a[N], tem[N];
int dp[N], s[N];
int n,m;

void modify ( int x, int k )
{
    for ( x; x <= m; x += x & -x )
        s[x] = max ( s[x], k );
}

int getnum ( int x )
{
    int ans = 0;
    for ( x; x > 0; x -= x & -x )
        ans = max ( ans, s[x] );
    return ans;
}

void  sclear ( int x )
{
    for ( x; x <= m; x += x & -x )
        s[x] = 0;
}
void solve ( int l, int r )
{
    if ( l == r ) {
        dp[a[l].p] = max ( dp[a[l].p], 1 );
        return ;
    }
    int mid = ( l + r ) >> 1;
    solve ( mid + 1, r );
    for ( int i = l; i <= r; ++i ) {
        tem[i] = node ( a[i].l, a[i].r, a[i].p );
    }
    sort ( tem + l, tem + mid + 1 );
    sort ( tem + mid + 1, tem + r + 1 );
    for ( int i = mid, j = r; i >= l; --i ) {
        while ( j > mid && tem[j].r >= tem[i].r ) {
            modify ( tem[j].l, dp[tem[j].p] );
            --j;
        }
        dp[tem[i].p] = max ( dp[tem[i].p], getnum ( tem[i].l ) + 1 );
    }
    for ( int i = mid + 1; i <= r; ++i ) {
        sclear ( tem[i].l );
    }
    solve ( l, mid );
}

int main()
{
    while ( scanf ( "%d", &n ) != EOF ) {
        vector<int> b;
        for ( int i = 1; i <= n; ++i ) dp[i] = 1;
        for ( int i = 1; i <= n; ++i ) {
            scanf ( "%d", &a[i].l );
            a[i].p=i;
            b.push_back ( a[i].l );
        }
        for ( int i = 1; i <= n; ++i ) {
            scanf ( "%d", &a[i].r );
            b.push_back ( a[i].r );
        }
        sort ( b.begin(), b.end() );
        b.erase ( unique ( b.begin(), b.end() ), b.end() );
        for ( int i = 1; i <= n; ++i ) {
            a[i].l = lower_bound ( b.begin(), b.end(), a[i].l ) - b.begin() + 1;
            a[i].r = lower_bound ( b.begin(), b.end(), a[i].r ) - b.begin() + 1;
        }
        m=b.size()+10;
        solve ( 1, n );
        int ans = 0;
        for ( int i = 1; i <= n; ++i ) {
            ans = max ( ans, dp[i] );
        }
        printf ( "%d\n", ans );
        int x = 0x7fffffff, y = -0x7fffffff;
        for ( int i = 1; i <= n&&ans; ++i ) {
            if ( dp[i] == ans && a[i].l <= x && a[i].r >= y ) {
                printf ( "%d", i );
                x = a[i].l, y = a[i].r;
                if ( --ans != 0 ) putchar ( 32 );
                else putchar ( 10 );
            }
        }
    }
    return 0;
}
//-----------------------------------

//3.分块
//-----------------------------------
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;
const int N = 60005;
int s[1000][1000], sum[1000];
int add[1000], a[N], pos[N];
int tem1[1000], tem2[1000], tol1, tol2;
int n, m, q, bk, mx, last;

inline bool cmp ( int x, int y )
{
    return a[x] < a[y];
}

inline void Merge ( int k , int l, int r )
{
    tol1 = 0, tol2 = 0;
    for ( int i = 0; i < sum[k]; ++i ) {
        if ( s[k][i] >= l && s[k][i] <= r )
            tem1[tol1++] = s[k][i];
        else tem2[tol2++] = s[k][i];
    }
    merge ( tem1 , tem1 + tol1 , tem2 , tem2  + tol2, s[k] , cmp );
    a[0] = last + 1 - add[k];
    p[k] = lower_bound ( s[k], s[k] + sum[k], 0, cmp ) - s[k];
}

inline void modify ( int l, int r )
{
    int k = pos[l], t = pos[r];
    if ( k == t ) {
        for ( int i = l; i <= r; ++i ) {
            ++a[i];
        }
        Merge ( k , l, r );
        return ;
    }

    for ( int i = k + ( pos[l - 1] == k ); i <= t - ( pos[r + 1] == t ) ; ++i ) {
        ++add[i];
        a[0] = last + 1 - add[i];
        p[i] = lower_bound ( s[i], s[i] + p[i], 0, cmp ) - s[i];
    }

    if ( pos[l - 1] == k ) {
        for ( int i = l; pos[i] == k; ++i ) {
            ++a[i];
        }
        Merge ( k , l, r );
    }

    if ( pos[r + 1] == t ) {
        for ( int i = r; pos[i] == t; --i ) {
            ++a[i];
        }
        Merge ( t , l, r );
    }
}



int main()
{

    while ( scanf ( "%d %d", &n, &q ) != EOF ) {
        if ( n == 0 && q == 0 ) continue;
        bk = ceil ( sqrt ( 1.*n ) + 0.005 );
        m = ( n - 1 ) / bk + 1;
        for ( int i = 1; i <= m; ++i ) {
            sum[i] = add[i] = 0;
        }
        for ( int i = 1; i <= n; ++i ) {
            rd ( a[i] );
            mx = max ( a[i], mx );
            pos[i] = ( i - 1 ) / bk + 1;
            s[pos[i]][sum[pos[i]]++] = i;
        }
        for ( int i = 1; i <= m; ++i ) {
            sort ( s[i], s[i] + sum[i] , cmp );
        }

}

//-----------------------------------

//4.卡特兰数递推
//C(2n,n)/(n+1)
//-----------------------------------
#include <iostream>
long long f[19];
int main()
{
    cout<<"卡特兰数到f[n]:"
    int n;
    cin>>n;
    f[0]=1;f[1]=1;
    for(int i=2 ; i <= n; ++i)
    {
        f[i]=((4*i-2)*f[i-1])/(i+1);
        printf("%d",f[i]);
    }
    return0;
}
//-----------------------------------

//5.FFT
//-----------------------------------
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 300005;

typedef long long LL;
struct C {
    double r, i;
    C() {}
    C ( double _r, double _i ) : r ( _r ), i ( _i ) {}
    inline C operator + ( const C &a ) const
    {
        return C ( r + a.r, i + a.i );
    }
    inline C operator - ( const C &a ) const
    {
        return C ( r - a.r, i - a.i );
    }
    inline C operator * ( const C &a ) const
    {
        return C ( r * a.r - i * a.i, r * a.i + i * a.r );
    }
} a[N], b[N];

const double pi = acos ( -1.0 );
int n, num[N], cnt[N];
LL res[N], sum[N];

void brc ( C *y, int l )
{
    int i, j, k;
    for ( i = 1, j = l >> 1; i < l - 1; ++i ) {
        if ( i < j ) swap ( y[i], y[j] );
        k = l >> 1;
        while ( j >= k ) {
            j -= k;
            k >>= 1;
        }
        j += k;
    }
}

void FFT ( C *y, int l, int on )
{
    int h, i, j, k;
    C u, t;
    brc ( y, l ); // 得到一个自底向上的序列
    for ( h = 2; h <= l; h <<= 1 ) { // 控制一个O(logn)的外层复杂度
        C wn ( cos ( on * 2 * pi / h ), sin ( on * 2 * pi / h ) );
        for ( j = 0; j < l; j += h ) { // 两个for循环共组成O(n)的复杂度
            C w ( 1, 0 );
            for ( k = j; k < j + h / 2; ++k ) {
                u = y[k];
                t = w * y[k + h / 2];
                y[k] = u + t;
                y[k + h / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if ( on == 1 ) {
        for ( i = 0; i < l; ++i ) {
            y[i] = y[i] * C ( 1.0 / l, 0.0 );
        }
    }
}

int main()
{
    int T;
    scanf ( "%d", &T );
    while ( T-- ) {
        scanf ( "%d", &n );
        int Max = 0;
        memset ( cnt, 0, sizeof ( cnt ) );
        for ( int i = 0; i < n; ++i ) {
            scanf ( "%d", &num[i] );
            Max = max ( Max, num[i] );
            ++cnt[num[i]];
        }
        int L = 1;
        ++Max;
        while ( L <= ( Max << 1 ) ) L <<= 1;
        for ( int i = 0; i < Max; ++i ) {
            a[i] = C ( cnt[i], 0 );
        }
        for ( int i = Max; i < L; ++i ) {
            a[i] = C ( 0, 0 );
        }
        FFT ( a, L, -1 );
        for ( int i = 0; i < L; ++i ) {
            a[i] = a[i] * a[i];
        }
        FFT ( a, L, 1 );
        for ( int i = 0; i < L; ++i ) {
            res[i] = ( LL ) floor ( a[i].r + 0.5 );
        }
        for ( int i = 0; i < Max; ++i ) {
            res[i << 1] -= cnt[i];
        }
        for ( int i = 0; i < L; ++i ) {
            res[i] >>= 1;
        }
        for ( int i = 1; i < L; ++i ) {
            sum[i] = sum[i - 1] + res[i];
        }
        double ret = 0, den = 1.0 * n * ( n - 1 ) * ( n - 2 ) / 6.0;
        for ( int i = 0; i < n; ++i ) {
            ret += sum[num[i]] / den;
        }
        printf ( "%.7f\n", 1 - ret );
    }
    return 0;
}

//-----------------------------------

//6.优先队列背包
//-----------------------------------
//“多重背包”通用模板
const int MAX_V = 10004;
//v、n、w：当前所处理的这类物品的体积、个数、价值
//V：背包体积， MAX_V：背包的体积上限值
//f[i]：体积为i的背包装前几种物品，能达到的价值上限。
inline void pack ( int f[], int V, int v, int n, int w )
{
    if ( n == 0 || v == 0 ) return;
    if ( n == 1 ) {             //01背包
        for ( int i = V; i >= v; --i )
            if ( f[i] < f[i - v] + w ) f[i] = f[i - v] + w;
        return;
    }
    if ( n * v >= V - v + 1 ) { //完全背包(n >= V / v)
        for ( int i = v; i <= V; ++i )
            if ( f[i] < f[i - v] + w ) f[i] = f[i - v] + w;
        return;
    }

    int va[MAX_V], vb[MAX_V];   //va/vb: 主/辅助队列
    for ( int j = 0; j < v; ++j ) {   //多重背包
        int *pb = va, *pe = va - 1;     //pb/pe分别指向队列首/末元素
        int *qb = vb, *qe = vb - 1;     //qb/qe分别指向辅助队列首/末元素
        for ( int k = j, i = 0; k <= V; k += v, ++i ) {
            if ( pe  == pb + n ) {     //若队列大小达到指定值，第一个元素X出队。
                if ( *pb == *qb ) ++qb; //若辅助队列第一个元素等于X，该元素也出队。
                ++pb;
            }
            int tt = f[k] - i * w;
            *++pe = tt;                  //元素X进队
            //删除辅助队列所有小于X的元素，qb到qe单调递减，也可以用二分法
            while ( qe >= qb && *qe < tt ) --qe;
            *++qe = tt;              //元素X也存放入辅助队列
            f[k] = *qb + i * w;      //辅助队列首元素恒为指定队列所有元素的最大值
        }
    }
}
//-----------------------------------

//7.表达式求值
//-----------------------------------
ll expression ( string );
ll term ( string );
ll factor ( string );
ll number ( string );
ll expression ( string s )
{
    ll res = term ( s );
    for ( ;; ) {
        if ( s[now] == '+' ) {
            now++;
            res += term ( s );
        } else if ( s[now] == '-' ) {
            now++;
            res -= term ( s );
        } else break;
    }
    return res;
}

ll term ( string s )
{
    ll res = factor ( s );
    for ( ;; ) {
        if ( s[now] == '*' ) {
            now++;
            res *= factor ( s );
        } else break;
    }
    return res;
}

ll factor ( string s )
{
    ll res = number ( s );
    if ( s[now] == '(' ) {
        now++;
        res += expression ( s );
        now++;
    }
    return res;
}

ll number ( string s )
{
    ll res = 0;
    if ( 'a' <= s[now] && s[now] <= 'z' ) {
        res = mp[s[now]];
        now++;
    }
	//此处为一位数字
    if ( '0' <= s[now] && s[now] <= '9' ) {
        res = s[now] - '0';
        now++;
    }
    return res;
}

//-----------------------------------

//8.n!的非零最低位
//-----------------------------------
#include<stdio.h>  
#include<string.h>  
  
#define maxn 10001  
  
const int mod[20]={1,1,2,6,4,2,2,4,2,8,4,4,8,4,6,8,8,6,8,2};  
  
int lastdigit(char buf[])  
{  
    int len=strlen(buf),a[maxn],i,c,ret=1;  
    if(len==1)return mod[buf[0]-'0'];  
    for(i=0;i<len;i++)  
        a[i]=buf[len-1-i]-'0';  
    while(len)  
    {  
        ret=ret*mod[a[1]%2*10+a[0]]%5;  
        for(c=0,i=len-1;i>=0;i--)  
        {  
            c=c*10+a[i],a[i]=c/5,c%=5;  
        }  
        len-=!a[len-1];  
    }  
    return ret+ret%2*5;  
}  
  
int main()  
{  
    char  n[maxn];  
    while(scanf("%s",n)!=EOF)  
    {  
        printf("%d\n",lastdigit(n));  
    }  
    return 0;  
} 
//-----------------------------------

//9.最优比率生成树
//Dinkelbach
//-----------------------------------
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

const int N = 1009;
const double Eps = 1e-4;
int n, k;
double x[N], y[N], h[N];
double dis[N][N], dh[N][N];
double prim ( double k )
{
    int vis[N] = {0, 1},pos[N]={0}, s = 1, u = 1, v;
    double c[N];
    double cost = 0., len = 0.;
    while ( s < n ) {
        double tem = 0x7fffffff;
        for ( int i = 1; i <= n; ++i ) {
            if ( !vis[i] ) {
                double bit = dh[u][i] - k * dis[u][i];
                if ( u == 1 || bit < c[i] ) {
                    c[i] = bit;
                    pos[i]=u;
                }
                if ( tem > c[i] ) {
                    tem = c[i];
                    v = i;
                }
            }
        }
        cost += dh[pos[v]][v], len += dis[pos[v]][v];
        vis[v] = 1;
        u = v;
        ++s;
    }
    return cost / len;
}

int main()
{
    while ( scanf ( "%d", &n ) != EOF ) {
        if ( n == 0 ) break;
        for ( int i = 1; i <= n; ++i ) {
            scanf ( "%lf %lf %lf", &x[i], &y[i], &h[i] );
        }
        for ( int i = 1; i <= n; ++i ) {
            for ( int j = i + 1; j <= n; ++j ) {
                dis[i][j] = dis[j][i] = sqrt ( ( x[i] - x[j] ) * ( x[i] - x[j] ) + ( y[i] - y[j] ) * ( y[i] - y[j] ) );
                dh[i][j] = dh[j][i] = fabs ( h[i] - h[j] );
            }
        }
        double ans = 0., k;
        while ( 1 ) {
            k = prim ( ans );
            if ( fabs ( k - ans ) < Eps ) break;
            ans = k;
        }
        printf ( "%0.3f\n", ans );
    }
}
//-----------------------------------