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
int N;
int x,y;
vector<pair<double,double> > co;

double caldis(pair<double,double> point){
	return sqrt(point.first*point.first+point.second*point.second);
}

double dis(pair<double,double> p1,pair<double,double> p2){
	return sqrt((p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second));
}

void mysort(double cx,double cy,vector<pair<double,double> > q){
	vector<double,pair<double,double> >  sq;
	for(int i=0;i<q.size();i++){
		q[i];
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin>>N;
	int cn=N;
	int count=0;
	map<int,set<int> > alre;
	while(cn--){
		cin>>x>>y;
		if(alre[x].find(y)==alre[x].end()){
			co.push_back(make_pair(x,y));
			count++;
			alre[x].insert(y);
		}
	}
	N=count;
	
	long long int sumx=0;
	long long int sumy=0;
	for(int i=0;i<N;i++){
		sumx+=co[i].first;
		sumy+=co[i].second;
	}

	double cenx=(double)sumx/N;
	double ceny=(double)sumy/N;

	cout<<"D1 "<<cenx<<" "<<ceny<<endl;

	for(int i=0;i<N;i++){
		co[i].first-=cenx;
		co[i].second-=ceny;
	}

	vector<pair<double,double> > qone;
	vector<pair<double,double> > qtwo;
	vector<pair<double,double> > qtre;
	vector<pair<double,double> > qfou;

	for(int i=0;i<N;i++){
		bool xpos=co[i].first>0;
		bool ypos=co[i].second>0;

		if(xpos&&ypos){
			qone.push_back(make_pair(co[i].first,co[i].second));
		}else if(xpos&&!ypos){
			qfou.push_back(make_pair(co[i].first,co[i].second));
		}else if(!xpos&&ypos){
			qtwo.push_back(make_pair(co[i].first,co[i].second));
		}else if(!xpos&&!ypos){
			qtre.push_back(make_pair(co[i].first,co[i].second));
		}
	}
	for(int i=0;i<qone.size();i++){
		cout<<"D5 "<<qone[i].first<<" "<<qone[i].second<<endl;	
	}

	cout<<"D3 "<<qone.size()<<endl;
	cout<<"D3 "<<qtwo.size()<<endl;
	cout<<"D3 "<<qtre.size()<<endl;
	cout<<"D3 "<<qfou.size()<<endl;

	mysort(qone,cenx,ceny);mysort(qtwo,cenx,ceny);
	mysort(qtre,cenx,ceny);mysort(qfou,cenx,ceny);

	pair<double,double> cone=qone[qone.size()-1];
	pair<double,double> ctwo=qtwo[qtwo.size()-1];
	pair<double,double> cthr=qtre[qtre.size()-1];
	pair<double,double> cfou=qfou[qfou.size()-1];

	cout<<"D10 "<<cone.first<<" "<<cone.second<<endl;
	cout<<"D10 "<<ctwo.first<<" "<<ctwo.second<<endl;
	cout<<"D10 "<<cthr.first<<" "<<cthr.second<<endl;
	cout<<"D10 "<<cfou.first<<" "<<cfou.second<<endl;

	vector<pair<double, pair<int,int> > > candi;

	candi.push_back(make_pair(caldis(cone),cone));
	candi.push_back(make_pair(caldis(ctwo),ctwo));
	candi.push_back(make_pair(caldis(cthr),cthr));
	candi.push_back(make_pair(caldis(cfou),cfou));

	sort(candi.begin(),candi.end());

	// for(int i=0;i<candi.size();i++){
	// 	cout<<candi[i].second.first<<" "<<candi[i].second.second<<endl;
	// }

	pair<double,double> pone=candi[1].second;
	pair<double,double> ptwo=candi[2].second;
	pair<double,double> pthr=candi[3].second;

	cout<<"D2 "<<pone.first<<" "<<pone.second<<endl;
	cout<<"D2 "<<ptwo.first<<" "<<ptwo.second<<endl;
	cout<<"D2 "<<pthr.first<<" "<<pthr.second<<endl;

	double a=dis(pone,ptwo);
	double b=dis(ptwo,pthr);
	double c=dis(pone,pthr);
	double s=(a+b+c)/2;

	double area=sqrt(s*(s-a)*(s-b)*(s-c));

	cout<<area<<endl;

	return 0;
}
