#ifndef __MAIN_RESOURCE_DELEGATE_
#define __MAIN_RESOURCE_DELEGATE_

class MainResourceDelegate
{
public:
	virtual void incrLife(int val) = 0;
	virtual void decrLife(int val) = 0;
	virtual void incrMoney(int val) = 0;
	virtual void decrMoney(int val) = 0;
};

#endif