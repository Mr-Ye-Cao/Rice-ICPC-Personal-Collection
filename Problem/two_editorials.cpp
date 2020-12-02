/***
  $2500 Dp Math Brute Force
  https://codeforces.com/contest/1443/problem/B
  The problem is just brutally solved with O(N^2)
  The input size is relatively small(2000)
  which makes brutally solving it possible.
  However, some bug still have to be fixed.
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


int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;

	vector<pair<int,pair<int,int> > > p;
	for(int i=0;i<m;i++){
		int l,r;
		cin>>l>>r;
		p.push_back(make_pair((l+r)/2,make_pair(l,r)));
	}

	sort(p.begin(),p.end());

	int res=0;

	int mdis=-1;
	vector<int> fchoic;

	for(int i=0;i<p.size();i++){
		// a b a+b=2m // b-a=k-1 // 2b=2m+k-1 => b=m+(k-1)/2 a=2m-b
		int m=p[i].first,b=m+(k-1)/2,a=2*m-b,tdis=0;
		vector<int> choice;
		for(int j=0;j<p.size();j++){
			int sta=p[i].second.first;
			int end=p[i].second.second;
			if(sta<=b){
				choice.push_back(j);
				int dis=min(end,b)-max(a,sta)+1;
				tdis+=dis;
			}
		}
		if(mdis<tdis){
			tdis=mdis;
			fchoic=choice;
		}
	}

	for(int i=fchoic.size()-1;i>=0;i--){
		p.erase(p.begin()+fchoic[i]);
	}

	res+=mdis;

	mdis=-1;

	for(int i=0;i<p.size();i++){
		// a b a+b=2m // b-a=k-1 // 2b=2m+k-1 => b=m+(k-1)/2 a=2m-b
		int m=p[i].first,b=m+(k-1)/2,a=2*m-b,tdis=0;
		vector<int> choice;
		for(int j=0;j<p.size();j++){
			int sta=p[i].second.first;
			int end=p[i].second.second;
			if(sta<=b){
				choice.push_back(j);
				int dis=min(end,b)-max(a,sta)+1;
				tdis+=dis;
			}
		}
		if(mdis<tdis){
			tdis=mdis;
			fchoic=choice;
		}
	}

	res+=mdis;

	cout<<res<<endl;

	return 0;
}
