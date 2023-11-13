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

		int deleted = 0;
		for (int i = 0; i < arr.size() - 1; i++) {
			for (int j = i + 1; j < arr.size(); j++) {
				if (arr[i] == arr[j] && arr[i] != -1) {
					arr[j] = -1;
					deleted++;
				}
			}
		}

		int ans = 0;
		for (int k = 0; k < arr.size(); k++) {
			if (arr[k] != -1) {
				ans += 1;
			}
		}

		if (deleted % 2 != 0) {
			ans -= 1;
		}
		std::cout << ans << std::endl;
	}
  return 0;
}