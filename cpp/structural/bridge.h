#ifndef BRIDGE_H
#define BRIDGE_H
#include <iostream>
#include <memory>

namespace designpattern {
namespace structual {
class Theme {
 public:
  virtual void SetColor(const std::string&) = 0;
  virtual std::string GetColor() = 0;
};

class DarkTheme : public Theme {
 public:
  void SetColor(const std::string& color) override { _color = color; };
  std::string GetColor() override { return _color; }

 private:
  std::string _color = "red";
};

class WebPage {
 public:
  virtual void SetTheme(std::shared_ptr<Theme> theme) = 0;
  virtual void GetContent() = 0;
};

class About : public WebPage {
 public:
  void SetTheme(std::shared_ptr<Theme> theme) override { _theme = theme; }
  void GetContent() override {
    std::cout << "About Page, Color: " << _theme->GetColor() << std::endl;
  }

 private:
  std::shared_ptr<Theme> _theme;
};

}  // namespace structual
}  // namespace designpattern
#endif  // BRIDGE_H
