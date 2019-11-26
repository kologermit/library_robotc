#include <library.h>
const int speed = 100;
task main(){
	int File = file("test.rtf", 'r');
	Display(0, 125, "%d", freadChar(File));
	while(1);
}
