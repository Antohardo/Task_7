#include <iostream> 
#include <cstdlib> 
#include <fstream> 
#include <string>
#include <Windows.h>
#include <conio.h>
void Encode(char*,char*,int); //�����������
void Decode(char*, char*,int); //������������
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	while (1)
	{
		int l = 0;
		cout << "�������� ��������: 1 - ������; 0 - �����." << endl;
		cout << ">";
		cin >> l;
		if (l != 1)
		{
			break;
		}
		system("cls");
		int choice,n;
		char str [1000];
		string msg;
		char s1;
		int k = 0;
		char alpha[] = "qwertyuiopasdfghjklzxcvbnm";

		cout << "�������� ��������: " << endl;
		cout << "1.����������\n2. ������������\n0. �����\n >";
		cin >> choice;
		if ((choice < 0) or (choice > 2))
		{
			do
			{
				system("cls");
				cout << "Error" << endl;
				cout << "�� ����� �� ������ ��������.���������� �����." << endl;
				cout << "1.����������\n2. ������������\n0. �����\n >";
				cin >> choice;
				

			} while ((choice < 0) or (choice > 2));
		}
		switch (choice)
		{
		 case 1:
		{   cout << "1-����� ����� �� �����.\n2-������ ����� � ����������.\n0-�����.\n>";
		cin >> n;
		if ((n < 0) or (n > 2))
		{
			do
			{
				system("cls");
				cout << "Error" << endl;
				cout << "�� ����� �� �� ��������.���������� �����." << endl;
				cout << "1-����� ����� �� �����.\n2-������ ����� � ����������.\n0-�����.\n>";
				cin >> n;


			} while ((n < 0) or (n > 2));
		}
		switch (n)
		{
		case 1:
		{
			string path = "MyFile.txt";
			fstream fs;
			fs.open(path, fstream::in | fstream::out | fstream::app);
			if (!fs.is_open())
			{
				cout << "Error! ������ �������� �����!" << endl;
			}
			else
			{
				cout << "���� ������� ������." << endl;
				while (!fs.eof())
				{
					msg = "";
					fs >> str[k];
					k++;
				}
				Encode(str, alpha, k);
				cout << endl;
				
				
			}
			fs.close();	
			break;
		}
		case 2:
		{
			cout << "������� ����� ��� ����������: ";
			cin.get(s1);
			while (cin.get(s1))
			{
				if (s1 == '\n') break;
				str[k] = s1;
				k++;
			}

			cout << "������.���� �����: ";
			Encode(str, alpha, k);
			break;
		}
		case 0: break;
		}
		break;
		}
		case 2:
		{

			cout << "������� ����� ��� �����������: ";
			cin.get(s1);
			while (cin.get(s1))
			{
				if (s1 == '\n') break;
				str[k] = s1;
				k++;
			}
			
			cout << "������.���� �����: ";
			Decode(str, alpha,k);
			break;
		}
		case 0: break;

		}
		cout << endl;
	}
	return 0;
}





void Encode(char* str,char* alpha, int k)
{
	char* slovo = new char[k];
	int m;
	char alfvit[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
	for (int l = 0;l < k;l++)
	{
		for (int i = 0;i < strlen(alfvit) ;i++)
		{
			if (str[l] == alfvit[i])
			{
				m = i;
			}
		}
		slovo[l] = alpha[m];
	}

	for (int i = 0;i < k;i++)
	{
		cout << slovo[i];
	}
	delete[] slovo;
}

void Decode(char* str, char* alpha,int k)
{
	char* slovo = new char[k];
	int m;
	char alfvit[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0' };


	for (int l = 0;l < k;l++)
	{
		for (int i = 0;i < strlen(alfvit);i++)
		{
			if (str[l] == alpha[i])
			{
				m = i;
			}
		}
		slovo[l] = alfvit[m];

	}

	for (int i = 0;i < k;i++)
	{
		cout << slovo[i];
	}
	delete[] slovo;
}























