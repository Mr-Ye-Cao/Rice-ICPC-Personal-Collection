/***
  $1600 brute force
  https://codeforces.com/contest/1461/problem/D
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
void help(set<int>& sus,vector<int>::iterator lb,vector<int>::iterator le,
					    vector<int>::iterator rb,vector<int>::iterator re){
	
	int ls=accumulate(lb,le,0);
	int rs=accumulate(rb,re,0);
	sus.insert(ls);
	sus.insert(rs);

	if(*lb!=*le){
		int mid=(*le+(*lb))/2;
		vector<int>::iterator up=upper_bound(lb,le,mid);
		help(sus,lb,up-1,up,le);
	}

	if(*rb!=*re){
		int mid=(*rb+(*re))/2;
		vector<int>::iterator up=upper_bound(rb,re,mid);
		help(sus,rb,up-1,up,re);
	}
}

void solve(){
	int n,q;
	cin>>n>>q;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a.begin(),a.end());

	set<int> sus;
	int mid=(*(a.end()-1)+(*a.begin()))/2;
	vector<int>::iterator up=upper_bound(a.begin(),a.end(),mid);

	help(sus,a.begin(),up-1,up,a.end());

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
	while(t--){
		solve();
	}

	// vector<int> a;
	// a.push_back(1);
	// cout<<*(a.end()-3)<<endl;
    return 0;
}
