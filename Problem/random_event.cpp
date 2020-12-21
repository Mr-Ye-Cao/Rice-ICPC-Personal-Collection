/***
  $1500 greedy probability
  https://codeforces.com/contest/1461/problem/C
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
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	vector<pair<int,double> > e;
	for(int j=0;j<m;j++){
		int r;
		double p;
		cin>>r>>p;
		e.push_back(make_pair(r,p));
	}
	
	if(is_sorted(a.begin(),a.end())){
		cout<<"1.000000"<<endl;
		return;
	}

	vector<pair<int,int> > ap;
	for(int r=0;r<n;r++)
		ap.push_back(make_pair(a[r],r));
	
	sort(ap.begin(),ap.end());

	int gi=-1;
	for(int k=n-1;k>=0;k--)
		if(ap[k].second!=k){
			gi=k+1;
			break;
		}
	 
	vector<double> candi;
	for(int k=0;k<m;k++)
		if(e[k].first>=gi)
			candi.push_back(1-e[k].second);

	if(candi.size()==0){
		cout<<"0.000000"<<endl;
		return;
	}
	
	double res=1.0-accumulate(candi.begin(),candi.end(),1.0,multiplies<double>());
	printf("%.6f\n",res);
}
 
 
int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	cin>>t;
	while(t--)
		solve();
 
    return 0;
}
