#include <string>
#include <unordered_map>

namespace designpattern {
namespace structual {
class Tea {};

class TeaMaker {
 public:
  Tea Make(const std::string& preference) {
    if (_storage.find(preference) == _storage.end()) {
    }
  }

 private:
  std::unordered_map<std::string, Tea> _storage;
};
}  // namespace structual
}  // namespace designpattern