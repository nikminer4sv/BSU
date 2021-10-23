using namespace std;
 
void BinarySort(int* Array,int N) {

    int x = 0, left = 0, right = 0, sred = 0;
	int swap = 0, comparison = 0;

	int CurrentArray[N];

	for (int i = 0; i < N; i++) {

		CurrentArray[i] = Array[i];

	}

    for (int i = 1; i < N; i++) 
        if (CurrentArray[i - 1] > CurrentArray[i]) {

			comparison++;

            x = CurrentArray[i];
            left = 0;  
            right = i - 1;

            do {

                sred = (left + right) / 2; 

                if (CurrentArray[sred] < x) 
					left = sred + 1;  
                else  
					right = sred - 1;

				comparison++; 

            } while (left <= right);

            for (int j = i - 1; j >= left; j--){

                CurrentArray[j + 1] = CurrentArray[j]; 
				swap++;

			}

            CurrentArray[left] = x;

    	} else {

			comparison++;

		}

	cout << "Binary sort: \n";
	cout << "Number of comparisons: " << comparison << endl;
	cout << "Number of swaps: " << swap << endl;

}