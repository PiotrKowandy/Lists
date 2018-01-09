#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct SElem{
	int number;
	string name;
	string last_name;
	SElem* prev;
	SElem* next;
	SElem(){
		prev =0;
		next=0;
		number=1;
	}
};

struct SBase{
	SElem *head, *tail;
	void add_elem(string name, string last_name);
	SElem show();
	void assign_num();
	void show_all_beg();
	void show_all_end();
	void show_head();
	void show_tail();
	int remove_one(int);
    bool ifempty();
    int how_many();
	SBase(){
		head=tail=0;
	}
};

void SBase::add_elem(string name, string last_name){
	if (head ==0){
		SElem *new_elem = new SElem;
		new_elem->name=name;
		new_elem->last_name=last_name;
		new_elem->prev = 0;
		new_elem->next=0;
		head = new_elem;
		tail = new_elem;
	}
	else{
		SElem *new_elem = new SElem;
		new_elem->name = name;
		new_elem->last_name = last_name;
		new_elem->prev=0;
		SElem *temp_he = head;
        head = new_elem;
        head->next = temp_he;
        temp_he->prev = head;
	}
}

void SBase::show_all_beg(){
    if (head){
        if (head->next== 0){
        cout << head->number << " " << head->name << " " <<head->last_name << endl;
        }
        else{
            SElem *temp = head;
            while (temp->next){
                cout << temp->number << " " << temp->name << " " << temp->last_name << endl;
                temp = temp->next;
            }
            cout << temp->number << " " << temp->name << " " << temp->last_name << endl;
        }
    }
    else{
        cout <<"No more elements in base."<< endl;
    }

}

void SBase::show_all_end(){
    if (tail){
        SElem *temp = tail;
        if (temp->prev == 0){
            cout << temp->number << " " << temp->name << " " << temp->last_name << endl;
        }
        else{
            while (temp->prev){
                cout << temp->number << " " << temp->name << " " << temp->last_name << endl;
                temp = temp->prev;
            }
            cout << temp->number << " " << temp->name << " " << temp->last_name << endl;
        }
    }
    else{
        cout <<"No more elements in base."<< endl;
    }
}

void SBase::show_tail(){
    if (tail){
        cout<< "this is tail: " << tail->name << " " << tail->last_name << endl;
    }
    else{
        cout << "There isn't tail in base. Base is empty." << endl;
    }
}

void SBase::show_head(){
    if (head){
        cout << "this is head: " << head->name << " " << head->last_name<< endl;
	    }
    else{
        cout << "There isn't head in base. Base is empty." << endl;
    }
}

bool SBase::ifempty(){

    if (head){
        return true;
    }
    else{
        return false;
    }
}

int SBase::how_many(){
    if (tail){
        return tail->number;
    }
    else{
        return 0;
    }
}

void SBase::assign_num(){
    if (head != 0){
        SElem *temp = head;
        temp->number=1;
        while (temp->next){
            temp->next->number = temp->number +1;
            temp = temp->next;
        }
	}
}

int SBase::remove_one(int number){

	SElem *temp = head;
	SElem *temp_t = tail;
	if (temp == 0){
		cout << "Base is empty." << endl;
	}
	else if (temp == temp_t && temp->number == number){
        cout << temp->name << " " << temp_t->name << endl;
        SElem *temp_h = head;
        head = tail = 0;
        delete temp_h;
        cout << "Head and tail were one element which has been removed. Base is empty. " << endl;
	}
	else{
        if (temp->number == number){
            head = temp->next;
            head->prev = 0;
            delete temp;
            cout << "One element has been removed" << endl;
        }
        else if (temp_t->number == number){
            tail = temp_t->prev;
            tail->next=0;
            delete temp_t;
            cout << "Last element known as tail has been erased." <<endl;
        }
        else{
            while (temp->next){
                if (temp->next->number==number){
                    SElem *temp_ne = temp->next;
                    temp_ne->next->prev = temp;
                    temp->next = temp_ne->next;
                    delete temp_ne;
                    cout << "Element has been erased." << endl;
                }
                temp = temp->next;
            }
        }
	}
}


int main (int argc, char * argv[]){

	SBase *new_base = new SBase;
    string name, last_name;
	int button, many, which_one;

	do{
        cout << "1- Add element to base. ----------------" << endl;
        cout << "2- Add random elements to base. --------" << endl;
        cout << "3- Show all elements from begin. -------" << endl;
        cout << "4- Show all elements from end. ---------" << endl;
        cout << "5- How much elements are in base. ------" << endl;
        cout << "6- Show me head. -----------------------" << endl;
        cout << "7- Show me tail. -----------------------" << endl;
        cout << "8- Remove one element from base. -------" << endl;

        cout << endl << "Pick one option of above list (number 0 is equal with exit): " << endl << endl;
        cin >> button;

        switch (button){
            case 0:{
                system("CLS");
                many = new_base->how_many();
                for (int i=1; i<many; i++){
                    if (new_base->ifempty()){
                        new_base->remove_one(i);
                    }
                    else {
                        cout <<"No more elements to erase."<< endl;
                    }
                }
                cout << "All elements have been removed." << endl;
                delete new_base;
                break;
            }
            case 1:{
                system("CLS");
                cout << "Please give name: ";
                cin >> name;
                cout << endl << "Please give last name: ";
                cin >> last_name;
                cout << endl;
                new_base->add_elem(name, last_name);
                cout << "Element has been added to base." << endl;
                new_base->assign_num();
                cout << endl;
                break;
            }
            case 2:{
                system("CLS");
                new_base->add_elem("Gregory", "House");
                new_base->add_elem("Margaret", "Snowitch");
                new_base->add_elem("Stephany", "Cools");
                new_base->add_elem("Mark", "Francis");
                new_base->assign_num();
                cout << "Elements have been added to base. " << endl;
                cout << endl;
                break;
            }

            case 3:{
                system("CLS");
                cout << endl << "List from begin: " << endl;
                new_base->show_all_beg();
                cout << endl;
                break;
            }

            case 4:{
                system("CLS");
                cout << endl << "List from end: " << endl;
                new_base->show_all_end();
                cout << endl;
                break;
            }

            case 5:{
                system("CLS");
                many = new_base->how_many();
                cout << "Currently base has: " << many << " elements." << endl;
                cout << endl;
                break;
            }

            case 6:{
                system("CLS");
                new_base->show_head();
                cout << endl;
                break;
            }

            case 7:{
                system("CLS");
                new_base->show_tail();
                cout << endl;
                break;
            }

            case 8:{
                system("CLS");
                new_base->show_all_end();
                cout << "Which one from list You choice: " << endl;
                cin >> which_one;
                new_base->remove_one(which_one);
                new_base->assign_num();
                cout << endl;
                break;
            }
        };

	}while (button != 0);

	return 0;
}

