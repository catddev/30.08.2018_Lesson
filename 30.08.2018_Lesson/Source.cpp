#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>

using namespace std;

//case3
void add_num(int *&a, int &n, int value) {
	int *tmp, *p, *p1; // p1 is pointer to tmp
	tmp = new int[n + 1];

	for (p = a, p1 = tmp; p < a + n; p++, p1++)
		*p1 = *p;

	*p1 = value;
	/*tmp[n] = value;*/ // the same

	if (n!=0) delete[] a;
	a = tmp;
	n++;
}
//case 3
void erase(int* &a, int &n, int value) {
	int k = -1;
	for (int i = 0; i < n; i++)
		if (a[i] == value) k = i;
	if (k < 0) return;
	int *tmp;
	int j = 0;
	tmp = new int[n - 1];
	for (int i = 0; i < n; i++)
		if (a[i] != value)
			tmp[j++] = a[i];
	delete[] a;
	a = tmp;
	n = j;
}


bool asc(int a, int b) {
	return (a > b);
}
bool desc(int a, int b) {
	return (a < b);
}
void sort_array(int *a, int n, bool(*f)(int, int)) {
	for (int pass = 0; pass < n - 1; pass++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (f(a[i], a[i + 1])) //
				swap(a[i], a[i + 1]);
		}
	}
}
// 20.	*Написать программу, которая содержит функцию,
// принимающую в качестве аргумента, указатель на массив и размер массива, и заменяет все отрицательные элементы на 0.
void arr_neg(int *a, int n) {
	for (int* p = a; p < a+ n; p++)
		if (*p < 0) *p = 0;
}
// 21.	*Написать программу, которая содержит функцию,
// принимающую в качестве аргумента, указатель на массив и размер массива, и заменяет все четные элементы на -1.
void arr_even(int *a, int n) {
	for (int* p = a; p < a + n; p++)
		if ((p-a) % 2 == 0) *p = -1;
}
// 22.	*Написать программу, которая содержит функцию,
// принимающую в качестве аргумента, указатель на массив и размер массива, и заменяет все кратные 4 элементы на 999.
void el_4(int *a, int n) {
	for (int* p = a; p < a + n; p++)
		if (*p % 4 == 0) *p = 999;
}
// 23.	***Написать функцию, которая получает указатель на динамический массив и его размер.
//Функция должна удалить из массива все простые числа и вернуть указатель на новый динамический массив.
void erase_prime(int *&a, int &n) {
	int *tmp;
	int k = 0, b = 0;

	for (int* p = a; p < a + n; p++)
		for (int j = 2; j < *p; j++)
			if (*p % j == 0)
			{
				k++;
				break;
			}
	cout << k << endl;

	tmp = new int[k];

	for (int* p = a; p < a + n; p++)
		for (int j = 2; j < *p; j++)
			if (*p % j == 0)
			{
				tmp[b++] = *p;
				break;
			}

	delete[] a;
	a = tmp;
	n = k;
}
//12. Написать функцию, которая принимает два указателя и возвращает указатель на меньшее число
int* min_pointer(int *p, int *p1) {
	if (*p > *p1) return p1;
	else return p;
}
// 29 и 30 объединить
// **Написать функцию, которая принимает указатель на массив и количество элементов
// и возвращает минимальный элемент массива(значение и номер элемента).
// (30)... и возвращает максимальный элемент массива(значение и номер элемента).
void min(int* a, int n) {
	int min = INT_MAX;
	int *p = a;
	int imin;

	for (; p < a + n; p++)
	{
		if (*p < min) {
			imin = p - a;
			min = *p;
		}
	}
		
	cout << "min a[" << imin << "] = " << min << endl;
}
void max(int* a, int n) {
	int max = INT_MIN;
	int *p = a;
	int imax;

	for (; p < a + n; p++)
	{
		if (*p > max) {
			imax = p - a;
			max = *p;
		}
	}

	cout << "max a[" << imax << "] = " << max << endl;
}

int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn;

		switch (tn)
		{
		case 1:
		{
			int n, m;
			cin >> n >> m;

			int **a;
			a = new int*[n];

			for (int i = 0; i < n; i++) // создали динамическую матрицу
				a[i] = new int[m];

			for (int i = 0; i < n; i++)// random
			{
				for (int j = 0; j < m; j++)
				{
					a[i][j] = rand() % 26;
					cout << setw(5) << a[i][j];
				}
				cout << endl;
			}
					
			for (int i = 0; i < n; i++) // для удаления матрицы
				delete[] a[i]; // сначала удалить каждый подмассив
			delete[] a; // затем только массив указателей
		}
		break;
		case 2:
		{
			// 16.	**Напишите программу, которая создает массив указателей. Каждый из которых ссылается на динамический массив из 10 элементов.
			// Каждый из этих массивов заполняется случайным образом в диапазоне от 1 до 12. Каждое число – это оценка по 12 системе.
			// Необходимо посчитать для каждой строки массива указателей количество пятерок.
			// Пятерка от 10 до 12 включительно.

			int **a;
			int n;
			cin >> n;
			int k = 0;
			a = new int*[n];

			for (int i = 0; i < n; i++) 
				a[i] = new int[10];

			for (int i = 0; i < n; i++)
			{
				k = 0;
				for (int j = 0; j < 10; j++)
				{
					a[i][j] = rand() % 12;
					cout << setw(4) << a[i][j];
					if (a[i][j] > 9 && a[i][j] <= 12) k++;
				}
				cout << "   |   " << k;
				cout << endl;
			}
			cout << endl;
			for (int i = 0; i < n; i++) 
				delete[] a[i]; 
			delete[] a;
		}
		break;
		case 3:
		{
			// 18.	**Написать программу «телефонный справочник». Создайте массив целых чисел, каждое число – это номер телефона.
			// Напишите функции для добавления нового телефона в массив,
			// для удаления указанного телефона из справочника
			// поиск телефона по номеру.
			// Создайте меню для пользователя.

			int *a;
			int n = 0;
			/*a = new int[n];*/
			/*for (int *p = a; p<a+n; p++)
			{
				*p = rand() % 9999999 + 7000000;
				cout << setw(3) << *p <<"    ";
			}
			cout << endl;*/

			add_num(a, n, 5);
			add_num(a, n, 6);
			add_num(a, n, 16);
			add_num(a, n, 12);
			add_num(a, n, 12);

			for (int i = 0; i < n; i++)
				cout << a[i] <<" ";
			cout << endl;

			erase(a, n, 4);
			erase(a, n, 12);
			for (int i = 0; i < n; i++)
				cout << a[i] << " ";
			cout << endl;
			/*delete[] a;*/
		}
		break;
		case 4:
		{
			// написать сортировку, в которой можно самим задать порядок сортировки
			// принимает размер массива

			int* a;
			int n = 12;
			a = new int[n];

			for (int i = 0; i < n; i++)
			{
				a[i] = rand() % 12;
				cout << a[i] << " ";
			}
			cout << endl;

			/*sort_array(a, n, desc);*/
			/*sort_array(a, n, asc);*/
			
			bool(*fs[2])(int, int) = { asc, desc };
			int choice;
			while (true)
			{
				cin >> choice;
				if (choice < 0 || choice>2) break;

				sort_array(a, n, *fs[choice]);

				for (int i = 0; i < n; i++)
					cout << a[i] << " ";
				cout << endl << endl;
			}
		}
		break;
		case 5:
		{
			int *a;
			int n = 5;
			a = new int[n];

			for (int* p = a; p<a + n; p++)
			{
				*p = rand() % 31 - 20;

				cout << *p << " ";
			}
			cout << endl;

			arr_neg(a, n);

			for (int* p = a; p<a + n; p++)
			{
				cout << *p << " ";
			}
			cout << endl << endl;
			delete[] a;
		}
		break;
		case 6:
		{
			int *a;
			int n = 5;
			a = new int[n];

			for (int* p=a; p<a+n; p++)
			{
				*p = rand() % 31 - 20;

				cout << *p << " ";
			}
			cout << endl;

			arr_even(a, n);

			for (int* p = a; p<a + n; p++)
			{
				cout << *p << " ";
			}
			cout << endl << endl;
			delete[] a;
		}
		break;
		case 7:
		{
			int *a;
			int n = 5;
			a = new int[n];

			for (int* p = a; p<a + n; p++)
			{
				*p = rand() % 31 - 20;

				cout << *p << " ";
			}
			cout << endl;

			el_4(a, n);

			for (int* p = a; p<a + n; p++)
			{
				cout << *p << " ";
			}
			cout << endl << endl;
			delete[] a;
		}
		break;
		case 8:
		{
			int *a;
			int n = 10;
			a = new int[n];

			for (int* p = a; p<a + n; p++)
			{
				*p = rand() % 100;
				cout << *p << " ";
			}
			cout << endl;

			erase_prime(a, n);

			for (int* p = a; p<a + n; p++)
			{
				cout << *p << " ";
			}
			cout << endl << endl;
			delete[] a;
		}
		break;
		case 9:
		{
			int *a, *b;
			int n = 7, m = 10;
			a = &n, b = &m;
			cout << *min_pointer(a, b) << endl;
		}
		break;
		case 10:
		{
			int *a;
			int n = 10;
			a = new int[10];

			for (int* p = a; p<a + n; p++)
			{
				*p = rand() % 100;
				cout << *p << " ";
			}
			cout << endl;

			void(*f[2])(int*, int) = { min, max };
			int choice;
			while (true)
			{
				cin >> choice;
				if (choice < 0 || choice>2) break;

				f[choice](a, n);
			}

		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}