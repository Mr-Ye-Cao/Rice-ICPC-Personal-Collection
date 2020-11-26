/***
  $800 Greedy
  https://codeforces.com/problemset/problem/1445/A
  Pretty easy both in implementation and greedy strategy
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
		int n,x;
		cin>>n>>x;
		bool big=false;
		vector<int> v1,v2;
		for(int i=0;i<2;i++){
			for(int j=0;j<n;j++){
				int temp;
				cin>>temp;
				if(temp>x){
					cout<<"NO"<<endl;
					big=true;
					break;
				}
				if(i==0){
					v1.push_back(temp);
				}else{
					v2.push_back(temp);
				}
			}
			if(big) break;
		}
		if(big) continue;
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());reverse(v2.begin(),v2.end());
		for(int i=0;i<n;i++){
			if(v1[i]+v2[i]>x){
				cout<<"NO"<<endl;
				big=true;
				break;
			}
		}
		if(!big){
			cout<<"YES"<<endl;
		}
	}
	return 0;
}
