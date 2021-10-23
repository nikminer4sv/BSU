using namespace std;

void SimpleSort(int* Array,int N) {

	int swap = 0, comparison = 0;

	int CurrentArray[N];

	for (int i = 0; i < N; i++) {

		CurrentArray[i] = Array[i];

	}

	for(int i = 1; i < N; i++) { 

		for(int j = i; j > 0; j--) {

			if (CurrentArray[j - 1] > CurrentArray[j]) {

				int temp = CurrentArray[j - 1];
				CurrentArray[j - 1] = CurrentArray[j];
				CurrentArray[j] = temp;

				swap++;
				comparison++;

			} else {

				comparison++;

			}

		}

	}

	cout << "Simple sort: \n";
	cout << "Number of comparisons: " << comparison << endl;
	cout << "Number of swaps: " << swap << endl;

}