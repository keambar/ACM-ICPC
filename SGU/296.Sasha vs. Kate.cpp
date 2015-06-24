#include <iostream>
#include <string>
using namespace std;

string s;
int k,t;
int main()
{
    cin>>s>>k;
    for(int i=1;i<s.size()&&t<k;++i){
        while(s[i]>s[i-1]){
            s.erase(s.begin()+i-1);
            if(++t==k) break;
            if(--i==0) break;
        }
    }
    while(t<k){
        s.erase(s.end()-1);
        ++t;
    }
    cout<<s<<endl;
}