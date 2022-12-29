#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include"Card.h"



using namespace std;
void Card::Show() {
	cout << endl;

	cout << "type of card : " << type << endl;
	cout << "number  : " << number << endl;
	cout << "balance : " << balance << endl;
	cout << "credit limit : " << credit_limit << endl;
	cout << "CVV : " << CVV << endl;
	cout << "date : " << date << endl;
	cout << "owner : " << owner << endl;

	cout << endl;
}
void  Card::Show_top(vector<Ñost_categories>& mas_cost) {

	vector<Ñost_categories> tmp_cost;
	tmp_cost = mas_cost;
	sort(tmp_cost.begin(), tmp_cost.end());

	reverse(tmp_cost.begin(), tmp_cost.end());

	for (size_t i = 0; i < 3; i++)
	{
		cout << tmp_cost[i].name_categories;
		cout << "-";
		cout << tmp_cost[i].count_categories;
		cout << endl;
	}
	cout << endl;
}
void Card::Show_top_spend(vector<Ñost_categories>& mas_cost) {

	vector<int> tmp_cost;

	for (size_t i = 0; i < mas_cost.size(); i++)
	{
		tmp_cost.push_back(mas_cost[i].spend_count_categories);
	}

	sort(tmp_cost.begin(), tmp_cost.end());

	reverse(tmp_cost.begin(), tmp_cost.end());

	for (size_t i = 0; i < 3; i++)
	{
		cout << tmp_cost[i];
		cout << endl;
	}
	cout << endl;
}
void Card::Save(vector<Card> pocket) {

	ofstream out;

	out.open("bank_system.txt", ios::out | ios::binary);

	if (out.is_open()) {
		out << pocket.size() << " ";
		for (size_t i = 0; i < pocket.size(); i++)
		{

			out << pocket[i].balance << " ";
			out << pocket[i].type << " ";
			out << pocket[i].number << " ";
			out << pocket[i].CVV << " ";
			out << pocket[i].date << " ";
			out << pocket[i].owner << " ";
			out << pocket[i].credit_limit << " ";

		}

	}
	out.close();

}
void Card::Save_top(vector<Ñost_categories> mas_cost) {

	ofstream out_top;

	out_top.open("top_payments.txt", ios::out | ios::binary);

	if (out_top.is_open()) {

		for (size_t i = 0; i < mas_cost.size(); i++)
		{
			out_top << mas_cost[i].name_categories << " ";
			out_top << mas_cost[i].spend_count_categories << " ";
			out_top << mas_cost[i].count_categories << " ";

		}

	}
	out_top.close();
}
void Card::Read(vector<Card>& pocket) {

	ifstream in("bank_system.txt", ios::in | ios::binary);

	if (in.is_open()) {

		int tmp_size;
		in >> tmp_size;

		Card* tmp = new Card();
		while (in >> tmp->balance >> tmp->type >> tmp->number >> tmp->CVV >> tmp->date >> tmp->owner >> tmp->credit_limit) {

			pocket.push_back(*tmp);

		}

	}

	in.close();

}
void Card::Read_top(vector<Ñost_categories> mas_cost_categiries, vector<Ñost_categories>& mas_cost) {

	ifstream in_top("top_payments.txt", ios::in | ios::binary);


	if (in_top.is_open()) {

		Ñost_categories* tmp_struct = new Ñost_categories();
		while (in_top >> tmp_struct->name_categories >> tmp_struct->spend_count_categories >> tmp_struct->count_categories) {


			mas_cost_categiries.push_back(*tmp_struct);

		}
		mas_cost = mas_cost_categiries;
	}

	in_top.close();

}
void Card::top_up() {
	int top_up;
	int tmp_balance = balance;

	cout << "how much u wanna add?" << endl;
	cin >> top_up;

	if (top_up < 0)
	{
		cout << "top up can't be bellow than 0";
	}
	else
	{
		tmp_balance += top_up;

		balance = tmp_balance;
	}

}
Card Card::create() {

	Card* card = new Card;
tryAgain:

	cout << "Enter card type: 1 - debet / 2 - credit" << endl;
	int choose;
	cin >> choose;

	if (choose == 1) {
		card->set_type("debet");
		card->set_limit(0);
		card->set_number();
		card->set_CVV();
		card->set_date();
		cin.ignore();
		card->set_owner();
		card->set_balance(0);
	}

	else if (choose == 2) {
		card->set_type("credit");
		card->set_limit(10000);
		card->set_number();
		card->set_CVV();
		card->set_date();
		cin.ignore();
		card->set_owner();
		card->set_balance(0);
	}
	else
	{
		cout << "Wrong choice!" << endl;
		goto tryAgain;
	}

	return *card;
}
void Card::Card_selection(vector<Card>& pocket, int summ) {
	string _numbCard;
	for (size_t i = 0; i < pocket.size(); i++)
	{
		pocket[i].Show();
	}

	cout << "Enter nunber card: \n";
	cin >> _numbCard;
	for (size_t i = 0; i < pocket.size(); i++)
	{
		if (_numbCard == pocket[i].get_number()) {



			if (pocket[i].get_type() == "credit")
			{
				if (summ <= pocket[i].get_balance()) {
					pocket[i].set_balance(pocket[i].get_balance() - summ);
				}
				else if (summ <= pocket[i].get_limit())
				{
					pocket[i].set_limit(pocket[i].get_limit() - summ);
				}
				else
				{
					cout << "Not enough money";
				}

			}

			if (pocket[i].get_type() == "debet")
			{
				if (summ <= pocket[i].get_balance()) {
					pocket[i].set_balance(pocket[i].get_balance() - summ);
				}
			}
			else
			{
				cout << "Not enough money";
			}

		}

	}
}
void Card::cost_report(vector<Card>& pocket, vector<Ñost_categories>& mas_cost) {
Begin:
	cout << "\tReport categories: " << endl;
	cout << "   daily report   - eneter '1' " << endl;
	cout << "   weekly report  - eneter '2' " << endl;
	cout << "   monthly report - eneter '3' " << endl;
	int numb;
	int count = 0;
	cin >> numb;
	if (numb > 0 && numb < 4) {
		if (numb == 1) {
			cout << "enter the day for the report " << endl;
			int _day;

			cin >> _day;

			for (int i = 0; i < mas_cost.size(); i++)
			{
				if (_day == mas_cost[i].GetDay()) {
					count++;
					cout << "On this day there were expenses by category: " << mas_cost[i].GetName_categorie() << endl;
				}

			}
			if (count == 0) {
				cout << "there were no charges that day! " << endl;
			}

		}
		if (numb == 2) {
			cout << "enter the week for the report " << endl;
			int _week;
			cin >> _week;
			for (int i = 0; i < mas_cost.size(); i++)
			{
				if (_week == mas_cost[i].GetWeek()) {
					count++;
					cout << "This week's expenses by category: " << mas_cost[i].GetName_categorie() << endl;
				}
			}
			if (count == 0) {
				cout << "no expenses this week! " << endl;
			}
		}
		if (numb == 3) {
			cout << "enter the week for the report " << endl;
			int _mohnt;
			cin >> _mohnt;
			for (int i = 0; i < mas_cost.size(); i++)
			{
				if (_mohnt == mas_cost[i].GetMohnt()) {
					count++;
					cout << "This month's expenses by category: " << mas_cost[i].GetName_categorie();
				}
			}
			if (count == 0) {
				cout << "no expenses this month! " << endl;
			}
		}
	}
	else {
		cout << "Wrong categori";
		goto Begin;
	}

}
void Card::Categori_Menu(vector<Card>& pocket, vector<Ñost_categories>& mas_cost) {

	int categori;
	int sum = 0;

	cout << "what categori u wanna use?" << endl;
	cout << "1 - Food" << endl;
	cout << "2 - Entertaiment " << endl;
	cout << "3 - Communal_payments " << endl;
	cout << "4 - Subscriptions " << endl;
	cout << "5 - Other" << endl;


Start:
	cin >> categori;

	switch (categori)
	{

	case 1:
		cout << "enter the purchase amount in this category: " << endl;

		cin >> sum;
		Card_selection(pocket, sum);
		mas_cost[0].spend_count_categories += sum;
		mas_cost[0].count_categories++;
		mas_cost[0].set_data_pay();




		break;

	case 2:
		cout << "enter the purchase amount in this category: " << endl;

		cin >> sum;
		Card_selection(pocket, sum);
		mas_cost[1].spend_count_categories += sum;
		mas_cost[1].count_categories++;
		mas_cost[1].set_data_pay();

		break;

	case 3:
		cout << "enter the purchase amount in this category: " << endl;

		cin >> sum;
		Card_selection(pocket, sum);
		mas_cost[2].spend_count_categories += sum;
		mas_cost[2].count_categories++;
		mas_cost[2].set_data_pay();

		break;

	case 4:
		cout << "enter the purchase amount in this category: " << endl;

		cin >> sum;
		Card_selection(pocket, sum);
		mas_cost[3].spend_count_categories += sum;
		mas_cost[3].count_categories++;
		mas_cost[3].set_data_pay();

		break;

	case 5:
		cout << "enter the purchase amount in this category: " << endl;

		cin >> sum;
		Card_selection(pocket, sum);
		mas_cost[4].spend_count_categories += sum;
		mas_cost[4].count_categories++;
		mas_cost[4].set_data_pay();

		break;

	default:

		cout << "Wrong categori";
		goto Start;

		break;
	}
}