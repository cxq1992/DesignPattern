/*
In plain words:
	It provides a way to delegate the instantiation logic to child classes.

Wikipedia says:
	In class-based programming, the factory method pattern is a creational pattern
that uses factory methods to deal with the problem of creating objects without
having to specify the exact class of the object that will be created. This is
done by creating objects by calling a factory method¡ªeither specified in an
interface and implemented by child classes, or implemented in a base class and
optionally overridden by derived classes¡ªrather than by calling a constructor.
*/

#include <iostream>
#include <memory>

class Interviewer {
public:
	virtual ~Interviewer() = default;

	virtual void AskQuestions() = 0;
};

class Developer : public Interviewer {
public:
	virtual ~Developer() = default;

	virtual void AskQuestions() {
		std::cout << "Asking about design patterns!" << std::endl;
	}
};

class CommunityExecutive : public Interviewer {
public:
	virtual ~CommunityExecutive() = default;

	virtual void AskQuestions() {
		std::cout << "Asking about community building!" << std::endl;
	}
};

class HiringManager {
public:
	virtual ~HiringManager() = default;

	virtual void TakeInterview() {
		MakeInterviewer()->AskQuestions();
	}

protected:
	// factory method
	virtual std::shared_ptr<Interviewer> MakeInterviewer() = 0;
};

class DevelopmentManager : public HiringManager {
public:
	virtual ~DevelopmentManager() = default;
	
protected:
	virtual std::shared_ptr<Interviewer> MakeInterviewer()
	{
		return std::shared_ptr<Interviewer>(new Developer());
	}
};

class MarketingManager : public HiringManager {
public:
	virtual ~MarketingManager() = default;

protected:
	virtual std::shared_ptr<Interviewer> MakeInterviewer()
	{
		return std::shared_ptr<Interviewer>(new CommunityExecutive());
	}
};

int main()
{
	DevelopmentManager development_manager;
	development_manager.TakeInterview();

	MarketingManager marketing_manager;
	marketing_manager.TakeInterview();
}