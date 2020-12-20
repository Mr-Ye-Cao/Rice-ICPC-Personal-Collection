/***
  $1600 Brute Force Recursion
  https://codeforces.com/contest/1461/problem/D
  The Run-Time error is fixed by changing the recursion structure.
  The Insert function runs backwards and the computation complexity is thus minizied:
  All of the additions of array is least overlapped by computing the subsequence elements first 
  and then add the elements together.
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

ll helper(set<ll>& sus,vector<ll>::iterator be,vector<ll>::iterator en){
	// unseperable
	if((*be)==(*en))
		return accumulate(be,en+1,0);
	
	ll mid=((*be)+(*en))/2;
	vector<ll>::iterator mip=upper_bound(be,en+1,mid);
	ll les=helper(sus,be,mip-1);
	ll ris=helper(sus,mip,en);
	sus.insert(les);
	sus.insert(ris);
	sus.insert(les+ris);

	return les+ris;
}

void solve(){
	int n,q;
	cin>>n>>q;
	vector<ll> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a.begin(),a.end());

	set<ll> sus;
	if(a[0]!=a[n-1])
		helper(sus,a.begin(),a.end()-1);
	else
		sus.insert(a[0]*n);

	for(int j=0;j<q;j++){
		int s;
		cin>>s;

		if(sus.find(s)!=sus.end())
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	cin>>t;
	while(t--)
		solve();
	
    return 0;
}
