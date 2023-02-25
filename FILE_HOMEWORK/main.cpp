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
	//1)считываем строки из файла
	ifstream fin;
	fin.open("201 RAW.txt");//открываем файл
	if (fin.is_open())
	{
		string IP;
		string MAC;

		while (!fin.eof())//читать строки пока файл не пуст
		{
			//т.к после значения есть пробел строки будут выводится построчно в разные строки
			fin >> IP;
			fin >> MAC;
			//склеиваем строку
			one_stroka = MAC;
			one_stroka += "        ";
			one_stroka += IP;
			//добавляем строку в конец вектора
			vse_stroki.push_back(one_stroka);
		}
		fin.close();
	}
	else
	{
		std::cerr << "Error: File not found";
	}


	char filename[] = { "201 ready.txt" };//макс длинна файла
	ofstream fout;/*1) создаем поток*/
	fout.open(filename, std::ios_base::app);/*2) открываем поток, ios - добавляется в конец файла*/
	for (string a : vse_stroki) { fout << a << "\n"; }//записываем из вектора строки в файл
	fout.close();/*3) закрываем поток*/
	char sz_command[_MAX_FNAME] = "notepad ";/*инициализация строки значением notepad(загружаем строку в переменную)*/
	strcat_s(sz_command, _MAX_FNAME, filename);/*склеиваем строку с нотепад и названием имени*/
	system(sz_command);/*открываем тот же файл что и создали*/

#endif  HOME_WORK_1/*	 1. Есть файл 201 RAW.txt, из этого файла нужно создат
	другой файл 201 ready.txt,в котором столбик с IP - адресом
	 и MAC - адресом будут поменяны местами;*/


	

#ifdef  HOME_WORK_2//2. Из файла 201 RAW.txt создать файл формата 201.dhcpd	
	
	rename("201 ready.txt", "201.dhcpd");
#endif //HOME_WORK_2

	
}