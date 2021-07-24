template<typename T, typename E>
class Pair
{
private:
	T value;
	E key;
public:
	friend ostream & operator<<(ostream & out, const Pair & P)
	{
		out << P.value << P.key;
		return out;
};

};

	class Foo
	{
		//code
	};
	class FooBar
	{
		// code
	};

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main()
{
	Pair<Foo, FooBar> P;
	// more code;
	cout << P;

	system("pause");
	return 0;
}