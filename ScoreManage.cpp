#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

// 学生结构体
struct Student {
    string id;     // 学号
    string name;   // 姓名
    int score;     // 成绩
};

vector<Student> stuList;

// 函数声明
void menu();                // 主菜单
void addStu();              // 添加学生
void showAll();             // 查看全部
void searchById();          // 按学号查询
void deleteStu();           // 删除学生
void sortByScore();         // 按成绩降序排序

int main()
{
    int choice;
    while (true)
    {
        menu();
        cin >> choice;
        switch (choice)
        {
        case 1: addStu(); break;
        case 2: showAll(); break;
        case 3: searchById(); break;
        case 4: deleteStu(); break;
        case 5: sortByScore(); break;
        case 0:
            cout << "程序退出！" << endl;
            return 0;
        default:
            cout << "输入错误，请重新选择！" << endl;
        }
        system("pause");
        system("cls");
    }
}

// 打印菜单
void menu()
{
    cout << "===== 学生成绩管理系统 =====" << endl;
    cout << "1. 添加学生信息" << endl;
    cout << "2. 查看所有学生" << endl;
    cout << "3. 按学号查找学生" << endl;
    cout << "4. 删除指定学生" << endl;
    cout << "5. 按成绩从高到低排序" << endl;
    cout << "0. 退出系统" << endl;
    cout << "============================" << endl;
    cout << "请输入功能序号：";
}

// 添加学生
void addStu()
{
    Student s;
    cout << "请输入学号：";
    cin >> s.id;
    cout << "请输入姓名：";
    cin >> s.name;
    cout << "请输入成绩：";
    cin >> s.score;
    stuList.push_back(s);
    cout << "✅ 添加成功！" << endl;
}

// 展示全部
void showAll()
{
    if (stuList.empty())
    {
        cout << "暂无学生数据！" << endl;
        return;
    }
    cout << left
        << setw(12) << "学号"
        << setw(10) << "姓名"
        << setw(8) << "成绩" << endl;
    for (auto& s : stuList)
    {
        cout << left
            << setw(12) << s.id
            << setw(10) << s.name
            << setw(8) << s.score << endl;
    }
}

// 学号查找
void searchById()
{
    string id;
    cout << "输入要查找的学号：";
    cin >> id;
    bool find = false;
    for (auto& s : stuList)
    {
        if (s.id == id)
        {
            cout << "找到：" << s.id << " " << s.name << " " << s.score << endl;
            find = true;
            break;
        }
    }
    if (!find)
        cout << "未找到该学号学生！" << endl;
}

// 删除学生
void deleteStu()
{
    string id;
    cout << "输入要删除的学号：";
    cin >> id;
    for (auto it = stuList.begin(); it != stuList.end(); it++)
    {
        if (it->id == id)
        {
            stuList.erase(it);
            cout << "✅ 删除完成！" << endl;
            return;
        }
    }
    cout << "未找到该学生！" << endl;
}

// 成绩降序排序
void sortByScore()
{
    sort(stuList.begin(), stuList.end(), [](Student a, Student b) {
        return a.score > b.score;
    });
    cout << "✅ 已按成绩从高到低排序！" << endl;
}