/*
In plain words:
    Simple factory simply generates an instance for client without exposing any
instantiation logic to the client

Wikipedia says:
    In object-oriented programming (OOP), a factory is an object for creating
other objects – formally a factory is a function or method that returns objects
of a varying prototype or class from some method call, which is assumed to be
"new".
*/

#include <iostream>
#include <memory>
#include <stdio.h>

class Door {
public:
  virtual ~Door() = default;
  virtual float GetWidth() = 0;
  virtual float GetHeight() = 0;
};

class WoodenDoor : public Door {
public:
  WoodenDoor(int width, int height) : _width(width), _height(height) {}
  virtual ~WoodenDoor() = default;
  virtual float GetWidth() { return _width; }
  virtual float GetHeight() { return _height; }

private:
  float _width;
  float _height;
};

class DoorFactory {
public:
  static std::shared_ptr<Door> MakeDoor(int width, int height) {
    return std::shared_ptr<Door>(new WoodenDoor(width, height));
  }
};

int main() {
  auto door = DoorFactory::MakeDoor(100, 200);
  std::cout << "door width:" << door->GetWidth() << std::endl;
  std::cout << "door height:" << door->GetHeight() << std::endl;
  return 0;
}