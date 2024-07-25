#include <stdio.h>

/*efficient method
only compares the current index
with the next index*/

int main () {
	int arr[5] = {5,7,3,2,6};
	
	/*int i will serve as the first compared element
	int j will then be the second compared element
	hence, eliminating the need to traverse the entire element
	and will only traverse the next element after the first element*/
	
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (arr[i] < arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	//write a print statement here
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	
	return 0;
}