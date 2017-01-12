/*	Purpose: 
	Name: Jared McDonald
	Account: cs214110
	Files: lab3.c
	Date Start: 09/21/2015 5:00pm
	Date End: 09//2015 6:00pm
	...

*/
#include <stdio.h>
#include <string.h>

//Prototypes
void printGroup();
void printSpace(char);
int trueLength(char *str);

//Global variables
char str[256];
char group[16];
int i,j;
int printed = 1;
int totalprinted = 0;
int begin = 0;

int main(){
	printf("Input something: ");
	fgets(str,sizeof(str),stdin); //scanf doesnt read all of the input
	int tlength = trueLength(str);
	printf("You entered %s",str);
	printf("%06d\t", totalprinted);
	for(i = 0;i<256;i++){
		
		if(str[i] == '\0'){
			printf("\n");
			for(j=begin;j <=i;j++){
				printf("%c",str[j]);
				if(j <= i){
					printf("  ");
				}
				if(str[j] == '\0'){
					printf("\n");
					break;
				}
			}
			begin = i;
			break;
		}
		else{
			if(str[i] != '\n' && i != tlength){ //if statement so the trailing \n doesnt print
				printf("%X ",str[i]);
			}
			totalprinted++;
			printed++;
			if(printed == 17){
				printf("\n	  ");
				for(j=begin;j <=i;j++){
					if(!isspace(str[j]) && str[j] != '\a' && str[j] != '\b' && str[j] != '\"' && str[j] != '\'' && str[j] != '\?' && str[j] != '\\'){
						printf("%c  ",str[j]);
					}
					else{
						printSpace(str[j]);
					}
					if(str[j] == '\0'){
						printf("\n");
						break;
					}
				}
				begin = i;
				printf("\n%06d\t",totalprinted);
				printed = 1;
			}
		}
	}
	return 0; //Return 0
}

void printGroup(){
	for(i = 0;i < 16;i++){
		printf("%x ",group[i]);	
	}
	printf("\n");
}

int trueLength(char *str){
	int count = 0;
	for(i = 0;i < 255;i++){
		if(str[i] == '\0'){
			break;
		}
		else{
			count++;
		}
	}
}

void printSpace(char ch){
	if(ch == ' '){
		printf(" ");
	}
	if(ch == '\a'){
		printf("\\a");
}
	else if(ch == '\b'){
		printf("\\b");
}
	else if(ch == '\t'){
		printf("\\t");
}
	else if(ch == '\n'){
		printf("\\n");
}
	else if(ch == '\v'){
		printf("\\v");
}
	else if(ch == '\f'){
		printf("\\f");
}
	else if(ch == '\r'){
		printf("\\r");
}
	else if(ch == '\"'){
		printf("\\\"");
}
	else if(ch == '\''){
		printf("\\\'");
}
	else if(ch == '\?'){
		printf("\\?");
}
	else if(ch == '\\'){
		printf("\\\\");
}
	printf("  ");
}
