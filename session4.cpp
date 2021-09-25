//
// Created by c2xu on 2021/9/17.
//
#include<iostream>
using namespace std;

class employee {
public:
	employee() {}
	employee(std::string name, int age) :name(name), age(age) {}
	bool  operator==(const employee& d) {
		return (name == d.name && age == d.age);
	}
private:
	std::string name = "";
	int age = 18;
};

template <class T>
class MyNode {
public:
	T data;
	MyNode* nextptr;

	MyNode() {

	}
	MyNode(T data) {
		this->data = data;
	}
	bool operator==(const MyNode& d) {
		return data == d.data;
	}

	bool operator==(T d) {
		return data == d;
	}
};

template <>
class MyNode<employee> {
public:
	employee data;
	MyNode* nextptr;

	MyNode(employee d) {
		data = d;
	}

	MyNode() {
		data = { "",18 };
	}

	bool operator==(const MyNode& d) {
		return data == d.data;
	}

	bool operator==(employee d) {
		return data == d;
	}
};

template <class T>
class MyList {
public:
	MyList() {
		head = new MyNode<T>();
		head->nextptr = nullptr;
	};

	~MyList() {
		while (head) {
			if (head->nextptr)
			{
				auto tmp = head;
				head = head->nextptr;
				delete tmp;
			}
		}
	}

	void insert(T data) {
		auto node = new MyNode<T>(data);
		node->nextptr = head->nextptr;
		head->nextptr = node;
	}

	void erase(T data) {
		auto tmp = head->nextptr;
		auto pre = head;
		while (tmp) {
			if (data == tmp->data)
			{
				tmp = pre->nextptr = tmp->nextptr;
				delete tmp;

			}
			else {
				pre = pre->nextptr;
				tmp = tmp->nextptr;
			}
		}
	}

	bool isContain(T data) {
		auto tmp = head;
		while (tmp) {
			if (data == tmp->data)
			{
				return true;
			}
			else {
				tmp = tmp->nextptr;
			}
		}
		return false;
	}
private:
	MyNode<T>* head;
};


int main() {
	auto test = MyList<employee>{};
	test.insert({ "aaa",18 });
	auto aaa = employee{ "aaa",18 };
	auto isExsit = test.isContain(aaa);
	cout << isExsit << endl;
	test.erase({ "aaa",18 });
	isExsit = test.isContain(aaa);
	cout << isExsit << endl;

	auto test2 = MyList<int>{};
	test2.insert({ 18 });
	auto isExsit2 = test2.isContain(18);
	cout << isExsit2 << endl;
}