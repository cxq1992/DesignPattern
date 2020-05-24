#pragma once
#include <cassert>
#include <iostream>
#include <memory>
#include <string>

namespace designpattern {
namespace structual {
class Computer {
 public:
  void GetElectricShock() { std::cout << "Ouch!" << std::endl; }

  void MakeSound() { std::cout << "Beep beep!" << std::endl; }

  void Start() { std::cout << "Starting..." << std::endl; }

  void ShowLoadingScreen() { std::cout << "Loading..." << std::endl; }

  void Ready() { std::cout << "Ready to be used!" << std::endl; }

  void Shutdown() { std::cout << "Shutting down..." << std::endl; }

  void PullCurrent() { std::cout << "Current pulled off" << std::endl; }

  void Sleep() { std::cout << "Zzzz" << std::endl; }
};

class ComputerFacade {
 public:
  explicit ComputerFacade(std::shared_ptr<Computer> computer)
      : _computer(computer) {}
  void Turnon() {
    assert(_computer != nullptr);
    _computer->GetElectricShock();
    _computer->MakeSound();
    _computer->Start();
    _computer->ShowLoadingScreen();
    _computer->Ready();
  }
  void Turnoff() {
    assert(_computer != nullptr);
    _computer->Shutdown();
    _computer->PullCurrent();
  }

 private:
  std::shared_ptr<Computer> _computer;
};

}  // namespace structual
}  // namespace designpattern