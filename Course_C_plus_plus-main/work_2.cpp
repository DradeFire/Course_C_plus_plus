#include <iostream>
//#include <string>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    double a, b, c, D;
    cin >> a >> b >> c;

    D = b * b - 4 * a * c;
    if (D > 0 && a != 0)
        cout << (-b + sqrt(D)) / (2 * a) << " " << (-b - sqrt(D)) / (2 * a);
    else if (D == 0 && a != 0)
        cout << (-b) / (2 * a);
    else if (a == 0 && b == 0)
        ;
    else if (a == 0)
        cout << (-c / b);

    return 0;
}
