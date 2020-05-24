#pragma once
#include <iostream>
#include <memory>
#include <string>

class Coffee {
 public:
  virtual float GetCost() = 0;
  virtual std::string GetDescription() = 0;
};

class SimpleCoffee : public Coffee {
 public:
  float GetCost() override { return 10; }

  std::string GetDescription() override { return "Simple Coffee"; }
};

class MilkCoffee : public Coffee {
 public:
  explicit MilkCoffee(const std::shared_ptr<Coffee> coffee) : _coffee(coffee) {}

  float GetCost() override { return _coffee->GetCost() + 2; }

  std::string GetDescription() override {
    return _coffee->GetDescription() + " plus milk";
  }

 private:
  std::shared_ptr<Coffee> _coffee;
};

class VanillaCoffee : public Coffee {
 public:
  explicit VanillaCoffee(const std::shared_ptr<Coffee> coffee)
      : _coffee(coffee) {}

  float GetCost() override { return _coffee->GetCost() + 3; }

  std::string GetDescription() override {
    return _coffee->GetDescription() + " plus vanilla";
  }

 private:
  std::shared_ptr<Coffee> _coffee;
};

class WhipCoffee : public Coffee {
 public:
  explicit WhipCoffee(const std::shared_ptr<Coffee> coffee) : _coffee(coffee) {}

  float GetCost() override { return _coffee->GetCost() + 4; }

  std::string GetDescription() override {
    return _coffee->GetDescription() + " plus whip";
  }

 private:
  std::shared_ptr<Coffee> _coffee;
};