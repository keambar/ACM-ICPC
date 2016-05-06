#includemap
#includestring
#includecstring
#includecstdio
#includecstdlib
#includecmath
#includequeue
#includevector
#includeiostream
#includealgorithm
#includebitset
#includeclimits
#includelist
#includeiomanip
#includestack
#includeset
using namespace std;
int main()
{
	int n;
	while(scanf(%d,&n)!=EOF)
	{
		bool flag=1;
		while(n--)
		{
			double t;
			scanf(%lf,&t);
			t=sqrt(t);
			if(ceil(t)!=floor(t))
				flag=0;
		}
		puts(flagYesNo);
	}
}