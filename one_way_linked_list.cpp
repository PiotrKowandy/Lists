#include <iostream>
#include <string>
using namespace std;

struct SElement{
	int number;
	string name;
	string last_name;
	int age;
	bool removed;
	SElement *next;
	SElement(){
	next=0;
	number=0;
	}
};

struct SBase{
	bool removed;
	SElement *first;
	void add(string, string, int);
	void show_list();
	void assign_numbers();
	int remove_element(int);
	void remove_last();
	int how_much();
	bool any_element();
	void delete_base(SBase *base);
	SBase(){
	first=0;
	removed=false;
	}
};

void SBase::add(string name, string last_name, int age){
	SElement *new_element = new SElement;

	new_element->name = name;
	new_element->last_name = last_name;
	new_element->age = age;

	if (first == 0){
		first= new_element;
		first->number=1;
		cout << "First element added." << endl;	
	}
	else {
		SElement *temp = first;
		while (temp->next){
			temp = temp->next;
		}
		
		new_element->number = temp->number+1;		
		
		cout << "Element has been added to end of list." << endl;
		temp->next = new_element;
		new_element->next=0;

	}
}

void SBase::show_list(){
	if (first){
		SElement *temp = first;
		cout << endl;	
		cout << temp->number << " Name: " << temp->name 
				     << " " << temp->last_name
				     << " " << temp->age << endl;
		while (temp->next){
			cout << temp->next->number << " Name: " << temp->next->name
						   << " " << temp->next->last_name
						   << " " << temp->next->age << endl;
			temp= temp->next;
		}
	}
	else{
		cout << "Base is empty." <<endl;
	}
}	

int SBase::remove_element(int number){
	if (first!=0){
		SElement *temp = first;
		removed=false;

		if (temp->number == number){
			SElement *temp_re = first;
			first = temp->next;
			cout << "First element has been removed." <<endl;
			delete temp_re;
			removed=true;
			assign_numbers();
		}
		else{
			while (temp->next){
				if (temp->next->number == number && temp->next->next){
                       			SElement *temp_bef = temp->next;
					temp->next = temp->next->next;
					cout << "This element will be erased: " << temp->next->number << endl;
					delete temp_bef;
					cout << "One element has been removed." <<endl;
					removed=true;
					assign_numbers();
				}
				else{
					if(!temp->next->next && temp->next->number == number){
						removed=true;
						remove_last();
					}
				}
				if (!removed){
					temp = temp->next;
				}
			}
		}
	}
	else{
		cout << "Base is empty." << endl;
	}

	if (!removed){
		assign_numbers();
		cout << "Element has been removed with succes." <<endl;
	}
}

void SBase::assign_numbers(){

	if (first){
		SElement *temp = first;
		temp->number=1;

		while(temp->next){
			temp->next->number = temp->number+1;
			temp = temp->next;
		}
	}
	else{
		cout << "Base is empty." << endl;
	}
}


void SBase::remove_last(){
	if (first != 0){
		SElement *temp = first;
		removed=false;
		if (temp->next == 0){
			delete first, temp;
			removed=true;
			assign_numbers();
			cout << "First alement was last element, which has been removed." << endl;
		}
		else{	
			while (temp->next){
				if (temp->next->next==0){
					SElement *temp_re = temp->next->next;
					temp->next=0;
					delete temp_re;
					removed=true;
					assign_numbers();	
					cout << "Last element has been deleted."<< endl;
					show_list();
				}
				if (!removed){
					temp= temp->next;
				}
			}
		}
	}
	else{
		cout << "Base is empty." << endl;
	}
}

int SBase::how_much(){
	int amount =0;
	if (first != 0){
		SElement *temp = first;
		amount++;
		while (temp->next){
			amount++;	
			temp = temp->next;
		}
	}
	else{
		cout << "Base is empty." << endl;
	}
	return amount;

}

bool SBase::any_element(){
	if (first){
		SElement *temp = first;

		if (temp){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}

}


int main (int argc, char *argv[]){
	system("clear");

	int choice=0;
	string name, last_name;
	int age, to_remove, amount;

	SBase *base = new SBase;
	
	do{
		cout << "-------------------------------------" << endl;
		cout << "-------------  Menu  ----------------" << endl;
		cout << "-------------------------------------" << endl;
		cout << "1. Show all elements in database." << endl;
		cout << "2. Add element to base." << endl;
		cout << "3. Remove element to base" << endl;
		cout << "4. How much elements is save into base." << endl;
		cout << "5. Add couple random elements to base." << endl; 	
		cout << "-------------------------------------" << endl << endl;

		cout << "0. exit (Remove every elements from base and delete base)" << endl << endl;
		cout << "Please choice one option." << endl;
		cin >> choice;

		switch (choice){
			case 1:{
				system("clear");
				cout << "1:--------";
				base->show_list();
				cout << "---------- " << endl << endl;
				break;
			}
			case 2:{
				system("clear");
				cout << "2:--------" << endl;
				cout << "Please give me name:" << endl;
				cin >> name;
				cout << "Please give me last name:" << endl;
				cin >> last_name;
				cout << "Please give me age:" << endl;
				cin >> age;
				base->add(name, last_name, age);
				break;
			}	
			case 3:{
				system("clear");
				cout << "3---------" << endl;
				if (base->any_element()){
					cout << "Which element do You want to remove:" << endl;
					base->show_list();
					cout << endl;
					cin >> to_remove;
					base->remove_element(to_remove);
				}	
				else{
					cout << "Base is empty." << endl;
					cout << "There isn't any element to remove." << endl;
				}
				break;			
			}
			case 4:{
				system("clear");
				cout << "4---------." << endl;
				amount = base->how_much();
				cout << "Amount of elements: " << amount << endl;
				break;
			}
			case 5:{
				system("clear");
				cout << "5---------" << endl;
				base->add("Henry", "Styles", 45);	
				base->add("Stacy", "McGregor", 33);
				base->add("Julia", "Roberts", 51);
				base->add("Bruce", "Willis", 62);
				base->add("Nina", "Dobrev", 28);
				cout << "Several items have been added to base." << endl;
				break;
			}
			case 0:{
				system("clear");
				cout << "Thanks for using program. Bye, bye." << endl;
				break;	
			}
		}
	}
	while(choice != 0);	

	int to_erase = base->how_much();
	cout << "How many elements: " << to_erase << endl;

	for (int i=to_erase; i > 0  ; i--){
		cout << "number " << to_erase << " will be removed." << endl;
        	base->remove_element(to_erase);
        	to_erase--;
         }

	delete base;
	
	return 0;
}
