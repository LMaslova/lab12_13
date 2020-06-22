#pragma once

#include <iostream>

void behavioralPatern1();

class AbstractRoleStrategy
{
public:

	virtual void showRights() = 0;
};

class SellerRole
{
public:
	SellerRole();
	void showRightsStrategy();
	void setNewStrategy(AbstractRoleStrategy* strategy);

private:
	std::unique_ptr<AbstractRoleStrategy> mStrategy;
};

class DefaultRoleStrategy : public AbstractRoleStrategy
{
public:

	void showRights() override;
};

class UserRoleStrategy : public AbstractRoleStrategy
{
public:

	void showRights() override;
};

class SellerRoleStrategy : public AbstractRoleStrategy
{
public:

	void showRights() override;
};

class AdminRoleStrategy : public AbstractRoleStrategy
{
public:

	void showRights() override;
};

