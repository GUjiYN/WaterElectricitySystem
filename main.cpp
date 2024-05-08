#include "function.cpp"

//测试代码
int main() {
    ConnectMysql();
    cout << ">> 无锡学院水电费管理系统 <<" << endl;
    while (true) {
        cout << "========================" << endl;
        cout << "1. 信息查询" << endl;
        cout << "2. 信息录入" << endl;
        cout << "3. 信息删除" << endl;
        cout << "4. 信息修改" << endl;
        cout << "5. 查询费用" << endl;
        cout << "6. 退出系统" << endl;
        cout << "========================" << endl;
        // 输入数据
        int a;
        cout << "请输入选项: ";
        std::cin >> a;

        switch (a) {
            case 1:
                int search;
                std::cout << "请选择查询类型（1.学生  2.老师）：" << std::endl;
                std::cin >> search;
                switch (search) {
                    case 1:
                        std::cout <<
                                  "1. 请选择查询方式：(1.按照姓名查询；2. 按照用水量查询；3. 按照用电量查询)"
                                  << std::endl;
                        int way1;
                        std::cin >> way1;
                        if (way1 == 1) {
                            std::cout << "请输入姓名：" << std::endl;
                            std::string name;
                            std::cin >> name;
                            QueryName(true, name);
                        } else if (way1 == 2) {
                            std::cout << "请输入最小用水量" << std::endl;
                            std::string min_electricity_usage;
                            std::cin >> min_electricity_usage;
                            std::cout << "请输入最大用水量" << std::endl;
                            std::string max_electricity_usage;
                            std::cin >> max_electricity_usage;
                            std::string sql_query =
                                    "select * from student where electricity_usage <  " + max_electricity_usage +
                                    " AND electricity_usage > " + min_electricity_usage;
                            QueryDatabase(sql_query);
                        } else if (way1 == 3) {
                            std::cout << "请输入最小用电量" << std::endl;
                            std::string min_water_usage;
                            std::cin >> min_water_usage;
                            std::cout << "请输入最大用电量" << std::endl;
                            std::string max_water_usage;
                            std::cin >> max_water_usage;
                            std::string sql_query =
                                    "select * from student where water_usage < " + max_water_usage +
                                    " AND water_usage > " + min_water_usage;
                            QueryDatabase(sql_query);
                        }
                        break;
                    case 2:
                        std::cout <<
                                  "1. 请选择查询方式：(1.按照姓名查询；2. 按照用水量查询；3. 按照用电量查询)"
                                  << std::endl;
                        int way2;
                        std::cin >> way2;
                        if (way2 == 1) {
                            std::cout << "请输入姓名：" << std::endl;
                            std::string name;
                            std::cin >> name;
                            QueryName(false, name);
                        } else if (way2 == 2) {
                            std::cout << "请输入最小用水量" << std::endl;
                            std::string min_electricity_usage;
                            std::cin >> min_electricity_usage;
                            std::cout << "请输入最大用水量" << std::endl;
                            std::string max_electricity_usage;
                            std::cin >> max_electricity_usage;
                            std::string sql_query =
                                    "select * from person where electricity_usage <  " + max_electricity_usage +
                                    " AND electricity_usage > " + min_electricity_usage;
                            QueryDatabase(sql_query);
                        } else if (way2 == 3) {
                            std::cout << "请输入最小用电量" << std::endl;
                            std::string min_water_usage;
                            std::cin >> min_water_usage;
                            std::cout << "请输入最大用电量" << std::endl;
                            std::string max_water_usage;
                            std::cin >> max_water_usage;
                            std::string sql_query =
                                    "select * from person where water_usage < " + max_water_usage +
                                    " AND water_usage > " + min_water_usage;
                            QueryDatabase(sql_query);
                        }
                        break;
                }
                break;
            case 2:
                int add;
                std::cout << "请选择新增的类型（1. 学生  2. 教师）：" << std::endl;
                std::cin >> add;
                switch (add) {
                    case 1:
                        func::addStudent();
                        break;
                    case 2:
                        func::addTeacher();
                        break;
                    default:
                        std::cout << "无效的选择" << std::endl;
                }
                break;
            case 3:
                std::cout << "请输入删除id：" << std::endl;
                while (true) {
                    std::string person_id;
                    std::cin >> person_id;
                    std::string sql_query = "delete from person where person_id = " + person_id;
                    updateData(sql_query);
                    break;
                }
                break;
            case 4:
                int edit;
                std::cout << "请选择修改的类型（1. 学生  2. 教师）：" << std::endl;
                std::cin >> edit;
                switch (edit) {
                    case 1:
                        func::editStudent();
                        break;
                    case 2:
                        func::editTeacher();
                        break;
                    default:
                        std::cout << "无效的选择：" << std::endl;
                }
                break;
            case 5:
                int calcType;
                while (true) {
                    double getData;
                    std::cout << "请选择查询的类型（1. 学生  2. 教师）：" << std::endl;
                    std::cin >> calcType;
                    string insertName;
                    std::cout << "请输入姓名：" << std::endl;
                    std::cin >> insertName;
                    if (calcType -1) {
                        getData = GetQueryData(false, insertName);
                    } else {
                        getData = GetQueryData(true, insertName);
                    }
                    std::cout << "学生 " << insertName << " 的总费用为 " << getData << " 元" << endl;
                    break;
                }
                break;
            case 6:
                std::cout << "退出程序" << std::endl;
                FreeConnect();
                return 0;
            default:
                std::cout << "请重新选择" << std::endl;
        }
    }
}


