//
// Created by 29464 on 2024/5/6.
//
#include "head.cpp"
//���ѧ��
namespace func {
    void addStudent() {
        std::string person_id, name, gender, class_name;
        string age;
        string electricity_usage, water_usage;

        std::cout << "������ѧ�ţ�" << std::endl;
        std::cin >> person_id;

        std::cout << "������������" << std::endl;
        std::cin >> name;

        std::cout << "�������Ա�(male, female)��" << std::endl;
        std::cin >> gender;

        std::cout << "���������䣺" << std::endl;
        std::cin >> age;

        std::cout << "������༶��" << std::endl;
        std::cin >> class_name;

        std::cout << "�������õ�����" << std::endl;
        std::cin >> electricity_usage;

        std::cout << "��������ˮ����" << std::endl;
        std::cin >> water_usage;

        // ���ɲ������ݿ�� SQL ���
        std::string personSQL =
                "INSERT INTO person (person_id, name, gender, age) VALUES ('"
                + person_id + "', '" + name + "', '" + gender + "', "
                + age + ")";
        std::string studentSQL =
                "INSERT INTO student (person_id, class_name, electricity_usage, water_usage) VALUES ('"
                + person_id + "', '" + class_name + "', '" + electricity_usage + "' , '"
                + water_usage + "')";
        // ʹ�� updateData ���뵽���ݿ�
        updateData(personSQL);
        updateData(studentSQL);
    }

//�����ʦ
    void addTeacher() {
        std::string person_id, name, gender, department;
        string age;
        string electricity_usage, water_usage;

        std::cout << "�������ְ���ţ�" << std::endl;
        std::cin >> person_id;

        std::cout << "������������" << std::endl;
        std::cin >> name;

        std::cout << "�������Ա�(male, female)��" << std::endl;
        std::cin >> gender;

        std::cout << "���������䣺" << std::endl;
        std::cin >> age;

        std::cout << "�����벿�ţ�" << std::endl;
        std::cin >> department;

        std::cout << "�������õ�����" << std::endl;
        std::cin >> electricity_usage;

        std::cout << "��������ˮ����" << std::endl;
        std::cin >> water_usage;

        // ���ɲ������ݿ�� SQL ���
        std::string personSQL =
                "INSERT INTO person (person_id, name, gender, age) VALUES ('"
                + person_id + "', '" + name + "', '" + gender + "', '"
                + age + "')";
        std::string teacherSQL =
                "INSERT INTO staff (person_id, department, electricity_usage, water_usage) VALUES ('"
                + person_id + "', '" + department + "','" + electricity_usage + "' , '"
                + water_usage + "')";
        // ʹ�� updateData ���뵽���ݿ�
        updateData(personSQL);
        updateData(teacherSQL);
    }


// �༭ѧ��
    void editStudent() {
        std::string person_id, name, gender, class_name;
        int age;
        double electricity_usage, water_usage;

        std::cout << "������Ҫ�޸ĵ�ѧ��ѧ�ţ�" << std::endl;
        std::cin >> person_id;

        std::cout << "�������µ�������" << std::endl;
        std::cin >> name;

        std::cout << "�������µ��Ա�(male, female)��" << std::endl;
        std::cin >> gender;

        std::cout << "�������µ����䣺" << std::endl;
        std::cin >> age;

        std::cout << "�������µİ༶��" << std::endl;
        std::cin >> class_name;

        std::cout << "�������µ��õ�����" << std::endl;
        std::cin >> electricity_usage;

        std::cout << "�������µ���ˮ����" << std::endl;
        std::cin >> water_usage;

        // ���ɸ������ݿ�� SQL ���
        std::string personSOL = "UPDATE person SET name = '" + name + "', gender = '" + gender + "', age = " +
                                std::to_string(age) +  " WHERE person_id = '" + person_id + "'";
        std::string studentSQL = "UPDATE student SET class_name = '" + class_name + "', electricity_usage = " +
                            std::to_string(electricity_usage) + ", water_usage = " +
                            std::to_string(water_usage)  + " WHERE person_id = '" + person_id + "'";

        updateData(personSOL);
        updateData(studentSQL);
    }

// �༭��ʦ
    void editTeacher() {
        std::string person_id, name, gender, department;
        int age;
        double electricity_usage, water_usage;

        std::cout << "������Ҫ�޸ĵĽ�ְ���ţ�" << std::endl;
        std::cin >> person_id;

        std::cout << "�������µ�������" << std::endl;
        std::cin >> name;

        std::cout << "�������µ��Ա�(male, female)��" << std::endl;
        std::cin >> gender;

        std::cout << "�������µ����䣺" << std::endl;
        std::cin >> age;

        std::cout << "�������µĲ��ţ�" << std::endl;
        std::cin >> department;

        std::cout << "�������µ��õ�����" << std::endl;
        std::cin >> electricity_usage;

        std::cout << "�������µ���ˮ����" << std::endl;
        std::cin >> water_usage;

        // ���ɸ������ݿ�� SQL ���
        std::string personSQL = "UPDATE person SET name = '" + name + "', gender = '" + gender + "', age = " +
                                 std::to_string(age) + " WHERE person_id = '" + person_id + "'";
        std::string teacherSQL = "UPDATE staff SET department = '" + department + "', electricity_usage = " +
                                 std::to_string(electricity_usage) + ", water_usage = " +
                                 std::to_string(water_usage) + " WHERE person_id = '" + person_id + "'";
        updateData(personSQL);
        updateData(teacherSQL);
    }
}