#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>

class Student {
public:
    std::string name;
    std::string gender;
    std::string id;
    std::string classname;
    std::vector<int> scores;

    Student() : scores(4, 0) {}

    double getTotalScore() const;
    double getAverageScore() const;

    static void saveToFile(const std::vector<Student>& students, const std::string& filename);
    static void loadFromFile(std::vector<Student>& students, const std::string& filename);
};

class User {
public:
    std::string username;
    std::string password;
    std::string role; // "admin" or "user" or "parent"

    User() {}
    User(const std::string& u, const std::string& p, const std::string& r) : username(u), password(p), role(r) {}
};

class StudentManagementSystem {
public:
    void run();
private:
    std::vector<Student> students;
    std::vector<User> users;
    User currentUser;

    void showMenu();
    void addUser();
    void userLogin();
    void addStudent();
    void modifyStudent();
    void deleteStudent();
    void queryStudent();
    void sortStudents();
    void calculateStatistics();
    void exportData();
    void importData();
    void analyzeScores();
    void generateReports();
    void saveToFile(const std::vector<User>& users, const std::string& filename);
    void loadFromFile(std::vector<User>& users, const std::string& filename);
};


// 获取总分
double Student::getTotalScore() const {
    double total = 0;
    for (int score : scores) {
        total += score;
    }
    return total;
}

// 获取平均分
double Student::getAverageScore() const {
    return getTotalScore() / scores.size();
}

// 保存学生信息到文件
void Student::saveToFile(const std::vector<Student>& students, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const Student& student : students) {
            file << student.name << "," << student.gender << "," << student.id << "," << student.classname;
            for (int score : student.scores) {
                file << "," << score;
            }
            file << "\n";
        }
        file.close();
    }
}

// 从文件加载学生信息
void Student::loadFromFile(std::vector<Student>& students, const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string token;
        Student student;
        std::getline(ss, student.name, ',');
        std::getline(ss, student.gender, ',');
        std::getline(ss, student.id, ',');
        std::getline(ss, student.classname, ',');
        for (int i = 0; i < 4; ++i) {
            std::getline(ss, token, ',');
            student.scores[i] = std::stoi(token);
        }
        students.push_back(student);
    }
}

// 保存用户信息到文件
void StudentManagementSystem::saveToFile(const std::vector<User>& users, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const User& user : users) {
            file << user.username << "," << user.password << "," << user.role << "\n";
        }
        file.close();
    }
}

// 从文件加载用户信息
void StudentManagementSystem::loadFromFile(std::vector<User>& users, const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string token;
        User user;
        std::getline(ss, user.username, ',');
        std::getline(ss, user.password, ',');
        std::getline(ss, user.role, ',');
        users.push_back(user);
    }
}

// 运行系统
void StudentManagementSystem::run() {
    Student::loadFromFile(students, "students.csv");
    loadFromFile(users, "users.csv");
    userLogin();
}

// 显示菜单
void StudentManagementSystem::showMenu() {
    std::cout << "***************************************\n";
    std::cout << "*           学生管理系统菜单           *\n";
    std::cout << "***************************************\n";
    std::cout << "* 1. 添加学生                         *\n";
    std::cout << "* 2. 修改学生信息                     *\n";
    std::cout << "* 3. 删除学生                         *\n";
    std::cout << "* 4. 查询学生                         *\n";
    std::cout << "* 5. 排序学生                         *\n";
    std::cout << "* 6. 统计学生成绩                     *\n";
    std::cout << "* 7. 导出数据                         *\n";
    std::cout << "* 8. 导入数据                         *\n";
    std::cout << "* 9. 分析成绩                         *\n";
    std::cout << "* 10. 生成报告                        *\n";
    std::cout << "* 0. 退出                             *\n";
    std::cout << "***************************************\n";
}


// 添加用户
void StudentManagementSystem::addUser() {
    User user;
    std::cout << "输入用户名: ";
    std::cin >> user.username;
    std::cout << "输入密码: ";
    std::cin >> user.password;
    std::cout << "输入角色 (admin/user/parent): ";
    std::cin >> user.role;
    users.push_back(user);
    saveToFile(users, "users.csv");
}

// 用户登录
void StudentManagementSystem::userLogin() {
    std::string username, password;
    std::cout << "输入用户名: ";
    std::cin >> username;
    std::cout << "输入密码: ";
    std::cin >> password;
    for (const auto& user : users) {
        if (user.username == username && user.password == password) {
            currentUser = user;
            std::cout << "登录成功！\n";
            while (true) {
                showMenu();
                int choice;
                std::cin >> choice;
                switch (choice) {
                    case 1: addStudent(); break;
                    case 2: modifyStudent(); break;
                    case 3: deleteStudent(); break;
                    case 4: queryStudent(); break;
                    case 5: sortStudents(); break;
                    case 6: calculateStatistics(); break;
                    case 7: exportData(); break;
                    case 8: importData(); break;
                    case 9: analyzeScores(); break;
                    case 10: generateReports(); break;
                    case 0: return;
                    default: std::cout << "无效选择\n"; break;
                }
            }
        }
    }
    std::cout << "用户名或密码错误！\n";
}

// 添加学生
void StudentManagementSystem::addStudent() {
    Student student;
    std::cout << "输入学生姓名: ";
    std::cin >> student.name;
    std::cout << "输入学生性别: ";
    std::cin >> student.gender;
    std::cout << "输入学生学号: ";
    std::cin >> student.id;
    std::cout << "输入学生班级: ";
    std::cin >> student.classname;
    std::cout << "输入学生四门功课的成绩: ";
    for (int& score : student.scores) {
        std::cin >> score;
    }
    students.push_back(student);
    Student::saveToFile(students, "students.csv");
}

// 修改学生信息
void StudentManagementSystem::modifyStudent() {
    std::string id;
    std::cout << "输入要修改的学生学号: ";
    std::cin >> id;
    for (auto& student : students) {
        if (student.id == id) {
            std::cout << "输入新的学生姓名: ";
            std::cin >> student.name;
            std::cout << "输入新的学生性别: ";
            std::cin >> student.gender;
            std::cout << "输入新的学生班级: ";
            std::cin >> student.classname;
            std::cout << "输入新的四门功课成绩: ";
            for (int& score : student.scores) {
                std::cin >> score;
            }
            Student::saveToFile(students, "students.csv");
            return;
        }
    }
    std::cout << "未找到该学号的学生！\n";
}

// 删除学生
void StudentManagementSystem::deleteStudent() {
    std::string id;
    std::cout << "输入要删除的学生学号: ";
    std::cin >> id;
    auto it = std::remove_if(students.begin(), students.end(), [&id](const Student& student) {
        return student.id == id;
    });
    if (it != students.end()) {
        students.erase(it, students.end());
        Student::saveToFile(students, "students.csv");
        std::cout << "学生信息已删除。\n";
    } else {
        std::cout << "未找到该学号的学生！\n";
    }
}

// 查询学生
void StudentManagementSystem::queryStudent() {
    int choice;
    std::cout << "1. 根据学号查询\n";
    std::cout << "2. 根据姓名和班级查询\n";
    std::cin >> choice;
    if (choice == 1) {
        std::string id;
        std::cout << "输入学生学号: ";
        std::cin >> id;
        for (const auto& student : students) {
            if (student.id == id) {
                std::cout << "姓名: " << student.name << ", 性别: " << student.gender << ", 学号: " << student.id << ", 班级: " << student.classname << "\n";
                for (size_t i = 0; i < student.scores.size(); ++i) {
                    std::cout << "科目" << i + 1 << "成绩: " << student.scores[i] << "\n";
                }
                return;
            }
        }
    } else if (choice == 2) {
        std::string name, classname;
        std::cout << "输入学生姓名: ";
        std::cin >> name;
        std::cout << "输入学生班级: ";
        std::cin >> classname;
        for (const auto& student : students) {
            if (student.name == name && student.classname == classname) {
                std::cout << "姓名: " << student.name << ", 性别: " << student.gender << ", 学号: " << student.id << ", 班级: " << student.classname << "\n";
                for (size_t i = 0; i < student.scores.size(); ++i) {
                    std::cout << "科目" << i + 1 << "成绩: " << student.scores[i] << "\n";
                }
                return;
            }
        }
    }
    std::cout << "未找到相关学生！\n";
}

// 排序学生
void StudentManagementSystem::sortStudents() {
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.getTotalScore() > b.getTotalScore();
    });
    Student::saveToFile(students, "students.csv");
}

// 统计学生成绩
void StudentManagementSystem::calculateStatistics() {
    std::map<std::string, std::vector<int>> classScores;
    for (const auto& student : students) {
        classScores[student.classname].push_back(student.getTotalScore());
    }
    for (const auto& entry : classScores) {
        int totalScore = 0;
        for (int score : entry.second) {
            totalScore += score;
        }
        double avgScore = static_cast<double>(totalScore) / entry.second.size();
        std::cout << "班级: " << entry.first << ", 平均总分: " << avgScore << "\n";
    }
}

// 导出数据
void StudentManagementSystem::exportData() {
    std::ofstream file("export.csv");
    if (file.is_open()) {
        for (const auto& student : students) {
            file << student.name << "," << student.gender << "," << student.id << "," << student.classname;
            for (int score : student.scores) {
                file << "," << score;
            }
            file << "\n";
        }
        file.close();
        std::cout << "数据已导出到 export.csv。\n";
    }
}

// 导入数据
void StudentManagementSystem::importData() {
    std::string filename;
    std::cout << "输入导入文件名: ";
    std::cin >> filename;
    Student::loadFromFile(students, filename);
    std::cout << "数据已导入。\n";
}

// 分析成绩
void StudentManagementSystem::analyzeScores() {
    std::map<std::string, std::vector<int>> classScores;
    for (const auto& student : students) {
        classScores[student.classname].push_back(student.getTotalScore());
    }
    for (const auto& entry : classScores) {
        int maxScore = *std::max_element(entry.second.begin(), entry.second.end());
        int minScore = *std::min_element(entry.second.begin(), entry.second.end());
        int totalScore = 0;
        int passCount = 0;
        for (int score : entry.second) {
            totalScore += score;
            if (score >= 60) {
                passCount++;
            }
        }
        double avgScore = static_cast<double>(totalScore) / entry.second.size();
        double passRate = static_cast<double>(passCount) / entry.second.size() * 100;
        std::cout << "班级: " << entry.first << "\n";
        std::cout << "最高分: " << maxScore << ", 最低分: " << minScore << ", 平均分: " << avgScore << ", 及格率: " << passRate << "%\n";
    }
}

// 生成报告
void StudentManagementSystem::generateReports() {
    std::map<std::string, std::vector<int>> subjectScores[4];
    for (const auto& student : students) {
        for (size_t i = 0; i < student.scores.size(); ++i) {
            subjectScores[i][student.classname].push_back(student.scores[i]);
        }
    }
    for (size_t i = 0; i < 4; ++i) {
        std::cout << "科目 " << i + 1 << " 成绩分析:\n";
        for (const auto& entry : subjectScores[i]) {
            int totalScore = 0;
            int passCount = 0;
            int maxScore = *std::max_element(entry.second.begin(), entry.second.end());
            int minScore = *std::min_element(entry.second.begin(), entry.second.end());
            for (int score : entry.second) {
                totalScore += score;
                if (score >= 60) {
                    passCount++;
                }
            }
            double avgScore = static_cast<double>(totalScore) / entry.second.size();
            double passRate = static_cast<double>(passCount) / entry.second.size() * 100;
            std::cout << "班级: " << entry.first << "\n";
            std::cout << "最高分: " << maxScore << ", 最低分: " << minScore << ", 平均分: " << avgScore << ", 及格率: " << passRate << "%\n";
        }
    }
}

// 主函数
int main() {
    StudentManagementSystem system;
    system.run();
    return 0;
}
