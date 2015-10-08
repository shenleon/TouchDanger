#include "Utils.h"

USING_NS_CC;

/*获取CCString*/
CCString * Utils::getString(const std::string& key)
{
	CCDictionary * strings = CCDictionary::createWithContentsOfFile("strings.xml");
	CCString * str = dynamic_cast<CCString*>(strings->objectForKey(key));
	return str;
}

/*获取字符串*/
const char * Utils::getCString(const std::string& key)
{
	CCString * str = Utils::getString(key);
	if (str == NULL) return NULL;
	return str->getCString();
}
