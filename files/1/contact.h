#include<iostream>
#include<string>

using namespace std;

class contact
{
	private:
		string name;
		string address;
		string email; 	
		string number;	
		contact* next;
	public:	
		contact();	
		contact(string newname, string newaddress,string newemail,string newnumber);	
		contact(string newname,string newaddress, string newemail,string newnumber, contact* nextContactPtr);	
		void setname(string newname);	
		void setaddress(string newaddress);	
		void setemail(string newemail);	
		void setnumber(string newint);	
		void setNext(contact* nextNodePtr);    
		string getname() const;    
		string getaddress() const;    
		string getemail() const;    
		string getnumber() const;	
		contact* contact::getNext() const;
}; 

//Constructors
contact::contact()
{
	name = "";
	number = "";
	email = "";
	address = "";
	next = nullptr;
}

contact::contact(string newname, string newaddress,string newemail,string newnumber)
{
	name = newname;
	number = newnumber;
	address = newaddress;
	email = newemail;
	next = nullptr;
}

contact::contact(string newname,string newaddress, string newemail,string newnumber, contact* nextContactPtr)
{
	name = newname;
	number = newnumber;
	address = newaddress;
	email = newemail;
	next = nextContactPtr;
}

//Setters
void contact::setname(string newname )
{
	name = newname;
}

void contact::setnumber(string newnumber )
{
	number = newnumber;
}

void contact::setaddress(string newaddress )
{
	address = newaddress;
}

void contact::setemail(string newemail )
{
	email = newemail;
}

void contact::setNext(contact* nextNodePtr)
{
	next = nextNodePtr;
}

//Getters
string contact::getname() const
{
	return name;
}

string contact::getnumber() const
{
	return number;
}

string contact::getaddress() const
{
	return address;
}

string contact::getemail() const
{
	return email;
}

contact* contact::getNext() const
{
	return next;
}