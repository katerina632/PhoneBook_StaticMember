#include<iostream>
#include"Circle.h"
#include "PhoneBook.h"

using namespace std;


int main() {
	//Zavdannja 1
	/*Circle first;
	Circle second(5);
	Circle third(2);

	first.Print();
	second.Print();	


	third.Print();

	cout <<"Count of circles - "<< Circle::GetCountOfCircles() << endl;
	cout << "Amount of circles areas - " <<Circle::GetAmountOfAreas() << endl;

	cout << "Radius of second circle - " << second.GetRadius() << endl;*/

	//Zavdannja 2
	PhoneBook book;

	Contact tempContact;	
	tempContact=book.SetContact("Kate", "0951234567", "112233", "job");
	book.AddContact(tempContact);

	tempContact = book.SetContact("Bob", "0681234567", "556677", "friend");
	book.AddContact(tempContact);

	tempContact = book.SetContact("John", "0771234567", "887799", "fromShop");
	book.AddContact(tempContact);

	book.ShowAllContacts();
	cout << endl;
	if (book.SearchByName("Kate")) {
		cout << "Contact is exist!" << endl;
	}
	else {
		cout << "Contact doesn't exist!" << endl;
	}

	if (book.SearchByPhoneNumber("0951234567")) {
		cout << "Contact is exist!" << endl;
	}
	else {
		cout << "Contact doesn't exist!" << endl;
	}
	cout << endl;

	book.DelContact(2);
	cout << endl;

	book.ShowAllContacts();
	cout << endl;
	book.Save();
	PhoneBook book2;
	book2.Load();
	book2.ShowAllContacts();
	
	system("pause");
	return 0;
}