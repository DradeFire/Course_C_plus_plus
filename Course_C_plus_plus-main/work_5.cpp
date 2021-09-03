#include <iostream>
//#include <string>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    int a,b;
	cin >> a >> b;
	while(a != b)
	{
		if(a % 2 == 0)
			cout << a << " ";
		a++;
	}

    return 0;
}
