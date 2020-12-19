/***
  $1400 dp math
  https://codeforces.com/contest/1461/submission/101689019
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
	int m,n;
	cin>>m>>n;
	vector<vector<int> > dp (m); 
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++){
			char ch;
			cin>>ch;
			if(ch=='*')
				dp[i].push_back(1);
			else
				dp[i].push_back(0);
		}
	reverse(dp.begin(),dp.end());
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(dp[i][j]!=0){
				if(i!=0&&j!=0&&j!=n-1){
					if(dp[i-1][j-1]!=0&&dp[i-1][j]!=0&&dp[i-1][j+1]!=0){
						int va=min(dp[i-1][j-1],dp[i-1][j]);
						va=min(va,dp[i-1][j+1]);
						dp[i][j]+=va;
					}
				}
			}
		
	long long int total=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			total+=dp[i][j];
			// cout<<dp[i][j]<<" ";
		}
			// cout<<endl;
	}
 
	cout<<total<<endl;
}
 
int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
    return 0;
}
