/***
  $1300 Math Logic
  https://codeforces.com/problemset/problem/1446/A
  Requires a bit math to think through the greedy part
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
		bool foun=false;
		int n;
		long long int w;
		cin>>n>>w;
		vector<pair<long long int,int> > nums; 
		for(int i=1;i<=n;i++){
			long long int temp;
			cin>>temp;
			if(temp<=w){
				nums.push_back(make_pair(temp, i));
			}
			if(temp<=w&&temp>=(w+1)/2){
				cout<<"1"<<endl;
				cout<<i<<endl;
				foun=true;
				break;
			}
		}
		if(foun)
			continue;

		long long int has=0;
		long long int goal=(w+1)/2;
		vector<int> choice;
		sort(nums.begin(),nums.end());
		reverse(nums.begin(),nums.end());
		while(nums.size()!=0){
			pair<long long int, int> cu=nums.back();
			nums.pop_back();
			choice.push_back(cu.second);
			has+=cu.first;
			if(has>=goal&&has<=w){
				cout<<choice.size()<<endl;
				for(int cho:choice){
					cout<<cho<<" ";
				}
					cout<<endl;
					foun=true;
					break;
			}
			if(has>w){
				break;
			}
		}
		if(foun){
			continue;
		}
		cout<<"-1"<<endl;
	}
	
	return 0;
}
