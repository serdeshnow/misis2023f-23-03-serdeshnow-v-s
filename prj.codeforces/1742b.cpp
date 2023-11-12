#include <iostream>
#include <algorithm>
#include <vector>
 
int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int n = 0;
		std::cin >> n;
		std::vector <int> arr;
		for (int i = 0; i < n; i++) {
			int a = 0;
			std::cin >> a;
			arr.push_back(a);
		}
		std::sort(arr.begin(), arr.end());
 
		bool flag = true;
		for (int j = 0; j < n - 1; j++) {
			if (arr[j] == arr[j + 1]) {
				flag = false;
				break;
			}
		}
		std::cout << ((flag) ? "YES\n" : "NO\n");
	}
 
	return 0;
}
