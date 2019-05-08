#include <fstream>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>
#include <map>
#include<stack>
#include<map>
#include<queue>
#include <math.h>
#include<set>
#include<stdint.h>
#include <utility>
#include <cmath>
#include <iostream>
#include <iomanip>
#define MAXN 300005
#define MAXLG 17
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

using namespace std;
typedef long long int ll;
typedef pair<int, int> mp;
template<class T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template<class T> void chmax(T &t, const T &f) { if (t < f) t = f; }

int n, t;
double p, dp[2005][2005];

int main()
{
	    scanf("%d %lf %d", &n, &p, &t);
		    
		    dp[1][0] = 1;
			    for(int i=1; i<=n+1; ++i)
					    {
							        for(int j=0; j<t; ++j)
										        {
													            if(j+1 >= i)
																	            {
																					                dp[i+1][j+1] += dp[i][j]*p;
																									                
																									                if(i <= n)
																														                    dp[i][j+1] += dp[i][j]*(1.-p);
																													                else
																																		                    dp[i][j+1] += dp[i][j];
																																	            }
																        }
									    }
				    
				    double ans = 0;
					    for(int i=1; i<=n+1; ++i)
							        ans += (i-1)*(dp[i][t]);
						    
						    printf("%.12lf", ans);
							    return 0;
}
