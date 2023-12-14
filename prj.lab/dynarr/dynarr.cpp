#include <iostream>
#include <cstddef>

class Dynarr {
public:
  Dynarr() = default;
  ~Dynarr() { delete[] data_; }
  /// corner cases (check)
  Dynarr(const Dynarr& rhs) = default;
  Dynarr& operator=(const Dynarr& rhs);




private:
  std::ptrdiff_t size_ = 0;
  std::ptrdiff_t capacity_ = 0;
  float* data_ = nullptr;
};