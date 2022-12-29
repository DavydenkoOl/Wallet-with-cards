#pragma once

#include"Cost_categories.h"
using namespace std;
class Card
{
private:
	Сost_categories cost_categiries;
	string type;
	string number;
	string CVV;
	string date;
	string owner;
	int credit_limit;
	int balance;

public:
	vector<Сost_categories> mas_cost_categiries;
	Card(int balance,
		string type,
		string number,
		string CVV,
		string date,
		string owner,
		int credit_limit)

	{

		this->balance = balance;
		this->type = type;
		this->number = number;
		this->CVV = CVV;
		this->date = date;
		this->owner = owner;
		this->credit_limit = credit_limit;

	};

	Card() {
		this->balance = 0;
		this->type = "type";
		this->number = "number";
		this->CVV = "CVV";
		this->date = "date";
		this->owner = "owner";
		this->credit_limit = 0;

	}

	void set_number() {
		cout << "type number" << endl;
		cin >> number;
	}

	string get_number() {
		return number;
	}

	void set_CVV() {
	Error_cvv:

		cout << "type CVV" << endl;
		cin >> CVV;

		if (CVV.size() != 3)
		{
			cout << "wrong CVV" << endl;
			goto Error_cvv;
		}

	}

	string get_CVV() {
		return CVV;
	}

	void set_date() {
		cout << "type date" << endl;
		cin >> date;
	}

	string get_date() {
		return date;
	}

	void set_owner() {
		cout << "type owner" << endl;
		getline(cin, owner);
	}

	string get_owner() {
		return owner;
	}

	void set_type(string type) {
		this->type = type;
	}

	string get_type() {
		return type;
	}

	void set_balance(int balance) {
		this->balance = balance;
	}

	int get_balance() {
		return balance;
	}

	void set_limit(int credit_limit) {
		this->credit_limit = credit_limit;
	}

	int get_limit() {
		return credit_limit;
	}

	vector<Сost_categories> get_mas()const {

		return this->mas_cost_categiries;

	}

	void Show();                                                                                 //вывод объекта Card на экран
	void Show_top(vector<Сost_categories>& mas_cost);                                            //выводит топ трат (категории)
	void Show_top_spend(vector<Сost_categories>& mas_cost);                                      //выводит топ трат
	void Save(vector<Card> pocket);                                                              //сохраняет карты в файл
	void Save_top(vector<Сost_categories> mas_cost);                                             //сохраняет затраты в файл
	void Read(vector<Card>& pocket);                                                             //считывает данные карт с файла
	void Read_top(vector<Сost_categories> mas_cost_categiries, vector<Сost_categories>& mas_cost); //считывает данные затрат с файла
	void top_up();                                                                               //пополняет карту
	Card create();                                                                               //создает карту
	void Card_selection(vector<Card>& pocket, int summ);                                         //списывает суммы затрат из карт
	void cost_report(vector<Card>& pocket, vector<Сost_categories>& mas_cost);                   //отчёт по категориям
	void Categori_Menu(vector<Card>& pocket, vector<Сost_categories>& mas_cost);                 //меню для выбора по затратам
};