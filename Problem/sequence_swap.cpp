/***
  $1600
  https://codeforces.com/problemset/problem/1455/D
  The subproblem I think is to just always greedily solve the
  very first conflict. Still some bugs need to be fixed.
  
  Correction: subproblem is to always first solve the minimum conflict 
  among the candidate conflicts. If x is smaller than the minimum conflict
  then it would be impossible to sovle it. This is proven by drawing chart and reach an contradiction.
  	     

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

int solve(){
	int n,x;
	cin>>n>>x;

	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];


	if(is_sorted(a.begin(), a.end()))
		return 0;

	vector<pair<int,int> > c;
	for(int j=0;j<n-1;j++)
		if(a[j]>a[j+1])
			c.push_back(make_pair(a[j],j));

	sort(c.begin(),c.end());

	if(c[0].first<=x)
		return -1;

	reverse(c.begin(),c.end());

	int cost=0;
	while(!c.empty()){
		pair<int,int> las_con=c.back();
		c.pop_back();
		int con_num=las_con.first;
		int con_ind=las_con.second;

		if(con_num<=x)
			return -1;
		
		


	}
}


int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		cout<<solve()<<endl;
	}
	return 0;
}
