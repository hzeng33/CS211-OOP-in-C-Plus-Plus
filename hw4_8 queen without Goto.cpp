// CS211_Self Practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

bool ok(int q[], int c)
{
	for (int i = 0; i < c; i++) {
		if ((q[i] == q[c]) || (c-i == abs(q[c]-q[i])))
			return false;
	}
	
	return true;
}

void backtrack(int& c) //The "&" here is a reference.
{
	c--;
	if (c < 0) {
		system("PAUSE");
		exit(1);
	}
}

void print(int q[]) {
	static int count = 0;
    int i;
	cout << "SOLUTION" << ++count<<":" << endl;
	for (i = 0; i < 8; i++) 
		cout << q[i] << " ";
		cout << endl << endl;
}


int main() {

	int q[8]; 
	q[0] = 0;
	int c = 1;
    bool from_backtrack = false;
	/*this variable will be used to determine whether 
	the row should be reset to -1 in that column */

while (true) {
    while (c<8) {//this should repeat 8 times for all the columns 
       if (!from_backtrack) q[c] = -1;
	   /*if this was reached where baktrack was 
	   not called then q[c] is set to -1 */
	   from_backtrack = true;

         while (q[c]<8) {//this loop repeats 8 times for the rows 
             q[c]++;
             if (q[c] == 8) {/*if it reaches 8, then there is
							 no solution, so backtrack is called*/ 
               from_backtrack = true;
               backtrack(c);
			   break;
             }//end of if(q[c]==8) 

             if (ok(q, c)) {/*this tests if the spot can have a queen.
							if it does then we go to the next column */
                from_backtrack = false;
                c++;
				break;
             }//end of if(ok(q,c) 
         }//end of while(q[c]<8) 
    }//end of while(c<8) 

   print(q);// By this point a solution was reached so we print it 
   from_backtrack = true;
   backtrack(c);//now to find other solutions, we backtrack 

  }//end of while(true) 

}//end of main() 


