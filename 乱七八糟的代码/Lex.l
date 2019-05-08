%{
#include<stdio.h>

%}

blank	[ ]
delim	[ \t\n]
ws		{delim}+
letter	[A-Za-z]
digit	[0-9]
id		{letter}({letter}|{digit})*
number	{digit}+(\.{digit}+)?(E[+-]?{digit}+)?
string	\"({letter}|{blank}|.)*\"

%%

{ws}		{}
if			printf("Keyword matched:%s\n",yytext);
while		printf("Keyword matched:%s\n",yytext);
int			printf("Keyword matched:%s\n",yytext);
cout		printf("Keyword matched:%s\n",yytext);
endl		printf("Keyword matched:%s\n",yytext);
{id}		printf("Pattern id matched:%s\n",yytext);
{number}	printf("Pattern number matched:%s\n",yytext);
"<<"		printf("Operator matched:%s\n",yytext);
"="			printf("Operator matched:%s\n",yytext);
"<"			printf("Operator matched:%s\n",yytext);
"+"			printf("Operator matched:%s\n",yytext);
"-"			printf("Operator matched:%s\n",yytext);
;			printf("Semicolon matched:%s\n",yytext);
\(			printf("Open paren matched:%s\n",yytext);
\)			printf("Close paren matched:%s\n",yytext);
\{			printf("Open brace matched:%s\n",yytext);
\}			printf("Close brace matched:%s\n",yytext);
{string}	printf("Pattern string matched:%s\n",yytext);

%%

