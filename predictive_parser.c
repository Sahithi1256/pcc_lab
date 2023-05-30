#include <stdio.h> 
#include <ctype.h> 
#include <string.h> 
#include <stdlib.h> 
char table[10][10][10], nter[10], ter[10]; 
char inp[20], stack[20]; 
int nut, nun, i = 0, top = 0; 
int get_nter(char); 
int get_ter(char); 
void replace(char, char); 
void main() { 
int i, j; 
printf("Enter number of Terminals:\n"); 
scanf("%d", &nut); 
printf("Enter number of Non-Terminals:\n"); 
scanf("%d", &nun); 
printf("Enter all Non-Terminals:\n"); 
scanf("%s", nter); 
printf("Enter all Terminals:\n"); 
scanf("%s", ter); 
for (i = 0; i < nut; i++) 
printf("%c\t", nter[i]); 
printf("\n"); 
for (j = 0; j < nun; j++) 
printf("%c\t", ter[j]); 
printf("\n"); 
for (i = 0; i < nun; i++) 
for (j = 0; j < nut; j++) { 
printf("Enter for %c and %c \n", nter[i], ter[j]); 
scanf("%s", table[i][j]); 
}
for (j = 0; j < nut; j++) 
printf("\t %c", ter[j]); 
printf("\n"); 
for (i = 0; i < nun; i++) { 
printf("%c", nter[i]); 
for (j = 0; j < nut; j++) { 
printf("\t %s", table[i][j]); 
} 
printf("\n"); 
} 
printf("Enter the string to parse:\n"); 
scanf("%s", inp); 
stack[top++] = '$'; 
stack[top++] = nter[0]; 
i = 0; 
while(1) { 
if ((stack[top - 1] == '$') && (inp[i] == '$')) { 
printf("String Accepted\n"); 
return; 
} 
else if (!isupper(stack[top - 1])) { 
if (stack[top - 1] == inp[i]) { 
i++; 
top--; 
} 
else { 
printf("Error not accepted\n"); 
return; 
} 
} 
else { 
replace(stack[top - 1], inp[i]); 
} 
} 
}
int get_nter(char x) { 
int a; 
for (a = 0; a < nun; a++) 
if (x == nter[a]) 
return a; 
return 100; 
} 
int get_ter(char x) { 
int a; 
for (a = 0; a < nut; a++) 
if (x == ter[a]) 
return a; 
return 100; 
} 
void replace (char NT, char T) { 
int in1, it1, len; 
char str[10]; 
in1 = get_nter(NT); 
it1 = get_ter(T); 
if ((in1 != 100) && (it1 != 100)) { 
strcpy(str, table[in1][it1]); 
if(strcmp(str, "#") == 0) { 
printf("Error\n"); 
exit(0);} 
if (strcmp(str, "@") == 0) 
top--; 
else { 
top--; 
len = strlen(str); 
len--; 
do { 
stack[top++] = str[len--]; 
} while (len >= 0); 
} 
} 
else { 
printf("Not Valid\n"); 
}}
Input:Grammer G: { E-> TE’ , E’ -> +TE’ | 0, T-> FT’ , T’-> *FT’|0 , F-> (E) | id}  
