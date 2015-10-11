#ifndef __MAIN_RESOURCE_DELEGATE_
#define __MAIN_RESOURCE_DELEGATE_

class MainResourceDelegate
{
public:
	virtual void incrExperience(const int val) = 0;
	virtual void decrExperience(const int val) = 0;
	virtual void incrMoney(const int val) = 0;
	virtual void decrMoney(const int val) = 0;
};

#endif