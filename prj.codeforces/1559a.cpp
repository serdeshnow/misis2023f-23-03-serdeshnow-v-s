#include <iostream>
#include <vector>

int main() {
  int t = 0;
  std::cin >> t;
  while (t--) {
    int n = 0;
    std::vector <int> arr;
    for (int index = 0; index < n; index++) {
      int a = 0;
      std::cin >> a;
      arr.push_back(a);
    }
    
    /*
    int l = 0;
    int r = 0;
    std::cin >> l >> r;
    l--;
    r--;
    std::vector <int> arr_slice(l, r);

    for (int i = 0; i < (arr_slice.size() + 1) / 2; i++) {
      arr_slice[i] = arr_slice[i] & arr_slice[arr_slice.size() - i];
    }
    
    
    int maxi = 0;
    for (int j = 0; j < arr_slice.size(); j++) {
      maxi = std::max(arr_slice[j], maxi);
    }
    std::cout << maxi;
    */
    int maxi = 0;
    for (int j = 0; j < arr.size(); j++) {
      maxi = std::max(arr[j], maxi);
    }
    std::cout << maxi;

  }
  return 0;
}