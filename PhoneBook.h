#pragma once
#include<iostream>
using namespace std;

struct Contact
{
	char name[50];
	char mobileNumber[20];
	char homeNumber[20];
	char note[20];	
};

class PhoneBook
{
private:
	Contact* book;
	int size;

	inline bool IsValidPosition(int pos);

public:
	
	PhoneBook();
	~PhoneBook();

	void AddContact(Contact contact);
	void DelContact(int pos);
	bool SearchByName(const char _name[]) const;
	bool SearchByPhoneNumber(const char mobile[]) const;
	void ShowAllContacts() const;
	Contact SetContact(const char _name[],const char mobile[], const char home[], const char note[]);

	void Save() const;
	void Load() ;

};

