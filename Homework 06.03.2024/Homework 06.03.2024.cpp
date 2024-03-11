// Homework 06.03.2024.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//




#include <iostream> 
#include <windows.h>
#include <io.h>
using namespace std;

void fileSearch(string path, string mask, int& count)
{
	string temp = path + "*.*";
	_finddata_t fileinfo;

	long long shapshot_number = _findfirst(temp.c_str(), &fileinfo);
	long long success = shapshot_number;

	while (success != -1)
	{
		string nameFile = fileinfo.name;
		if ((fileinfo.attrib & _A_SUBDIR) == 0)
		{
			
			if (nameFile != "." &&
				nameFile != ".." &&
				nameFile.substr(nameFile.find_last_of(".") + 1) == mask)
			{
				cout << path + nameFile << "\n";
				count++;
			}
			
		}
		else if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
		{
			string new_path = path;
			new_path += nameFile;
			new_path += "\\";
			fileSearch(new_path, mask, count);
		}
		

		success = _findnext(shapshot_number, &fileinfo);
	}

	_findclose(shapshot_number);
}

int main()
{
	int count = 0;
	fileSearch("C:\\Program Files\\", "txt", count);
	cout << "Total txt-files count: " << count << "\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
