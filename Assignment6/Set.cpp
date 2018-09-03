/*Halil Onur Arslanturk
CS240
Assignment 6*/
//Set.cpp

#include "Set.h"
#include<iostream>

using namespace std;

// the program crates a BST and find the size and height of the BST.
// the program prints the BST and remove an element from the object.

Set::Set() {
	root = NULL;
	numberOfItems = 0;
}

Set::Set(const Set& original) {
	consRec(root, original.root);
	numberOfItems = original.numberOfItems;
}

void Set::consRec(BinNode*& thisP, BinNode* original) {
	thisP = new BinNode();
	thisP->item = original->item;
	numberOfItems++;
	if (original->left != NULL) consRec(thisP->left, original->left);
	if (original->right != NULL) consRec(thisP->right, original->right);
}

bool Set::empty() const {
	return numberOfItems == 0;
}// return true if the BST is empty. no side effects;

int Set::getSize() const {
	return numberOfItems;
}// return number of items in the BST

bool Set::add(const ItemType & item) {
	return addRec(root, item);
}// call addRec for recursive adding;

bool Set::find(const ItemType & item) {
	return binSearch(root, item);
}// call binSearch for recursive searching

int Set::height()const {
	if (root == NULL) return 0;
	else return heightRec(root);
}// return 0 if BST is empty otherwise it calls heightRec for finding height recursivly

bool Set::remove(const ItemType & item) {
	if (!root) return false;
	if (root->item == item) { // root has a node should be deleted
		if ((*this).getSize() == 1) { // if only one node exist
			delete root;
			root = NULL;
			numberOfItems--;
			
			return true;
		}
		else if (!((root->left) && (root->right))) {
			if (root->left) {
				BinNode* temp = root->left;
				delete root; // delete the root
				numberOfItems--;
				root = temp; 
			}
			else {
				BinNode* temp = root->right;
				delete root;
				numberOfItems--;
				root = temp;
			}
		}
	}
	else {
		bool left = false;
		bool right = false;
		if (item < root->item) left = removeRec(root, root->left, item);
		else right = removeRec(root, root->right, item);

		return left || right; // if item deleted succesfully
	}
} // delete item 
// it does not work if the node that will be deleted has two child

void Set::display(ostream & out) const {
	displayRec(out, root);
}// calls displayRec to display BST recursively

bool Set::removeRec(BinNode*&parent, BinNode*& current, const ItemType& item) {
	if (current == NULL) return false;
	if (item < current->item) return removeRec(current, current->left, item);
	else if (item>current->item) return removeRec(current, current->right, item);
	if ((current->left == NULL) && (current->right == NULL)) { // if both child is null
		if (parent->left == current) { // if current node is left child of parent
			delete current;
			parent->left = NULL;
		}
		else if (parent->right == current) {
			delete current;
			parent->right = NULL; 
		}
		numberOfItems--;

		return true;
	}
	else if (!((current->left) && (current->right))) { // if one of child is null
		if (current->left) { // if left is not null
			if (parent->left == current) { 
				BinNode* temp = current->left;
				delete current;
				numberOfItems--;
				parent->left = temp;

				return true;
			}
			else if (parent->right == current) {
				BinNode* temp = current->left;
				delete current;
				numberOfItems--;
				parent->right = temp;

				return true;
			}
		}
		else {
			if (parent->left == current) {
				BinNode* temp = current->right;
				delete current;
				numberOfItems--;
				parent->left = temp;

				return true;
			}
			else if (parent->right == current) {
				BinNode* temp = current->right;
				delete current;
				numberOfItems--;
				parent->right = temp;

				return true;
			}
		}
	}
	else { // if right node is not null
		BinNode* temp = current->right;
		BinNode* tempForParent = current;;
		for (; temp->left != NULL; temp = temp->left) {
			tempForParent = tempForParent->left;
		}

		current->item = temp->item;
		tempForParent->left = NULL;
		delete temp;
		numberOfItems--;
	}/*there is a problem here. if and only if left and right node exist the program gives error in height function because there is a problem in else section*/
} // delete item recursively

Set::~Set() {
	removeAllRec(root);
}

void Set::removeAllRec(BinNode* p) {
	if (p != NULL) {
		if (p->left != NULL) removeAllRec(p->left);
		if (p->right != NULL) removeAllRec(p->right);
		
		delete p;
	}
}

int Set::heightRec(BinNode* p) const {
	if (p == NULL) return 0;
	else {
		int left = heightRec(p->left);
		int right = heightRec(p->right);
		if (left < right) return right + 1;
		else return left + 1;
	}
} // find the high of BTS recursively. (1+max(height of it left subtree, height of its right subtree))

bool Set::binSearch(const BinNode* p, const ItemType& num) const{
	if (!p) return false;
	if ((p->item) == num) return true;
	if ((p->item)>num) return binSearch(p->left, num);
	else if ((p->item)<num) return binSearch(p->right, num);
}

bool Set::addRec(BinNode*& p, const ItemType& item) {
	if (p != NULL) {
		if (p->item < item) addRec(p->right, item);
		else if (p->item > item) addRec(p->left, item);
		else return false;
	}
	else {
		p = new BinNode(item);
		numberOfItems++;
		p->left = NULL;
		p->right = NULL;
		
		return true;
	}
}

void Set::displayRec(ostream& out, BinNode* p) const {
	if (p != NULL) {
		displayRec(out, p->left);
		cout << p->item << endl;
		displayRec(out, p->right);
	}
}
