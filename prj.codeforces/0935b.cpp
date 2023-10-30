# include <iostream>
# include <string>

int main() {
	int n = 0;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	int x = 0, y = 0;
	int count = 0;
	int p_x = 0, p_y = 0;
	bool half_1 = false, half_2 = false;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'U') {
			y += 1;
		}
		else {
			x += 1;
		}

		if (p_x == p_y && x != 0 && ((y - x > 0 && half_2 == true) || (x - y > 0 && half_1 == true)) ) {
			count += 1;
		}
		p_x = x; p_y = y;

		if (y > x) {
			half_1 = true; half_2 = false;
		}
		else if (x > y) {
			half_1 = false; half_2 = true;
		}
	}
	std::cout << count;

	return 0;
}
