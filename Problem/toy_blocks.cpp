/***
$1400
Math

This cp problem is easier to solve if thinking backwards:
so the end scenorio is that every number is the same after choosing a random one
this means that 1. if sum of numbers are conserved then every number should be equal
to the average of mean over (n-1). On the other hand, if there is a maximum number
then all number should at least be equal to this number.

The difference between the sum of previous scenorio and one of the two scenorios is least
number added.

Thinking backwards of the end scenorio will eliminate the process of thinking about the 
process of how exactly the numbers are distributed which is way more complicated and irrelevant
to this question.
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
		int n;
		cin>>n;
		long long int sum=0,m=-1;
		vector<long long int> num(n);
		for(int i=0;i<n;i++){
			long long int tem;
			cin>>tem;
			if(tem>m){
				m=tem;
			}
			sum+=tem;
			num.push_back(tem);
		}
		long long int res=0;
		long long int k=max(m,(sum+n-2)/(n-1));
		cout<<k*(n-1)-sum<<endl;
	}

	return 0;
}
