/*
 *file: comprehensive_example.cpp
 *function: ×ÛºÏÁ·Ï°Ìâ
 *author: yws
 *date: 
 *notes:
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

/*type definition -----------------------------------*/
typedef struct
{
	string book_name;
	string author_name;
	double price;
}TagBook;

typedef struct
{
	string author_name;
	int count;
}TagStatic;

/*function declare------------------------------------*/
/*
 *@brief: read data from file
 *@param: string filename:
 *        vector<Tagbook> &vec_book
 *@reval: void
 */
void read_book_info(string filename, vector<TagBook> &vec_book);
/*
*@brief: display book information
*@param: vector<Tagbook> &vec_book
*@reval: void
*/
void print(vector<TagBook> &vec_book, bool row = true);
/*
*@brief: find a static infomation
*@param: vector<TagBook> &vec_book
*        vector<TagStatic> &vec_static
*@reval: void
*/
void static_count_by_author(vector<TagBook> &vec_book, vector<TagStatic> &vec_static);
/*
*@brief: find a author
*@param: vector<TagStatic> &vec_static
*@reval: vector<TagStatic>::iterator
*/
vector<TagStatic>::iterator find_author(vector<TagStatic> &vec_static, string author_name);
/*
*@brief: delete book
*@param: vector<TagBook> &vec_book
*        double price
*@reval: void
*/
void delete_book(vector<TagBook> &vec_book, double price);
/*
*@brief: display static information
*@param: vector<TagStatic> &vec_static
*@reval: void
*/
void print(vector<TagStatic> &vec_static);
/*
*@brief: compare function by book name
*@param: TagBook book1
*        TagBook book2
*@reval: bool
*/
bool comp_book_name(TagBook book1, TagBook book2);
/*
*@brief: compare function by book price
*@param: TagBook book1
*        TagBook book2
*@reval: bool
*/
bool comp_book_price(TagBook book1, TagBook book2);

/*function definition---------------------------------*/
void read_book_info(string filename, vector<TagBook> &vec_book)
{
	TagBook  book;
	ifstream in(filename.c_str());
	string book_str;
	if (!in)
	{
		cout << "Can't open the file: " << filename << endl;
		exit(0);
	}
	while (getline(in, book_str))
	{ 
		istringstream sin(book_str);
		sin >> book.book_name >> book.author_name >> book.price;
		vec_book.push_back(book);
	}
}

void print(vector<TagBook> &vec_book, bool row)
{
	vector<TagBook>::iterator it = vec_book.begin();
	while (it != vec_book.end())
	{
		if (row)
		{
			cout << setw(30) << it->book_name << setw(20) << it->author_name << setw(10) << fixed << setprecision(2) << it->price << endl;
		}
		else
		{
			cout << "===============================\n"
				<< it->book_name << "\n"
				<< it->author_name << "\n"
				<< fixed << setprecision(2) << it->price << endl;
		}
		++it;
	}
}

void static_count_by_author(vector<TagBook> &vec_book, vector<TagStatic> &vec_static)
{
	vector<TagBook>::iterator it = vec_book.begin();
	vector<TagStatic>::iterator it_static;
	TagStatic static_data;
	while (it != vec_book.end())
	{		
		it_static = find_author(vec_static, it->author_name);
		/*Have not this author*/
		if (it_static == vec_static.end())
		{
			static_data.author_name = it->author_name;
			static_data.count = 1;
			vector<TagBook>::iterator it2 = it + 1;
			while (it2 != vec_book.end())
			{
				if (it2->author_name == static_data.author_name)
				{
					static_data.count++;					
				}
				it2++;
			}
			vec_static.push_back(static_data);				
		}
		++it;
	}
}

vector<TagStatic>::iterator find_author(vector<TagStatic> &vec_static, string author_name)
{
	vector<TagStatic>::iterator it = vec_static.begin();
	while (it != vec_static.end())
	{
		if (author_name == it->author_name)
			break;
		else
			++it;
	}
	return it;
}

void print(vector<TagStatic> &vec_static)
{
	vector<TagStatic>::iterator it = vec_static.begin();
	while (it != vec_static.end())
	{
		cout << setw(20) << it->author_name << setw(10) << it->count << endl;
		++it;
	}
}

void delete_book(vector<TagBook> &vec_book, double price)
{
	vector<TagBook>::iterator it = vec_book.begin();
	while (it != vec_book.end())
	{
		if (it->price < price)
			it = vec_book.erase(it);
		else
			++it;
	}
}

bool comp_book_name(TagBook book1, TagBook book2)
{
	return book1.book_name.length() < book2.book_name.length();
}

bool comp_book_price(TagBook book1, TagBook book2)
{
	return book1.price < book2.price;
}

/*test program-------------------------------------------*/
int main()
{
	vector<TagBook> vec_book;
	vector<TagStatic> vec_static;
	string filename = "data.txt";

	/*===read data=========*/
	read_book_info(filename, vec_book);
	cout << "===one row===\n";
	print(vec_book);
	cout << "====multi row===\n";
	print(vec_book,false);

	/*===static author ====*/
	static_count_by_author(vec_book, vec_static);
	cout << "======static result===========\n";
	print(vec_static);

	/*===delete book===*/
	delete_book(vec_book, 20);
	cout << "====one row after deletion===\n";
	print(vec_book);

	sort(vec_book.begin(), vec_book.end(), comp_book_name);
	cout << "====one row after sort by book name===\n";
	print(vec_book);

	sort(vec_book.begin(), vec_book.end(), comp_book_price);
	cout << "====one row after sort by book price===\n";
	print(vec_book);

	return 0;
}
