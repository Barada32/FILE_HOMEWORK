#include <iostream>
#include<fstream>
#include <vector>
#include <string>

#define HOME_WORK_1
//#define HOME_WORK_2
using namespace std;
void main()
{

	setlocale(LC_ALL, "");


#ifdef HOME_WORK_1

	string one_stroka;
	vector<string> vse_stroki;
	//1)��������� ������ �� �����
	ifstream fin;
	fin.open("201 RAW.txt");//��������� ����
	if (fin.is_open())
	{
		string IP;
		string MAC;

		while (!fin.eof())//������ ������ ���� ���� �� ����
		{
			//�.� ����� �������� ���� ������ ������ ����� ��������� ��������� � ������ ������
			fin >> IP;
			fin >> MAC;
			//��������� ������
			one_stroka = MAC;
			one_stroka += "        ";
			one_stroka += IP;
			//��������� ������ � ����� �������
			vse_stroki.push_back(one_stroka);
		}
		fin.close();
	}
	else
	{
		std::cerr << "Error: File not found";
	}


	char filename[] = { "201 ready.txt" };//���� ������ �����
	ofstream fout;/*1) ������� �����*/
	fout.open(filename, std::ios_base::app);/*2) ��������� �����, ios - ����������� � ����� �����*/
	for (string a : vse_stroki) { fout << a << "\n"; }//���������� �� ������� ������ � ����
	fout.close();/*3) ��������� �����*/
	char sz_command[_MAX_FNAME] = "notepad ";/*������������� ������ ��������� notepad(��������� ������ � ����������)*/
	strcat_s(sz_command, _MAX_FNAME, filename);/*��������� ������ � ������� � ��������� �����*/
	system(sz_command);/*��������� ��� �� ���� ��� � �������*/

#endif  HOME_WORK_1/*	 1. ���� ���� 201 RAW.txt, �� ����� ����� ����� ������
	������ ���� 201 ready.txt,� ������� ������� � IP - �������
	 � MAC - ������� ����� �������� �������;*/


	

#ifdef  HOME_WORK_2//2. �� ����� 201 RAW.txt ������� ���� ������� 201.dhcpd	
	
	rename("201 ready.txt", "201.dhcpd");
#endif //HOME_WORK_2

	
}