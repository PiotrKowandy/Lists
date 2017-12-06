#include <iostream>
#include <string>
using namespace std;

struct SElement{

	string name;
	string last_name;
	int age;
	SElement *next;
	SElement(){
	next=0;
	}
};

struct SBase{
	SElement *first;
	void add(string, string, int);
	void show_list();
	SBase(){
	first=0;
	}
};

void SBase::add(string name, string last_name, int age){
	cout << "I'm adding new element to base." << endl;
	SElement *new_element = new SElement;

	new_element->name = name;
	new_element->last_name = last_name;
	new_element->age = age;

	cout << "I'm looking any element in base." <<endl;

	if (first == 0){
		first= new_element;
		cout << "First element added." << endl;
	}
	else {
		SElement *temp = first;
		cout << "I'm walking thru all elements in base until i found last element." << endl;

		while (temp->next){
		temp = temp->next;
		}

		cout << "Element has been added to end of list." << endl;

		temp->next = new_element;
		new_element->next=0;

	}
}

void SBase::show_list(){
	SElement *temp = first;

	cout << "Name: " << temp->name << endl;
	while (temp->next){
	cout << "Name: " << temp->next->name << endl;
	temp= temp->next;
	}
}

int main (int argc, char *argv[]){

	cout << "I'm creating base." <<endl;
	SBase *base = new SBase;

	cout << "I'm adding 3 elements to the base." << endl;
	base->add("John", "Boo", 34);
	base->add("Mickey", "Walter", 22);
	base->add("Stacy", "Mitcher", 45);

	base->show_list();

	cout << "I'm deleting base." << endl;
	delete (base);

	return 0;
}
