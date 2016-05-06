// File Name: 663A.cpp
// Author: keambar
// Created Time: 2016年05月06日 星期五 22时41分46秒

#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#define LL long long

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
