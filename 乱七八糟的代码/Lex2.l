%{
#include<stdio.h>

%}

delim	[ \t\n]
ws		{delim}+
letter	[A-Za-z]
digit	[0-9]
TLD		(com)|(net)|(org)|(info)|(cn)|(us)
name	({letter}|{digit})+({letter}|{digit}|-)*
website	({name}\.)+{TLD}
user	({letter}|{digit}|_)+
email	{user}@{website}
point	[.,;\"\':<>?-]

%%

{ws}		{}
{website}	printf("Website matched:%s\n",yytext);
{email}		printf("E-mail matched:%s\n",yytext);
{letter}	{}
{digit}		{}
{point}		{}

%%
