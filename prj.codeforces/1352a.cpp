#include <iostream>
#include <vector>
 
int main() {
    int nums;
    std::cin >> nums;
 
    for (int i = 0; i < nums; i++) {
        int n;
        std::cin >> n;
 
        std::vector<int> slagaemye;
 
        int k = 1;
        while (n > 0) {
            int digit = n % 10;
            if (digit != 0) {
                slagaemye.push_back(digit * k);
            }
            n /= 10;
            k *= 10;
        }
 
        std::cout << slagaemye.size() << std::endl;
        for (int j = slagaemye.size() - 1; j >= 0; j--) {
            std::cout << slagaemye[j] << " ";
        }
        std::cout << std::endl;
    }
 
    return 0;
}
