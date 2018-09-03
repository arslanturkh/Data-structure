// test program

#include "SimpleListL.h"

	
void testPhase1Methods(const SimpleList & sl);
// input: a SimpleList
// output: none
// side effects: displays test results on screen

void testPhase2Methods();
// input: none
// output: none
// side effects: displays test results on screen

void testCopyConstructor();
// input: none
// output: none
// side effects: displays test results on screen

void testOperator();
// input: none
// output: none
// side effects: displays test results on screen

void testIteratorMethods();
// input: none
// output: none
// side effects: displays test results on screen

int main(){
	SimpleList l;
	testPhase1Methods(l);
	l.append(76);
	l.append(36);
	cout << "after 2 appends" << endl;
	testPhase1Methods(l);
	testPhase2Methods();
	testCopyConstructor();
	testOperator();
	testIteratorMethods();
}
	
void testPhase1Methods(const SimpleList & sl){
	if(sl.empty())
		cout << "list is empty: " << endl;
	else
		cout << "list is not empty" << endl;
	cout << "size of list is: " << sl.listSize() << endl;
	cout << "contents of list: " << endl;
	sl.display(cout);
}

void testPhase2Methods(){
	cout << endl << "TESTING PHASE 2" << endl;
	SimpleList sl;
	sl.insert(34, 1);  // insert into an empty list
	cout << "\nafter insert into empty list: should be 34" << endl;
	for(int i = 1; i <= sl.listSize(); i++){
		cout << sl.retrieve(i) << "  ";
	}
	sl.insert(45, 1);  // insert at beginning of a list
	cout << "\nafter insert at beginning: should be  45, 34" << endl;
	for(int i = 1; i <= sl.listSize(); i++){
		cout << sl.retrieve(i) << "  ";
	}
	sl.insert(56, 2);  // insert in the middle of a list 
	sl.insert(72, 2);	
	cout << "\nafter inserts in middle: should be 45, 72, 56, 34" << endl;
	for(int i = 1; i <= sl.listSize(); i++){
		cout << sl.retrieve(i) << "  ";
	}
	sl.insert(67, 5);  // insert at end of a list
	cout << "\nafter insert at end: should be 45, 72, 56, 34, 67" << endl;
	for(int i = 1; i <= sl.listSize(); i++){
		cout << sl.retrieve(i) << "  ";
	}
	cout << endl;

	sl.remove(2);      // delete from middle of a list
	cout << "\nafter delete from 2: should be 45, 56, 34, 67" << endl;
	sl.display(cout);
	sl.remove(1);      // delete from front of a list
	cout << "\nafter delete from front: should be: 56, 34, 67" << endl;
	sl.display(cout);
	sl.remove(3);      // delete from end of a list
	cout << "\nafter delete from end: should be: 56, 34" << endl;
	sl.display(cout);
	sl.remove(1);
	sl.remove(1);      // deletes make the list empty
	cout << "\nafter deleting last item: list should be empty" << endl;
	sl.display(cout);
	if(sl.empty())
		cout << "list is empty: " << endl;
	else
		cout << "list is not empty" << endl;
}

void testCopyConstructor(){
	cout << endl << "TESTING COPY CONSTRUCTOR" << endl;
	SimpleList sl1;
	sl1.append(23);
	sl1.append(73);
	sl1.append(16);
	sl1.append(98);
	cout << "sl1 should be: 23, 73, 16, 98" << endl;
	sl1.display(cout);
	SimpleList sl2(sl1);  // make a copy of sl1
	cout << "\nafter making a copy sl2 should be: 23, 73, 16, 98" << endl;
	sl2.display(cout);
	sl2.append(45);
	sl2.insert(36, 1);	
	cout << "\nafter changing sl2 sl1 should be: 23, 73, 16, 98" << endl;
	sl1.display(cout);
	cout << "\nsl2 should be: 36, 23, 73, 16, 98, 45" << endl;
	sl2.display(cout);
}

void testOperator(){
	cout << endl << "TEST OPERATOR=" << endl;
	SimpleList sl3;
	sl3.append(15);
	sl3.append(36);
	sl3.append(25);
	cout << "\nsl3 should be: 15, 36, 25" << endl;
	sl3.display(cout);
	SimpleList sl4;
	sl4.append(99);
	sl4.append(44);
	cout << "\nsl4 should be: 99, 44" << endl;
	sl4.display(cout);	
	sl4 = sl3;    // use operator=
	cout << "\nafter sl4 = sl3" << endl;	
	cout << "\nsl4 should be: 15, 36, 25" << endl;
	sl4.display(cout);
	cout << "\nsl3 should be: 15, 36, 25" << endl;
	sl3.display(cout);
	sl3.append(76);	
	cout << "\nafter changing sl3" << endl;
	cout << "\nsl4 should be: 15, 36, 25" << endl;
	sl4.display(cout);
	cout << "\nsl3 should be: 15, 36, 25, 76" << endl;
	sl3.display(cout);
}

void testIteratorMethods(){
	SimpleList sl5;
	sl5.append(55);
	sl5.append(44);
	sl5.append(33);
	sl5.append(22);
	
	cout << endl << "TEST ITERATOR METHODS" << endl;
	// display a list using the iterator methods
	cout << "contents should be: 55, 44, 33, 22" << endl;
	for(sl5.moveToStart(); ! sl5.pastTheEnd(); sl5.next()){
		cout << sl5.getItem() << endl;
	}
}



	








	
	
	
	
