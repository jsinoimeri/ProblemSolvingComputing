/******************************
 *   By: Jeton Sinoimeri      *
 *   Assignment 4 Q2          *
 *   Version: 1.0             *
 *                            *
 *   This program uses for    * 
 *   loops and output         *
 *   formatting to print      *
 *   tables of values,        *
 *   their square, square     *
 *   root, and whether they   *
 *   are prime or not.        *
 ******************************/





#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Returns the square of an integer value.
int sqrInt(int value);

/* Returns true if value is prime, false otherwise.
  (Also returns false if value is less than 2.)
*/ 
bool isPrime (int value);

/* Returns an integer value from the user between minimum and 
   maximum, inclusive. We assume that the calling function has 
   output the initial request for input. This function will check 
   the value entered and output an error message until a value 
   in the correct range is entered.
*/ 
int getInt(int minimum, int maximum);

int main () {

  int prev, 
      value, 
      rows, 
      dec, 
      i, 
      j, 
      maxrows;
      
  double sqrtv;
  
  bool firstTime = true, 
       prime;

  // loop until user enters the same number twice
  for (;;) {
    
    /* get value from user and ensure that it is in the valid range, 
       i.e. abs(value) < 10000 */
    for(;;) {
        cout << "Enter start value (repeat previous valid number to exit): ";
        cin >> value;
        
        if (abs(value)<10000) {
            break;
        }
        
        cout << "Value must be between -9999 and 9999, try again!" << endl;
    } // end for   
    
    /* if it's the first time, change our flag
       otherwise if user entered the same value, then exit */
    if (firstTime) {
        firstTime = false;
        
    } else if (value == prev) {break;}
    
    // store value in prev for next comparison
    prev = value;
    
    /* get number of  rows (between 1 and 200, as long as numbers don't
       exceed 9999) */
    maxrows=200;
    
    if (value>9800) {
        maxrows = 10000-value;
    }
    for(;;) {
        cout << "Enter number of rows (1 to " << maxrows << "): ";
        cin >> rows;
        
        // valid input
        if (rows>=1&&rows<=maxrows) {
            break;
        }
        
        cout << "Rows must be between 1 and " << maxrows << ", try again!" << endl;
    
    } // end for
    
    // get number of decimal places (between 1 and 7)
    for(;;) {
        cout << "Enter number of decimal places (1 to 7): ";
        cin >> dec;
        
        // valid input
        if (dec>=1&&dec<=7) {
            break;
        } 

        cout << "Decimals must be between 1 and 7, try again!" << endl;

    } // end for

    // output table
    cout << "     Value     Square   Square Root  Prime?" << endl;
    cout << setiosflags (ios::showpoint | ios::fixed) << setprecision (dec);
    
    for (i = 0; i < rows; i++) {
        
        // output current value and its square
        cout << setw(10) << value+i << setw(11) << sqrInt(value+i) << setw(13);
        
        // output its square root, if applicable
        if (value+i<0) {
            cout << "N/A" << setw(7);
            
        } else {
            sqrtv = sqrt(value+i); // we'll use this later, so it's more efficient
            cout << sqrtv << setw(7);
        } // end if
        
        // output if it's prime or not, if applicable
        if (value + i < 2) {
            cout << "N/A" << endl;
            
        } else {
            prime = true;
            for (j=2; j <= sqrtv; j++) { // here's where we used sqrtv
                if ((value + i)%j == 0) {
                    prime=false;
                    break;
                }
            } // end for
            if (prime) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            } // end if
        } // end if

    } // end for
    cout << endl;

  } // end for
  
  system ("PAUSE"); 
  
  return 0;

} // end main
