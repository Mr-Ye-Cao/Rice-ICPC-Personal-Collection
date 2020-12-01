/***
  $1300 Dp Math
  https://codeforces.com/contest/1443/problem/B
  Some bug waiting to be fixed. The majority frame of the code works
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
		string s;
		cin>>s;
		size_t found_sta=s.find("1");
		if(found_sta==string::npos){
			cout<<"0"<<endl;
			continue;
		}
		size_t found_end=s.find("0",found_sta);

		vector<pair<int,int> > ones;
		while(found_sta!=string::npos){
			found_sta=s.find("1",found_end);
			found_end=s.find("0",found_sta);
			if(found_end==string::npos){
				ones.push_back(make_pair(found_sta,s.size()-1));
				break;
			}
				ones.push_back(make_pair(found_sta,found_end-1));
		}


		long long int cost=0;
		
		while(ones.size()!=0){
			if(ones.size()==1){
				cost+=a;
				ones.pop_back();
			}else{
				if((ones[ones.size()-1].first-ones[ones.size()-2].second-1)*b<a){
					ones[ones.size()-2].second=ones[ones.size()-1].second;
					cost+=b;
					ones.pop_back();
				}else{
					cost+=a;
					ones.pop_back();
				}
			}
		}

		cout<<cost<<endl;
	}
	return 0;
}
