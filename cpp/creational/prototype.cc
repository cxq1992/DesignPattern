#include <string>

namespace design_patern {
namespace creational {
class Sheep{
public:
    Sheep(const std::string & name = "Dolly", const std::string& type = "Mountain Sheep")
        : _name(name), _type(type)
    {}
    void SetName(const std::string &name)
    {
        _name = name;
    }
    void SetType(const std::string & type)
    {
        _type = type;
    }
    const std::string & GetName() const
    {
        return _name;
    }
    const std::string & GetType() const
    {
        return _type;
    }
    Sheep Clone()
    {
        return Sheep(_name, _type);
    }
private:
    std::string _name;
    std::string _type;
};
}
}
