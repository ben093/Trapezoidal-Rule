/*=============================================================
	COURSE:	CSC460, assignment1
	PROGRAMMERS: 	Ben (bb), Anthony (av)
	MODIFIED BY: Ben, Anthony
	LAST MODIFIED DATE:	2/9/2016
	DESCRIPTION:	This program is an implementation of the trapezoidal rule.
	NOTE: 50% Ben, 50% Anthony
	FILES:	makefile, trapezoidal.cpp, trapezoidal.o, callFunction.cpp, callFunction.h, callFunction.o,
            trapezoidal
	IDE/COMPILER/INTERPRETER:	GNU g++
	INSTRUCTION FOR COMPILATION AND EXECUTION:
	1. make	to COMPILE
	2. type:	./trapezoidal left right to EXECUTE
=============================================================*/

#include "iostream"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <iomanip>
#include <ctype.h>
#include "callFunction.h"

using namespace std;

int main(int argCount, char* argList[])
{
  double leftEnd = 0, rightEnd = 0;

  if(argCount != 3)
  { // Validate number of arguments
    cout << "Invalid input parameters" << endl;
    return 0;
  }

  for (int i=1; i < argCount; i++) 
  { // Validate entries to only allow double inputs.
    char* end;
    double val = strtod(argList[i], &end);
    if (end[0])
    { // end[0] is the first non-numeric argument.
      cout << "Error: Invalid input." << endl;
      return 0;
    }
    else
    {  // Input appears valid so far.
       if(i == 1)
       { // First iteration is leftEnd
         leftEnd = val;
       }
       else if(i == 2)
       { // Second iteration is rightend
         rightEnd = val;
       }
    }
  }
  
  if(leftEnd >= rightEnd)
  { // Left end cannot be greater than or equal to the right end.
    cout <<  "Left end has to be less than the right end." << endl;
    return 0;
  }
  
  srand(time(NULL));
  // Generate random number between 5 and 100.
  double n = (rand() % 95) + 5;
  
  double y1 = callFunction(leftEnd);

  double y2 = callFunction(rightEnd);

  // Calculate delta X
  double deltaX = (double)(rightEnd - leftEnd)/ n;

  double ans = 0;
  for(int i = 1; i < n; i++)
  { // Iterate through n times
    leftEnd += deltaX;
    ans = ans + (2 * callFunction(leftEnd));
  }

  ans += (y1 + y2);

  ans = ans * (deltaX/2);

  // Set precision to allow more decimal places.
  cout << setprecision(9) << "Trapezoid Approximation: " << ans << endl;

  return 0;
}
