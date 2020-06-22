#include "lab12.h"
using namespace std;

void behavioralPatern1()
{
	SellerRole seller;
	seller.showRightsStrategy();

	seller.setNewStrategy(new UserRoleStrategy);
	seller.showRightsStrategy();

	seller.setNewStrategy(new SellerRoleStrategy);
	seller.showRightsStrategy();

	seller.setNewStrategy(new AdminRoleStrategy);
	seller.showRightsStrategy();
}

SellerRole::SellerRole():
	mStrategy(new DefaultRoleStrategy)
{
}

void SellerRole::showRightsStrategy()
{
	mStrategy->showRights();
}

void SellerRole::setNewStrategy(AbstractRoleStrategy* strategy)
{
	mStrategy.reset(strategy);
}

void UserRoleStrategy::showRights()
{
	cout << "User: book and buy tickets" << endl;
}

void SellerRoleStrategy::showRights()
{
	cout << "Seller: add/delete tickets" << endl;
}

void AdminRoleStrategy::showRights()
{
	cout << "Admin: add/delete tickets, create new sellers" << endl;
}

void DefaultRoleStrategy::showRights()
{
	cout << "Default strategy" << endl;
}
