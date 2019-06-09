#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
using namespace std;
template <typename T>//定义类模板 
class student
{
public:
	T summary;//学生单人的六科总分，是T类型的变量
	char name[5];//学生姓名
	long code;//学号
	int sex;//性别
	T grade[3];//单人成绩，0为英语，1为中文，2为数学，是T类型的变量
	static T total[3];//全班各科总分，0为英语，1为中文，2为数学，是T类型的静态数据成员
	static int count;//用于计算学生人数的计数器
	student(T sum, char *str, long co, int se, T a, T b, T c) { summary = sum;strcpy_s(name, str);code = co;sex = se;grade[0] = a;grade[1] = b;grade[2] = c; }//成员函数是函数模板
	virtual void show() const {//用于展示班级三科平均分的虚函数
		cout << "英语总分：" << total[0] << endl;
		cout << "中文总分：" << total[1] << endl;
		cout << "数学总分：" << total[2] << endl;
		cout << "英语平均分：" << total[0] / count << endl;
		cout << "中文平均分：" << total[1] / count << endl;
		cout << "数学平均分：" << total[2] / count << endl;
	}
	virtual void print() const {//用于展示学生个人信息及成绩的虚函数
		cout << name << " " << code << " " << sex << " " << summary << " " << grade[0] << " " << grade[1] << " " << grade[2] << " ";
	}
	virtual T getGrade3() const = 0;//纯虚函数
	virtual T getGrade4() const = 0;
	virtual T getGrade5() const = 0;
};
template <typename T> T student<T>::total[3] = { 0 };
template <typename T> int student<T>::count = 0;

template <typename T>//定义类模板
class science : public student<T>//理科学生类
{
public:
	static int count1;//用于计算学生人数的计数器
	static T total1[3];//全班理科独有科目总分，0为物理，1为化学，2为生物
	T grade1[3];//单人理科独有科目分数，0为物理，1为化学，2为生物
	science(double sum, char *str, long co, int se, T a, T b, T c, T d, T e, T f) :student<T>(sum, str, co, se, a, b, c)//成员函数是函数模板
	{
		grade1[0] = d;
		grade1[1] = e;
		grade1[2] = f;
		student<T>::total[0] += a;
		student<T>::total[1] += b;
		student<T>::total[2] += c;
		student<T>::count++;
		total1[0] += d;
		total1[1] += e;
		total1[2] += f;
		count1++;
	}
	virtual void show() const {//用于展示理科三科总分及平均分的虚函数
		student<T>::show();
		cout << "物理总分：" << total1[0] << endl;
		cout << "化学总分：" << total1[1] << endl;
		cout << "生物总分：" << total1[2] << endl;
		cout << "物理平均分：" << total1[0] / count1 << endl;
		cout << "化学平均分：" << total1[1] / count1 << endl;
		cout << "生物平均分：" << total1[2] / count1 << endl;
	}
	virtual void print() const {//用于展示理科学生信息及个人成绩的虚函数
		student<T>::print();
		cout << grade1[0] << " " << grade1[1] << " " << grade1[2] << endl;
	}
	virtual T getGrade3() const {
		return grade1[0];
	}
	virtual T getGrade4() const {
		return grade1[1];
	}
	virtual T getGrade5() const {
		return grade1[2];
	}
};
template <typename T> int science<T>::count1 = 0;
template <typename T> T science<T>::total1[3] = { 0 };

template <typename T>//定义类模板
class art : public student<T>//文科学生类
{
public:
	static int count2;//用于计算学生人数的计数器
	static T total2[3];//全班文科独有科目总分，0为历史，1为地理，2为政治
	T grade2[3];//单人文科独有科目分数，0为历史，1为地理，2为政治
	art(double sum, char *str, long co, int se, T a, T b, T c, T d, T e, T f) :student<T>(sum, str, co, se, a, b, c)//成员函数是函数模板
	{
		grade2[0] = d;
		grade2[1] = e;
		grade2[2] = f;
		student<T>::total[0] += a;
		student<T>::total[1] += b;
		student<T>::total[2] += c;
		student<T>::count++;
		total2[0] += d;
		total2[1] += e;
		total2[2] += f;
		count2++;
	}
	virtual	void show() const {//用于展示文科三科总分及平均分的虚函数

		cout << "历史总分：" << total2[0] << endl;
		cout << "地理总分：" << total2[1] << endl;
		cout << "政治总分：" << total2[2] << endl;
		cout << "历史平均分：" << total2[0] / count2 << endl;
		cout << "地理平均分：" << total2[1] / count2 << endl;
		cout << "政治平均分：" << total2[2] / count2 << endl;
	}
	virtual void print() const {//用于展示文科学生信息及个人成绩的虚函数
		student<T>::print();
		cout << grade2[0] << " " << grade2[1] << " " << grade2[2] << endl;
	}
	virtual T getGrade3() const {
		return grade2[0];
	}
	virtual T getGrade4() const {
		return grade2[1];
	}
	virtual T getGrade5() const {
		return grade2[2];
	}
};
template <typename T> int art<T>::count2 = 0;
template <typename T> T art<T>::total2[3] = { 0 };



int main()
{
	ofstream outstuf, outf;
	student<int> *stu[100];//实例化int类型的指针数组
	student<double> *stu2[100];//实例化double类型的指针数组
	char name[30];//学生姓名
	long code;//学号
	int sex;//性别
	double grade[6];
	int mode, type, choose;//用于进行模式选择的变量
	int i = 0;
	int t1, t2;//分别存储文理科学生的顺序
	cout << "请输入存储学生成绩的文本文件名(.txt)：" << endl;
	char fileName1[30];
	cin >> fileName1;
	cout << "请输入存储学生成绩的二进制文件名(.dat)：" << endl;
	char fileName2[30];
	cin >> fileName2;
	cout << "请选择数据类型：1.整型 2.double型" << endl;
	cin >> choose;// choose = 1 为整型，choose = 2 为double型 
	if (choose == 1) {
		cout << "模式选择：1、添加学生成绩 2、输出各科总分平均分 3、输出成绩单 4、打开文件" << endl;
		cout << "请输入模式编号，按回车键确认：";
		cin >> mode;
		outstuf.open(fileName1, ios::out);//打开文件
		while (mode == 1)
		{

			if (!outstuf)
			{
				cerr << "File could not be open." << endl;
				abort();
			}
			cout << "请输入学生的类型（1为理科，2为文科）： ";
			cin >> type;
			if (type == 1)//理科生
			{
				cout << "请按如下格式输入学生成绩：" << endl;
				cout << "姓名 学号 性别（1为男性，2为女性） 英语成绩 中文成绩 数学成绩 物理成绩 化学成绩 生物成绩 " << endl;
				cin >> name >> code >> sex >> grade[0] >> grade[1] >> grade[2] >> grade[3] >> grade[4] >> grade[5];
				outstuf << name << " " << code << " " << sex << " " << grade[0] + grade[1] + grade[2] + grade[3] + grade[4] + grade[5] << " " << grade[0] << " " << grade[1] << " " << grade[2] << " " << grade[3] << " " << grade[4] << " " << grade[5] << '\n';//将数据存入外部文件中
				stu[i] = new science<int>(grade[0] + grade[1] + grade[2] + grade[3] + grade[4] + grade[5], name, code, sex, grade[0], grade[1], grade[2], grade[3], grade[4], grade[5]);//实例化
				t1 = i;
			}
			else if (type == 2)//文科生
			{
				cout << "请按如下格式输入学生成绩：" << endl;
				cout << "姓名 学号 性别（1为男性，2为女性） 英语成绩 中文成绩 数学成绩 历史成绩 地理成绩 政治成绩 " << endl;
				cin >> name >> code >> sex >> grade[0] >> grade[1] >> grade[2] >> grade[3] >> grade[4] >> grade[5];
				outstuf << name << " " << code << " " << sex << " " << grade[0] + grade[1] + grade[2] + grade[3] + grade[4] + grade[5] << " " << grade[0] << " " << grade[1] << " " << grade[2] << " " << grade[3] << " " << grade[4] << " " << grade[5] << '\n';//将数据存入外部文件中
				stu[i] = new art<int>(grade[0] + grade[1] + grade[2] + grade[3] + grade[4] + grade[5], name, code, sex, grade[0], grade[1], grade[2], grade[3], grade[4], grade[5]);//实例化
				t2 = i;
			}
			i++;
			cout << "模式选择：1、添加学生成绩 2、输出各科总分平均分 3、输出成绩单 4、打开文件" << endl;
			cout << "请输入模式编号，按回车键确认：";
			cin >> mode;
		}
		outstuf.close();
		if (mode == 2)
		{
			stu[t1]->show();//调用理科生类中的show函数显示理科成绩
			stu[t2]->show();//调用文科生类中的show函数显示文科成绩
			system("pause");
		}
		if (mode == 3)
		{
			cout << "排名" << endl;
			cout << "姓名 学号 性别（1为男性，2为女性）六科总分 英语成绩 中文成绩 数学成绩 物理(历史)成绩 化学(地理)成绩 生物(政治)成绩 " << endl;
			int index[100];//以下部分为对学生成绩进行排序
			int j, k;
			for (j = 0;j < 100;j++)
				index[j] = j;
			int temp;
			for (j = 1;j < i;j++)
			{
				for (k = 0;k <= i - 1 - j;k++)
					if (stu[index[k]]->summary < stu[index[k + 1]]->summary || stu[index[k]]->summary == stu[index[k + 1]]->summary&&stu[index[k]]->grade[1] < stu[index[k + 1]]->grade[1] || stu[index[k]]->summary == stu[index[k + 1]]->summary&&stu[index[k]]->grade[1] == stu[index[k + 1]]->grade[1] && stu[index[k]]->grade[2] < stu[index[k + 1]]->grade[2] || stu[index[k]]->summary == stu[index[k + 1]]->summary&&stu[index[k]]->grade[1] == stu[index[k + 1]]->grade[1] && stu[index[k]]->grade[2] == stu[index[k + 1]]->grade[2] && stu[index[k]]->grade[0] < stu[index[k + 1]]->grade[0])//排名交换的各种情况
					{
						temp = index[k];
						index[k] = index[k + 1];
						index[k + 1] = temp;
					}
			}
			for (j = 0;j < i;j++)
				stu[index[j]]->print();//调用stu类中的print函数进行成绩排名的输出
		}
		if (mode == 4) {
			ifstream instuf(fileName1, ios::in);//读取外部文件内容
			instuf.seekg(0, ios::beg);
			if (!instuf) {
				cerr << "File could not be open." << endl;
				abort();
			}
			outf.open(fileName2, ios::out | ios::binary);
			if (!outf)
			{
				cerr << "File could not be open." << endl;
				abort();
			}
			int score;
			cout << "文本文件中的学生信息（未排名）：" << endl;
			cout << "姓名 学号 性别（1为男性，2为女性）六科总分 英语成绩 中文成绩 数学成绩 物理(历史)成绩 化学(地理)成绩 生物(政治)成绩 " << endl;
			while (instuf >> name >> code >> sex >> score >> grade[0] >> grade[1] >> grade[2] >> grade[3] >> grade[4] >> grade[5]) {//输出外部文件中的内容
				cout << name << " " << code << " " << sex << " " << score << " " << grade[0] << " " << grade[1] << " " << grade[2] << " " << grade[3] << " " << grade[4] << " " << grade[5] << endl;
			}
			instuf.close();
			int index[100];//以下部分为对学生成绩进行排序
			int j, k;
			for (j = 0;j < 100;j++)
				index[j] = j;
			int temp;
			for (j = 1;j < i;j++)
			{
				for (k = 0;k <= i - 1 - j;k++)
					if (stu[index[k]]->summary < stu[index[k + 1]]->summary || stu[index[k]]->summary == stu[index[k + 1]]->summary&&stu[index[k]]->grade[1] < stu[index[k + 1]]->grade[1] || stu[index[k]]->summary == stu[index[k + 1]]->summary&&stu[index[k]]->grade[1] == stu[index[k + 1]]->grade[1] && stu[index[k]]->grade[2] < stu[index[k + 1]]->grade[2] || stu[index[k]]->summary == stu[index[k + 1]]->summary&&stu[index[k]]->grade[1] == stu[index[k + 1]]->grade[1] && stu[index[k]]->grade[2] == stu[index[k + 1]]->grade[2] && stu[index[k]]->grade[0] < stu[index[k + 1]]->grade[0])//排名交换的各种情况
					{
						temp = index[k];
						index[k] = index[k + 1];
						index[k + 1] = temp;
					}
			}
			outf.write((char*)&i, sizeof(i));
			for (j = 0;j < i;j++) {//在外部文件中进行排序
				strcpy_s(name, stu[index[j]]->name);
				code = stu[index[j]]->code;
				sex = stu[index[j]]->sex;
				int all;
				int score[3];
				int main[3];
				main[0] = stu[index[j]]->grade[0];
				main[1] = stu[index[j]]->grade[1];
				main[2] = stu[index[j]]->grade[2];
				score[0] = stu[index[j]]->getGrade3();
				score[1] = stu[index[j]]->getGrade4();
				score[2] = stu[index[j]]->getGrade5();
				all = stu[index[j]]->summary;
				outf.write((char*)&name, sizeof(name));
				outf.write((char*)&code, sizeof(code));
				outf.write((char*)&sex, sizeof(sex));
				outf.write((char*)&all, sizeof(all));
				outf.write((char*)&main[0], sizeof(main[0]));
				outf.write((char*)&main[1], sizeof(main[1]));
				outf.write((char*)&main[2], sizeof(main[2]));
				outf.write((char*)&score[0], sizeof(score[0]));
				outf.write((char*)&score[1], sizeof(score[1]));
				outf.write((char*)&score[2], sizeof(score[2]));
			}
			outf.close();
			ifstream inf(fileName2, ios::in | ios::binary);
			if (!inf) {
				cerr << "File could not be open." << endl;
				abort();
			}
			cout << "二进制文件中的学生信息（已排名）：" << endl;
			cout << "姓名 学号 性别（1为男性，2为女性）六科总分 英语成绩 中文成绩 数学成绩 物理(历史)成绩 化学(地理)成绩 生物(政治)成绩 " << endl;
			inf.read((char*)&i, sizeof(i));
			for (int j = 0;j < i;j++) {
				int score[3];
				int all;
				int main[3];
				inf.read((char*)&name, sizeof(name));//读取外部文件信息
				inf.read((char*)&code, sizeof(code));
				inf.read((char*)&sex, sizeof(sex));
				inf.read((char*)&all, sizeof(all));
				inf.read((char*)&main[0], sizeof(main[0]));
				inf.read((char*)&main[1], sizeof(main[1]));
				inf.read((char*)&main[2], sizeof(main[2]));
				inf.read((char*)&score[0], sizeof(score[0]));
				inf.read((char*)&score[1], sizeof(score[1]));
				inf.read((char*)&score[2], sizeof(score[2]));
				cout << name << " " << code << " " << sex << " " << all << " " << main[0] << " " << main[1] << " " << main[2] << " " << score[0] << " " << score[1] << " " << score[2] << endl;
			}
			inf.close();
		}
	}
	if (choose == 2) {
		cout << "模式选择：1、添加学生成绩 2、输出各科总分平均分 3、输出成绩单 4、打开文件" << endl;
		cout << "请输入模式编号，按回车键确认：";
		cin >> mode;
		outstuf.open(fileName1, ios::out);
		while (mode == 1)
		{
			cout << "请输入学生的类型（1为理科，2为文科）： ";
			cin >> type;
			if (type == 1)//理科生
			{
				cout << "请按如下格式输入学生成绩：" << endl;
				cout << "姓名 学号 性别（1为男性，2为女性） 英语成绩 中文成绩 数学成绩 物理成绩 化学成绩 生物成绩 " << endl;
				cin >> name >> code >> sex >> grade[0] >> grade[1] >> grade[2] >> grade[3] >> grade[4] >> grade[5];
				outstuf << name << " " << code << " " << sex << " " << grade[0] + grade[1] + grade[2] + grade[3] + grade[4] + grade[5] << " " << grade[0] << " " << grade[1] << " " << grade[2] << " " << grade[3] << " " << grade[4] << " " << grade[5] << '\n';
				stu2[i] = new science<double>(grade[0] + grade[1] + grade[2] + grade[3] + grade[4] + grade[5], name, code, sex, grade[0], grade[1], grade[2], grade[3], grade[4], grade[5]);//实例化
				t1 = i;

			}
			else if (type == 2)//文科生
			{
				cout << "请按如下格式输入学生成绩：" << endl;
				cout << "姓名 学号 性别（1为男性，2为女性） 英语成绩 中文成绩 数学成绩 历史成绩 地理成绩 政治成绩 " << endl;
				cin >> name >> code >> sex >> grade[0] >> grade[1] >> grade[2] >> grade[3] >> grade[4] >> grade[5];
				outstuf << name << " " << code << " " << sex << " " << grade[0] + grade[1] + grade[2] + grade[3] + grade[4] + grade[5] << " " << grade[0] << " " << grade[1] << " " << grade[2] << " " << grade[3] << " " << grade[4] << " " << grade[5] << '\n';
				stu2[i] = new art<double>(grade[0] + grade[1] + grade[2] + grade[3] + grade[4] + grade[5], name, code, sex, grade[0], grade[1], grade[2], grade[3], grade[4], grade[5]);//实例化
				t2 = i;

			}
			i++;
			cout << "模式选择：1、添加学生成绩 2、输出各科总分平均分 3、输出成绩单 4、打开文件" << endl;
			cout << "请输入模式编号，按回车键确认：";
			cin >> mode;

		}
		outstuf.close();
		if (mode == 2)
		{

			stu2[t1]->show();//调用理科生类中的show函数显示理科成绩
			stu2[t2]->show();//调用文科生类中的show函数显示文科成绩
			system("pause");
		}
		if (mode == 3)
		{

			cout << "排名" << endl;
			cout << "姓名 学号 性别（1为男性，2为女性）六科总分 英语成绩 中文成绩 数学成绩 物理(历史)成绩 化学(地理)成绩 生物(政治)成绩 " << endl;
			int index[100];//以下部分为对学生成绩进行排序
			int j, k;
			for (j = 0;j < 100;j++)
				index[j] = j;
			int temp;
			for (j = 1;j < i;j++)
			{
				for (k = 0;k <= i - 1 - j;k++)
					if (stu2[index[k]]->summary < stu2[index[k + 1]]->summary || stu2[index[k]]->summary == stu2[index[k + 1]]->summary&&stu2[index[k]]->grade[1] < stu2[index[k + 1]]->grade[1] || stu2[index[k]]->summary == stu2[index[k + 1]]->summary&&stu2[index[k]]->grade[1] == stu2[index[k + 1]]->grade[1] && stu2[index[k]]->grade[2] < stu2[index[k + 1]]->grade[2] || stu2[index[k]]->summary == stu2[index[k + 1]]->summary&&stu2[index[k]]->grade[1] == stu2[index[k + 1]]->grade[1] && stu2[index[k]]->grade[2] == stu2[index[k + 1]]->grade[2] && stu2[index[k]]->grade[0] < stu2[index[k + 1]]->grade[0])//排名交换的各种情况
					{
						temp = index[k];
						index[k] = index[k + 1];
						index[k + 1] = temp;
					}
			}
			for (j = 0;j < i;j++)
				stu2[index[j]]->print();//调用stu类中的print函数进行成绩排名的输出
		}
		if (mode == 4) {
			ifstream instuf(fileName1, ios::in);
			instuf.seekg(0, ios::beg);
			if (!instuf) {
				cerr << "File could not be open." << endl;
				abort();
			}
			outf.open(fileName2, ios::out | ios::binary);
			if (!outf)
			{
				cerr << "File could not be open." << endl;
				abort();
			}
			double score;
			cout << "文本文件中的学生信息（未排名）：" << endl;
			cout << "姓名 学号 性别（1为男性，2为女性）六科总分 英语成绩 中文成绩 数学成绩 物理(历史)成绩 化学(地理)成绩 生物(政治)成绩 " << endl;
			while (instuf >> name >> code >> sex >> score >> grade[0] >> grade[1] >> grade[2] >> grade[3] >> grade[4] >> grade[5]) {
				cout << name << " " << code << " " << sex << " " << score << " " << grade[0] << " " << grade[1] << " " << grade[2] << " " << grade[3] << " " << grade[4] << " " << grade[5] << endl;
			}
			instuf.close();
			int index[100];//以下部分为对学生成绩进行排序
			int j, k;
			for (j = 0;j < 100;j++)
				index[j] = j;
			int temp;
			for (j = 1;j < i;j++)
			{
				for (k = 0;k <= i - 1 - j;k++)
					if (stu2[index[k]]->summary < stu2[index[k + 1]]->summary || stu2[index[k]]->summary == stu2[index[k + 1]]->summary&&stu2[index[k]]->grade[1] < stu2[index[k + 1]]->grade[1] || stu2[index[k]]->summary == stu2[index[k + 1]]->summary&&stu2[index[k]]->grade[1] == stu2[index[k + 1]]->grade[1] && stu2[index[k]]->grade[2] < stu2[index[k + 1]]->grade[2] || stu2[index[k]]->summary == stu2[index[k + 1]]->summary&&stu2[index[k]]->grade[1] == stu2[index[k + 1]]->grade[1] && stu2[index[k]]->grade[2] == stu2[index[k + 1]]->grade[2] && stu2[index[k]]->grade[0] < stu2[index[k + 1]]->grade[0])//排名交换的各种情况
					{
						temp = index[k];
						index[k] = index[k + 1];
						index[k + 1] = temp;
					}
			}
			outf.write((char*)&i, sizeof(i));
			for (j = 0;j < i;j++) {
				strcpy_s(name, stu2[index[j]]->name);
				code = stu2[index[j]]->code;
				sex = stu2[index[j]]->sex;
				double all;
				double score[3];
				double main[3];
				main[0] = stu2[index[j]]->grade[0];//在外部文件中进行排序
				main[1] = stu2[index[j]]->grade[1];
				main[2] = stu2[index[j]]->grade[2];
				score[0] = stu2[index[j]]->getGrade3();
				score[1] = stu2[index[j]]->getGrade4();
				score[2] = stu2[index[j]]->getGrade5();
				all = stu2[index[j]]->summary;
				outf.write((char*)&name, sizeof(name));
				outf.write((char*)&code, sizeof(code));
				outf.write((char*)&sex, sizeof(sex));
				outf.write((char*)&all, sizeof(all));
				outf.write((char*)&main[0], sizeof(main[0]));
				outf.write((char*)&main[1], sizeof(main[1]));
				outf.write((char*)&main[2], sizeof(main[2]));
				outf.write((char*)&score[0], sizeof(score[0]));
				outf.write((char*)&score[1], sizeof(score[1]));
				outf.write((char*)&score[2], sizeof(score[2]));
			}
			outf.close();
			ifstream inf(fileName2, ios::in | ios::binary);
			if (!inf) {
				cerr << "File could not be open." << endl;
				abort();
			}
			cout << "二进制文件中的学生信息（已排名）：" << endl;
			cout << "姓名 学号 性别（1为男性，2为女性）六科总分 英语成绩 中文成绩 数学成绩 物理(历史)成绩 化学(地理)成绩 生物(政治)成绩 " << endl;
			inf.read((char*)&i, sizeof(i));
			for (int j = 0;j < i;j++) {
				double score[3];
				double all;
				double main[3];
				inf.read((char*)&name, sizeof(name));
				inf.read((char*)&code, sizeof(code));
				inf.read((char*)&sex, sizeof(sex));
				inf.read((char*)&all, sizeof(all));
				inf.read((char*)&main[0], sizeof(main[0]));
				inf.read((char*)&main[1], sizeof(main[1]));
				inf.read((char*)&main[2], sizeof(main[2]));
				inf.read((char*)&score[0], sizeof(score[0]));
				inf.read((char*)&score[1], sizeof(score[1]));
				inf.read((char*)&score[2], sizeof(score[2]));
				cout << name << " " << code << " " << sex << " " << all << " " << main[0] << " " << main[1] << " " << main[2] << " " << score[0] << " " << score[1] << " " << score[2] << endl;
			}
			inf.close();
		}
	}
	return 0;
}
