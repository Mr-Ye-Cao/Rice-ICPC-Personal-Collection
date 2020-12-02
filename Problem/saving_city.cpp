/***
  $1300 Dp Math
  https://codeforces.com/contest/1443/problem/B
  The bug is fixed: first bug is to transform the string; the second bug is way to calculate the cost of merging.
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
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		string m;
		cin>>m;
		
		long long int cost=0;
		vector<pair<int,int> > pres;
		size_t f_s=m.find("1");
		size_t f_e=m.find("0",f_s);

		while(f_s!=string::npos){
			if(f_e==string::npos){
				pres.push_back(make_pair(f_s,m.size()-1));
				break;
			}
				pres.push_back(make_pair(f_s,f_e-1));
				f_s=m.find("1",f_e);
				f_e=m.find("0",f_s);
		}

		while(pres.size()!=0){
			if(pres.size()==1){
				cost+=a;
				break;
			}
			pair<int,int> lo=pres[pres.size()-1];
			pair<int,int> lt=pres[pres.size()-2];

			if((lo.first-lt.second-1)*b<a){
				pres[pres.size()-2].second=pres[pres.size()-1].second;
				pres.pop_back();
				cost+=(lo.first-lt.second-1)*b;
			}else{
				pres.pop_back();
				cost+=a;
			}
		}


		cout<<cost<<endl;
	}
	return 0;
}
