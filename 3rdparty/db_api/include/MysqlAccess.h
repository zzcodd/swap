/*
 * MySQL访问接口
 *
 * Copyright (C) 2016 NUDT
 */
#ifndef __DB_ACCESS_MYSQL_API_H
#define __DB_ACCESS_MYSQL_API_H
#include <mysql/mysql.h>
#include <string>
#include <vector>

/// 宏定义
#define MYSQL_HOST 	"localhost"
#define MYSQL_USER_NAME "test"
#define MYSQL_PASSWORD  "test"
#define MYSQL_DB_NAME 	"test_server"
#define MYSQL_SERVER_PORT (3306)

/// 枚举定义

/// 结构定义

using namespace std;


/*
 * MySQL访问接口
 */
class MysqlAccess
{
  public:
    /* 构造函数 */
    MysqlAccess(void);
    /* 析构函数 */
    ~MysqlAccess(void);

    /**
     * @brief   取得类对象的指针
     *
     * @param   无
     *
     * @retval  类对象指针
     */
    static MysqlAccess* Instance(void);

    /**
     * @brief   释放掉类对象的指针指向的对象
     *
     * @param   无
     *
     * @retval  无
     */
    static void ReleaseInstance(void);

    void Configure(char *host, int port, char *name, char *pass, char *db);

    int OpenConnect(void);

    int InsertSQL(char const *p_sql, char *p_error);

    int DeleteSQL(char const *p_sql, char *p_error);

    int UpdateSQL(char const *p_sql, char *p_error);

    int QuerySQL(char const *p_sql, vector<vector<string> > &data,
        char *p_error);

    int SelectDB(char *db);

    int RevertDB(void);

    long GetLastInsertID();

    void CloseConnect(void);

  private:
    static MysqlAccess *p_instance;
    MYSQL *p_mysqlInstance;

    int m_iOPNum;

    char host[128];
    int port;
    char username[32];
    char password[32];
    char db_name[32];

    int ExecuteSQL(char const *p_sql, char *p_error);

    int ExecuteSQL(char const *p_sql, vector<vector<string> > &data,
        char *p_error);

    time_t last_tick;
    bool is_running;

    void* Loop(void *param);
};

#endif /* __DB_ACCESS_MYSQL_API_H */
