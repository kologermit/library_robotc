#include <library.h>
const int speed = 100;
task main(){
	int arr[] = {1, 3, 2, 4, 0};
	Clear();
	sort(arr, 5);
	displayBigStringAt(0, 125,  "%d %d %d %d %d", arr[0], arr[1], arr[2], arr[3], arr[4]);
	displayBigStringAt(0, 100, "%d", binary_search(arr, 5, 1));
	WT;
}
