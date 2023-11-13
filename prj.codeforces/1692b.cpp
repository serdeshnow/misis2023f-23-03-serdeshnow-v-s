#include <iostream>
#include <vector>


int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int n = 0;
		std::cin >> n;
		std::vector <int> arr;
		for (int index = 0; index < n; index++) {
			int a = 0;
			std::cin >> a;
			arr.push_back(a);
		}

		for (int i = 0; i < arr.size(); i++) {
			for (int j = i + 1; j < arr.size(); j++) {
				if (arr[i] == arr[j] && arr[i] != -1) {
					arr[j] = -1;
				}
			}
		}

		int count = 0;
		for (int k = 0; k < arr.size(); k++) {
			if (arr[k] != -1) {
				count += 1;
			}
		}
		std::cout << count << std::endl;
	}
	return 0;
}