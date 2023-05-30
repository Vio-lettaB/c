#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct {
	char* khozain;
	int yacheika[10][10];
}pole;

void vivod(pole a, pole b, FILE* OUT)
{

	fprintf(OUT, "%s    \t%s\n", a.khozain, b.khozain);
	fprintf(OUT, " 0123456789\t 0123456789\n");
	int i = 0;
	for (i; i < 10; i++)
	{
		fprintf(OUT, "%d", i);
		for (int j = 0; j < 10; j++)
		{
			if (a.yacheika[i][j] == 0) fprintf(OUT, "\033[43m.\033[0m");
			if (a.yacheika[i][j] == 1) fprintf(OUT, "\033[41m.\033[0m");
			if (a.yacheika[i][j] == 2) fprintf(OUT, "\033[41m+\033[0m");
			if (a.yacheika[i][j] == 3) fprintf(OUT, "\033[43m+\033[0m");
		}
		fprintf(OUT, "\t%d", i);
		for (int j = 0; j < 10; j++)
		{
			if (b.yacheika[i][j] == 0) fprintf(OUT, "\033[44m.\033[0m");
			if (b.yacheika[i][j] == 1) fprintf(OUT, "\033[46m.\033[0m");
			if (b.yacheika[i][j] == 2) fprintf(OUT, "\033[46m+\033[0m");
			if (b.yacheika[i][j] == 3) fprintf(OUT, "\033[44m+\033[0m");
		}
		fprintf(OUT, "\n");
	}
}

pole zapolnenie(pole a, int korabl, int g[4], int v[4], int* m)
{
	if ((g[0] >= 0) && (g[0] < 10) && (g[1] >= 0) && (g[1] < 10) && (g[2] >= 0) && (g[2] < 10) && (g[3] >= 0) && (g[3] < 10) && (v[0] >= 0) && (v[0] < 10) && (v[1] >= 0) && (v[1] < 10) && (v[2] >= 0) && (v[2] < 10) && (v[3] >= 0) && (v[3] < 10))
	{
		if (korabl == 4)
		{
			if ((((v[0] == v[1]) && (v[1] == v[2]) && (v[2] == v[3]) && (abs(g[3] - g[0]) == 3))) || ((g[0] == g[1]) && (g[1] == g[2]) && (g[2] == g[3]) && (abs(v[3] - v[0]) == 3)))
			{
				if ((a.yacheika[g[0]][v[0]] == 0) && (a.yacheika[g[1]][v[1]] == 0) && (a.yacheika[g[2]][v[2]] == 0) && (a.yacheika[g[3]][v[3]] == 0))
				{
					a.yacheika[g[0]][v[0]] = 1;
					a.yacheika[g[1]][v[1]] = 1;
					a.yacheika[g[2]][v[2]] = 1;
					a.yacheika[g[3]][v[3]] = 1;
					*m = 3;
					return(a);
				}
			}
		}
		if (korabl == 3)
		{
			if (((g[0] == g[1]) && (g[1] == g[2]) && (abs(v[2] - v[0]) == 2) || ((v[0] == v[1]) && (v[1] == v[2]) && (abs(g[2] - g[0]) == 2))))
			{
				if ((a.yacheika[g[0]][v[0]] == 0) && (a.yacheika[g[1]][v[1]] == 0) && (a.yacheika[g[2]][v[2]] == 0))
				{
					a.yacheika[g[0]][v[0]] = 1;
					a.yacheika[g[1]][v[1]] = 1;
					a.yacheika[g[2]][v[2]] = 1;
					*m = 3;
					return(a);
				}
			}
		}
		if (korabl == 2)
		{
			if (((g[0] == g[1]) && (abs(v[1] - v[0]) == 1) || ((v[0] == v[1]) && (abs(g[1] - g[0]) == 1))))
			{
				if ((a.yacheika[g[0]][v[0]] == 0) && (a.yacheika[g[1]][v[1]] == 0))
				{
					a.yacheika[g[0]][v[0]] = 1;
					a.yacheika[g[1]][v[1]] = 1;
					*m = 3;
					return(a);
				}
			}
		}
		if (korabl == 1)
		{
			if (a.yacheika[g[0]][v[0]] == 0)
			{
				a.yacheika[g[0]][v[0]] = 1;
				*m = 3;
				return (a);
			}
		}
	}
	*m = 1;
	return(a);
}

pole computer(pole c, int g[4], int v[4], int q)
{
	int nada = 0;
	int ogran = 0;;
	if (q == 4) ogran = 1;
	if (q == 3) ogran = 2;
	if (q == 2) ogran = 3;
	if (q == 1) ogran = 4;
	int polozhenie;
	while (nada < ogran)
	{
		srand(time(NULL));
		polozhenie = rand() % (2) + 1;
		int m = 0;
		if (polozhenie == 1)
		{
			srand(time(NULL));
			g[0] = rand() % (10);
			g[1] = g[0]; g[2] = g[0]; g[3] = g[0];
			srand(time(NULL));
			v[0] = rand() % (7);
			v[1] = v[0] + 1; v[2] = v[0] + 2; v[3] = v[0] + 3;
			c = zapolnenie(c, q, g, v, &m);
			if (m == 3) nada += 1;
		}
		if (polozhenie == 2)
		{
			srand(time(NULL));
			v[0] = rand() % (10);
			v[1] = v[0]; v[2] = v[0]; v[3] = v[0];
			srand(time(NULL));
			g[0] = rand() % (7);
			g[1] = g[0] + 1; g[2] = g[0] + 2; g[3] = g[0] + 3;
			c = zapolnenie(c, q, g, v, &m);
			if (m == 3) nada += 1;
		}
	}
	return c;
}

pole vvod(pole a, int q, int* oshibka, FILE * IN)
{
	int g[4] = { 0,0,0,0 };
	int v[4] = { 0,0,0,0 };
	for (int i = 0; i < q; i++)
		scanf("%d %d", &g[i], &v[i]);
	int m = 0;
	a = zapolnenie(a, q, g, v, &m);
	if (m == 1)
	     *oshibka = *oshibka + q;
	return a;
}



int main()
{
	setlocale(LC_ALL, "Rus");
	pole a, b1, c, b2;
	int g[4] = { 0,0,0,0 };
	int v[4] = { 0,0,0,0 };
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			a.yacheika[i][j] = 0;
			b1.yacheika[i][j] = 0;
			b2.yacheika[i][j] = 0;
			c.yacheika[i][j] = 0;
		}
	printf("\033[45mПриветствую в игре под названием морской бой.\033[0m\n");
	system("pause");
	system("cls");
	int interaktiv = 0;
	while (interaktiv != 5)
	{
		printf("Что бы вы хотели сделать?\n 1-начать играть с другим игроком.\n 2-начать играть с ботом.\n 3-посмотреть правила.\n 5-выйти из игры.\n");
		scanf("%d", &interaktiv);
		if ((interaktiv < 0) || (interaktiv > 5)) interaktiv = 5;
		if (interaktiv == 1)
		{
			a.khozain = "Игрок а:";
			c.khozain = "Игрок b:";
			b1.khozain = "Игрок a:";
			b2.khozain = "Игрок b:";
			int oshibka1 = 0;
			int oshibka2 = 0;
			system("cls");
			int vibor = 3;
			printf("Вы хотите заполнить поле сами или рандомно?\n 1- сами.\n 2 - рандомно.\n");
			scanf("%d", &vibor);
			if (vibor == 1) {
				vivod(a, b2, stdout);
				printf("Давайте заполним поле игрока a.\n Сначала поставим корабль 4 на 1 (сначала вводим строку, потом столбец через пробел, корабли вводить строго сверху вних или справа налево):\n");
				{
					int nada = oshibka1;
					a = vvod(a, 4, &oshibka1, stdin);
					system("cls");
					vivod(a, b1, stdout);
					if (oshibka1 > nada) printf("Упс, что-то пошло не так, не правильно расположил корабль. В качестве наказания своей невнимательности ты останешься без этого коробля.\n");
					nada = oshibka1;

					for (int i = 0; i < 2; i++) {
						printf("Теперь поставим корабль 3 на 1. %d штука:\n", i + 1);
						a = vvod(a, 3, &oshibka1, stdin);
						system("cls");
						vivod(a, b1, stdout);
						if (oshibka1 > nada) printf("Упс, что-то пошло не так, не правильно расположил корабль. В качестве наказания своей невнимательности ты останешься без этого коробля.\n");
						nada = oshibka1;

					}
					for (int i = 0; i < 3; i++) {
						printf("Теперь поставим корабль 2 на 1. %d штука:\n", i + 1);
						a = vvod(a, 2, &oshibka1, stdin);
						system("cls");
						vivod(a, b1, stdout);
						if (oshibka1 > nada) printf("Упс, что-то пошло не так, не правильно расположил корабль. В качестве наказания своей невнимательности ты останешься без этого коробля.\n");
						nada = oshibka1;

					}
					for (int i = 0; i < 4; i++) {
						printf("Теперь поставим корабль 1 на 1. %d штука:\n", i + 1);
						a = vvod(a, 1, &oshibka1, stdin);
						system("cls");
						vivod(a, b1, stdout);
						if (oshibka1 > nada) printf("Упс, что-то пошло не так, не правильно расположил корабль. В качестве наказания своей невнимательности ты останешься без этого коробля.\n");
						nada = oshibka1;
					}
				}
			}
			if (vibor == 2)
			{
				a = computer(a, g, v, 4);
				printf("Заполнен 1 корабль 4 на 1.\n");
				vivod(a, b2,stdout);
				system("pause");
				system("cls");
				g[3] = 0, v[3] = 0;
				a = computer(a, g, v, 3);
				printf("Заполнено 2 корабля 2 на 1.\n");
				vivod(a, b2, stdout);
				system("pause");
				system("cls");
				g[2] = 0, v[2] = 0;
				a = computer(a, g, v, 2);
				printf("Заполнено 3 корабля 2 на 1.\n");
				vivod(a, b2, stdout);
				system("pause");
				system("cls");
				g[1] = 0, v[1] = 0;
				a = computer(a, g, v, 1);
				printf("Заполнено 4 корабля 1 на 1.\n");
				vivod(a, b2, stdout);
				system("pause");
				system("cls");
				g[0] = 0, v[0] = 0;
				system("pause");
			}
			system("cls");
			vivod(b1, b2, stdout);
			printf("Теперь пусть второй игрок заполнит своё поле.");
			system("pause");
			system("cls");

			vibor = 3;
			printf("Вы хотите заполнить поле сами или рандомно?\n 1- сами.\n 2 - рандомно.\n");
			scanf("%d", &vibor);
			if (vibor == 1) {
				vivod(b1, c, stdout);
				{
					printf("Сначала поставим корабль 4 на 1 (сначала вводим строку, потом столбец через пробел, корабли вводить строго сверху вних или справа налево):\n");
					int nada = oshibka2;
					c = vvod(c, 4, &oshibka2, stdin);
					system("cls");
					vivod(b1, c, stdout);
					if (oshibka2 > nada) printf("Упс, что-то пошло не так, не правильно расположил корабль. В качестве наказания своей невнимательности ты останешься без этого коробля.\n");
					nada = oshibka2;

					for (int i = 0; i < 2; i++) {
						printf("Теперь поставим корабль 3 на 1. %d штука:\n", i + 1);
						c = vvod(c, 3, &oshibka2, stdin);
						system("cls");
						vivod(b1, c, stdout);
						if (oshibka2 > nada) printf("Упс, что-то пошло не так, не правильно расположил корабль. В качестве наказания своей невнимательности ты останешься без этого коробля.\n");
						nada = oshibka2;

					}
					for (int i = 0; i < 3; i++) {
						printf("Теперь поставим корабль 2 на 1. %d штука:\n", i + 1);
						c = vvod(c, 2, &oshibka2, stdin);
						system("cls");
						vivod(b1, c, stdout);
						if (oshibka2 > nada) printf("Упс, что-то пошло не так, не правильно расположил корабль. В качестве наказания своей невнимательности ты останешься без этого коробля.\n");
						nada = oshibka2;

					}
					for (int i = 0; i < 4; i++) {
						printf("Теперь поставим корабль 1 на 1. %d штука:\n", i + 1);
						c = vvod(c, 1, &oshibka2, stdin);
						system("cls");
						vivod(b1, c, stdout);
						if (oshibka2 > nada) printf("Упс, что-то пошло не так, не правильно расположил корабль. В качестве наказания своей невнимательности ты останешься без этого коробля.\n");
						nada = oshibka2;
					}
				}
			}
			if (vibor == 2) {
				c = computer(c, g, v, 4);
				printf("Заполнен 1 корабль 4 на 1.\n");
				vivod(b1, c, stdout);
				system("pause");
				system("cls");
				g[3] = 0, v[3] = 0;
				c = computer(c, g, v, 3);
				printf("Заполнено 2 корабля 2 на 1.\n");
				vivod(b1, c, stdout);
				system("pause");
				system("cls");
				g[2] = 0, v[2] = 0;
				c = computer(c, g, v, 2);
				printf("Заполнено 3 корабля 2 на 1.\n");
				vivod(b1, c, stdout);
				system("pause");
				system("cls");
				g[1] = 0, v[1] = 0;
				c = computer(c, g, v, 1);
				printf("Заполнено 4 корабля 1 на 1.\n");
				vivod(b1, c, stdout);
				system("pause");
				system("cls");
				g[0] = 0, v[0] = 0;
				system("pause");

			}
			system("cls");
			printf("\033[35mДа начнётся бой!\033[0\n");
			system("pause");
			system("cls");
			int end1 = 20 - oshibka1;
			int end2 = 20 - oshibka2;
			while ((end1 != 0) && (end2 != 0))
			{
				int nada = 0;
				printf("\033[43mХод игрока a.\033[0m\n");
				system("pause");
				system("cls");
				while (nada == 0)
				{
					system("cls");
					vivod(a, b2, stdout);
					printf("Сделайте ваш выстрел! (координаты выстрела выглядят так же, как и координаты корабля)\n");
					scanf("%d %d", &g[0], &v[0]);
					if ((g[0] >= 0) && (g[0] < 10) && (v[0] >= 0) && (v[0] < 10))
					{
						if (c.yacheika[g[0]][v[0]] == 1)
						{
							c.yacheika[g[0]][v[0]] = 2;
							b2.yacheika[g[0]][v[0]] = 2;
							end2 = end2 - 1;
							system("cls");
							vivod(a, b2, stdout);
							printf("\033[32mЕсть попадание!\033[0m\n");
							system("pause");
						}
						if (c.yacheika[g[0]][v[0]] == 0)
						{
							c.yacheika[g[0]][v[0]] = 3;
							b2.yacheika[g[0]][v[0]] = 3;
							system("cls");
							vivod(a, b2, stdout);
							printf("\033[31mМимо!\033[0m\n");
							system("pause");
							nada = 1;
						}
					}
					else { printf("Неправильно введены координаты! В качестве наказания за невнимательность - пропуск хода.\n"); nada = 1; }
				}
				system("cls");
				printf("\033[44mХод игрока b.\033[0m\n");
				nada = 0;
				system("pause");
				while (nada == 0)
				{
					system("cls");
					vivod(b1, c, stdout);
					printf("Сделайте ваш выстрел! (координаты выстрела выглядят так же, как и координаты корабля)\n");
					scanf("%d %d", &g[0], &v[0]);
					if ((g[0] >= 0) && (g[0] < 10) && (v[0] >= 0) && (v[0] < 10))
					{
						if (a.yacheika[g[0]][v[0]] == 1)
						{
							a.yacheika[g[0]][v[0]] = 2;
							b1.yacheika[g[0]][v[0]] = 2;
							end1 = end1 - 1;
							system("cls");
							vivod(b1, c, stdout);
							printf("\033[32mЕсть попадание!\033[0m\n");
							system("pause");
						}
						if (c.yacheika[g[0]][v[0]] == 0)
						{
							a.yacheika[g[0]][v[0]] = 3;
							b1.yacheika[g[0]][v[0]] = 3;
							system("cls");
							vivod(b1, c, stdout);
							printf("\033[31mМимо!\033[0m\n");
							system("pause");
							nada = 1;
						}
						system("cls");
					}
					else { printf("Неправильно введены координаты! В качестве наказания за невнимательность - пропуск хода.\n"); nada = 1; }
				}
			}
			if (end2 == 0) printf("\033[43mПобедил игрок a!!!\033[0m\n");
			if (end1 == 0) printf("\033[44mПобедил игрок b!!!\033[0m\n");
			system("pause");
			system("cls");
			for (int i = 0; i < 10; i++)
				for (int j = 0; j < 10; j++)
				{
					a.yacheika[i][j] = 0;
					b1.yacheika[i][j] = 0;
					b2.yacheika[i][j] = 0;
					c.yacheika[i][j] = 0;
				}
		}
		if (interaktiv == 3)
		{
			a.khozain = "Игрок а:";
			c.khozain = "Игрок b:";
			system("cls");
			printf(" Привет! Правила данной игры очень просты и понятны. На экране ты видишь поле 2 поля:\n");
			vivod(a, c, stdout);
			printf("Одно из полей - твоё, другое соперника. На поле можно разместить корабли:\n 1 корабль - 1 на 4 клетки,\n 2 корабля - 1 на 3 клетки,\n 3 корабля - 1 на 2 клетки,\n 4 корабля - 1 на 1 клетку.\n Иногда требуют, чтобы между кораблями было хотябы клеточное расстояние, но в нашей версии это не обязательно.\n Если на клетке стоит корабль, то клетка меняет цвет:\033[43m.\033[0m->\033[41m.\033[0m.");
			printf(" После расстановки кораблей нужно выстрелами искать корабли противника и уночтожать их. Уничтоженные корабли помечаются белыми крестиками: \033[43m.\033[0m->\033[41m+\033[0m. А если ячейка оказалась пустая, то она не меняет своего цвета и просто отмечается крестиком: \033[43m.\033[0m->\033[43m+\033[0m.\n");
			printf("Удачной игры!\n");
			system("pause");
			system("cls");
		}
		if (interaktiv == 2)
		{
			a.khozain = "Вы:";
			b1.khozain = "Вы:";
			c.khozain = "Компьютер:";
			b2.khozain = "Комьпьютер:";
			system("cls");
			int oshibka1 = 0;
			int vibor = 3;
			printf("Вы хотите заполнить поле сами или рандомно?\n 1- сами.\n 2 - рандомно.\n");
			scanf("%d", &vibor);
			system("cls");
			if (vibor == 1) {
				vivod(a, b2, stdout);
				printf("Давайте заполним поле игрока a.\n Сначала поставим корабль 4 на 1 (сначала вводим строку, потом столбец через пробел, корабли вводить строго сверху вних или справа налево):\n");
				{
					int nada = oshibka1;
					a = vvod(a, 4, &oshibka1, stdin);
					system("cls");
					vivod(a, b1, stdout);
					if (oshibka1 > nada) printf("Упс, что-то пошло не так, не правильно расположил корабль. В качестве наказания своей невнимательности ты останешься без этого коробля.\n");
					nada = oshibka1;

					for (int i = 0; i < 2; i++) {
						printf("Теперь поставим корабль 3 на 1. %d штука:\n", i + 1);
						a = vvod(a, 3, &oshibka1, stdin);
						system("cls");
						vivod(a, b1, stdout);
						if (oshibka1 > nada) printf("Упс, что-то пошло не так, не правильно расположил корабль. В качестве наказания своей невнимательности ты останешься без этого коробля.\n");
						nada = oshibka1;

					}
					for (int i = 0; i < 3; i++) {
						printf("Теперь поставим корабль 2 на 1. %d штука:\n", i + 1);
						a = vvod(a, 2, &oshibka1, stdin);
						system("cls");
						vivod(a, b1, stdout);
						if (oshibka1 > nada) printf("Упс, что-то пошло не так, не правильно расположил корабль. В качестве наказания своей невнимательности ты останешься без этого коробля.\n");
						nada = oshibka1;

					}
					for (int i = 0; i < 4; i++) {
						printf("Теперь поставим корабль 1 на 1. %d штука:\n", i + 1);
						a = vvod(a, 1, &oshibka1, stdin);
						system("cls");
						vivod(a, b1, stdout);
						if (oshibka1 > nada) printf("Упс, что-то пошло не так, не правильно расположил корабль. В качестве наказания своей невнимательности ты останешься без этого коробля.\n");
						nada = oshibka1;
					}
				}
			}
			if (vibor == 2)
			{
				a = computer(a, g, v, 4);
				printf("Заполнен 1 корабль 4 на 1.\n");
				vivod(a, b2, stdout);
				system("pause");
				system("cls");
				g[3] = 0, v[3] = 0;
				a = computer(a, g, v, 3);
				printf("Заполнено 2 корабля 2 на 1.\n");
				vivod(a, b2, stdout);
				system("pause");
				system("cls");
				g[2] = 0, v[2] = 0;
				a = computer(a, g, v, 2);
				printf("Заполнено 3 корабля 2 на 1.\n");
				vivod(a, b2, stdout);
				system("pause");
				system("cls");
				g[1] = 0, v[1] = 0;
				a = computer(a, g, v, 1);
				printf("Заполнено 4 корабля 1 на 1.\n");
				vivod(a, b2, stdout);
				system("pause");
				system("cls");
				g[0] = 0, v[0] = 0;
				system("pause");
			}
			system("cls");
			vivod(b1, b2, stdout);
			printf("Теперь компьютер заполнит своё поле.");
			c = computer(c, g, v, 4);
			printf("Заполнен 1 корабль 4 на 1.");
			g[3] = 0, v[3] = 0;
			c = computer(c, g, v, 3);
			printf("Заполнено 2 корабля 2 на 1.");
			g[2] = 0, v[2] = 0;
			c = computer(c, g, v, 2);
			printf("Заполнено 3 корабля 2 на 1.");
			g[1] = 0, v[1] = 0;
			c = computer(c, g, v, 1);
			printf("Заполнено 4 корабля 1 на 1.");
			g[0] = 0, v[0] = 0;
			system("pause");
			system("cls");
			printf("\033[35mДа начнётся бой!\033[0\n");
			system("pause");
			int end1 = 20 - oshibka1;
			int end2 = 20;
			while ((end1 != 0) && (end2 != 0))
			{
				int nada = 0;
				system("cls");
				system("cls");
				vivod(a, b2, stdout);
				while (nada == 0)
				{
					system("cls");
					vivod(a, b2, stdout);
					printf("Сделайте ваш выстрел! (координаты выстрела выглядят так же, как и координаты корабля)\n");
					scanf("%d %d", &g[0], &v[0]);
					if ((g[0] >= 0) && (g[0] < 10) && (v[0] >= 0) && (v[0] < 10))
					{
						if (c.yacheika[g[0]][v[0]] == 1)
						{
							c.yacheika[g[0]][v[0]] = 2;
							b2.yacheika[g[0]][v[0]] = 2;
							end2 = end2 - 1;
							system("cls");
							vivod(a, b2, stdout);
							printf("\033[32mЕсть попадание!\033[0m\n");
							system("pause");
						}
						if (c.yacheika[g[0]][v[0]] == 0)
						{
							c.yacheika[g[0]][v[0]] = 3;
							b2.yacheika[g[0]][v[0]] = 3;
							system("cls");
							vivod(a, b2, stdout);
							printf("\033[31mМимо!\033[0m\n");
							system("pause");
							nada = 1;
						}
					}
					else { printf("Неправильно введены координаты! В качестве наказания за невнимательность - пропуск хода.\n"); nada = 1; }
				}
				nada = 0;
				while (nada == 0)
				{
					g[0] = rand() % (10);
					v[0] = rand() % (10);
				    if (a.yacheika[g[0]][v[0]] == 1)
					{
						a.yacheika[g[0]][v[0]] = 2;
						b1.yacheika[g[0]][v[0]] = 2;
						end1 = end1 - 1;
						system("cls");
						vivod(a, b2, stdout);
						printf("\033[32mЕсть попадание!\033[0m\n");
						system("pause");
					}
					if (a.yacheika[g[0]][v[0]] == 0)
					{
						a.yacheika[g[0]][v[0]] = 3;
						b1.yacheika[g[0]][v[0]] = 3;
						system("cls");
						vivod(a, b2, stdout);
						printf("\033[31mМимо!\033[0m\n");
						system("pause");
						nada = 1;
					}
					
				}
			}
			if (end2 == 0) printf("\033[43mВы победили!!!\033[0m\n");
			if (end1 == 0) printf("\033[44mПобедил компьютер!!\033[0m\n");
			system("pause");
			system("cls");
			for (int i = 0; i < 10; i++)
				for (int j = 0; j < 10; j++)
				{
					a.yacheika[i][j] = 0;
					b1.yacheika[i][j] = 0;
					b2.yacheika[i][j] = 0;
					c.yacheika[i][j] = 0;
				}
		}
	}
	return 0;
}
