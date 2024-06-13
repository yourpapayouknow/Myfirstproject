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


// ��ȡ�ܷ�
double Student::getTotalScore() const {
    double total = 0;
    for (int score : scores) {
        total += score;
    }
    return total;
}

// ��ȡƽ����
double Student::getAverageScore() const {
    return getTotalScore() / scores.size();
}

// ����ѧ����Ϣ���ļ�
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

// ���ļ�����ѧ����Ϣ
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

// �����û���Ϣ���ļ�
void StudentManagementSystem::saveToFile(const std::vector<User>& users, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const User& user : users) {
            file << user.username << "," << user.password << "," << user.role << "\n";
        }
        file.close();
    }
}

// ���ļ������û���Ϣ
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

// ����ϵͳ
void StudentManagementSystem::run() {
    Student::loadFromFile(students, "students.csv");
    loadFromFile(users, "users.csv");
    userLogin();
}

// ��ʾ�˵�
void StudentManagementSystem::showMenu() {
    std::cout << "***************************************\n";
    std::cout << "*           ѧ������ϵͳ�˵�           *\n";
    std::cout << "***************************************\n";
    std::cout << "* 1. ���ѧ��                         *\n";
    std::cout << "* 2. �޸�ѧ����Ϣ                     *\n";
    std::cout << "* 3. ɾ��ѧ��                         *\n";
    std::cout << "* 4. ��ѯѧ��                         *\n";
    std::cout << "* 5. ����ѧ��                         *\n";
    std::cout << "* 6. ͳ��ѧ���ɼ�                     *\n";
    std::cout << "* 7. ��������                         *\n";
    std::cout << "* 8. ��������                         *\n";
    std::cout << "* 9. �����ɼ�                         *\n";
    std::cout << "* 10. ���ɱ���                        *\n";
    std::cout << "* 0. �˳�                             *\n";
    std::cout << "***************************************\n";
}


// ����û�
void StudentManagementSystem::addUser() {
    User user;
    std::cout << "�����û���: ";
    std::cin >> user.username;
    std::cout << "��������: ";
    std::cin >> user.password;
    std::cout << "�����ɫ (admin/user/parent): ";
    std::cin >> user.role;
    users.push_back(user);
    saveToFile(users, "users.csv");
}

// �û���¼
void StudentManagementSystem::userLogin() {
    std::string username, password;
    std::cout << "�����û���: ";
    std::cin >> username;
    std::cout << "��������: ";
    std::cin >> password;
    for (const auto& user : users) {
        if (user.username == username && user.password == password) {
            currentUser = user;
            std::cout << "��¼�ɹ���\n";
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
                    default: std::cout << "��Чѡ��\n"; break;
                }
            }
        }
    }
    std::cout << "�û������������\n";
}

// ���ѧ��
void StudentManagementSystem::addStudent() {
    Student student;
    std::cout << "����ѧ������: ";
    std::cin >> student.name;
    std::cout << "����ѧ���Ա�: ";
    std::cin >> student.gender;
    std::cout << "����ѧ��ѧ��: ";
    std::cin >> student.id;
    std::cout << "����ѧ���༶: ";
    std::cin >> student.classname;
    std::cout << "����ѧ�����Ź��εĳɼ�: ";
    for (int& score : student.scores) {
        std::cin >> score;
    }
    students.push_back(student);
    Student::saveToFile(students, "students.csv");
}

// �޸�ѧ����Ϣ
void StudentManagementSystem::modifyStudent() {
    std::string id;
    std::cout << "����Ҫ�޸ĵ�ѧ��ѧ��: ";
    std::cin >> id;
    for (auto& student : students) {
        if (student.id == id) {
            std::cout << "�����µ�ѧ������: ";
            std::cin >> student.name;
            std::cout << "�����µ�ѧ���Ա�: ";
            std::cin >> student.gender;
            std::cout << "�����µ�ѧ���༶: ";
            std::cin >> student.classname;
            std::cout << "�����µ����Ź��γɼ�: ";
            for (int& score : student.scores) {
                std::cin >> score;
            }
            Student::saveToFile(students, "students.csv");
            return;
        }
    }
    std::cout << "δ�ҵ���ѧ�ŵ�ѧ����\n";
}

// ɾ��ѧ��
void StudentManagementSystem::deleteStudent() {
    std::string id;
    std::cout << "����Ҫɾ����ѧ��ѧ��: ";
    std::cin >> id;
    auto it = std::remove_if(students.begin(), students.end(), [&id](const Student& student) {
        return student.id == id;
    });
    if (it != students.end()) {
        students.erase(it, students.end());
        Student::saveToFile(students, "students.csv");
        std::cout << "ѧ����Ϣ��ɾ����\n";
    } else {
        std::cout << "δ�ҵ���ѧ�ŵ�ѧ����\n";
    }
}

// ��ѯѧ��
void StudentManagementSystem::queryStudent() {
    int choice;
    std::cout << "1. ����ѧ�Ų�ѯ\n";
    std::cout << "2. ���������Ͱ༶��ѯ\n";
    std::cin >> choice;
    if (choice == 1) {
        std::string id;
        std::cout << "����ѧ��ѧ��: ";
        std::cin >> id;
        for (const auto& student : students) {
            if (student.id == id) {
                std::cout << "����: " << student.name << ", �Ա�: " << student.gender << ", ѧ��: " << student.id << ", �༶: " << student.classname << "\n";
                for (size_t i = 0; i < student.scores.size(); ++i) {
                    std::cout << "��Ŀ" << i + 1 << "�ɼ�: " << student.scores[i] << "\n";
                }
                return;
            }
        }
    } else if (choice == 2) {
        std::string name, classname;
        std::cout << "����ѧ������: ";
        std::cin >> name;
        std::cout << "����ѧ���༶: ";
        std::cin >> classname;
        for (const auto& student : students) {
            if (student.name == name && student.classname == classname) {
                std::cout << "����: " << student.name << ", �Ա�: " << student.gender << ", ѧ��: " << student.id << ", �༶: " << student.classname << "\n";
                for (size_t i = 0; i < student.scores.size(); ++i) {
                    std::cout << "��Ŀ" << i + 1 << "�ɼ�: " << student.scores[i] << "\n";
                }
                return;
            }
        }
    }
    std::cout << "δ�ҵ����ѧ����\n";
}

// ����ѧ��
void StudentManagementSystem::sortStudents() {
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.getTotalScore() > b.getTotalScore();
    });
    Student::saveToFile(students, "students.csv");
}

// ͳ��ѧ���ɼ�
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
        std::cout << "�༶: " << entry.first << ", ƽ���ܷ�: " << avgScore << "\n";
    }
}

// ��������
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
        std::cout << "�����ѵ����� export.csv��\n";
    }
}

// ��������
void StudentManagementSystem::importData() {
    std::string filename;
    std::cout << "���뵼���ļ���: ";
    std::cin >> filename;
    Student::loadFromFile(students, filename);
    std::cout << "�����ѵ��롣\n";
}

// �����ɼ�
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
        std::cout << "�༶: " << entry.first << "\n";
        std::cout << "��߷�: " << maxScore << ", ��ͷ�: " << minScore << ", ƽ����: " << avgScore << ", ������: " << passRate << "%\n";
    }
}

// ���ɱ���
void StudentManagementSystem::generateReports() {
    std::map<std::string, std::vector<int>> subjectScores[4];
    for (const auto& student : students) {
        for (size_t i = 0; i < student.scores.size(); ++i) {
            subjectScores[i][student.classname].push_back(student.scores[i]);
        }
    }
    for (size_t i = 0; i < 4; ++i) {
        std::cout << "��Ŀ " << i + 1 << " �ɼ�����:\n";
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
            std::cout << "�༶: " << entry.first << "\n";
            std::cout << "��߷�: " << maxScore << ", ��ͷ�: " << minScore << ", ƽ����: " << avgScore << ", ������: " << passRate << "%\n";
        }
    }
}

// ������
int main() {
    StudentManagementSystem system;
    system.run();
    return 0;
}
