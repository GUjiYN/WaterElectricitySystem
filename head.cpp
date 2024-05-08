//--------------�ⲿ�ַ�ͷ�ļ�----------------------
#include <mysql.h>
#include <iostream>
using namespace std;

//---------------�ⲿ�ַ�Դ�ļ�------------------------

MYSQL mysql;
MYSQL_RES *res;//����ṹ�������е�һ����ѯ�����
MYSQL_ROW column;//һ�������ݵ����Ͱ�ȫ(type-safe)�ı�ʾ

//�������ݿ�
bool ConnectMysql() {
    mysql_init(&mysql);//��ʼ��mysql
    if (!(mysql_real_connect(&mysql,
                             "localhost",//���� �����Զ�̾͸ĳɷ�������ip��ַ
                             "root",//�û���
                             "CWily031118",//����
                             "waterelectricity_system",//���ݿ��� �������Ѿ����ڵ� �ҵ�mysql��Сд������
                             3306,//�˿ں� Ĭ�ϵ�0����3306
                             nullptr, 0//������������ĳ���д�� ��������������
    ))) {
        cout << "Error connecting to database:" + (string) mysql_error(&mysql) << endl;
        return false;
    } else {
        cout << "Connected..." << endl;
        return true;
    }
}

//���е����ݿ����������д��sql���
//Ȼ����mysql_query(&mysql,query)�����
//�����������ݿ��� ��ɾ�Ĳ�
bool updateData(string sql){
    mysql_query(&mysql, "set names utf8");//���ñ����ʽ ����mysql����������
    // ִ��SQL���
    // 0 ִ�гɹ�
    // 1 ִ��ʧ��
    if (mysql_query(&mysql, sql.c_str())) {//mysql_query�ڶ�������ֻ����const cahr* ��Ҫ��string����ת��
        cout << "Update failed ( " + (string) mysql_error(&mysql) + " )" << endl;
        return false;
    } else {
        cout << "Update success..." << endl;
        return true;
    }
}

//������
void outMysql() {
    //��ӡ��������
    cout << "number of dataline returned: " << mysql_affected_rows(&mysql) << endl;

    char *field[32];//�ֶ���

    int num = mysql_num_fields(res);//��ȡ����
    for (int i = 0; i < num; ++i) {//��ȡ�ֶ���
        field[i] = mysql_fetch_field(res)->name;
    }

    for (int i = 0; i < num; ++i) {
        cout << (string) field[i] << "    ";
    }
    cout << endl;

    while (column = mysql_fetch_row(res)) {//��ȡһ������
        for (int i = 0; i < num; ++i) {
            cout << column[i] << "    ";
        }
        cout << endl;
    }
}

//��ѯ�����
bool QueryDatabase(string sql) {
    mysql_query(&mysql, "set names gbk");//���ñ����ʽ ����cmd����������
    // ִ��SQL���
    // 0 ִ�гɹ�
    // 1 ִ��ʧ��
    if (mysql_query(&mysql, sql.c_str())) {//mysql_query�ڶ�������ֻ����const cahr* ��Ҫ��string����ת��
        cout << "Query failed ( " + (string) mysql_error(&mysql) + " )" << endl;
        return false;
    } else {
        cout << "query success" << endl;
    }

    //��ý���� MYSQL_RES *res;
    if (!(res = mysql_store_result(&mysql))) {
        cout << "Couldn't get result from " + (string) mysql_error(&mysql) << endl;
        return false;
    }
    outMysql();//��ӡ���
    return true;
}

//�ͷ���Դ
void FreeConnect() {
    mysql_free_result(res);
    mysql_close(&mysql);
}

bool QueryName(bool type, string name) {
    string queryNameSQL = "SELECT person_id FROM person WHERE name = '" + name + "' LIMIT 1";
    mysql_query(&mysql, "set names gbk");//���ñ����ʽ ����cmd����������
    if (mysql_query(&mysql, queryNameSQL.c_str())) {//mysql_query�ڶ�������ֻ����const cahr* ��Ҫ��string����ת��
        cout << "Query failed ( " + (string) mysql_error(&mysql) + " )" << endl;
    } else {
        MYSQL_RES *result;
        // ��ý���� MYSQL_RES *result;
        if (!(result = mysql_store_result(&mysql))) {
            cout << "Couldn't get result from " + (string) mysql_error(&mysql) << endl;
            return false;
        }
        // �Ի�ȡ���ݼ����в�����ȡ person_id
        string getPersonID;
        while (column = mysql_fetch_row(result)) {//��ȡһ������
            getPersonID = column[0];
        }

        string querySQL;
        // true Ϊѧ����false Ϊ��ʦ
        if (type) {
            // �Ի�ȡֵ�������ݿ��ѯ
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
 // �Ұٶ�һ��
double GetQueryData(bool type, string name) {
    string queryNameSQL = "SELECT person_id FROM person WHERE name = '" + name + "' LIMIT 1";
    mysql_query(&mysql, "set names gbk");//���ñ����ʽ ����cmd����������
    if (!mysql_query(&mysql, queryNameSQL.c_str())) {
        MYSQL_RES *result;
        MYSQL_ROW singleColumn;
        // ��ý���� MYSQL_RES *result;
        if (!(result = mysql_store_result(&mysql))) {
            cout << "Couldn't get result from " + (string) mysql_error(&mysql) << endl;
            return 0;
        }
        // �Ի�ȡ���ݼ����в�����ȡ person_id
        string getPersonID;
        while (singleColumn = mysql_fetch_row(result)) {//��ȡһ������
            getPersonID = singleColumn[0];
        }

        string querySQL;
        // true Ϊѧ����false Ϊ��ʦ
        if (type) {
            // �Ի�ȡֵ�������ݿ��ѯ
            querySQL = "SELECT electricity_usage, water_usage FROM student WHERE person_id = '" + getPersonID + "' LIMIT 1";
        } else {
            querySQL = "SELECT electricity_usage, water_usage FROM staff WHERE person_id = '" + getPersonID + "' LIMIT 1";
        }
        mysql_query(&mysql, "set names gbk");//���ñ����ʽ ����cmd����������
        if (!mysql_query(&mysql, querySQL.c_str())) {
            MYSQL_RES *getResult;
            MYSQL_ROW getColumn;
            // ��ý���� MYSQL_RES *result;
            if (!(getResult = mysql_store_result(&mysql))) {
                cout << "Couldn't get result from " + (string) mysql_error(&mysql) << endl;
                return 0;
            }
            double data[2];
            // �Ի�ȡ���ݼ����в�����ȡ person_id
            while (getColumn = mysql_fetch_row(getResult)) {//��ȡһ������
                for (int i = 0; i < 2; ++i) {
                    data[i] = stod(getColumn[i]);
                }
            }
            double calcTotal;
            // ʵ�ַ��õļ���(data[0] ��ѡ�data[1] ˮ��)
            double elecCharge = data[0] > 20 ? (data[0] - 20.0) * 0.5 : 0;
            double waterCharge = data[1] > 30 ? (data[1] - 30.0) * 1.5 : 0;
            calcTotal = elecCharge + waterCharge;
            return calcTotal;
        }
    }
    return 0;
}