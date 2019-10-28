#include <iostream>
#include "builder.h"

Burger::Burger(BurgerBuilder& builder) : _size(builder._size), _cheese(builder._cheese), _pepperoni(builder._pepperoni), _tomato(builder._tomato), _lettuce(builder._lettuce)
{
}
void Burger::Flavor()
{
	std::cout << _size << " sized, ";
	if (_cheese)
	{
		std::cout << " chessed,";
	}
	if (_pepperoni)
	{
		std::cout << " pepperoni flavored,";
	}
	if (_tomato)
	{
		std::cout << " plus tomato,";
	}
	if (_lettuce)
	{
		std::cout << " if having lettuce";
	}
	std::cout << " burger" << std::endl;
}


BurgerBuilder::BurgerBuilder(size_t size) :_size(size) {}

BurgerBuilder& BurgerBuilder::AddCheese()
{
	_cheese = true;
	return *this;
}

BurgerBuilder& BurgerBuilder::AddPepperoni()
{
	_pepperoni = true;
	return *this;
}

BurgerBuilder& BurgerBuilder::AddTomato()
{
	_tomato = true;
	return *this;
}

BurgerBuilder& BurgerBuilder::AddLettuce()
{
	_lettuce = true;
	return *this;
}

Burger BurgerBuilder::Build() {
	return std::move(Burger(*this));
}

int main()
{
	BurgerBuilder(16).AddPepperoni().AddTomato().AddLettuce().Build().Flavor();
}