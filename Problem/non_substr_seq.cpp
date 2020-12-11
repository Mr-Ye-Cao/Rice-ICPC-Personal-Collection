/***
  $900 DP
  https://codeforces.com/problemset/problem/1451/B
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

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		string s;
		cin>>s;
		s="X"+s;

		int ml_one=-1,ml_zero=-1,mr_one=-1,mr_zero=-1;

		for(int i=1;i<=n;i++)
			if(s[i]=='0'){
				ml_zero=i;
				break;
			}
		
		for(int i=n;i>=1;i--)
			if(s[i]=='0'){
				mr_zero=i;
				break;
			}
		
		for(int i=1;i<=n;i++)
			if(s[i]=='1'){
				ml_one=i;
				break;
			}
		for(int i=n;i>=1;i--)
			if(s[i]=='1'){
				mr_one=i;
				break;
			}

		bool fon=false;
		for(int i=0;i<q;i++){
			int l,r,lind,rind;
			cin>>l>>r;
			if(s[l]=='0')
				lind=ml_zero;
			else
				lind=ml_one;
			if(s[r]=='0')
				rind=mr_zero;
			else
				rind=mr_one;

			if((lind!=-1&&lind<l)||(rind!=-1&&rind>r))
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}

    return 0;
}
