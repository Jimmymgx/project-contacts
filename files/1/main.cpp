#include <iostream>
#include "contactList.h"
using namespace std;

int main()
{
	int option;
	char c='y';

	string name,number,address,email,key,newitem;
	while(c!='n'||c!='N')
	{
	contactList x = contactList();
	cout<<"Choose one option from the following"<<endl;
	cout<<"0 for Adding new Contact"<<endl;
	cout<<"1 for searching for a contact"<<endl;
	cout<<"2 for editing contact"<<endl;
	cout<<"3 for showing all the list"<<endl;
	cout<<"4 for loading the contact from files"<<endl;
	cin>>option;
	switch(option){
	case 0:
		cout<<"Enter Name: ";
		cin>>name;
		cout<<"Enter Number: ";
		cin>>number;
		cout<<"Enter Address: ";
		cin>>address;
		cout<<"Enter E-mail: ";
		cin>>email;
		x.addContact(name,number,address,email);
		break;
	case 1:
		cout<<"Enter the search key: ";
		cin>>key;
		x.search(key);
		break;
	case 2:
		cout<<"Enter the search key: ";
		cin>>key;
		cout<<"Enter the new item: ";
		cin>>newitem;
		x.edit(key,newitem);
		break;
	case 3:
		x.print();
		break;
	case 4:
		x.load();
		break;
	default:
		cout<<"incorrect input";
	}
	
	cout<<"Do you want to continue: (y) for Yes , (n) for NO "<<endl;
	cin>>c;
	
	}
	system("pause");
	return 0;
	}