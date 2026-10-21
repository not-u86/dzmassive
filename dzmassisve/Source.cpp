#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);


    const double p[2][7] = {
        {300, 750, 1500, 2000, 1, 4, 7},
        {1000, 1000, 2000, 3000, 2, 4, 6}
    };
    const double temp = 100;

    int n;
    double ab, bc, w;

    cout << "самолет 1 или 2: ";
    cin >> n;
    cout << "A-B, B-C, вес: ";
    cin >> ab >> bc >> w;
    n--;

    double rate = -1;
    if (w <= p[n][1]) rate = p[n][4];
    else if (w <= p[n][2]) rate = p[n][5];
    else if (w <= p[n][3]) rate = p[n][6];

    if (rate < 0) {
        cout << "не тот груз\n";
        return 0;
    }

    double needAB = ab * rate;
    double needBC = bc * rate;
    double cap = p[n][0];
    double maxA = (n == 1) ? cap + temp : cap;

    if (needAB > maxA || needBC > cap) {
        cout << "полет невозможен\n";
        return 0;
    }

    double left;
    if (n == 1)
        left = (needAB <= temp) ? cap : cap - (needAB - temp);
    else
        left = cap - needAB;

    double refuel = (left >= needBC) ? 0 : needBC - left;

    cout << fixed << setprecision(1);
    cout << "мин дозаправка в B: " << refuel << " лт\n";

    return 0;
}