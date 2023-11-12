#include <iostream>
#include <vector>
 
int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int n = 0, a = 0;
		std::cin >> n;
		std::vector <int> arr;
		while (n--) {
			std::cin >> a;
			arr.push_back(a);
		}
 
		int con = 0;
		if (arr[0] == arr[1]) {
			con = arr[0];
		}
		else if (arr[0] == arr[2]) {
			con = arr[0];
		}
		else if (arr[1] == arr[2]) {
			con = arr[1];
		}
		
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] != con) {
				std::cout << i + 1;
				break;
			}
		}
		std::cout << std::endl;
	}
	return 0;
}
