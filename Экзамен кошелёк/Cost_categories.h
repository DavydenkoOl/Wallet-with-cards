#pragma once
#include <string>
#include <iostream>

using namespace std;
struct Data {
	int month;
	int day;
	int week;
};

struct Сost_categories {

	string name_categories;
	float spend_count_categories = 0;              //общая сумма покупок в данной категории
	int count_categories = 0;                     //колличество покупок в данной категории
	Data data_pay;

	void set_data_pay() {

		int _month;
		int _week;
		int _day;
		cout << "when the transaction was made?" << endl;

		cout << "month" << endl;
		cin >> _month;

		cout << "week" << endl;
		cin >> _week;

		cout << "day" << endl;
		cin >> _day;


		data_pay.month = _month;
		data_pay.week = _week;
		data_pay.day = _day;

	}
	int GetDay() { return data_pay.day; }
	int GetMohnt() { return data_pay.month; }
	int GetWeek() { return data_pay.week; }

	int GetCount() { return count_categories; }

	string GetName_categorie() { return name_categories; }
	Сost_categories() {
		name_categories = "name";
		spend_count_categories = 0;
		count_categories = 0;
	}
	Сost_categories(string name, float spend_count_categories, int count_categories) {
		name_categories = name;
		this->spend_count_categories = spend_count_categories;
		this->count_categories = count_categories;
	}
	

bool operator<( const Сost_categories& c1)
{
	return this->count_categories < c1.count_categories;
}
};

