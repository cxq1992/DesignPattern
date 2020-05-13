#ifndef SINGLETON_H
#define SINGLETON_H
namespace design_pattern {
namespace creational {
class President
{
public:
    static President& CreatePresident()
    {
        static President president = President();
        return president;
    }
private:
    President() = default;
    President(const President &) = delete;
    President(President &&) = delete;
    President & operator=(const President&) = delete;
    President & operator=(President&&) = delete;

};
}
}
#endif // SINGLETON_H
