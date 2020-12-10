/***
  $1400 DP
  https://codeforces.com/problemset/problem/1415/C
  Instead of directly calculating the cost, we calculate the intermidate dp, resulting in linear time of solving the problem.
  Don't forget to reset the entry of array to 0 after the calculation to prevent memery reset.
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

ll maxE=1e6;

void solve(){
	ll n,p,k;
	cin>>n>>p>>k;
	string s;
	cin>>s;
	ll x,y;
	cin>>x>>y;

	s="X"+s;
	ll dp[maxE];

	for(ll i=n;i>=p;i--)
		dp[i]=dp[i+k]+(s[i]=='1'?0:1);
		
	ll cost=LONG_MAX;
	
	for(ll j=0;n-j>=p;j++)
		cost=min(cost,dp[p+j]*x+j*y);

	for(ll i=n;i>=p;i--)
		dp[i]=0;

	cout<<cost<<endl;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
