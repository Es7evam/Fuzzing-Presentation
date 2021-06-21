#include <stdio.h>
#include <stdint.h>

int parse(char* input){
	int count = 0;
	if(input[0] == 'O'){ 
		count++;
		if(input[1] == 'i') {
			count++;
				if(input[2] == ' ') {count++;
				if(input[3] == 'T') count++;
			}
		}else{
			if(input[4] == 'u') count++;
		}
	}
	return count;
}

int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size){
	char *input;
	input = (char*)Data;
	if(Size < 2) return 0;

	int ret = parse(input);
	return 0;
}

