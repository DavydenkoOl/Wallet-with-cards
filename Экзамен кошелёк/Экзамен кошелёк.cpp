// Экзамен кошелёк.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include"Card.h"


using namespace std;

int main()
{
	vector<Card> pocket;

	vector<Сost_categories> mas_cost;
	Сost_categories categories("Food", 0, 0);
	Сost_categories categories1("Entertaiment", 0, 0);
	Сost_categories categories2("Communal_payments", 0, 0);
	Сost_categories categories3("Subscriptions", 0, 0);
	Сost_categories categories4("Other", 0, 0);
	mas_cost.push_back(categories);
	mas_cost.push_back(categories1);
	mas_cost.push_back(categories2);
	mas_cost.push_back(categories3);
	mas_cost.push_back(categories4);
	//временный объект Card для вызова методов
	Card tmp_card;


	string number_card;
	int choose;
	bool No_exit = true;


	//чтение из файла
	tmp_card.Read(pocket);
	tmp_card.Read_top(tmp_card.get_mas(), mas_cost);


Start_Menu:

	string tmp_number;

	while (No_exit) {

		cout << "1 add card\n";
		cout << "2 top up card\n";
		cout << "3 show pocket\n";
		cout << "4 clear console\n";
		cout << "5 card replenishment\n";
		cout << "6 costs by category\n";
		cout << "7 cost and category report\n";
		cout << "8 Show top by catigories\n";
		cout << "9 Show top by summ\n";
		cout << "10 save & exit\n";



		cin >> choose;
		switch (choose)
		{

			//создаёт объект Card и записывет в vector
		case 1:

			pocket.push_back(tmp_card.create());

			system("cls");

			break;


			//ищет в vectore объект Card с подходящим номером
		case 2:

			cout << "type nomber of card for top up \n";
			cin >> tmp_number;
			for (size_t i = 0; i < pocket.size(); i++)
			{
				if (pocket[i].get_number() == tmp_number)
				{
					pocket[i].top_up();
					goto Start_Menu;
				}

			}
			break;

			//вывод vectora объектов Card на экран
		case 3:

			for (size_t i = 0; i < pocket.size(); i++)
			{
				pocket[i].Show();
			}
			break;

			//очистка консоли и показ стартового меню
		case 4:

			system("cls");

			break;
			//пополнение карт
		case 5:
			cout << "choose a card to replenish your account" << endl;
			for (size_t i = 0; i < pocket.size(); i++)
			{
				pocket[i].Show();
			}

			cout << "Enter nunber card: \n";
			cin >> number_card;
			for (size_t i = 0; i < pocket.size(); i++)
			{
				if (number_card == pocket[i].get_number()) {
					int sum = 0;
					cout << "enter the amount to replenish the account\n";
					cin >> sum;
					pocket[i].set_balance(sum);
				}
			}

			break;

			//сохранение в файл выход из меню
		case 6:
			tmp_card.Categori_Menu(pocket, mas_cost);


			break;
			//отчет по затратам и категориям
		case 7:
			tmp_card.cost_report(pocket, mas_cost);


			break;

		case 8:
			tmp_card.Show_top(mas_cost);


			break;


		case 9:
			tmp_card.Show_top_spend(mas_cost);


			break;


			//сохранение в файл выход из меню
		case 10:
			tmp_card.Save(pocket);
			tmp_card.Save_top(mas_cost);
			No_exit = false;

			break;
		default:
			cout << "error\n";

			goto Start_Menu;

			//если ввел несуществующий нукт в меню правильно

			break;
		}


	}


}
