// File Name: 663A.cpp
// Author: keambar
// Created Time: 2016年05月06日 星期五 22时41分46秒

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define LL long long
#define se second
#define fi first
const int N = 200005;
const int Mod = ( int ) 1e9 + 7;

using namespace std;
vector<int> A,B;
vector<string> sym;
int lenA,lenB,tmp,n,len;
int main(){
    string ch;
    while(cin>>ch,ch[0]!='='){
        if(ch[0]=='?'){
            ++lenA;
            A.push_back(1);
        }
        else{
            ++len;
            sym.push_back(ch);
            if(ch[0]=='-'){
                --lenA;
                ++lenB;
                B.push_back(1);
            }
        }
    }
    cin>>n;
    tmp=n-lenA+lenB;
    for(int i=0;i<lenA;++i){
        if(tmp>0&&A[i]<n){
            int k=min(tmp,n-A[i]);
            A[i]+=k;
            tmp-=k;
        }
    }
    for(int i=0;i<lenB;++i){
        if(tmp<0&&B[i]<n){
            int k=min(-tmp,n-B[i]);
            B[i]+=k;
            tmp+=k;
        }
    }
    if(tmp!=0){
        cout<<"Impossible"<<endl;
    }
    else{
        cout<<"Possible"<<endl;
        cout<<A[0];
        int i=1,j=0,p=0;
        while(p!=len){
            if(sym[p]=="+"){
                cout<<" + "<<A[i];
                ++i;
            }
            else{
                cout<<" - "<<B[j];
                ++j;
            }
            ++p;
        }
        cout<<" = "<<n<<endl;

    }
    return 0;
}
