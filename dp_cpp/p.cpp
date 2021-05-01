#include <iostream>
#include <string>
using namespace std;
class wektor
{
    int *pkt1x, *pkt1y, *pkt2x, *pkt2y;

public:
    wektor()
    {
        pkt1x = new int;
        pkt1y = new int;
        pkt2x = new int;
        pkt2y = new int;
        *pkt1x = 0;
        *pkt1y = 0;
        *pkt2x = 0;
        *pkt2y = 0;
    }
    ~wektor();
    void PlusAndMinus();
};
void wektor::PlusAndMinus()
{
    cout << "Podaj pierwsza wspolrzedna pierwszego wektora: ", cin >> *pkt1x, cout << "\n";
    cout << "Podaj druga wspolrzedna pierwszego wektora: ", cin >> *pkt1y, cout << "\n";
    cout << "Podaj pierwsza wspolrzedna drugiego wektora: ", cin >> *pkt2x, cout << "\n";
    cout << "Podaj druga wspolrzedna drugiego wektora: ", cin >> *pkt2y, cout << "\n";
    cout << "Wynik dodawania wektorow to: " << *pkt1x + *pkt2x << "," << *pkt1y + *pkt2y << "\n";
    cout << "Wynik odejmowania wektorow to: " << *pkt1x - *pkt2x << "," << *pkt1y - *pkt2y << "\n";
    cout << "Wynik iloczynu skalarnego tych wektorow wynosi: " << *pkt1x * *pkt2x << "," << *pkt1y * *pkt2y << "\n";
}
wektor::~wektor()
{
    delete pkt1x;
    delete pkt1y;
    delete pkt2x;
    delete pkt2y;
}

int main()
{

    wektor ob1;
    ob1.PlusAndMinus();
    cout << "Rozmiar 1 obiektu klasy wektro wynosi: " << sizeof(ob1);
}