#include <iostream>
#include <deque>
#include <string>
using namespace std;

deque<int> D;
int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		if (s == "pop_back")
			D.pop_back();
		else if (s == "pop_front")
			D.pop_front();
		else if (s == "push_back")
		{
			int x;
			cin >> x;
			D.push_back(x);
		}
		else
		{
			int x;
			cin >> x;
			D.push_front(x);
		}
	}
	for (deque<int>::iterator i = D.begin(); i != D.end(); ++i)
		cout << *i << endl;
}
