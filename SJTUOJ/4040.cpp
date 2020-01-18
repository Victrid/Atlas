#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int a, b, armstrong;
	bool AF = false;
	cin >> a >> b;
	if (a > b || a <= 0)
	{
		cout << "error";
		return 0;
	}
	for (int i = a; i <= b; i++)
	{
		armstrong = 0;
		for (int OpNumber = i;OpNumber!=0;)
		{
			armstrong += pow((OpNumber % 10), 3);
			OpNumber /= 10;
		}
		if (armstrong == i)
		{
            if(AF)cout<<endl;
			cout <<i;
			AF = true;
		}
	}
	if (!AF)cout << "no";
	return 0;
}