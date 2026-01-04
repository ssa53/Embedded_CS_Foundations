#include <iostream>
using namespace std;
#include <string>

class Array {
private:
	int n;
	int* arr;
public:
	Array(int size) {
		this->n = 0;
		this->arr = new int[size];
		for (int i = 0; i < size; i++) {
			arr[i] = 0;
		}
	}

	int at(int idx) {
		if (idx>=n) {
			return 0;
		}
		return arr[idx];
	}

	void set(int idx, int X) {
		if (idx>=n) {
			cout << 0 << endl;
		}
		else {
			arr[idx] = X;
		}
	}
	void add(int idx, int X) {
		if (idx > n || arr[idx] == 0) {
			arr[n] = X;
		}
		else {
			for (int i = n; i > idx; i--) {
				arr[i] = arr[i - 1];
			}
			arr[idx] = X;
		}
		n++;
	}
	void remove(int idx) {
		if (idx >= n) {
			cout << 0 << endl;
		}
		else {
			cout << arr[idx] << endl;
			for (int i = idx; i < n - 1; i++) {
				arr[i] = arr[i + 1];
			}
			arr[n] = 0;
			n--;
		}
	}
	void printArray() const {
		if (n == 0) {
			cout << 0 << endl;
		}
		else {
			for (int i = 0; i < n; i++) {
				cout << arr[i] << " ";
			}
			cout << endl;
		}
	}
};
int main() {
	int m;
	cin >> m;
	Array array{ 10000 };
	for (int i = 0; i < m; i++) {
		string cmd = "";
		cin >> cmd;
		int idx, x;
		if (cmd == "at") {
			cin >> idx;
			cout << array.at(idx) << endl;
		}
		else if (cmd == "set") {
			cin >> idx >> x;
			array.set(idx, x);
		}
		else if (cmd == "add") {
			cin >> idx >> x;
			array.add(idx, x);
		}
		else if (cmd == "remove") {
			cin >> idx;
			array.remove(idx);
		}
		else if (cmd == "printArray") {
			array.printArray();
		}
	}
}



