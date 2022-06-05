#include <iostream>
using namespace std;

int main()
{
	int n, x;
	cin >> n;
	while (n--) {
		cin >> x;
		if (x & 1) cout << "zs wins" << endl;
		else cout << "pb wins" << endl;
	}
}