// Kompilator_BrainFuck.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

void checkChar(char c, int* t, int i, stack<int>* s)
{
	switch (c)
	{
	case '+': ++(*t); break;
	case '-': --(*t); break;
	case '>': t++; break;
	case '<': t--; break;
	case '.': printf("%c ", *t + 'A'); break;
	case '=': printf("%d ", *t); break;
	case ',': *t = getchar(); break;
	case '[':pushToStack(s, i);  break;
	case ']':
	{
		if( checkActualCell(t)== 1) break;
		else backToBeginLoop(s->top() , t); 
	}
	default:
		break;
	}
}


void pushToStack(stack<int>* mStack, int posision)
{
	mStack->push(posision);
}


int checkActualCell( int* vskTab )
{
	if (*vskTab == 0) return 1; 
	// if cell == 0, clean possision in stack.  leave loop  
}

void backToBeginLoop( int pos, int* table )
{

}

int main()
{
	int* p = new int[3000]; //clean 
	memset(p, 0, 3000 * sizeof(int));
	int* tab = p;

	stack<int>* myStack = new stack<int>; 

	fstream file;
	string buff;
	string buff2;
	file.open("code.txt", ios::in);

	if (file.good() == false)
	{
		cout << "Can not open this file /n";
		return 0;
	}

	while (!file.eof())
	{
		getline(file, buff); // take line
		buff2.append(buff); // add to end string 
	}
	int len = buff.length();
	int n = 0;
	
	while (n != len) // operete on every single char 
	{
		checkChar(buff[n], tab, n , myStack);
		n++;
	}
	//	buff.erase();

	delete myStack; 
	file.close();
	return 0;
}
