#include "PhoneBook.h"
#include<iostream>
#include<fstream>

using namespace std;

const string fileName = "PhoneBook.txt";

inline bool PhoneBook::IsValidPosition(int pos)
{
	return pos > 0 && pos <= size;
}

PhoneBook::PhoneBook()
{
	book = nullptr;
	size = 0;
}

PhoneBook::~PhoneBook()
{
	if (book != nullptr) {
		delete[] book;
	}
}


void PhoneBook::AddContact(Contact contact)
{
	Contact* newBook = new Contact[size + 1];

	for (int i = 0; i < size; i++) {
		newBook[i] = book[i];
	}
	newBook[size] = contact;

	delete[] book;
	book = newBook;
	++size;
}

void PhoneBook::DelContact(int pos)
{
	if (IsValidPosition(pos) == 1 && book != nullptr) {

		--size;
		Contact* newBook = new Contact[size];
		for (int i = 0; i < size; i++) {
			if (i < pos - 1)
				newBook[i] = book[i];
			else
				newBook[i] = book[i + 1];
		}
		delete[]book;
		book = newBook;
	}
	else {
		cout << "Enter correct number!" << endl;
	}
}

bool  PhoneBook::SearchByName(const char _name[]) const
{
	for (int i = 0; i < size; i++) {
		return strcmp(book[i].name, _name) == 0;
	}
}

bool  PhoneBook::SearchByPhoneNumber(const char mobile[]) const
{
	for (int i = 0; i < size; i++) {
		return strcmp(book[i].mobileNumber, mobile) == 0;
	}
}

void PhoneBook::ShowAllContacts() const
{
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ") " << book[i].name << " (" <<
			book[i].note << ")" << endl;
		cout << "\tMobile: " << book[i].mobileNumber << endl;
		cout << "\tHome: " << book[i].homeNumber << endl;
	}
}

Contact PhoneBook::SetContact(const char _name[], const char mobile[], const char home[], const char note[])
{
	Contact newContact;
	strcpy_s(newContact.name, 50, _name);
	strcpy_s(newContact.mobileNumber, 20, mobile);
	strcpy_s(newContact.homeNumber, 20, home);
	strcpy_s(newContact.note, 20, note);

	return newContact;
}

void PhoneBook::Save() const
{
	ofstream fout;
	fout.open(fileName);
	bool isOpen = fout.is_open();
	if (isOpen == true) {
		fout << size << endl;
		for (int i = 0; i < size; i++) {
			fout << book[i].name << endl;
			fout << book[i].mobileNumber << endl;
			fout << book[i].homeNumber << endl;
			fout << book[i].note << endl;
		}
	}
	else {
		cout << "Error!" << endl;
	}

	fout.close();
}

void PhoneBook::Load() 
{
	int size;
	ifstream fin;
	fin.open(fileName);

	bool isOpen = fin.is_open();
	if (isOpen == true) {

		fin >> size;
		Contact getContact;
		for (int i = 0; i < size; i++) {
			fin >> getContact.name;

			fin >> getContact.mobileNumber;
			fin >> getContact.homeNumber;
			fin >> getContact.note;

			AddContact(getContact);
		}
	}
	else {
		cout << "Error!" << endl;
	}

	fin.close();
}

