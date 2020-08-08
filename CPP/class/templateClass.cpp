#include<iostream>
using namespace std;

template<typename T>
class templateClass
{
	public:
		templateClass();
		~templateClass();

		T function(T arg);
};

template<typename T>
templateClass<T>::templateClass()
{
}

template<typename T>
templateClass<T>::~templateClass()
{
}

template<typename T>
T templateClass<T>::function(T arg)
{
	cout<<"Inside function";
	return arg;
}
int main(void)
{
	templateClass<int> tObj;
	cout<<tObj.function(5);
	return 0;
}
