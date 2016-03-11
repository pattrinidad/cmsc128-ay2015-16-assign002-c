#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*Assumes that all user input is correct*/

/*Sources: Stackoverflow*/


int length_of_s1 = 0, length_of_s2 = 0;
//2 character arrays to accept two strings
int getHammingDistance(char *a, char *b);
int countSubstrPattern(char *original, char *pattern);
int isValidString(char *str, char *alphabet);
int getSkew(char *str, int n);
int getMaxSkewN(char *str, int n);
int getMinSkewN(char *str, int n);

main(){
	int choice;
	char a[256], b[256];
	int nucleotide;

while(1){
	printf("---------MENU-----------\n");
	printf("[1]Hamming Distance of Two Strings\n");
	printf("[2]Count Substring Pattern\n");
	printf("[3]Check if String is valid\n");
	printf("[4]Get Skew\n");
	printf("[5]Get Max Skew N\n");
	printf("[6]Get Min Skew N\n");
	scanf("%d",&choice);

	if(choice == 1){
			//execute Hamming Distance function
			printf("Enter the strings: ");
			getchar();
			fgets(a,256,stdin);
			fgets(b,256,stdin);

			//removes trailing new line
			a[strlen(a) - 1] = '\0';
			b[strlen(b) - 1] = '\0';

			//if strlen of a and b are not equal
			if(strlen(a) != strlen(b)){
				printf("Wrong input!\n");
			}
			//if strlen of a and b is less than 2
			else if(strlen(a) < 2 || strlen(b) < 2){
				printf("Wrong input!\n");
			}
			else{
			//if input is correct, execute Hamming Distance
				int result = getHammingDistance(a,b);
				printf("The hamming distance of %s and %s is %d!\n",a,b,result);			
			}
	}
	else if(choice == 2){
			//execute substring pattern function
			printf("Enter a string: ");
			getchar();
			fgets(a,256,stdin);
			printf("Enter a substring: ");
			fgets(b,256,stdin);
			
			//removes trailing newlines
			a[strlen(a) - 1] = '\0';
			b[strlen(b) - 1] = '\0';			

			//execute substring function
			int result = countSubstrPattern(a,b);
			printf("%s has %d substring pattern(s) of %s on it!\n",a,result,b);

	}
	else if(choice == 3){
			//execute isValid function
			printf("Enter the string: ");
			getchar();
			fgets(a,256,stdin);
			printf("Enter the alphabet: ");
			fgets(b,256,stdin);

			a[strlen(a) - 1] = '\0';
			b[strlen(b) - 1] = '\0';

			//executes substring function
			int result = isValidString(a,b);

			if(result == 0) printf("False! Not a valid string.\n");	//toggle 0 if false
			else if (result == 1) printf("True! A valid string.\n");	//toggle 1 if true
	}
	else if(choice == 4){
			
			//execute getSkew function
			printf("Enter the genome: ");
			getchar();
			fgets(a,256,stdin);
			printf("Enter the nucleotide (n > 0) :");
			scanf("%d", &nucleotide);

			printf("Result: %d\n", getSkew(a,nucleotide-1));
				
	}
	else if(choice == 5){
			//execute max skew function
			printf("Enter the genome: ");
			getchar();
			fgets(a,256,stdin);
			printf("Enter the nucleotide (n > 0) :");
			scanf("%d", &nucleotide);

			printf("Result: %d\n", getMaxSkewN(a,nucleotide-1));
	}
	else if(choice == 6){
			//execute min skew function
			printf("Enter the genome: ");
			getchar();
			fgets(a,256,stdin);
			printf("Enter the nucleotide (n > 0) :");
			scanf("%d", &nucleotide);

			printf("Result: %d\n", getMinSkewN(a,nucleotide-1));
	}
	else{
			printf("Wrong Input!\n");
			continue;			
	}

return 0;
}
}

int getHammingDistance(char a[], char b[]){
	int res1 = 0, i;

	for(i = 0; i < strlen(a); i++){
			if(a[i] != b[i]){
					res1 += 1;
			}
	}
	
	return res1;
}

int countSubstrPattern(char original[], char pattern[]){
	int i=0,j=0, counter=0;
	char *foo = original;

	while(original[i] != '\0' && (foo = strstr(foo,pattern))){
			counter += 1;
			foo += 2;		
	}
	
	return counter;
}

int isValidString(char str[], char alphabet[]){
	int i = 0, j = 0, counter = 0;

	for(i = 0; str[i] != '\0'; i++){
		for(j = 0; alphabet[j] != '\0'; j++){
				if(str[i] == alphabet[j]){
						counter += 1; break;
				}
			}
	}

	if(counter == strlen(str)){
			return 1;
		}
	else{
			return 0;
	}
}

int getSkew(char str[], int n){
			int numOfG = 0, numOfC = 0,i;		

			for(i = 0; i <= n; i++){
					if(str[i] == 'G'){
							numOfG += 1;
					}
					if(str[i] == 'C'){
							numOfC += 1;
					}
			}

		return numOfG - numOfC;
}

int getMaxSkewN(char str[], int n){
		int numOfG = 0, numOfC = 0, i, j, maxSkew = 0,temp = 0;
		int index[n], count = 0;
		maxSkew =  getSkew(str, 0);	
	
		for(i = 1; i <= n ; i++){
					temp = getSkew(str,i);	
					if(temp >= maxSkew) maxSkew = temp;	
		}

	return maxSkew;	
}

int getMinSkewN(char str[], int n){
		int numOfG = 0, numOfC = 0, i, j, minSkew = 0, temp = 0;
		int index[n], count = 0;
		minSkew = getSkew(str,0);

		for(i = 1; i <= n; i++){
				temp = getSkew(str,i);
				if(temp <= minSkew) minSkew = temp;
		}

	return minSkew;
}
# cmsc128-ay2015-16-assign002-c
# cmsc128-ay2015-16-assign002-c
# cmsc128-ay2015-16-assign002-c
