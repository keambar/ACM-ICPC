#include <bits/stdc++.h>
using namespace std;

class LureLucas
{
public:
    vector<string> placeReel(vector<pair<string,int> > &tab)
    {
        vector<string> wiecej;
        for(int i=0; i<tab.size(); ++i)
        {
            if (tab[i].second>1)
            {
                wiecej.push_back(tab[i].first);
                tab[i].second -= 2;
            }
        }
        vector<string> ret;
        sort(wiecej.begin(),wiecej.end());
        for(int i=0; i<wiecej.size(); ++i)
            ret.push_back(wiecej[i]);
        sort(tab.begin(),tab.end());
        for(int i=0; i<tab.size(); ++i)
        {
            for(int j=0; j<tab[i].second; ++j)
                ret.push_back(tab[i].first);
        }
        for(int i=0; i<wiecej.size(); ++i)
            ret.push_back(wiecej[i]);
        return ret;
    }
};

int main()
{
//    ifstream fin("1.in");
//    ofstream fout("2.out");
//    #define cin fin
//    #define cout fout
    int n;
    while(cin>>n)
    {
        vector<pair<string,int> > tab(n);
        string str;
        int num;
        for(int i=0; i<n; ++i)
        {
            cin>>str;
            cin>>num;
            tab[i]=make_pair(str,num);
        }
        LureLucas lureLucas;
        vector<string> ans=lureLucas.placeReel(tab);
        int len=ans.size();
        for(int i=0;i<len;++i)
            cout<<ans[i]<<((i==len-1)?"":" ");
        cout<<endl;
    }
    return 0;
}
/*
3
Thunder 1 Wind 3 Soil 2
--------------------------------------------
Soil Wind Thunder Wind Soil Wind
*/


/**< Test Unit */
//
//#include <bits/stdc++.h>
//using namespace std;
//string trim(string &s)
//{
//    if (s.empty()) return s;
//    s.erase(0,s.find_first_not_of(" "));
//    s.erase(s.find_last_not_of(" ") + 1);
//    return s;
//}
//
//int main()
//{
//    ifstream fin1("1.out");
//    ifstream fin2("2.out");
//    string s1,s2;
//    bool flag=0;
//    while(getline(fin1,s1) && getline(fin2,s2))
//    {
////        trim(s2);
//        cout<<s1<<endl;
//        cout<<s2<<endl;
//        cout<<"s1.length()="<<s1.length()<<endl;
//        cout<<"s2.length()="<<s2.length()<<endl;
//        if(s1.compare(s2)==0)
//            continue;
//        else
//        {
//            flag=1;
//            break;
//        }
//    }
//    if(flag)
//        cout<<"wrong answer"<<endl;
//    else
//        cout<<"accepted"<<endl;
//    return 0;
//}
