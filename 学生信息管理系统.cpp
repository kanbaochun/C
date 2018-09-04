// 学生信息管理系统.cpp: 定义控制台应用程序的入口点。
//

#include<iostream>
using namespace std;
//结构体
struct Student
{
	char name[20];
	char number[20];
	Student *next;
};
//链表类
class ManageStudent 
{
private:
	Student *Head;
	int n;
public:
	ManageStudent();
	void CreateLinkList();
	void InsertLinkList();
	void DeleteLinkList();
	void FindLinkList();
	void ModifyLinkList();
	void DisplayLinkList();
};
//构造函数
ManageStudent::ManageStudent()
{
	Head = new Student;
	Head->next = NULL;
}
//创建链表  
void ManageStudent::CreateLinkList() 
{
	Student *p, *t;
	p = Head;
	cout << "请输入要录入信息的个数： ";
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		t = new Student;
		cout << "请输入第" << i << "个人的姓名： ";
		cin >> t->name; 
		cout << "请输入第" << i << "个人的学号： ";
		cin >> t->number;
		p->next = t; p=p->next;
	}
	p->next = NULL;
}
//插入学生信息
void ManageStudent::InsertLinkList() 
{
	Student *p, *t;
	p = Head;
	cout << "请输入插入信息的位置： ";
	cin >> n;
	while ((p!=NULL)&&(n>1)) 
	{
		p = p->next;
		n--;

	}
	t = new Student;
	cout << "请输入第" << n << "个人的姓名： ";
	cin >> t->name;
	cout << "请输入第" << n << "个人的学号： ";
	cin >> t->number;
	t->next = p->next;
	p->next = t; 
}
//删除学生信息
void ManageStudent::DeleteLinkList()
{
	Student *p;
	p = Head;
	cout << "请输入删除信息的位置： ";
	cin >> n;
	while ((p != NULL) && (n>1))
	{
		p = p->next;
		n--;
	}
	cout << "你要删除的信息是： " << p->next->name << "  " << p->next->number << endl;
	p->next = p->next->next;
	//delete p->next->next;
}
//查找学生信息
void ManageStudent::FindLinkList()
{
	Student *p;
	p = Head;
	cout << "请输入查找信息的位置： ";
	cin >> n;
	while ((p != NULL) && (n>1))
	{
		p = p->next;
		n--;
	}
	cout << "您要查找的信息是： " << p->next->name << "  " << p->next->number << endl;
}
//修改学生信息
void ManageStudent::ModifyLinkList()
{
	Student *p;
	p = Head;
	cout << "请输入要修改信息的位置： ";
	cin >> n;
	while ((p != NULL) && (n>1))
	{
		p = p->next;
		n--;
	}
	cout << "请输入第" << n+1 << "个人的姓名： ";
	cin >> p->next->name;
	cout << "请输入第" << n+1 << "个人的学号： ";
	cin >> p->next->number;
}
//打印学生信息
void ManageStudent::DisplayLinkList() 
{
	Student *p;
	p = Head->next;
	cout << "学生的所有信息如下： " << endl;
	while (p != NULL) 
	{
		cout << p->name << "  " << p->number << endl;
		p = p->next;
	}
}

int main()
{
	ManageStudent S1;
	while (true)
	{
		cout << "请选择你要进行的操作：\n";
		cout << "1.创建学生信息\n2.插入学生信息\n3.删除学生信息\n";
		cout<< "4.查找学生信息\n5.修改学生信息\n6.显示学生信息\n7.退出管理系统 " << endl;
		int op;
		cin >> op;
		if (op == 1){ S1.CreateLinkList(); }
		else if(op == 2){ S1.InsertLinkList(); }
		else if (op == 3) { S1.DeleteLinkList(); }
		else if (op == 4) { S1.FindLinkList(); }
		else if (op == 5) { S1.ModifyLinkList(); }
		else if (op == 6) { S1.DisplayLinkList(); }
		else { break; }
	}
    return 0;
}