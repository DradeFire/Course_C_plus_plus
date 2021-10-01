#include <iostream>
#include <string>
#include <vector>

using namespace std;

void PrintVectorPart(const vector<int>& numbers);

void PrintVectorPart(const vector<int>& numbers) {
	auto it = numbers.begin();
	while (it != end(numbers) && *it >= 0) {
		it++;
	}
	if (it == numbers.begin()) {
		return;
	}else{
		it--;
		while (it != begin(numbers))
		{
			cout << *it << ' ';
			it--;
		}
		cout << *it;
	}
}

int main() {
	PrintVectorPart({ 6, 1, 8, -5, 4 });
	cout << endl;
	PrintVectorPart({ -6, 1, 8, -5, 4 });  // ничего не выведется
	cout << endl;
	PrintVectorPart({ 6, 1, 8, 5, 4 });
	cout << endl;
	return 0;
}