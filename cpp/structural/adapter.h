#ifndef ADAPTER_H
#define ADAPTER_H
#include <iostream>

namespace designpattern {
namespace structual {
class Lion {
 public:
  virtual void Roar() = 0;
};

class AfricaLion : public Lion {
 public:
  void Roar() override { std::cout << "Africa lion roaring..." << std::endl; };
};

class AsiaLion : public Lion {
 public:
  void Roar() override { std::cout << "Asia lion roaring..." << std::endl; }
};

class Hunter {
 public:
  void Hunt(Lion& lion) { lion.Roar(); }
};

class WildDog {
 public:
  void Bark() { std::cout << "WildDog barking..." << std::endl; }
};

class WildDogAdapter : public Lion {
 public:
  WildDogAdapter(WildDog& wild_dog) : _wild_dog(wild_dog) {}
  void Roar() override { _wild_dog.Bark(); }

 private:
  WildDog _wild_dog;
};

}  // namespace structual
}  // namespace designpattern
#endif  // ADAPTER_H
