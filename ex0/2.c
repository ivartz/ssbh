#include <stdio.h>



int main(int argc, char *argv[]){
	while(argc--){
		printf("%i\n", argc);
		printf("%s\n",*argv++);
	}
	return 0;
}