/***
  $900 DP
  https://codeforces.com/problemset/problem/1451/B
***/

#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
typedef long long ll;
int maxE=1e3;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	cin>>t;
	int dp[maxE];
	while(t--){
		int n,q;
		cin>>n>>q;
		string s;
		cin>>s;
		s="X"+s;
		bool one_f=false,zer_f=false;
		for(int j=1;j<=n;j++){
			if(!one_f&&s[j]=='1'){
				dp[j]=-1;
				one_f=true;
			}else if(!zer_f&&s[j]=='0'){
				dp[j]=-1;
				zer_f=true;
			}else if(one_f&&s[j]=='1'){
				dp[j]=1;
			}else if(zer_f&&s[j]=='0'){
				dp[j]=1;
			}
		}
		
		one_f=false,zer_f=false;
		for(int j=n;j>=1;j--){
			if(!one_f&&s[j]=='1'){
				one_f=true;
			}else if(!zer_f&&s[j]=='0'){
				zer_f=true;
			}else if(one_f&&s[j]=='1'){
				if(dp[j]==-1){
					dp[j]=1;
				}
			}else if(zer_f&&s[j]=='0'){
				if(dp[j]==-1){
					dp[j]=1;
				}
			}
		}

		dp[1]=-1;
		dp[n]=-1;

		bool fon=false;
		for(int i=0;i<q;i++){
			int l,r;
			cin>>l>>r;
			if(dp[l]==1||dp[r]==1){
				cout<<"YES"<<endl;
			}else{
				cout<<"NO"<<endl;
			}
		}

		for(int j=n;j>=1;j--){
			dp[j]=0;
		}
	}

    return 0;
}
