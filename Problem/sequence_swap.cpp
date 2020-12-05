/***
  $1600
  https://codeforces.com/problemset/problem/1455/D
  Not figuered out and solved yet. 

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
		bool im=false;
		cin>>n>>x;
		vector<int> a(n);
		for(int i=0;i<n;i++)
			cin>>a[i];
		
		vector<int> c;
		for(int j=0;j<n-1;j++)
			if(a[j]>a[j+1]){
				c.push_back(j+1);
				break;
			}

		if(c.size()==0){
			cout<<"0"<<endl;
			continue;
		}
		
		for(int i=0;i<n;i++)
			if(a[i]<x){
				cout<<"-1"<<endl;
				im=true;
				break;
			}
		
		if(im)
			continue;


		int mino=0;
		for(int i=0;i<c.size();i++){
			mino+=c[i]+1;
		}

		cout<<mino<<endl;
	}
	return 0;
}
