#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){int N,i,x;cin>>N;vector<int> v(N,0);while(i<N){cin>>x;v[i++]=x;}sort(v.begin(),v.end());cout<<v[N/2];}
