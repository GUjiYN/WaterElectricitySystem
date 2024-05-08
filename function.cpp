//
// Created by 29464 on 2024/5/6.
//
#include "head.cpp"
//添加学生
namespace func {
    void addStudent() {
        std::string person_id, name, gender, class_name;
        string age;
        string electricity_usage, water_usage;

        std::cout << "请输入学号：" << std::endl;
        std::cin >> person_id;

        std::cout << "请输入姓名：" << std::endl;
        std::cin >> name;

        std::cout << "请输入性别(male, female)：" << std::endl;
        std::cin >> gender;

        std::cout << "请输入年龄：" << std::endl;
        std::cin >> age;

        std::cout << "请输入班级：" << std::endl;
        std::cin >> class_name;

        std::cout << "请输入用电量：" << std::endl;
        std::cin >> electricity_usage;

        std::cout << "请输入用水量：" << std::endl;
        std::cin >> water_usage;

        // 生成插入数据库的 SQL 语句
        std::string personSQL =
                "INSERT INTO person (person_id, name, gender, age) VALUES ('"
                + person_id + "', '" + name + "', '" + gender + "', "
                + age + ")";
        std::string studentSQL =
                "INSERT INTO student (person_id, class_name, electricity_usage, water_usage) VALUES ('"
                + person_id + "', '" + class_name + "', '" + electricity_usage + "' , '"
                + water_usage + "')";
        // 使用 updateData 插入到数据库
        updateData(personSQL);
        updateData(studentSQL);
    }

//添加老师
    void addTeacher() {
        std::string person_id, name, gender, department;
        string age;
        string electricity_usage, water_usage;

        std::cout << "请输入教职工号：" << std::endl;
        std::cin >> person_id;

        std::cout << "请输入姓名：" << std::endl;
        std::cin >> name;

        std::cout << "请输入性别(male, female)：" << std::endl;
        std::cin >> gender;

        std::cout << "请输入年龄：" << std::endl;
        std::cin >> age;

        std::cout << "请输入部门：" << std::endl;
        std::cin >> department;

        std::cout << "请输入用电量：" << std::endl;
        std::cin >> electricity_usage;

        std::cout << "请输入用水量：" << std::endl;
        std::cin >> water_usage;

        // 生成插入数据库的 SQL 语句
        std::string personSQL =
                "INSERT INTO person (person_id, name, gender, age) VALUES ('"
                + person_id + "', '" + name + "', '" + gender + "', '"
                + age + "')";
        std::string teacherSQL =
                "INSERT INTO staff (person_id, department, electricity_usage, water_usage) VALUES ('"
                + person_id + "', '" + department + "','" + electricity_usage + "' , '"
                + water_usage + "')";
        // 使用 updateData 插入到数据库
        updateData(personSQL);
        updateData(teacherSQL);
    }


// 编辑学生
    void editStudent() {
        std::string person_id, name, gender, class_name;
        int age;
        double electricity_usage, water_usage;

        std::cout << "请输入要修改的学生学号：" << std::endl;
        std::cin >> person_id;

        std::cout << "请输入新的姓名：" << std::endl;
        std::cin >> name;

        std::cout << "请输入新的性别(male, female)：" << std::endl;
        std::cin >> gender;

        std::cout << "请输入新的年龄：" << std::endl;
        std::cin >> age;

        std::cout << "请输入新的班级：" << std::endl;
        std::cin >> class_name;

        std::cout << "请输入新的用电量：" << std::endl;
        std::cin >> electricity_usage;

        std::cout << "请输入新的用水量：" << std::endl;
        std::cin >> water_usage;

        // 生成更新数据库的 SQL 语句
        std::string personSOL = "UPDATE person SET name = '" + name + "', gender = '" + gender + "', age = " +
                                std::to_string(age) +  " WHERE person_id = '" + person_id + "'";
        std::string studentSQL = "UPDATE student SET class_name = '" + class_name + "', electricity_usage = " +
                            std::to_string(electricity_usage) + ", water_usage = " +
                            std::to_string(water_usage)  + " WHERE person_id = '" + person_id + "'";

        updateData(personSOL);
        updateData(studentSQL);
    }

// 编辑教师
    void editTeacher() {
        std::string person_id, name, gender, department;
        int age;
        double electricity_usage, water_usage;

        std::cout << "请输入要修改的教职工号：" << std::endl;
        std::cin >> person_id;

        std::cout << "请输入新的姓名：" << std::endl;
        std::cin >> name;

        std::cout << "请输入新的性别(male, female)：" << std::endl;
        std::cin >> gender;

        std::cout << "请输入新的年龄：" << std::endl;
        std::cin >> age;

        std::cout << "请输入新的部门：" << std::endl;
        std::cin >> department;

        std::cout << "请输入新的用电量：" << std::endl;
        std::cin >> electricity_usage;

        std::cout << "请输入新的用水量：" << std::endl;
        std::cin >> water_usage;

        // 生成更新数据库的 SQL 语句
        std::string personSQL = "UPDATE person SET name = '" + name + "', gender = '" + gender + "', age = " +
                                 std::to_string(age) + " WHERE person_id = '" + person_id + "'";
        std::string teacherSQL = "UPDATE staff SET department = '" + department + "', electricity_usage = " +
                                 std::to_string(electricity_usage) + ", water_usage = " +
                                 std::to_string(water_usage) + " WHERE person_id = '" + person_id + "'";
        updateData(personSQL);
        updateData(teacherSQL);
    }
}