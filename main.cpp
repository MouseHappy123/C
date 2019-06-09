#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
using namespace std;
template <typename T>//������ģ�� 
class student
{
public:
	T summary;//ѧ�����˵������ܷ֣���T���͵ı���
	char name[5];//ѧ������
	long code;//ѧ��
	int sex;//�Ա�
	T grade[3];//���˳ɼ���0ΪӢ�1Ϊ���ģ�2Ϊ��ѧ����T���͵ı���
	static T total[3];//ȫ������ܷ֣�0ΪӢ�1Ϊ���ģ�2Ϊ��ѧ����T���͵ľ�̬���ݳ�Ա
	static int count;//���ڼ���ѧ�������ļ�����
	student(T sum, char *str, long co, int se, T a, T b, T c) { summary = sum;strcpy_s(name, str);code = co;sex = se;grade[0] = a;grade[1] = b;grade[2] = c; }//��Ա�����Ǻ���ģ��
	virtual void show() const {//����չʾ�༶����ƽ���ֵ��麯��
		cout << "Ӣ���ܷ֣�" << total[0] << endl;
		cout << "�����ܷ֣�" << total[1] << endl;
		cout << "��ѧ�ܷ֣�" << total[2] << endl;
		cout << "Ӣ��ƽ���֣�" << total[0] / count << endl;
		cout << "����ƽ���֣�" << total[1] / count << endl;
		cout << "��ѧƽ���֣�" << total[2] / count << endl;
	}
	virtual void print() const {//����չʾѧ��������Ϣ���ɼ����麯��
		cout << name << " " << code << " " << sex << " " << summary << " " << grade[0] << " " << grade[1] << " " << grade[2] << " ";
	}
	virtual T getGrade3() const = 0;//���麯��
	virtual T getGrade4() const = 0;
	virtual T getGrade5() const = 0;
};
template <typename T> T student<T>::total[3] = { 0 };
template <typename T> int student<T>::count = 0;

template <typename T>//������ģ��
class science : public student<T>//���ѧ����
{
public:
	static int count1;//���ڼ���ѧ�������ļ�����
	static T total1[3];//ȫ����ƶ��п�Ŀ�ܷ֣�0Ϊ����1Ϊ��ѧ��2Ϊ����
	T grade1[3];//������ƶ��п�Ŀ������0Ϊ����1Ϊ��ѧ��2Ϊ����
	science(double sum, char *str, long co, int se, T a, T b, T c, T d, T e, T f) :student<T>(sum, str, co, se, a, b, c)//��Ա�����Ǻ���ģ��
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
	virtual void show() const {//����չʾ��������ּܷ�ƽ���ֵ��麯��
		student<T>::show();
		cout << "�����ܷ֣�" << total1[0] << endl;
		cout << "��ѧ�ܷ֣�" << total1[1] << endl;
		cout << "�����ܷ֣�" << total1[2] << endl;
		cout << "����ƽ���֣�" << total1[0] / count1 << endl;
		cout << "��ѧƽ���֣�" << total1[1] / count1 << endl;
		cout << "����ƽ���֣�" << total1[2] / count1 << endl;
	}
	virtual void print() const {//����չʾ���ѧ����Ϣ�����˳ɼ����麯��
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

template <typename T>//������ģ��
class art : public student<T>//�Ŀ�ѧ����
{
public:
	static int count2;//���ڼ���ѧ�������ļ�����
	static T total2[3];//ȫ���Ŀƶ��п�Ŀ�ܷ֣�0Ϊ��ʷ��1Ϊ����2Ϊ����
	T grade2[3];//�����Ŀƶ��п�Ŀ������0Ϊ��ʷ��1Ϊ����2Ϊ����
	art(double sum, char *str, long co, int se, T a, T b, T c, T d, T e, T f) :student<T>(sum, str, co, se, a, b, c)//��Ա�����Ǻ���ģ��
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
	virtual	void show() const {//����չʾ�Ŀ������ּܷ�ƽ���ֵ��麯��

		cout << "��ʷ�ܷ֣�" << total2[0] << endl;
		cout << "�����ܷ֣�" << total2[1] << endl;
		cout << "�����ܷ֣�" << total2[2] << endl;
		cout << "��ʷƽ���֣�" << total2[0] / count2 << endl;
		cout << "����ƽ���֣�" << total2[1] / count2 << endl;
		cout << "����ƽ���֣�" << total2[2] / count2 << endl;
	}
	virtual void print() const {//����չʾ�Ŀ�ѧ����Ϣ�����˳ɼ����麯��
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
	student<int> *stu[100];//ʵ����int���͵�ָ������
	student<double> *stu2[100];//ʵ����double���͵�ָ������
	char name[30];//ѧ������
	long code;//ѧ��
	int sex;//�Ա�
	double grade[6];
	int mode, type, choose;//���ڽ���ģʽѡ��ı���
	int i = 0;
	int t1, t2;//�ֱ�洢�����ѧ����˳��
	cout << "������洢ѧ���ɼ����ı��ļ���(.txt)��" << endl;
	char fileName1[30];
	cin >> fileName1;
	cout << "������洢ѧ���ɼ��Ķ������ļ���(.dat)��" << endl;
	char fileName2[30];
	cin >> fileName2;
	cout << "��ѡ���������ͣ�1.���� 2.double��" << endl;
	cin >> choose;// choose = 1 Ϊ���ͣ�choose = 2 Ϊdouble�� 
	if (choose == 1) {
		cout << "ģʽѡ��1�����ѧ���ɼ� 2����������ܷ�ƽ���� 3������ɼ��� 4�����ļ�" << endl;
		cout << "������ģʽ��ţ����س���ȷ�ϣ�";
		cin >> mode;
		outstuf.open(fileName1, ios::out);//���ļ�
		while (mode == 1)
		{

			if (!outstuf)
			{
				cerr << "File could not be open." << endl;
				abort();
			}
			cout << "������ѧ�������ͣ�1Ϊ��ƣ�2Ϊ�Ŀƣ��� ";
			cin >> type;
			if (type == 1)//�����
			{
				cout << "�밴���¸�ʽ����ѧ���ɼ���" << endl;
				cout << "���� ѧ�� �Ա�1Ϊ���ԣ�2ΪŮ�ԣ� Ӣ��ɼ� ���ĳɼ� ��ѧ�ɼ� ����ɼ� ��ѧ�ɼ� ����ɼ� " << endl;
				cin >> name >> code >> sex >> grade[0] >> grade[1] >> grade[2] >> grade[3] >> grade[4] >> grade[5];
				outstuf << name << " " << code << " " << sex << " " << grade[0] + grade[1] + grade[2] + grade[3] + grade[4] + grade[5] << " " << grade[0] << " " << grade[1] << " " << grade[2] << " " << grade[3] << " " << grade[4] << " " << grade[5] << '\n';//�����ݴ����ⲿ�ļ���
				stu[i] = new science<int>(grade[0] + grade[1] + grade[2] + grade[3] + grade[4] + grade[5], name, code, sex, grade[0], grade[1], grade[2], grade[3], grade[4], grade[5]);//ʵ����
				t1 = i;
			}
			else if (type == 2)//�Ŀ���
			{
				cout << "�밴���¸�ʽ����ѧ���ɼ���" << endl;
				cout << "���� ѧ�� �Ա�1Ϊ���ԣ�2ΪŮ�ԣ� Ӣ��ɼ� ���ĳɼ� ��ѧ�ɼ� ��ʷ�ɼ� ����ɼ� ���γɼ� " << endl;
				cin >> name >> code >> sex >> grade[0] >> grade[1] >> grade[2] >> grade[3] >> grade[4] >> grade[5];
				outstuf << name << " " << code << " " << sex << " " << grade[0] + grade[1] + grade[2] + grade[3] + grade[4] + grade[5] << " " << grade[0] << " " << grade[1] << " " << grade[2] << " " << grade[3] << " " << grade[4] << " " << grade[5] << '\n';//�����ݴ����ⲿ�ļ���
				stu[i] = new art<int>(grade[0] + grade[1] + grade[2] + grade[3] + grade[4] + grade[5], name, code, sex, grade[0], grade[1], grade[2], grade[3], grade[4], grade[5]);//ʵ����
				t2 = i;
			}
			i++;
			cout << "ģʽѡ��1�����ѧ���ɼ� 2����������ܷ�ƽ���� 3������ɼ��� 4�����ļ�" << endl;
			cout << "������ģʽ��ţ����س���ȷ�ϣ�";
			cin >> mode;
		}
		outstuf.close();
		if (mode == 2)
		{
			stu[t1]->show();//������������е�show������ʾ��Ƴɼ�
			stu[t2]->show();//�����Ŀ������е�show������ʾ�ĿƳɼ�
			system("pause");
		}
		if (mode == 3)
		{
			cout << "����" << endl;
			cout << "���� ѧ�� �Ա�1Ϊ���ԣ�2ΪŮ�ԣ������ܷ� Ӣ��ɼ� ���ĳɼ� ��ѧ�ɼ� ����(��ʷ)�ɼ� ��ѧ(����)�ɼ� ����(����)�ɼ� " << endl;
			int index[100];//���²���Ϊ��ѧ���ɼ���������
			int j, k;
			for (j = 0;j < 100;j++)
				index[j] = j;
			int temp;
			for (j = 1;j < i;j++)
			{
				for (k = 0;k <= i - 1 - j;k++)
					if (stu[index[k]]->summary < stu[index[k + 1]]->summary || stu[index[k]]->summary == stu[index[k + 1]]->summary&&stu[index[k]]->grade[1] < stu[index[k + 1]]->grade[1] || stu[index[k]]->summary == stu[index[k + 1]]->summary&&stu[index[k]]->grade[1] == stu[index[k + 1]]->grade[1] && stu[index[k]]->grade[2] < stu[index[k + 1]]->grade[2] || stu[index[k]]->summary == stu[index[k + 1]]->summary&&stu[index[k]]->grade[1] == stu[index[k + 1]]->grade[1] && stu[index[k]]->grade[2] == stu[index[k + 1]]->grade[2] && stu[index[k]]->grade[0] < stu[index[k + 1]]->grade[0])//���������ĸ������
					{
						temp = index[k];
						index[k] = index[k + 1];
						index[k + 1] = temp;
					}
			}
			for (j = 0;j < i;j++)
				stu[index[j]]->print();//����stu���е�print�������гɼ����������
		}
		if (mode == 4) {
			ifstream instuf(fileName1, ios::in);//��ȡ�ⲿ�ļ�����
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
			cout << "�ı��ļ��е�ѧ����Ϣ��δ��������" << endl;
			cout << "���� ѧ�� �Ա�1Ϊ���ԣ�2ΪŮ�ԣ������ܷ� Ӣ��ɼ� ���ĳɼ� ��ѧ�ɼ� ����(��ʷ)�ɼ� ��ѧ(����)�ɼ� ����(����)�ɼ� " << endl;
			while (instuf >> name >> code >> sex >> score >> grade[0] >> grade[1] >> grade[2] >> grade[3] >> grade[4] >> grade[5]) {//����ⲿ�ļ��е�����
				cout << name << " " << code << " " << sex << " " << score << " " << grade[0] << " " << grade[1] << " " << grade[2] << " " << grade[3] << " " << grade[4] << " " << grade[5] << endl;
			}
			instuf.close();
			int index[100];//���²���Ϊ��ѧ���ɼ���������
			int j, k;
			for (j = 0;j < 100;j++)
				index[j] = j;
			int temp;
			for (j = 1;j < i;j++)
			{
				for (k = 0;k <= i - 1 - j;k++)
					if (stu[index[k]]->summary < stu[index[k + 1]]->summary || stu[index[k]]->summary == stu[index[k + 1]]->summary&&stu[index[k]]->grade[1] < stu[index[k + 1]]->grade[1] || stu[index[k]]->summary == stu[index[k + 1]]->summary&&stu[index[k]]->grade[1] == stu[index[k + 1]]->grade[1] && stu[index[k]]->grade[2] < stu[index[k + 1]]->grade[2] || stu[index[k]]->summary == stu[index[k + 1]]->summary&&stu[index[k]]->grade[1] == stu[index[k + 1]]->grade[1] && stu[index[k]]->grade[2] == stu[index[k + 1]]->grade[2] && stu[index[k]]->grade[0] < stu[index[k + 1]]->grade[0])//���������ĸ������
					{
						temp = index[k];
						index[k] = index[k + 1];
						index[k + 1] = temp;
					}
			}
			outf.write((char*)&i, sizeof(i));
			for (j = 0;j < i;j++) {//���ⲿ�ļ��н�������
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
			cout << "�������ļ��е�ѧ����Ϣ������������" << endl;
			cout << "���� ѧ�� �Ա�1Ϊ���ԣ�2ΪŮ�ԣ������ܷ� Ӣ��ɼ� ���ĳɼ� ��ѧ�ɼ� ����(��ʷ)�ɼ� ��ѧ(����)�ɼ� ����(����)�ɼ� " << endl;
			inf.read((char*)&i, sizeof(i));
			for (int j = 0;j < i;j++) {
				int score[3];
				int all;
				int main[3];
				inf.read((char*)&name, sizeof(name));//��ȡ�ⲿ�ļ���Ϣ
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
		cout << "ģʽѡ��1�����ѧ���ɼ� 2����������ܷ�ƽ���� 3������ɼ��� 4�����ļ�" << endl;
		cout << "������ģʽ��ţ����س���ȷ�ϣ�";
		cin >> mode;
		outstuf.open(fileName1, ios::out);
		while (mode == 1)
		{
			cout << "������ѧ�������ͣ�1Ϊ��ƣ�2Ϊ�Ŀƣ��� ";
			cin >> type;
			if (type == 1)//�����
			{
				cout << "�밴���¸�ʽ����ѧ���ɼ���" << endl;
				cout << "���� ѧ�� �Ա�1Ϊ���ԣ�2ΪŮ�ԣ� Ӣ��ɼ� ���ĳɼ� ��ѧ�ɼ� ����ɼ� ��ѧ�ɼ� ����ɼ� " << endl;
				cin >> name >> code >> sex >> grade[0] >> grade[1] >> grade[2] >> grade[3] >> grade[4] >> grade[5];
				outstuf << name << " " << code << " " << sex << " " << grade[0] + grade[1] + grade[2] + grade[3] + grade[4] + grade[5] << " " << grade[0] << " " << grade[1] << " " << grade[2] << " " << grade[3] << " " << grade[4] << " " << grade[5] << '\n';
				stu2[i] = new science<double>(grade[0] + grade[1] + grade[2] + grade[3] + grade[4] + grade[5], name, code, sex, grade[0], grade[1], grade[2], grade[3], grade[4], grade[5]);//ʵ����
				t1 = i;

			}
			else if (type == 2)//�Ŀ���
			{
				cout << "�밴���¸�ʽ����ѧ���ɼ���" << endl;
				cout << "���� ѧ�� �Ա�1Ϊ���ԣ�2ΪŮ�ԣ� Ӣ��ɼ� ���ĳɼ� ��ѧ�ɼ� ��ʷ�ɼ� ����ɼ� ���γɼ� " << endl;
				cin >> name >> code >> sex >> grade[0] >> grade[1] >> grade[2] >> grade[3] >> grade[4] >> grade[5];
				outstuf << name << " " << code << " " << sex << " " << grade[0] + grade[1] + grade[2] + grade[3] + grade[4] + grade[5] << " " << grade[0] << " " << grade[1] << " " << grade[2] << " " << grade[3] << " " << grade[4] << " " << grade[5] << '\n';
				stu2[i] = new art<double>(grade[0] + grade[1] + grade[2] + grade[3] + grade[4] + grade[5], name, code, sex, grade[0], grade[1], grade[2], grade[3], grade[4], grade[5]);//ʵ����
				t2 = i;

			}
			i++;
			cout << "ģʽѡ��1�����ѧ���ɼ� 2����������ܷ�ƽ���� 3������ɼ��� 4�����ļ�" << endl;
			cout << "������ģʽ��ţ����س���ȷ�ϣ�";
			cin >> mode;

		}
		outstuf.close();
		if (mode == 2)
		{

			stu2[t1]->show();//������������е�show������ʾ��Ƴɼ�
			stu2[t2]->show();//�����Ŀ������е�show������ʾ�ĿƳɼ�
			system("pause");
		}
		if (mode == 3)
		{

			cout << "����" << endl;
			cout << "���� ѧ�� �Ա�1Ϊ���ԣ�2ΪŮ�ԣ������ܷ� Ӣ��ɼ� ���ĳɼ� ��ѧ�ɼ� ����(��ʷ)�ɼ� ��ѧ(����)�ɼ� ����(����)�ɼ� " << endl;
			int index[100];//���²���Ϊ��ѧ���ɼ���������
			int j, k;
			for (j = 0;j < 100;j++)
				index[j] = j;
			int temp;
			for (j = 1;j < i;j++)
			{
				for (k = 0;k <= i - 1 - j;k++)
					if (stu2[index[k]]->summary < stu2[index[k + 1]]->summary || stu2[index[k]]->summary == stu2[index[k + 1]]->summary&&stu2[index[k]]->grade[1] < stu2[index[k + 1]]->grade[1] || stu2[index[k]]->summary == stu2[index[k + 1]]->summary&&stu2[index[k]]->grade[1] == stu2[index[k + 1]]->grade[1] && stu2[index[k]]->grade[2] < stu2[index[k + 1]]->grade[2] || stu2[index[k]]->summary == stu2[index[k + 1]]->summary&&stu2[index[k]]->grade[1] == stu2[index[k + 1]]->grade[1] && stu2[index[k]]->grade[2] == stu2[index[k + 1]]->grade[2] && stu2[index[k]]->grade[0] < stu2[index[k + 1]]->grade[0])//���������ĸ������
					{
						temp = index[k];
						index[k] = index[k + 1];
						index[k + 1] = temp;
					}
			}
			for (j = 0;j < i;j++)
				stu2[index[j]]->print();//����stu���е�print�������гɼ����������
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
			cout << "�ı��ļ��е�ѧ����Ϣ��δ��������" << endl;
			cout << "���� ѧ�� �Ա�1Ϊ���ԣ�2ΪŮ�ԣ������ܷ� Ӣ��ɼ� ���ĳɼ� ��ѧ�ɼ� ����(��ʷ)�ɼ� ��ѧ(����)�ɼ� ����(����)�ɼ� " << endl;
			while (instuf >> name >> code >> sex >> score >> grade[0] >> grade[1] >> grade[2] >> grade[3] >> grade[4] >> grade[5]) {
				cout << name << " " << code << " " << sex << " " << score << " " << grade[0] << " " << grade[1] << " " << grade[2] << " " << grade[3] << " " << grade[4] << " " << grade[5] << endl;
			}
			instuf.close();
			int index[100];//���²���Ϊ��ѧ���ɼ���������
			int j, k;
			for (j = 0;j < 100;j++)
				index[j] = j;
			int temp;
			for (j = 1;j < i;j++)
			{
				for (k = 0;k <= i - 1 - j;k++)
					if (stu2[index[k]]->summary < stu2[index[k + 1]]->summary || stu2[index[k]]->summary == stu2[index[k + 1]]->summary&&stu2[index[k]]->grade[1] < stu2[index[k + 1]]->grade[1] || stu2[index[k]]->summary == stu2[index[k + 1]]->summary&&stu2[index[k]]->grade[1] == stu2[index[k + 1]]->grade[1] && stu2[index[k]]->grade[2] < stu2[index[k + 1]]->grade[2] || stu2[index[k]]->summary == stu2[index[k + 1]]->summary&&stu2[index[k]]->grade[1] == stu2[index[k + 1]]->grade[1] && stu2[index[k]]->grade[2] == stu2[index[k + 1]]->grade[2] && stu2[index[k]]->grade[0] < stu2[index[k + 1]]->grade[0])//���������ĸ������
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
				main[0] = stu2[index[j]]->grade[0];//���ⲿ�ļ��н�������
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
			cout << "�������ļ��е�ѧ����Ϣ������������" << endl;
			cout << "���� ѧ�� �Ա�1Ϊ���ԣ�2ΪŮ�ԣ������ܷ� Ӣ��ɼ� ���ĳɼ� ��ѧ�ɼ� ����(��ʷ)�ɼ� ��ѧ(����)�ɼ� ����(����)�ɼ� " << endl;
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
