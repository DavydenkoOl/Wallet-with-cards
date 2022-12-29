#pragma once

#include"Cost_categories.h"
using namespace std;
class Card
{
private:
	�ost_categories cost_categiries;
	string type;
	string number;
	string CVV;
	string date;
	string owner;
	int credit_limit;
	int balance;

public:
	vector<�ost_categories> mas_cost_categiries;
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

	vector<�ost_categories> get_mas()const {

		return this->mas_cost_categiries;

	}

	void Show();                                                                                 //����� ������� Card �� �����
	void Show_top(vector<�ost_categories>& mas_cost);                                            //������� ��� ���� (���������)
	void Show_top_spend(vector<�ost_categories>& mas_cost);                                      //������� ��� ����
	void Save(vector<Card> pocket);                                                              //��������� ����� � ����
	void Save_top(vector<�ost_categories> mas_cost);                                             //��������� ������� � ����
	void Read(vector<Card>& pocket);                                                             //��������� ������ ���� � �����
	void Read_top(vector<�ost_categories> mas_cost_categiries, vector<�ost_categories>& mas_cost); //��������� ������ ������ � �����
	void top_up();                                                                               //��������� �����
	Card create();                                                                               //������� �����
	void Card_selection(vector<Card>& pocket, int summ);                                         //��������� ����� ������ �� ����
	void cost_report(vector<Card>& pocket, vector<�ost_categories>& mas_cost);                   //����� �� ����������
	void Categori_Menu(vector<Card>& pocket, vector<�ost_categories>& mas_cost);                 //���� ��� ������ �� ��������
};