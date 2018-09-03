// SimpleList.cpp

#include <cassert>
#include "SimpleListL.h"
 
SimpleList::SimpleList(){
 	size = 0;
	head = NULL;
 	last = NULL;
 	
}
SimpleList::~SimpleList(){
    cout << "Destructor called" << endl;
    Node *current = head;
	if(size!=0)
	{
		while (current != 0) {
			Node *next = current->next;
			delete current;
			current = next;
		}
	head = NULL;
	size=0;
	}
    
}
SimpleList::SimpleList(const SimpleList& listToCopy){
    cout << "copy constructor called" << endl;
    size=0;
    current = 0;
	Node *next = 0;
	if (listToCopy.head == 0)
		head = 0;
	else {
		head = new Node();
		head->next = listToCopy.head->next;
		head->data = listToCopy.head->data;

		current = head;
		next = listToCopy.head->next;
		size++;
	}

	while (next) {
		current->next = new Node();
		current = current->next;
		current->next = next->next;
		current->data = next->data;

		next = next->next;
		size++;
	}

	current->next = 0;
	last=current;
}
SimpleList & SimpleList::operator=(const SimpleList & listToCopy){
    cout << "override called" << endl;
  //previous datas are being erasing

	  Node *current = head;
	if(size!=0)
	{
		while (current != 0) {
			Node *next = current->next;
			delete current;
			current = next;
		}
	head = NULL;
	size=0;
	}

	// nodes are copied from listToCopy
	 size=0;
    current = 0;
	Node *next = 0;
	if (listToCopy.head == 0)
		head = 0;
	else {
		head = new Node();
		head->next = listToCopy.head->next;
		head->data = listToCopy.head->data;

		current = head;
		next = listToCopy.head->next;
		size++;
	}

	while (next) {
		current->next = new Node();
		current = current->next;
		current->next = next->next;
		current->data = next->data;

		next = next->next;
		size++;
	}

	current->next = 0;
	last=current;


    return *this;
}


bool SimpleList::empty () const{
 	return size == 0;
}
 
int SimpleList::listSize () const{
 	return size;
}

void SimpleList::append (const ItemType & item){
	Node * append = new Node();
	append->data = item;
	if(size!=0){
		last->next = append;
        last = append;
	}else{
		head = append;
		last = append;
	}

	
    current = last;
    last->next = NULL;
	size++;
}
void SimpleList::display (ostream & out) const{
 	Node *now = head;
	while(now!=NULL){
		out<< now->data << endl;
		now = now->next;
	}
}


void SimpleList::setCurrentToIndex(int i){
    Node * temp = head;
    while (i!=0) {
        current = head;
        
        head = head->next;
        i--;
    }
    head = temp;
    
}
void SimpleList::setCurrentToEnd(){
    setCurrentToIndex(size);
}
void SimpleList::insert (const ItemType & item, int position){
    assert (position >= 0 && position-1 <= size);
    
    Node * insert = new Node();
	insert->data = item;
    if(size==0){
        head=insert;
    }
    else if (position==1){
            insert->next=head;
	head=insert;
        
    }else{
        
        Node *current=head;
	int count =0;

	while(count<position-2 && current!= NULL){
		current=current->next;
		count++;
	}

	insert->next=current->next;
	current->next=insert;
    }
    
    
    size++;
    
}

ItemType SimpleList::retrieve (int position){
    assert (position >= 0 && position-1 < size);
    int i = position;
    setCurrentToIndex(i);
    return current->data;
}
ItemType SimpleList::getItem() const{
  
    return current->data;
}

void SimpleList::remove (int position){
    assert (position >= 0 && position <= size);
   
    Node *current=head;
	Node *previous=NULL;
	Node * temp;
	if (position==1){
		temp=head;
		head=head->next;
		delete temp;
	}

	else{
		for(int i=1; i<position; i++){
			previous=current;
			current=current->next;
		}
		
		previous->next=current->next;
		delete current;
	}

	size--;    
}

void SimpleList::next(){
    current = current->next;
}

void SimpleList::moveToStart(){
    current = head;
}

bool SimpleList::pastTheEnd() const
{
	return !(current);
}
