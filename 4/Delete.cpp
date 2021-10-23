using namespace std;

void Delete(char* Array, int Number, int Amount) {

	for (int i = Number; i < sizeof(Array); i++) {

		Array[i] = Array[i + Amount];

	}
	
}