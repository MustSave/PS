#include <iostream>
int main(){
	int T,x;
	std::cin>>T;
	for(int t=0;t<T;++t){
		int a=0;
		for(int j=0;j<10;++j){
			std::cin>>x;
			a+=x&1?x:0;
		}
		std::cout<<'#'<<t+1<<' '<<a<<'\n';
	}
}