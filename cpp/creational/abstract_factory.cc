/*
Real world example:
	Extending our door example from Simple Factory. Based on your needs you might get 
a wooden door from a wooden door shop, iron door from an iron shop or a PVC door from 
the relevant shop. Plus you might need a guy with different kind of specialities to fit
the door, for example a carpenter for wooden door, welder for iron door etc. As you can 
see there is a dependency between the doors now, wooden door needs carpenter, iron door 
needs a welder etc.

In plain words:
	A factory of factories; a factory that groups the individual but related/dependent 
factories together without specifying their concrete classes.

Wikipedia says:
	The abstract factory pattern provides a way to encapsulate a group of individual 
factories that have a common theme without specifying their concrete classes
*/

#include <iostream>
#include <memory>

class Door {
public:	
	virtual ~Door() = default;

	virtual void GetDescription() = 0;
};

class WoodenDoor : public Door {
public:
	virtual ~WoodenDoor() = default;

	virtual void GetDescription()
	{
		std::cout << "It's a wooden door." << std::endl;
	}
};

class IronDoor : public Door {
public:
	virtual ~IronDoor() = default;

	virtual void GetDescription()
	{
		std::cout << "It's a iron door." << std::endl;
	}
};

class DoorFittingExpert {
public:
	virtual ~DoorFittingExpert() = default;

	virtual void GetDescription() = 0;
};

class Carpenter : public DoorFittingExpert {
public:
	virtual ~Carpenter() = default;

	virtual void GetDescription()
	{
		std::cout << "I'm a carpenter." << std::endl;
	}
};

class Welder : public DoorFittingExpert {
public:
	virtual ~Welder() = default;

	virtual void GetDescription()
	{
		std::cout << "I'm a welder." << std::endl;
	}
};

class DoorFactory {
public:
	virtual ~DoorFactory() = default;
	
	virtual std::shared_ptr<Door> MakeDoor() = 0;

	virtual std::shared_ptr<DoorFittingExpert> MakeFittingExpert() = 0;
};

class WoodenDoorFactory : public DoorFactory {
public:
	virtual ~WoodenDoorFactory() = default;

	virtual std::shared_ptr<Door> MakeDoor()
	{
		return std::shared_ptr<Door>(new WoodenDoor());
	}

	virtual std::shared_ptr<DoorFittingExpert> MakeFittingExpert()
	{
		return std::shared_ptr<DoorFittingExpert>(new Carpenter());
	}
};

class IronDoorFactory : public DoorFactory {
public:
	virtual ~IronDoorFactory() = default;

	virtual std::shared_ptr<Door> MakeDoor()
	{
		return std::shared_ptr<Door>(new IronDoor());
	}

	virtual std::shared_ptr<DoorFittingExpert> MakeFittingExpert()
	{
		return std::shared_ptr<DoorFittingExpert>(new Welder());
	}
};

void Test(std::shared_ptr<DoorFactory> door_factory)
{
	std::shared_ptr<Door> door = door_factory->MakeDoor();
	std::shared_ptr<DoorFittingExpert> expert = door_factory->MakeFittingExpert();
	door->GetDescription();
	expert->GetDescription();
}

int main()
{
	Test(std::shared_ptr<DoorFactory>(new WoodenDoorFactory()));
	Test(std::shared_ptr<DoorFactory>(new IronDoorFactory()));
}
