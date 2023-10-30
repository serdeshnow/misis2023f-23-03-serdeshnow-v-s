#include <iostream>
#include <vector>
 
int main() {
	int amount = 0, now = 0;
	std::vector <int> res = {};
	std::cin >> amount;
	for (int i = 0; i < amount; i++) {
		std::cin >> now;
		for (int j = 0; j < res.size(); j++) {
			if (res[j] == now) {
				res[j] = -1;
			}
		}
		res.push_back(now);
	}
	int count = 0;
	std::vector <int> ans = {};
	for (int k = 0; k < res.size(); k++) {
		if (res[k] != -1) {
			ans.push_back(res[k]);
			count++;
		}
	}
	std::cout << count << std::endl;
	for (int p = 0; p < ans.size(); p++) {
		std::cout << ans[p] << " ";
	}
	return 0;
}
