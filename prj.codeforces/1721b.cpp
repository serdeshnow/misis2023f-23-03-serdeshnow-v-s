#include <iostream>
 
 
int main() {
	int t = 0;
	std::cin >> t;
	while (t > 0) {
		int n, m, sx, sy, d;
		std::cin >> n >> m >> sx >> sy >> d; 
		//if (((2 * d + 1 >= n) || (2 * d + 1 >= m)) || ((sx + d >= n) && (sy + d >= m))) {
		if (((sy - d - 1 > 0) && (sx + d < n)) || ((sy + d < m) && (sx - d - 1 > 0)) ) {
			std::cout << m+n-2 << std::endl;
		}
		else {
			std::cout << -1 << std::endl;
		}
		t--;
	}
	return 0;
}
