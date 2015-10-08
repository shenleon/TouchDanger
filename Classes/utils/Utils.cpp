#include "Utils.h"

USING_NS_CC;

/*��ȡCCString*/
CCString * Utils::getString(const std::string& key)
{
	CCDictionary * strings = CCDictionary::createWithContentsOfFile("strings.xml");
	CCString * str = dynamic_cast<CCString*>(strings->objectForKey(key));
	return str;
}

/*��ȡ�ַ���*/
const char * Utils::getCString(const std::string& key)
{
	CCString * str = Utils::getString(key);
	if (str == NULL) return NULL;
	return str->getCString();
}
