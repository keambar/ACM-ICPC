#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

char Astr[200],Bstr[200];
int Astrlen,Bstrlen;
char str[200];
void rev(char *s) {
    int len = strlen(s);
    int k = len/2;
    for (int i = 0 ;i <= len/2 ;i ++) {
        s[i] = s[len - i - 1];
    }
}

bool  addToCmp(bool aRev,bool bRev) {
    char tmpStr[500];
    char tmpRevStr[500];
    memset(tmpStr,0,sizeof(tmpStr));
    memset(tmpRevStr,0,sizeof(tmpRevStr));

    if (aRev) {
        for (int i = 0 ;i < Astrlen ;i ++) {
            tmpStr[i] = Astr[Astrlen-i-1];
        }
        for (int i = Bstrlen ;i < Astrlen + Bstrlen ;i ++) {
            tmpRevStr[i] = Astr[Astrlen - (i - Bstrlen) - 1];
        }
    } else {
        for (int i = 0 ;i < Astrlen ;i ++) {
            tmpStr[i] = Astr[i];
        }
        for (int i = Bstrlen ;i < Astrlen + Bstrlen ;i ++) {
            tmpRevStr[i] = Astr[i - Bstrlen];
        }
    }

    if (bRev) {
        for (int i = Astrlen ;i < Astrlen + Bstrlen ;i ++) {
            tmpStr[i] = Bstr[Bstrlen - (i - Astrlen) -1];
        }
        for (int i = 0 ;i < Bstrlen;i ++) {
             tmpRevStr[i] = Bstr[Bstrlen - i - 1];
        }
    } else {
        for (int i = Astrlen ;i < Astrlen + Bstrlen ;i ++) {
            tmpStr[i] = Bstr[i - Astrlen];
        }
        for (int i = 0 ;i < Bstrlen;i ++) {
             tmpRevStr[i] = Bstr[i];
        }
    }

    if (strcmp(tmpStr,str) == 0) {
        return true;
    }
    if (strcmp(tmpRevStr,str) == 0) {
         return true;
    }
    return false;
}

void solve() {
    for (int i = 0 ;i < 4 ;i ++) {
        if (addToCmp(i%2,i/2)) {
            printf("yes\n");
            return ;
        }
    }
    printf("no\n");
}

int main() {
    freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
    clock_t be,en ;
    be = clock();
    int N;
    scanf("%d",&N);
    while(N--) {
        scanf("%s %s",Astr,Bstr);
        scanf("%s",str);
        Astrlen = strlen(Astr);
        Bstrlen = strlen(Bstr);
        solve();
    }
    en = clock();
    printf("%lf\n",1.0*(en-be)/CLOCKS_PER_SEC);
    return 0;
}
