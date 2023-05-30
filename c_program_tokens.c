#include <stdio.h> 
#include <ctype.h> 
#include <string.h> 
int is_reserved(char *word); 
int is_operator(char *word); 
int main() { 
 FILE *fp; 
 char filename[100]; 
 char ch; 
 char buffer[100]; 
 int buf_idx = 0; 
printf("Enter the name of the file: "); 
 scanf("%s", filename); 
 fp = fopen(filename, "r"); 
 if (fp == NULL) { 
 printf("Error opening file\n"); 
 return 1; 
 } 
while ((ch = fgetc(fp)) != EOF) { 
 if (isalnum(ch) || ch == '_') { 
 buffer[buf_idx++] = ch; 
 } else { 
 buffer[buf_idx] = '\0'; 
 if (strlen(buffer) > 0) { 
 if (is_reserved(buffer)) { 
 printf("Reserved word: %s\n", buffer); 
 } else { 
 printf("Identifier: %s\n", buffer);} } 
  
buf_idx = 0; 
 if (is_operator(&ch)) { 
 printf("Operator: %c\n", ch); 
 } else if (ispunct(ch)) { 
 printf("Special character: %c\n", ch); 
 } 
 } 
 } 
 fclose(fp); 
 return 0; 
} 
int is_reserved(char *word) { 
 char *reserved_words[] = {"auto", "break", "case", "char", "const", "continue",  "default", "do", "double", "else", "enum", "extern", "float", "for", 
 "goto", "if", "int", "long", "register", "return", "short", "signed", 
 "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned",  "void", "volatile", "while" 
 }; 
 int num_reserved = sizeof(reserved_words) / sizeof(reserved_words[0]);  for (int i = 0; i < num_reserved; i++) { 
 if (strcmp(word, reserved_words[i]) == 0) { 
 return 1; 
 } 
 } 
 return 0; 
} 
int is_operator(char *word) { 
 char *operators[] = {"+", "-", "*", "/", "%", "++", "--", "==", "!=", "<", ">", "<=", ">=",  "&&", "||", "!", "&", "|", "^", "~", "<<", ">>", "=", "+=", "-=", "*=", "/=", "%=",  "<<=", ">>=", "&=", "^=", "|=" 
 }; 
int num_operators = sizeof(operators) / sizeof(operators[0]);
for (int i = 0; i < num_operators; i++) { 
 if (strcmp(word, operators[i]) == 0) { 
 return 1; 
 } 
 } 
 return 0; 
} 

Add.c 
#include<stdio.h> 
int main(){ 
int x,y,z; 
x = 1; 
y = 2; 
z = x + y; 
printf("%d",z); 
} 
