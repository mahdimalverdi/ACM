#include <iostream>

const int MAXN = 1000;

using namespace std;

int parent[MAXN];

int find(int a) {
	if (parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}

void join(int a, int b) {
	parent[find(a)] = parent[find(b)];
}

int check(int a, int b) {
	return find(a) == find(b);
}


int main() {
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; ++i)
		parent[i] = i;

	for (int i = 0; i < q; ++i)
	{
		int type;
		int a, b;
		cin >> type >> a >> b;

		if (type == 0) {
			cout << check(a, b) << endl;
		} else {
			join(a, b);
		}
	}
	return 0;
}