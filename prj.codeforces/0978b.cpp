#include <iostream>
#include <string>
 
int main() {
	int a = 0;
	std::cin >> a; // кол-во символов
	std::string str;
	std::cin >> str; // вводим символы
	int ans = 0, countx = 0; // счет ответа и счет х подряд
	for (int i = 0; i < a; i++) {
		if (str[i] == 'x') {
			countx++;
			if (countx > 2) {
				ans++;
			}
		}
		else {
			countx = 0;
		}
	}
	std::cout << ans;
	return 0;
}
