#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node {
	Node* next;
	Node* prev;
	int value;
	int key;
	Node(Node* p, Node* n, int k, int val) :prev(p), next(n), key(k), value(val) {};
	Node(int k, int val) :prev(NULL), next(NULL), key(k), value(val) {};
};

class Cache {

protected:
	map<int, Node*> mp; //map the key to the node in the linked list
	int cp;  //capacity
	Node* tail; // double linked list tail pointer
	Node* head; // double linked list head pointer
	virtual void set(int, int) = 0; //set function
	virtual int get(int) = 0; //get function

};

class LRUCache : virtual public Cache {
private:
public:
	LRUCache(int c) { cp = c; tail = nullptr; head = nullptr; }
	void set(int k, int v);
	int get(int k);
	~LRUCache(){
		for (auto &i: mp)
			delete i.second;
	}
	void printMap();
	void reversePrintMap();
};

void LRUCache::printMap() {
	Node* ptrNode = head;

	if (mp.size() == 0)
		return;
	while (ptrNode != tail) {
		cout << ptrNode->key << "/" << ptrNode->value << "  ->  ";
		ptrNode = ptrNode->next;
	}
	cout << ptrNode->key << "/" << ptrNode->value << endl;

}

void LRUCache::reversePrintMap() {
	Node* ptrNode = tail;

	if (mp.size() == 0)
		return;
	while (ptrNode != head) {
		cout << ptrNode->key << "/" << ptrNode->value << "  <-  ";
		ptrNode = ptrNode->prev;
	}
	cout << ptrNode->key << "/" << ptrNode->value << endl;

}
void LRUCache::set(int k, int v) {
	map<int, Node*>::iterator itMP = mp.find(k);
	int mapSize = mp.size();

	if (itMP == mp.end()) {  //  NOT found - add it to front
		Node* myNode = new Node(k, v);
		if (mapSize == 0) {
			tail = myNode;
			head = myNode;
		}
		else {  //  move to front, 
			myNode->prev = nullptr;
			myNode->next = head;
			head->prev = myNode;
			head = myNode;

			//  remove tail if we are at capacity
			if (mapSize == cp) {
				itMP = mp.find(tail->key);
				mp.erase(itMP);
				tail->prev->next = nullptr;
				Node* tempNode = tail->prev;
				delete tail;
				tail = tempNode;
			}
		}
		mp.insert(std::pair<int, Node*>(k, myNode));
	}//  end if NOT found 
	else {  //  found -  move it to front
		Node* myNode = itMP->second;
		if (myNode ==head)
			head->value = v;
		else {
			bool isTail = myNode == tail ? true : false;
			myNode->prev->next = myNode->next;
			if (isTail)
				tail = tail->prev;
			else
				myNode->next->prev = myNode->prev;
			myNode->prev = nullptr;
			myNode->next = head;
			head->prev = myNode;
			myNode->value = v;
			head = myNode;

		}

	} //  end found
	//printMap();
	//reversePrintMap();
}
int LRUCache::get(int k) {
	map<int, Node*>::iterator itMP = mp.find(k);
	if (itMP != mp.end())
		return itMP->second->value;
	return -1;
}

int main() {
	int n, capacity, i;
	cin >> n >> capacity;
	LRUCache l(capacity);
	for (i = 0; i < n; i++) {
		string command;
		cin >> command;
		cout << command;
		if (command == "get") {
			int key;
			cin >> key;
			cout << key << endl;
			cout << l.get(key) << endl;
		}
		else if (command == "set") {
			int key, value;
			cin >> key >> value;
			cout << " " << key << " " << value << endl;
			l.set(key, value);
		}
		cout << "\n";
	}
	return 0;
}
