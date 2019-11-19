#include "Laba4.h"


void Zadacha1_1()
{
	cout << "Input string: " << endl;
	char *str = new char[256];
	while (str[0] < 0 || str[0] == '\0') cin.getline(str, 256);
	int length = Strlength(str);
	int k = 0;
	if (length % 2 == 0)  k = 1;
	else  k = 2;

	if (isPolind(str, length))
	{
		cout << "Str is Polid" << endl;
		return;
	}

	int i = 0, count = 0;
	while (!isPolind(str, length))
	{
		bool f = true;
		for (int j = length / 2, q = length - 1, p = length - 2; ; j--, q++)
		{
			if (f)
			{
				f = false;
				if (str[j - 1] == str[j + 1])
				{
					if (k == 2 && !isPolind(str, length + 1)) continue;
					CreatPolid(str, length);
					return;
				}
			}
			else
			{
				str[q] = str[p--];
				count++;
				if (q == (length - 1) * 2) break;
			}
		}

		for (int i = 0; i < count + length; i++) cout << str[i];
		cout << endl;
		return;
	}
}

bool isPolind(char* str, int length)
{
	for (int i = 0, j = length - 1; i < length / 2; i++, j--)
	{
		if (str[i] != str[j]) return false;
	}

	return true;
}

void CreatPolid(char* str, int length)
{
	int p = 0, count = 0;
	for (int j = length / 2 - 1, q = length - 1; j != -1; j--)
	{
		str[q++] = str[j];
		count = q;
		if (isPolind(str, count)) break;
	}
	for (int i = 0; i < count + length; i++)
	{
		cout << str[i];
		if (str[i] == str[count]) break;
	}
	cout << endl;
}

int Strlength(char* str)
{
	int i = 0;
	while (str[i] != '\0') i++;
	return i;
}


void Zadacha1_2()
{
	srand(time(NULL));
	cout << "Imput size of array: " << endl;
	int sizeArr = 0;
	cin >> sizeArr;
	if (cin.fail())
	{
		cin.clear(); 
		cin.ignore(32767, '\n');
		cout << "Incorrect input! Try again!" << endl;
		cin >> sizeArr;
	}

	int* arr = new int[sizeArr];
	for (int i = 0; i < sizeArr; i++) arr[i] = rand() % 10;

	int sizeArrRes = 0;

	int** arrRes = new int*[sizeArr * sizeArr];
	for (int i = 0; i < sizeArr * sizeArr; i++) arrRes[i] = new int[3];

	cout << "Your arr: " << endl;
	for (int i = 0; i < sizeArr; i++) { cout << arr[i] << " "; if (i != 0 && i % 10 == 0) cout << endl; }

	Logic(sizeArr, arr, arrRes, sizeArrRes);

	cout << endl << endl;
	for (int i = 0; i < sizeArrRes; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arrRes[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Logic(int sizeArr, int *arr, int **arrRes, int &sizearrRes)
{
	for (int i = 0; i < sizeArr; i++)
	{
		for (int j = 0; j < sizeArr; j++)
		{
			for (int g = 0; g < sizeArr; g++)
			{
				if (i == j || i == g || g == j) break;
				int mx = max(max(arr[i], arr[g]), arr[j]);
				if (mx == arr[i])
				{
					if (mx > arr[j] + arr[g]) continue;
					if (mx * mx > arr[j] * arr[j] + arr[g] * arr[g])
					{
						bool flag = false;
						for (int q = 0; q < sizearrRes; q++)
						{
							if (!isRepeat(mx, arr[j], arr[g], arrRes[q]))
								flag = true;
						}
						if (flag) continue;
						arrRes[sizearrRes][0] = mx;
						arrRes[sizearrRes][1] = arr[j];
						arrRes[sizearrRes++][2] = arr[g];
					}
				}
				else
				{
					if (mx == arr[j])
					{
						if (mx > arr[i] + arr[g]) continue;
						if (mx * mx > arr[i] * arr[i] + arr[g] * arr[g])
						{
							bool flag = false;
							for (int q = 0; q < sizearrRes; q++)
							{
								if (!isRepeat(mx, arr[i], arr[g], arrRes[q]))
									flag = true;
							}
							if (flag) continue;

							arrRes[sizearrRes][0] = mx;
							arrRes[sizearrRes][1] = arr[i];
							arrRes[sizearrRes++][2] = arr[g];
						}
					}
					else
					{
						if (mx == arr[g])
						{
							bool flag = false;
							for (int q = 0; q < sizearrRes; q++)
							{
								if (!isRepeat(mx, arr[i], arr[j], arrRes[q])) flag = true;
							}
							if (flag) continue;

							if (mx > arr[j] + arr[i]) continue;
							if (mx * mx > arr[j] * arr[j] + arr[i] * arr[i])
							{
								arrRes[sizearrRes][0] = mx;
								arrRes[sizearrRes][1] = arr[j];
								arrRes[sizearrRes++][2] = arr[i];
							}
						}
					}
				}
			}
		}
	}
}

bool isRepeat(int a, int b, int c, int* arr)
{
	int count = 0;
	if (a == b && b == c) 
		return true;
	for (int i = 0; i < 3; i++)
	{
		if (arr[i] == a)
		{ count++; continue; }
		if (arr[i] == b) 
		{ count++; continue; }
		if (arr[i] == c) 
		{ count++; continue; }
	}
	if (count == 3) 
		return false;

	return true;
}
