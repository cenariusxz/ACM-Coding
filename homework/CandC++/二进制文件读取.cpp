/**------------------------------------------------------------------------------------
*@filename: file_2.cpp
*@function: The example about file operator
*@author: yws
*@date: 2014-09-23
*@notes:
*-------------------------------------------------------------------------------------
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

/*data type declare-------------------------------------------------*/
typedef struct
{
	char book_name[50];
	char author_name[20];
	float price;
}TagBook;

/*function declare------------------------------------------------------*/
/*@brief: input book informations to binary file
 *@param: char file_name[]:file name
 *        int num: the numbers of books
 *@retval: void
 */
void input_books(char file_name[], int num);

/*@brief: read all book informations to binary file
 *@param: char file_name[]:file name
 *        TagBook books[]: the book's data
 *@retval: int: the numbers of book
 */
int read_books(char file_name[], TagBook books[]);

/*@brief: display book informations to binary file
 *@param: TagBook books[]: the book's data
 *        int count:  the number of book
 *@retval: void
 */
void display_books(TagBook books[], int count);

/*@brief: read some book informations to binary file
 *@param: char file_name[]: the file name
 *        int number:  the number of book
 *@retval: TagBook: the book's information
 */
TagBook read_one_book(char file_name[], int number);

/*function defintion------------------------------------------------*/
void input_books(char file_name[], int num)
{
	ofstream outfile;
	TagBook  temp_book;
	// open the file;
	outfile.open(file_name, ios::out|ios::binary);
	if (outfile.fail())
	{
		cout << "Can't open the file:" << file_name << endl;
		exit(0);
	}

	// write data
	for (int i = 0; i < num; i++)
	{
		// input book information from keyboard
		cout << "Pleas input No." << i + 1 << "book's information:\n";
		cin >> temp_book.book_name >> temp_book.author_name >> temp_book.price;
		outfile.write((char*)&temp_book, sizeof(temp_book));
	}
	// close file
	outfile.close();
}

int read_books(char file_name[], TagBook books[])
{
	ifstream infile;
	int num;
	// open the file;
	infile.open(file_name, ios::in|ios::binary);
	if (infile.fail())
	{
		cout << "Can't open the file:" << file_name << endl;
		exit(0);
	}
	
	// read book's information
	infile.seekg(0, SEEK_END);
	num = infile.tellg() / sizeof(TagBook);
	infile.seekg(0, SEEK_SET);
	infile.read((char*)books, num*sizeof(TagBook));
	// close file
	infile.close();
	return num;
}

void display_books(TagBook books[], int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << books[i].book_name << "  "<< books[i].author_name << setw(8) << showpoint
			<< books[i].price << "\n";
	}
}

TagBook read_one_book(char file_name[], int number)
{
	TagBook book;
	ifstream infile;
	int num;
	// open the file;
	infile.open(file_name, ios::in|ios::binary);
	if (infile.fail())
	{
		cout << "Can't open the file:" << file_name << endl;
		exit(0);
	}
	// read book's information
	infile.seekg(0, SEEK_END);
	num = infile.tellg() / sizeof(TagBook);
	if (num < number)
	{
		cout << "There is not enough book's data!\n";
		infile.close();
		return book;
	}
	infile.seekg(0, SEEK_SET);
	infile.seekg(number*sizeof(TagBook), SEEK_SET);
	infile.read((char*)&book, sizeof(TagBook));

	//close file
	infile.close();
	return book;
}

/*test program----------------------------------*/
int main()
{
	TagBook  books[40], book;
	int count, number, index;
	char file_name[20];

	cout << "Please input the number of book:\n";
	cin >> number;
	cout << "Pleas input the file name:\n";
	cin >> file_name;
	// write book's information to file
	input_books(file_name, number);
	count = read_books(file_name, books);
	display_books(books, count);

	//
	cout << "Pleas input the index of book:\n";
	cin >> index;
	book = read_one_book(file_name, index);
	display_books(&book, 1);

	return 0;
}

