﻿

#include <iostream> 
#include <iomanip> 
#include <string> 
#include <ctype.h>  
#include <string.h> 
#include <stdio.h>
#pragma warning(disable : 4996)



// 1) видалити з S перше входження буквосполучення «tr»;
void task1_C()
{
	char S[20], s2[3] = "tr";
	printf("Видалити з S перше входження буквосполучення «tr»\n");
	printf ("Введіть рядок: ");
	scanf("%s", &S);
	char* p = strstr(S, s2); // шукає підрядок s2 в рядку S
	if (p) 
	{
		strcpy(p, p + strlen(s2)); //  копіює усі символи після позиції, де знаходиться підрядок s2, у початкову позицію p
		printf (S) << '\n';
	}
	else printf(S) << '\n';
}

void task1_Cpp() 
{
	std::string S, s2 = "tr";
	std::cout << "Видалити з S перше входження буквосполучення «tr»\n";
	std::cout << "Введіть рядок: "; 
	std::cin >> S;
	int p = 0;
	p = S.find(s2); //повертає позицію першого входження підрядка s2 у S або std::string::npos, якщо підрядок не знайдено.
	if (p >= 0)
	{
		S.erase(p, s2.size()); //якщо р= true, то видаляє підрядок s2 з рядка S, починаючи з позиції p із заданою довжиною s2.size()
		std::cout << S << '\n';
	}
	else std::cout << S << '\n';
}


//2) після першого буквосполучення «func» вставити «tion»;

void task2_C()
{
	char S[20], s1[5] = "func", s2[5] = "tion", s3[20] = "\0";
	printf ("Після першого буквосполучення «func» вставити «tion»\n");
	printf ("Введіть рядок: ");
	scanf("%s", &S);
	char* p = strstr(S, s1);// шукає підрядок s1 в рядку S

	if (p) 
	{
		p += strlen(s1); //Вказільник p пересувається до кінця першого входження підрядка s1 у рядок S за допомогою функції strlen, 
		//яка визначає довжину рядка s1, і додає цю довжину до вказільника p.
		strcpy(s3, p); //Значення покажчика p (тобто частину рядка S після першого входження підрядка s1) копіюється до рядка s3 
		strcpy(p, s2); //  Рядок s2 (тобто рядок, який потрібно вставити) копіюється в місце рядка S, що розташоване після першого входження підрядка s1.
		p += strlen(s2);//Вказільник p переміщується в кінець вставленого рядка s2
		strcpy(p, s3);//Значення рядка s3 (тобто рядка S, що зберігається після вставленого рядка s2) копіюється до рядка S в позицію, що відповідає початку рядка s3.
		printf (S) << '\n';
	}
	else printf (S) << '\n';
}

void task2_Cpp()
{
	std::string S, s1 = "func", s2 = "tion";
	std::cout << "Після першого буквосполучення «func» вставити «tion»\n";
	std::cout << "Введіть рядок: "; 
	std::cin >> S;
	int p = S.find(s1);//повертає позицію першого входження підрядка s1 у S або std::string::npos, якщо підрядок не знайдено.

	if (p >= 0) ///         ????
	{
		S.insert(p + s2.size(), s2); //p + s2.size(): Обчислює позицію вставки; вставляє рядок s2 у рядок S
		std::cout << S <<'\n';
	}
	else std::cout << S << '\n';
}


//3) в рядок D скопіювати 3 символи з рядка S після першої «k»;
void task3_C()
{
	char D[20], S[20], K = 'k'; // Оголошення рядків та символу K, який ми шукаємо у рядку S
	printf("В рядок D скопіювати 3 символи з рядка S після першої «k»\n");
	printf("Введіть рядок S: ");
	scanf("%s", S); // Зчитуємо рядок S з консолі
	printf("Введіть рядок D: ");
	scanf("%s", D); // Зчитуємо рядок D з консолі

	char* p = strchr(S, K); // Шукаємо перше входження символу 'k' у рядку S
	if (p)
	{ // Якщо 'k' було знайдено
		if (strlen(p) >= 3)
		{
			char copied[4]; // Рядок для зберігання скопійованого підрядка
			strncpy(copied, p + 1, 3); // Копіюємо 3 символи після 'k' у рядок copied, +1 для того, щоб пропустити сам символ 'k'
			copied[3] = '\0'; // Додаємо завершуючий нуль для завершення рядка copied
			strcat(D, copied); // Додаємо скопійований підрядок до початкового значення рядка D
			printf("%s\n", D); // Виводимо результуючий рядок D
		}
		else
		{
			printf("Після «k» недостатньо символів для копіювання\n"); // Повідомлення про те, що після 'k' недостатньо символів для копіювання
		}
	}
	else
	{
		printf("В рядку S немає «k»\n"); // Повідомлення про те, що 'k' не було знайдено у рядку S
	}
}	
	
void task3_Cpp()
{
	std::string D, S, K = "k";
	std::cout << "В рядок D скопіювати 3 символи з рядка S після першої «k»\n" ;
	std::cout << "Введіть рядок S: "; 
	std::cin >> S;
	std::cout << "Введіть рядок D: "; 
	std::cin >> D;
	size_t p = S.find(K); // Знаходимо позицію першого входження "k" у рядку S
	if (p != std::string::npos) //перевіряє, чи позиція p  не дорівнює значенню std::string::npos(чи входить К в підрядок)
	{ // Якщо "k" знайдено
		p += K.size(); // Збільшуємо позицію на довжину "k", щоб отримати позицію після "k"
		if (S.size() >= p + 3)
		{ // Перевіряємо, чи є довжина рядка достатньою для копіювання 3 символів після "k"
			std::string X = S.substr(p, 3); // Беремо 3 символи з позиції p
			std::cout << D + X << '\n'; // Додаємо скопійований підрядок до рядка D і виводимо результат
		}
		else
		{
			std::cout << "Після «k» недостатньо символів для копіювання\n";
		}
	}
	else
	{
		std::cout << "Символ 'k' не знайдено в рядку S\n";
	}
}


//4) підрахувати кількість буквосполучень «th».


//void task4_Cpp()
//{
//	std::string S;
//	std::string substr = "th";
//	int count = 0;
//	size_t pos = 0;// Ініціалізація лічильника входжень та позиції в рядку S для пошуку
//	std::cout << "Введіть рядок: ";
//	std::getline(std::cin, S); // Зчитуємо рядок з консолі ( з пробілами)
//
//	while ((pos = S.find(substr, pos)) != std::string::npos) // Пошук входжень підрядка substr у рядку S
//	{
//		count++;
//		pos += substr.size(); // Якщо входження знайдено, збільшити лічильник та оновити позицію для наступного пошуку
//	}
//
//	std::cout << "Кількість входжень буквосполучення 'th': " << count << '\n';
//}



int main()
{
	int t, x;
	std::cout << "Input number of task (1 to 3): "; 
	std::cin >> t;
	std::cout << "C or C++ (1 or 2) : "; 
	std::cin >> x;

	switch (x) 
	{
	case 1:
		switch (t)
		{
		case 1: task1_C(); break;
		case 2: task2_C(); break;
		case 3: task3_C(); break;
		
		}
		break;

	case 2:
		switch (t)
		{
		case 1: task1_Cpp(); break;
		case 2: task2_Cpp(); break;
		case 3: task3_Cpp(); break;
		/*case 4: task4_Cpp(); break;*/
		
		}
		break;
	default: std::cout << "Неправильне значення!";

	}
	
}
