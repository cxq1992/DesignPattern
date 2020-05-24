/*
Real world example

Imagine you are at Hardee's and you order a specific deal, lets say, "Big
Hardee" and they hand it over to you without any questions; this is the example
of simple factory. But there are cases when the creation logic might involve
more steps. For example you want a customized Subway deal, you have several
options in how your burger is made e.g what bread do you want? what types of
sauces would you like? What cheese would you want? etc. In such cases builder
pattern comes to the rescue.

In plain words

Allows you to create different flavors of an object while avoiding constructor
pollution. Useful when there could be several flavors of an object. Or when
there are a lot of steps involved in creation of an object.

Wikipedia says

The builder pattern is an object creation software design pattern with the
intentions of finding a solution to the telescoping constructor anti-pattern.
*/

/*telescoping anti-pattern(NEVER DO THIS!), parameters keep going on if you want
 * to add more options in future*/
#include <iostream>

class AntiPatternBurger {
 public:
  AntiPatternBurger(size_t size, bool cheese = true, bool pepperoni = true,
                    bool tomato = true, bool lettuce = true) {}
};

/*The sane alternative*/
class BurgerBuilder;
class Burger {
 public:
  Burger(BurgerBuilder& builder);
  void Flavor();

 private:
  size_t _size;
  bool _cheese;
  bool _pepperoni;
  bool _tomato;
  bool _lettuce;
};

class BurgerBuilder {
 public:
  size_t _size;
  bool _cheese = false;
  bool _pepperoni = false;
  bool _tomato = false;
  bool _lettuce = false;

  BurgerBuilder(size_t size);

  BurgerBuilder& AddCheese();

  BurgerBuilder& AddPepperoni();

  BurgerBuilder& AddTomato();

  BurgerBuilder& AddLettuce();

  Burger Build();
};
