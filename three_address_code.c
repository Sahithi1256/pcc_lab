#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void pm();
void plus();
void divide();
void reverse_string(char* str);
int i, ch, j, l, addr = 100;
char ex[10], expression[10], exp1[10], expression2[10], id1[10], op[3], id2[10];
int main()
{
 while (1)
 {
 printf("\n1. Assignment\n2. Arithmetic\n3. Relational\n4. Exit\nEnter the choice: ");
 scanf("%d", &ch);
 switch (ch)
 {
 case 1:
printf("\nEnter the expression with assignment operator: ");
scanf("%s", expression);
l = strlen(expression);
expression2[0] = '\0';
i = 0;
while (expression[i] != '=')
{
i++;
}
strncat(expression2, expression, i);
 reverse_string(expression);
 exp1[0] = '\0';
 strncat(exp1, expression, l - (i + 1));
 printf("Three address code:\ntemp = %s\n%s = temp\n", exp1, 
expression2);
 break;
case 2:
 printf("\nEnter the expression with arithmetic operator: ");
 scanf("%s", ex);
 strcpy(expression, ex);
 l = strlen(expression);
 exp1[0] = '\0';
 for (i = 0; i < l; i++)
 {
 if (expression[i] == '+' || expression[i] == '-')
 {
 if (expression[i + 2] == '/' || expression[i + 2] == '*')
 {
 divide();
 break;
 }
 else
 {
 plus();
 break;
 }
 }
else if (expression[i] == '/' || expression[i] == '*')
 {
 divide();
 break;
 }
 }
 break;
     case 3:
 printf("Enter the expression with relational operator: ");
 scanf("%s%s%s", id1, op, id2);
 if (strcmp(op, "<") == 0 || strcmp(op, ">") == 0 || strcmp(op, "<=") == 0 || 
strcmp(op, ">=") == 0 || strcmp(op, "==") == 0 || strcmp(op, "!=") == 0)
 {
 printf("\n%d\tif %s %s %s goto %d\n", addr, id1, op, id2, addr + 3);
 addr++;
 printf("%d\tT := 0\n", addr);
 addr++;
 printf("%d\tgoto %d\n", addr, addr + 2);
 addr++;
 printf("%d\tT := 1\n", addr);
 }
 else
 {
 printf("Expression is invalid\n");
 }
 break;
 case 4:
 exit(0);
 }
 }
 return 0;
}
void pm()
{
 reverse_string(expression);
 j = l - i - 1;
 strncat(exp1, expression, j);
 printf("Three address code:\ntemp = %s\ntemp1 = %c%c temp\n", exp1, expression[j + 
1], expression[j]);
}
void divide()
{
 strncat(exp1, expression, i + 2);
 printf("Three address code:\ntemp = %s\ntemp1 = temp %c%c\n", exp1, expression[i + 
2], expression[i + 3]);
}
void plus()
{
 strncat(exp1, expression, i + 2);
 printf("Three address code:\ntemp = %s\ntemp1 = temp %c%c\n", exp1, expression[i + 
2], expression[i + 3]);
}
void reverse_string(char* str)
{
 int length = strlen(str);
 int i;
 char temp;
 for (i = 0; i < length / 2; i++)
 {
 temp = str[i];
 str[i] = str[length - i - 1];
 str[length - i - 1] = temp;
 }
}
