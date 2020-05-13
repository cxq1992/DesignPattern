#ifndef SINGLETON_TEMPLATE_H
#define SINGLETON_TEMPLATE_H
namespace design_pattern {
namespace creational {
template <typename Derived>
class Singleton{
public:
    static Derived & GetInstance()
    {
        static Derived instance;
        return instance;
    }
private:
    Singleton() = default;
    Singleton(const Singleton &) = delete;
    Singleton(Singleton &&) = delete;
    Singleton & operator=(const Singleton&) = delete;
    Singleton & operator=(Singleton&&) = delete;
};
}
}
#endif // SINGLETON_TEMPLATE_H
