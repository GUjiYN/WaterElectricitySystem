#include "function.cpp"

//���Դ���
int main() {
    ConnectMysql();
    cout << ">> ����ѧԺˮ��ѹ���ϵͳ <<" << endl;
    while (true) {
        cout << "========================" << endl;
        cout << "1. ��Ϣ��ѯ" << endl;
        cout << "2. ��Ϣ¼��" << endl;
        cout << "3. ��Ϣɾ��" << endl;
        cout << "4. ��Ϣ�޸�" << endl;
        cout << "5. ��ѯ����" << endl;
        cout << "6. �˳�ϵͳ" << endl;
        cout << "========================" << endl;
        // ��������
        int a;
        cout << "������ѡ��: ";
        std::cin >> a;

        switch (a) {
            case 1:
                int search;
                std::cout << "��ѡ���ѯ���ͣ�1.ѧ��  2.��ʦ����" << std::endl;
                std::cin >> search;
                switch (search) {
                    case 1:
                        std::cout <<
                                  "1. ��ѡ���ѯ��ʽ��(1.����������ѯ��2. ������ˮ����ѯ��3. �����õ�����ѯ)"
                                  << std::endl;
                        int way1;
                        std::cin >> way1;
                        if (way1 == 1) {
                            std::cout << "������������" << std::endl;
                            std::string name;
                            std::cin >> name;
                            QueryName(true, name);
                        } else if (way1 == 2) {
                            std::cout << "��������С��ˮ��" << std::endl;
                            std::string min_electricity_usage;
                            std::cin >> min_electricity_usage;
                            std::cout << "�����������ˮ��" << std::endl;
                            std::string max_electricity_usage;
                            std::cin >> max_electricity_usage;
                            std::string sql_query =
                                    "select * from student where electricity_usage <  " + max_electricity_usage +
                                    " AND electricity_usage > " + min_electricity_usage;
                            QueryDatabase(sql_query);
                        } else if (way1 == 3) {
                            std::cout << "��������С�õ���" << std::endl;
                            std::string min_water_usage;
                            std::cin >> min_water_usage;
                            std::cout << "����������õ���" << std::endl;
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
                                  "1. ��ѡ���ѯ��ʽ��(1.����������ѯ��2. ������ˮ����ѯ��3. �����õ�����ѯ)"
                                  << std::endl;
                        int way2;
                        std::cin >> way2;
                        if (way2 == 1) {
                            std::cout << "������������" << std::endl;
                            std::string name;
                            std::cin >> name;
                            QueryName(false, name);
                        } else if (way2 == 2) {
                            std::cout << "��������С��ˮ��" << std::endl;
                            std::string min_electricity_usage;
                            std::cin >> min_electricity_usage;
                            std::cout << "�����������ˮ��" << std::endl;
                            std::string max_electricity_usage;
                            std::cin >> max_electricity_usage;
                            std::string sql_query =
                                    "select * from person where electricity_usage <  " + max_electricity_usage +
                                    " AND electricity_usage > " + min_electricity_usage;
                            QueryDatabase(sql_query);
                        } else if (way2 == 3) {
                            std::cout << "��������С�õ���" << std::endl;
                            std::string min_water_usage;
                            std::cin >> min_water_usage;
                            std::cout << "����������õ���" << std::endl;
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
                std::cout << "��ѡ�����������ͣ�1. ѧ��  2. ��ʦ����" << std::endl;
                std::cin >> add;
                switch (add) {
                    case 1:
                        func::addStudent();
                        break;
                    case 2:
                        func::addTeacher();
                        break;
                    default:
                        std::cout << "��Ч��ѡ��" << std::endl;
                }
                break;
            case 3:
                std::cout << "������ɾ��id��" << std::endl;
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
                std::cout << "��ѡ���޸ĵ����ͣ�1. ѧ��  2. ��ʦ����" << std::endl;
                std::cin >> edit;
                switch (edit) {
                    case 1:
                        func::editStudent();
                        break;
                    case 2:
                        func::editTeacher();
                        break;
                    default:
                        std::cout << "��Ч��ѡ��" << std::endl;
                }
                break;
            case 5:
                int calcType;
                while (true) {
                    double getData;
                    std::cout << "��ѡ���ѯ�����ͣ�1. ѧ��  2. ��ʦ����" << std::endl;
                    std::cin >> calcType;
                    string insertName;
                    std::cout << "������������" << std::endl;
                    std::cin >> insertName;
                    if (calcType -1) {
                        getData = GetQueryData(false, insertName);
                    } else {
                        getData = GetQueryData(true, insertName);
                    }
                    std::cout << "ѧ�� " << insertName << " ���ܷ���Ϊ " << getData << " Ԫ" << endl;
                    break;
                }
                break;
            case 6:
                std::cout << "�˳�����" << std::endl;
                FreeConnect();
                return 0;
            default:
                std::cout << "������ѡ��" << std::endl;
        }
    }
}


