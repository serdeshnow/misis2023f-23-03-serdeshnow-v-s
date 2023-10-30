#include <iostream>
#include <string>
#include <cmath>
 
int main()
{
    int all;
    std::cin >> all;
    for (int i = 0; i < all; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        int abs = std::abs(a - b);
        double part = abs / 2.0;
        int result = std::ceil(part / c);
        std::cout << result << std::endl;
    }
    
}
