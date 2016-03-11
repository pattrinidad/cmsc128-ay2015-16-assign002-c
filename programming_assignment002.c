#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*Assumes that all user input is correct*/

/*Sources: Stackoverflow*/

//Function Calls
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

	//assumming that both the strlen(a) and strlen(b) is equal
	for(i = 0; i < strlen(a); i++){	//while i is not equal to strlen(a)
			if(a[i] != b[i]){	//if a[i] != b[i]
					res1 += 1;	//increment res1
			}
	}
	
	return res1;	//return res1
}

int countSubstrPattern(char original[], char pattern[]){
	int i=0,j=0, counter=0;
	char *foo = original;	//foo copies the original string

	while(original[i] != '\0' && (foo = strstr(foo,pattern))){ //while not end of the string
			counter += 1;				//and foo still has a substring for the pattern
			foo += 2;				//increment foo by 2
	}
	
	return counter; //return counter
}

int isValidString(char str[], char alphabet[]){
	int i = 0, j = 0, counter = 0;

	for(i = 0; str[i] != '\0'; i++){	//while not end of str
		for(j = 0; alphabet[j] != '\0'; j++){	//while not end of the alphabet
				if(str[i] == alphabet[j]){	//compare str[i] to all of the letters on the alphabet
						counter += 1; break;	//increment count
				}
			}
	}

	if(counter == strlen(str)){	//if counter == strlen(str), which means that all of the str[i] is present
			return 1;	//on the alphabet, return true
		}
	else{
			return 0;	//else return 0
	}
}

int getSkew(char str[], int n){
			int numOfG = 0, numOfC = 0,i;		
	
	//before n is passed as n-1, see the function call above
			for(i = 0; i <= n; i++){	//while 0 to position n-1
					if(str[i] == 'G'){	//if G == str[i]
							numOfG += 1;	//increment the number of Gs
					}
					if(str[i] == 'C'){	//if C == str[i]
							numOfC += 1;	//increment the number of Cs
					}
			}

		return numOfG - numOfC;	//return the difference of the two to get the skew
}

int getMaxSkewN(char str[], int n){
		int numOfG = 0, numOfC = 0, i, j, maxSkew = 0,temp = 0;
		int index[n], count = 0;
		maxSkew =  getSkew(str, 0);	//get the skew for position 1 (n-1 is passed as parameter)
	
		for(i = 1; i <= n ; i++){	//for the rest of the string after position 1
					temp = getSkew(str,i);	//get the skew, call it
					if(temp >= maxSkew) maxSkew = temp;	//if the skew of a given position
		}							//is greater than the current maxSkew, replace maxSkew with the value of temp

	return maxSkew;	//return maxSkew
}

int getMinSkewN(char str[], int n){
		int numOfG = 0, numOfC = 0, i, j, minSkew = 0, temp = 0;
		int index[n], count = 0;
		minSkew = getSkew(str,0);	//get the skew for position 1

		for(i = 1; i <= n; i++){	//for the rest of the string after position 1(index 0 to str)
				temp = getSkew(str,i);	//get the skew, call it using the getSkew function
				if(temp <= minSkew) minSkew = temp;	//if the skew of a given position
		}//is less than the current minSkew, replace minSkew with the value of temp

	return minSkew; //return minSkew
}
