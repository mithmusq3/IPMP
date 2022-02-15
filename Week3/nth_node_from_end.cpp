#include <iostream>
#include <iterator>
#include <list>
using namespace std;

void showlist(list<int> g)
{
    list<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    list<int> gqlist1;
    list<int>::iterator it2;
    for (int i = 0; i < 10; ++i)
    {
        gqlist1.push_back(i * 2);
    }
    cout << "\nList 1 (gqlist1) is : ";
    showlist(gqlist1);

    it2 = gqlist1.end();
    while (n != 0)
    {
        it2--;
        n--;
    }
    cout << '\t' << *it2;

    return 0;
}
