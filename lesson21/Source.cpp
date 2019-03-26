#include <iostream>
#include <clocale>
#include <fstream>
#define use using namespace std;
use
int buf_size = 0;
int cur_size = 0;


//#define N 100
//#define str "Hello, World!"
//#define begin {
//#define end }
//#define program int main()
//#define read cin>>
//#define screen_save system("pause");
//#define exit return 0;
//#define print cout<<
//#define Integer int
//#define maximum(a,b)(a>b?a:b)
//#define chetn(a)(a%2==0)
//
//program begin
//Integer a, b;
//read a;
//read b;
//print maximum(a, b);
//print chetn(a);

struct flat {
	int flat_no : 9, rooms : 4, area : 9;
	void print() {
		cout << flat_no << " " << rooms << " " << area;
	}
};

struct home
{
	char home_no[30];
	int flat_amount: 9;
	flat* fs=NULL;
	void print() {
		cout << home_no << endl;
		if(fs!=NULL)
		for (size_t i = 0; i < flat_amount; i++)
		{
			fs[i].print();
		}
	}
};



template<typename T>
void add(T*&fs, T el)
{
	if (buf_size == 0)
	{
		buf_size = 4;
		fs = new T[buf_size];
	}
	else
	{
		if (cur_size == buf_size)
		{
			buf_size *= 2;
			T* tmp = new T[buf_size];
			for (size_t i = 0; i < cur_size; i++)
			{
				tmp[i] = fs[i];
			}
			delete[] fs;
			fs = tmp;
		}
	}
	fs[cur_size++] = el;
}

int main() {
	setlocale(LC_ALL, "RUS");
	ifstream in_file("in.txt");

	int tmp;
	flat el;
	home* hs = 0;
	home home_el;
	flat* fs = 0;
	while (!in_file.eof())
	{
		in_file >> home_el.home_no >> tmp;
		home_el.flat_amount = tmp;
		home_el.fs = new flat[tmp];
		for (int i = 0; i < home_el.flat_amount; i++) {
			in_file >> tmp;
			home_el.fs[i].flat_no = tmp;
			in_file >> tmp;
			home_el.fs[i].rooms = tmp;
			in_file >> tmp;
			home_el.fs[i].area = tmp;
		}
		add(hs, home_el);
	}
	
	for (size_t i = 0; i < cur_size; i++)
	{
		hs[i].print();
		cout << endl;
	}
	for (size_t i = 0; i < cur_size; i++)
	{
		delete[] hs[i].fs;
	}
	delete[] hs;
	system("pause");
	return 0;
}