#include <iostream>
 
 
int main() {
	long double n = 0, m = 0, a = 0;
	std::cin >> n >> m >> a;
	long double one = ceil(m / a);
	long double two = ceil(n / a);
	long long ans = one * two;
	std::cout << ans;
	return 0;
}
