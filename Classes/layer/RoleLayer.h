#ifndef __ROLE_LAYER_
#define __ROLE_LAYER_

#include "AlertLayer.h"

/*��ɫ��Ϣ��*/
class RoleLayer : public AlertLayer
{
public:
	virtual bool init();
	CREATE_FUNC(RoleLayer);
};

#endif
