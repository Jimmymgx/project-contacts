#include "contact.h"
#include <fstream>

class contactList
{
private:
	contact* head;
	
public:
	contactList();
	~contactList();
	void addContact(string name, string number, string address, string email);
	void search(string key);
	void edit(string key,string newitem);
	void print();
	void load();
	void save();
};

contactList::contactList()
{
	head = nullptr;
}
contactList::~contactList()
{
	
}
void contactList::addContact(string name, string number, string address, string email)
{
	
	if (head == nullptr)
	{
		contact* first = new contact;
		first->setemail(email);
        first->setaddress(address);
        first->setname(name);
        first->setnumber(number);
        first->setNext(nullptr);
		head = first;
	}
	else{
		contact *newContact = new contact;
		newContact->setemail(email);
        newContact->setaddress(address);
        newContact->setname(name);
        newContact->setnumber(number);
        newContact->setNext(nullptr);

		contact* current = head;
		while(current)
		{
			if(current->getNext() == nullptr)
			{
				current->setNext(newContact);
				break;
			}
		}
	}
}

void contactList::search(string key)
{
	contact *cur = head;
	bool flag= false;
	while(cur) {
		if(cur->getname().find(key) != std::string::npos) 
		{
			cout << cur->getname() << endl;
			flag = true;
		}
            cur = cur->getNext();
	}
	if(!flag)
		cout << "Not found!" << endl;
}

void contactList::print()
{
	contact* current = head;
	while(current)
	{
		cout << current->getname() << endl;
		cout << current->getnumber() << endl;
		cout << current->getaddress() << endl;
		cout << current->getemail() << endl;
		current = current->getNext();
	}
}

void contactList::edit(string key,string newitem)
{
	int option;
	cout << "Which of the following componenets do you want to edit Name(1), Number(2), Address(3), Email(4)?" << endl;
	cin >> option;
	contact* current = head;
	contact* cur = new contact;
	while(current)
	{
		if(key == current->getname())
			{
				cur = current;
				break;
			}
		current = current->getNext();
	}
	switch(option){
		case 1: 
			cur->setname(newitem);
			break;
		case 2: 
			cur->setemail(newitem);
			break;
		case 3: 
			cur->setaddress(newitem);
			break;
		case 4: 
			cur->setnumber(newitem);
			break;
    }
}

void contactList::load()
{
	ifstream name("name.txt");
	ifstream number("number.txt");
	ifstream address("address.txt");
	ifstream email("email.txt");
	
	string acqName;
	string acqNumber;
	string acqAddress;
	string acqEmail;
	
	while(!name.eof())
	{
		if(!name.eof())
	{
		name>>acqName;
	}
	if(!number.eof())
	{
		number>>acqNumber;
	}
	if(!address.eof())
	{
		address>>acqAddress;
	}
	if(!email.eof())
		email>>acqEmail;

	addContact( acqName, acqNumber, acqAddress, acqEmail);
	
	name.close();
	number.close();
	address.close();
	email.close();
}
}
void contactList::save()
{
	ofstream name;
	ofstream number;
	ofstream address;
	ofstream email;
	
	string acqName;
	string acqNumber;
	string acqAddress;
	string acqEmail;
	
	
	contact* current = head;
	while(current)
	{   name.open("name.txt",ios::out);
		acqName =current->getname();
		name << acqName;
		name.close();
		number.open("number.txt");
		acqNumber = current->getnumber();
		number << acqNumber;
		number.close();
		address.open("address.txt");
		acqAddress = current->getaddress();
		address << acqAddress ;
		address.close();
		email.open("email.txt");
		acqEmail=current->getemail();
		email << acqEmail;
		email.close();
		
	}

addContact( acqName, acqNumber, acqAddress, acqEmail);	
	
	
	
	
}