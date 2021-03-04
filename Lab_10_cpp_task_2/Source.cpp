#include <iostream>
#include <list>
#include <ctime>
#include <clocale>
#include <algorithm> 
#include <iterator>
#define DEBUG
#define F_REVERCE 1

using namespace std;
using std::cout;

typedef unsigned int  u_int;
typedef short int     s_int;
typedef unsigned char u_char;


/*Функиця заполняет список элементами пользователя*/
template<typename T>
void inptList(list<T> &ls) {
#undef DEBUG

	int size;
	int i = 0;

	cout << "Введите количество элементнов в каждой тройке" << endl;
	cout << "Ввод: "; cin >> size;

	ls.clear();			
	ls.resize(size,0);

	cout << "Введите " << size << "элемента(ов)" << endl;
	for (auto& it : ls) {
		cout << "[" << i++ << "] ";
		cin  >> it;
	}
	
	auto it = ls.begin();

	for (int i = 0; i < 2 * size; i++)
		ls.push_back(*it++);
	
	return;
};

/*Функция выводит часть элементов списка. Флаг указыывает на направление вывода элементов*/
template<typename T>
void outList(list<T> ls, size_t st_item, size_t en_item , u_char flag = 0) {
	
	if (st_item > en_item)
		swap(st_item, en_item);
	
	if (en_item > ls.size())
		return;

	if (!flag) {
		auto st_it = ls.begin();
		auto en_it = ls.begin();

		advance(st_it, st_item);
		advance(en_it, en_item);

		copy(st_it, en_it, ostream_iterator<T>(cout, " "));
	}
	else
	{
		auto st_it = ls.rbegin();
		auto en_it = ls.rbegin();

		swap(st_item, en_item);
		st_item = ls.size() - st_item;
		en_item = ls.size() - en_item;

		advance(st_it, st_item);
		advance(en_it, en_item);

		copy(st_it, en_it, ostream_iterator<T>(cout, " "));
	}

	cout << endl;

	return;
};


int main(){
	setlocale(0, "");

	list<int> inpt_l = {0,1,2,3,4,5,6,7,8};
	list<int> buf;
	int answ = 0;
		
	cout << "Выберите способ заполнения списка" << endl;
	cout << "1 - с помощью конструктора"     << endl;
	cout << "2 - с помощью итераторов"          << endl;
	cout << "Выбор: "; cin >> answ;
	
	if (answ == 2) 
		inptList(inpt_l);
	
#ifdef DEBUG
	cout << "---------S_ENTRY_MASS---------" << endl;
	for (const auto& it : inpt_l)
		cout << it << endl;
	cout << "---------E_ENTRY_MASS---------" << endl;
#endif // DEBUG

	outList(inpt_l, 0, inpt_l.size()/3);
	outList(inpt_l, inpt_l.size() / 3, inpt_l.size() * 2 / 3, F_REVERCE);
	outList(inpt_l, inpt_l.size() * 2 / 3, inpt_l.size(), F_REVERCE);
	
 	return 0;
}