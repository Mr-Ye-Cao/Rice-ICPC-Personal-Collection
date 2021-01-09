/***
https://codeforces.com/contest/1471/problem/B
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

void solve(){
	ll n,x,res=0;
	cin>>n>>x;
	vector<ll> a(n);
	vector<ll> xa(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	xa=a;
	bool term=false,temw=false;
	while(!temw){
		if(!term){
			res+=accumulate(a.begin(),a.end(),0);
		}else{
			for(int i=0;i<n;i++){
				if(xa[i]!=-1){
					res+=a[i];
				}else{
					temw=true;
					break;
				}
			}
		}
		if(!term){
			for(int j=0;j<n;j++)
				if(xa[j]%x){
					xa[j]/=x;
				}else{
					term=true;
					xa[j]=-1;
					break;
				}
		}
	}

	cout<<res<<endl;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	cin>>t;
	while(t--)
		solve();

    return 0;
}
