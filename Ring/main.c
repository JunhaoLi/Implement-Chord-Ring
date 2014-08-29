#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "helper.c"
#include "sha_ex.c"


#define MAX_FINGER 160
#define SHA_LEN 32

struct Node {
	char sha_id[20];  //20 byte sha-1 id
	Node *finger[MAX_FINGER];
  Node *pre;
	Node *pre_pre;
	Node():pre(NULL),pre_pre(NULL){}	
};

int main (int argc, const char* argv[])
{
	/*printf("compile test success\n");
	return EXIT_SUCCESS;*/

	if (argc<=1){
		fprintf(stderr,"Wrong Arguments, at least should be 1!\n");
		return EXIT_FAILURE;
	}
	if (argc==2) {
		if (strcmp(argv[1],"quit") == 0){
			//perform quit
		}
		//preform search
	}
	if (argc==3) {
		if ( strcmp(argv[1],"chord")==0 && isNumber(argv[2])==true  ) {
			//perform create
		}
		else{
			//perform search
		}
	}
	if (argc==4){
		//perform search
	}
	if (argc==5){
		if (strcmp(argv[1],"chord")==1 && isPort(argv[2]) && isIP(argv[3]),isPort(argv[4])){
			//perform join
		}
		else {
			//perform search
		}
	}

//perform search


return EXIT_SUCCESS;
}
