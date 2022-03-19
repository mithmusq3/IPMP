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
int data;
	list<int> gqlist1;
	list<int>::iterator it2;
	list<int>::iterator it;


int n,check=0;
cout<<"Enter the number of entries of list: ";
cin>>n;


	for (int i = 0; i < n; ++i) {
        cin>>data;
		gqlist1.push_back(data);
	}
	cout << "\nList 1 (gqlist1) is : ";
	showlist(gqlist1);
    n=(n+1)/2;
    it=gqlist1.begin();
it2=gqlist1.end();
it2--;
    while(n!=0){
        if(*it!=*it2){
            check =1;
        }
        it++;
        it2--;
        n--;
    }
    if(check == 0){
    cout<<"\n The given data is palindrome ";
    }
    else{
    cout<<"\n The given data is not palindrome ";

    }
	return 0;
}
