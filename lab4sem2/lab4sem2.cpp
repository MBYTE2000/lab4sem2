#include <iostream>

using namespace std;

struct Stack
{
	char info;
	Stack* next;
};

bool IsOperand(char a) {

	if (a == '*' || a == '/' || a == '+' || a == '-' || a == '^') { return true; }
	else return false;
}

//-------- Функция добаления элементов в стек-----------
void InStack(Stack** top, char in)
{
	Stack* t = new Stack;
	t->info = in;
	t->next = *top;
	*top = t;
}
//-------- Функция реализации приоритета операций-----------
int Prior(char a)
{
	switch (a)
	{
	case '(':   case ')': return 1;
	case '+':	case '-':   return 2;
	case '*':	case '/':   return 3;
	}
}
//-------- Функция удаления элементов из стека -----------
void OutStack(Stack** top, char* s)
{
	Stack* t = (*top);
	*top = (*top)->next;
	*s = t->info;
	delete t;
}
//-------- Функция расчета -----------
void Rezult(char* str)
{
	double* massive = new double[strlen(str) / 2];
	int pos = 0; double value;

	for (int i = 0; i < strlen(str); i++)
	{
		char ch = str[i];
		if (!IsOperand(ch))
		{
			cout << "Enter your value " << ch << ": " << ch << " = "; cin >> value;
			double(ch) = value;
		}



		if (!IsOperand(str[i]))
		{
			switch (str[i])
			{
			case 'a':massive[pos] = value; break;
			case 'b':massive[pos] = value; break;
			case 'c':massive[pos] = value; break;
			case 'd':massive[pos] = value; break;
			case 'e':massive[pos] = value; break;
			default: cout << "Error1";
			}
			pos++;
		}
		if (IsOperand(str[i]))
		{
			pos--;
			switch (str[i])
			{
			case'+': massive[pos - 1] = massive[pos - 1] + massive[pos]; break;
			case'-': massive[pos - 1] = massive[pos - 1] - massive[pos]; break;
			case'*': massive[pos - 1] = massive[pos - 1] * massive[pos]; break;
			case'/': massive[pos - 1] = massive[pos - 1] / massive[pos]; break;
			default: cout << "Error2";
			}
		}
	}
	cout << "Ответ:" << massive[0] << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	Stack* k = NULL;
	Stack* t;
	char a, str1[50], str2[50];
	int j = 0, i = 0;
	cout << "Введите выражение:" << endl;
	std::cin >> str1;

	while (str1[i] != '\0')
	{
		if (str1[i] == ')')
		{
			while (k->info != '(')
			{
				OutStack(&k, &a);
				if (k == NULL) a = '\0';
				str2[j++] = a;
			}
			t = k;
			k = k->next;
			delete t;
		}
		else
			if (str1[i] >= 'a' && str1[i] <= 'z') { str2[j++] = str1[i]; }
			else
				if (str1[i] == '(') { InStack(&k, '('); }
				else
					if (IsOperand(str1[i]))
					{
						while (k != NULL && Prior(k->info) >= Prior(str1[i]))
						{
							OutStack(&k, &a);
							str2[j++] = a;
						}
						InStack(&k, str1[i]);
					}
		i++;
	}
	while (k != NULL)//если стек не пуст, переписываем все операции
	{
		OutStack(&k, &a);
		str2[j++] = a;
	}
	str2[j] = '\0';

	cout << "Ваше выражение в ОПЗ:" << endl;
	cout << str2 << endl;
	Rezult(str2);
	return 0;
}