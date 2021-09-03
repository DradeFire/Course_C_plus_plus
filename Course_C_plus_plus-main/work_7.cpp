#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int a, b;
	cin >> a >> b;
	
	while(a > 0 && b > 0)
	{
		if(a > b)
			a %=b;
		else
			b %=a;
	}

	cout << a + b;

	return 0;
}
