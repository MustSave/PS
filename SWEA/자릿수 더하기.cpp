#include <iostream>
int main() {
    int N,a;
    std::cin>>N;
    while(N){a+=N%10;N/=10;}
    std::cout<<a;
}