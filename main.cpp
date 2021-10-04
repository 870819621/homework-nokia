//æ€∫œ≥ı ºªØ
#include <iostream>
using namespace std;

class MyClass
{
public:
	MyClass(int id) { i = 10; };
	int i;

private:

};



int main() {
	auto d = std::is_aggregate<MyClass>::value;
	cout << d << endl;

	MyClass a{ 11 };
	cout << a.i << endl;
    return 0;
}