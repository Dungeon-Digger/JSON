#include <iostream>
#include "Letter.h"

using namespace std;

void main() {
	Letter l("Alex", "Mike", "Hi Mike! This is my letter...", "28.12.21");

	l.Serialize();
	system("pause");
	l = l.Deserialize();

	l.Print();
}