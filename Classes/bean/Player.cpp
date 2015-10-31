#include "Player.h"

USING_NS_CC;

/** 角色信息静态引用  */
static Player * p_mPlayer;
int loadPlayer(void * para,int n_column,char ** column_value,char ** column_name);
int loadCount(void * para,int n_column,char ** column_value,char ** column_name);

/*获取静态玩家对象*/
Player * Player::instance()
{
	if(p_mPlayer==NULL)
	{
		p_mPlayer = new Player();
		p_mPlayer->init();
	}
	return p_mPlayer;
}

/*初始化玩家数据*/
void Player::init()
{
	this->setName("小明");
	this->setUid("10001");
	this->loadData();//加载本地数据
	CCPoolManager::sharedPoolManager()->push();
}

Player::Player(){}

Player::~Player()
{
	this->saveData();
	CCPoolManager::sharedPoolManager()->pop();
	CCPoolManager::purgePoolManager();
	p_mPlayer = NULL;
}

/*准备数据库 */
sqlite3 * Player::prepareDb()
{
	sqlite3 * pDb = NULL;
	char * errorMsg = NULL;
	if(SQLITE_OK != sqlite3_open("my.db",&pDb))
	{
		CCLOG("open sql file failed!");
		return NULL;
	}
	std::string sql = "create table if not exists player (uid char(80) primary key,name char(80),money integer,experience integer)";
	sqlite3_exec(pDb,sql.c_str(),NULL,NULL,&errorMsg);
	if(errorMsg!=NULL)
	{
		CCLOG("exec sql %s fail with msg:%s",sql.c_str(),errorMsg);
		sqlite3_close(pDb);
		return NULL;
	}
	return pDb;
}

/*加载本地数据*/
void Player::loadData()
{
	char sql[1024];
	sqlite3 * pDb = this->prepareDb();
	if(pDb==NULL) return;
	int count = 0;
	char * errorMsg;
	sprintf(sql,"select * from player where uid = %s",this->getUid());
	sqlite3_exec(pDb,sql,loadPlayer,this,&errorMsg);
	if(errorMsg!=NULL)
	{
		CCLOG("exec sql %s fail with msg: %s ",sql,errorMsg);
		sqlite3_close(pDb);
		return;
	}
	sqlite3_close(pDb);
}

int loadPlayer(void * para,int n_column,char ** column_value,char ** column_name)
{
	Player * player = (Player*)para;
	CCLOG("n_column = %d,column_value=%s,%s,%s,%s",n_column,column_value[0],column_value[1],column_value[2],column_value[3]);
	int exp =0 , money =0;
	sscanf(column_value[2],"%d",&money);
	sscanf(column_value[3],"%d",&exp);
	if(exp<0) exp = 0;
	if(money<0) money = 0;
	player->setExperience(exp);
	player->setMoney(money);
	return 0;
}

int loadCount(void * para,int n_column,char ** column_value,char ** column_name)
{
	int * pCount = (int *)para;
	sscanf(column_value[0],"%d%",pCount);
	CCLOG("pCount=%d",*pCount);
	return 0;
}


/*存储本地数据*/
void Player::saveData()
{
	char sql[1024];
	sqlite3 * pDb = this->prepareDb();
	if(pDb==NULL) return;
	int count = 0;
	char * errorMsg;

	sprintf(sql,"select count(*) from player where uid = %s",this->getUid());
	sqlite3_exec(pDb,sql,loadCount,&count,&errorMsg);
	if(errorMsg!=NULL)
	{
		CCLOG("exec sql %s fail with msg : %s",sql,errorMsg);
		sqlite3_close(pDb);
		return;
	}
	if(count)
	{
		sprintf(sql,"update player set experience=%d,money=%d where uid=%s",this->getExperience(),this->getMoney(),this->getUid());
	}else
	{
		sprintf(sql,"insert into player(uid,experience,money) values(%s,%d,%d)",this->getUid(),this->getExperience(),this->getMoney());
	}
	CCLOG("sql:%s",sql);
	sqlite3_exec(pDb,sql,NULL,NULL,&errorMsg);
	if(errorMsg!=NULL)
	{
		CCLOG("exec sql %s fail with msg : %s",sql,errorMsg);
		sqlite3_close(pDb);
		return;
	}
	sqlite3_close(pDb);
}

