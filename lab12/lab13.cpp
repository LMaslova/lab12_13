#include "lab13.h"
using namespace std;

int Observer::static_number_ = 0;

void Subject::Attach(IObserver * observer)
{
	list_observer_.push_back(observer);
}

void Subject::Detach(IObserver * observer)
{
	list_observer_.remove(observer);
}


void Subject::NewMessage(string message)
{
	this->message_ = message;

}

void Subject::SomeBusinessLogic()
{
	this->message_ = "some message";
	cout << "I'm some massage\n";
}

Observer::Observer(Subject & subject)
	: subject_(subject) {
	this->subject_.Attach(this);
	cout << "Observer \"" << ++Observer::static_number_ << "\".\n";
	this->number_ = Observer::static_number_;
}

void Observer::Print()
{
	cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";
}

void Observer::Update(const string & message_from_subject)
{
	message_from_subject_ = message_from_subject;
	Print();
}

void Observer::Remove()
{
	subject_.Detach(this);
	cout << "Observer \"" << number_ << "\" deleted.\n";
}



void behavioralPatern2()
{
	Subject *subject = new Subject;
	Observer *observer1 = new Observer(*subject);
	Observer *observer2 = new Observer(*subject);
	Observer *observer3;

	subject->NewMessage("new tickets");
	observer2->Remove();

	subject->NewMessage("ticket reservation expired ");
	observer3 = new Observer(*subject);

	observer1->Remove();

	delete observer1;
	delete observer2;
	delete observer3;
	delete subject;
}
