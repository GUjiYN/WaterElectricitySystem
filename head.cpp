//--------------这部分放头文件----------------------
#include <mysql.h>
#include <iostream>
using namespace std;

//---------------这部分放源文件------------------------

MYSQL mysql;
MYSQL_RES *res;//这个结构代表返回行的一个查询结果集
MYSQL_ROW column;//一个行数据的类型安全(type-safe)的表示

//连接数据库
bool ConnectMysql() {
    mysql_init(&mysql);//初始化mysql
    if (!(mysql_real_connect(&mysql,
                             "localhost",//主机 如果是远程就改成服务器的ip地址
                             "root",//用户名
                             "CWily031118",//密码
                             "waterelectricity_system",//数据库名 必须是已经存在的 我的mysql大小写不敏感
                             3306,//端口号 默认的0或者3306
                             nullptr, 0//最后两个参数的常用写法 几乎都是这两个
    ))) {
        cout << "Error connecting to database:" + (string) mysql_error(&mysql) << endl;
        return false;
    } else {
        cout << "Connected..." << endl;
        return true;
    }
}

//所有的数据库操作都是先写个sql语句
//然后用mysql_query(&mysql,query)来完成
//包括创建数据库或表 增删改查
bool updateData(string sql){
    mysql_query(&mysql, "set names utf8");//设置编码格式 否则mysql里中文乱码
    // 执行SQL语句
    // 0 执行成功
    // 1 执行失败
    if (mysql_query(&mysql, sql.c_str())) {//mysql_query第二个参数只接受const cahr* 需要将string类型转化
        cout << "Update failed ( " + (string) mysql_error(&mysql) + " )" << endl;
        return false;
    } else {
        cout << "Update success..." << endl;
        return true;
    }
}

//输出结果
void outMysql() {
    //打印数据行数
    cout << "number of dataline returned: " << mysql_affected_rows(&mysql) << endl;

    char *field[32];//字段名

    int num = mysql_num_fields(res);//获取列数
    for (int i = 0; i < num; ++i) {//获取字段名
        field[i] = mysql_fetch_field(res)->name;
    }

    for (int i = 0; i < num; ++i) {
        cout << (string) field[i] << "    ";
    }
    cout << endl;

    while (column = mysql_fetch_row(res)) {//获取一行数据
        for (int i = 0; i < num; ++i) {
            cout << column[i] << "    ";
        }
        cout << endl;
    }
}

//查询并输出
bool QueryDatabase(string sql) {
    mysql_query(&mysql, "set names gbk");//设置编码格式 否则cmd下中文乱码
    // 执行SQL语句
    // 0 执行成功
    // 1 执行失败
    if (mysql_query(&mysql, sql.c_str())) {//mysql_query第二个参数只接受const cahr* 需要将string类型转化
        cout << "Query failed ( " + (string) mysql_error(&mysql) + " )" << endl;
        return false;
    } else {
        cout << "query success" << endl;
    }

    //获得结果集 MYSQL_RES *res;
    if (!(res = mysql_store_result(&mysql))) {
        cout << "Couldn't get result from " + (string) mysql_error(&mysql) << endl;
        return false;
    }
    outMysql();//打印结果
    return true;
}

//释放资源
void FreeConnect() {
    mysql_free_result(res);
    mysql_close(&mysql);
}

bool QueryName(bool type, string name) {
    string queryNameSQL = "SELECT person_id FROM person WHERE name = '" + name + "' LIMIT 1";
    mysql_query(&mysql, "set names gbk");//设置编码格式 否则cmd下中文乱码
    if (mysql_query(&mysql, queryNameSQL.c_str())) {//mysql_query第二个参数只接受const cahr* 需要将string类型转化
        cout << "Query failed ( " + (string) mysql_error(&mysql) + " )" << endl;
    } else {
        MYSQL_RES *result;
        // 获得结果集 MYSQL_RES *result;
        if (!(result = mysql_store_result(&mysql))) {
            cout << "Couldn't get result from " + (string) mysql_error(&mysql) << endl;
            return false;
        }
        // 对获取数据集进行操作获取 person_id
        string getPersonID;
        while (column = mysql_fetch_row(result)) {//获取一行数据
            getPersonID = column[0];
        }

        string querySQL;
        // true 为学生；false 为老师
        if (type) {
            // 对获取值进行数据库查询
            querySQL = "SELECT * FROM student WHERE person_id = '" + getPersonID + "' LIMIT 1";
        } else {
            querySQL = "SELECT * FROM staff WHERE person_id = '" + getPersonID + "' LIMIT 1";
        }
        QueryDatabase(querySQL);
    }
    return true;
}

/**
 *
 */
 // 我百度一下
double GetQueryData(bool type, string name) {
    string queryNameSQL = "SELECT person_id FROM person WHERE name = '" + name + "' LIMIT 1";
    mysql_query(&mysql, "set names gbk");//设置编码格式 否则cmd下中文乱码
    if (!mysql_query(&mysql, queryNameSQL.c_str())) {
        MYSQL_RES *result;
        MYSQL_ROW singleColumn;
        // 获得结果集 MYSQL_RES *result;
        if (!(result = mysql_store_result(&mysql))) {
            cout << "Couldn't get result from " + (string) mysql_error(&mysql) << endl;
            return 0;
        }
        // 对获取数据集进行操作获取 person_id
        string getPersonID;
        while (singleColumn = mysql_fetch_row(result)) {//获取一行数据
            getPersonID = singleColumn[0];
        }

        string querySQL;
        // true 为学生；false 为老师
        if (type) {
            // 对获取值进行数据库查询
            querySQL = "SELECT electricity_usage, water_usage FROM student WHERE person_id = '" + getPersonID + "' LIMIT 1";
        } else {
            querySQL = "SELECT electricity_usage, water_usage FROM staff WHERE person_id = '" + getPersonID + "' LIMIT 1";
        }
        mysql_query(&mysql, "set names gbk");//设置编码格式 否则cmd下中文乱码
        if (!mysql_query(&mysql, querySQL.c_str())) {
            MYSQL_RES *getResult;
            MYSQL_ROW getColumn;
            // 获得结果集 MYSQL_RES *result;
            if (!(getResult = mysql_store_result(&mysql))) {
                cout << "Couldn't get result from " + (string) mysql_error(&mysql) << endl;
                return 0;
            }
            double data[2];
            // 对获取数据集进行操作获取 person_id
            while (getColumn = mysql_fetch_row(getResult)) {//获取一行数据
                for (int i = 0; i < 2; ++i) {
                    data[i] = stod(getColumn[i]);
                }
            }
            double calcTotal;
            // 实现费用的计算(data[0] 电费、data[1] 水费)
            double elecCharge = data[0] > 20 ? (data[0] - 20.0) * 0.5 : 0;
            double waterCharge = data[1] > 30 ? (data[1] - 30.0) * 1.5 : 0;
            calcTotal = elecCharge + waterCharge;
            return calcTotal;
        }
    }
    return 0;
}