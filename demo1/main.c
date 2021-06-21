#include <stdio.h>

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

int main(){
	FILE *fp;
	char input[100];
	fp = fopen("input.txt", "r");
	fscanf(fp, "%[^\n]", input);
	fclose(fp);

	int ret = parse(input);
	printf("%d\n", ret);
}

