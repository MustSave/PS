#include <iostream>
using namespace std;
int main(){
	int T,M,m;
	cin>>T;
	for(int i=0;i<T;++i){
		M=0;
		for(int j=0;j<10;++j){
			cin>>m;
			M=max(M,m);
		}
		cout<<'#'<<i+1<<' '<<M<<'\n';
	}
}