/***************************
 *   By: Jeton Sinoimeri   *
 *   Assignment 3 Q2       *
 *   Version: 1.0          *
 ***************************/




#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

bool isInt (double value) {
    double dummy;
    return bool(modf(value, &dummy) == 0);
}

double sqr(double value) { return value * value; }

int main (void) {

    // INSERT YOUR CONSTANT DECLARATIONS HERE
    const int MAX_GAP_ALLOWED = 1*60 - 1;

    // INSERT YOUR VARIABLE DECLARATIONS HERE
    int hours, mins, valid_times = 0, 
        invalid_times = 0, previous_mins = 0, actual_mins,
        gap, min_gap = 30000, max_gap = 0;
        
    double total_gap = 0;
    
    bool is_after_midnight;

    
    // input statements
    cout << "Enter time in hours and minutes (99 99 to stop): ";
    cin >> hours >> mins;
    
    while (hours != 99 && mins != 99) {
        is_after_midnight = false;


        // validate time entered
        if (hours < 0 || hours > 23 || mins < 0 || mins > 59) {
            cout << "** Time ignored - hours and/or minutes invalid. **" <<endl;
            invalid_times ++; // adds one to invalid times
        }
          
        else {
            actual_mins = hours * 60 + mins; // converts everything into mins
            
            // is midnight in the gap
            if (valid_times > 0 && actual_mins <= previous_mins ){
                actual_mins += 24 * 60; // add 24 hours
                is_after_midnight = true;             
            }
           
            if (is_after_midnight && valid_times > 0 && actual_mins - previous_mins > MAX_GAP_ALLOWED) {
                    
                // gap is more than allowed
                cout << "** Time ignored - not >= previous time. **" << endl;
                invalid_times ++;
            }
            
            // validated data
             else {
                valid_times ++;
                
                if (valid_times > 1){
                    gap = actual_mins - previous_mins;
                    
                    // max and min
                    if (gap < min_gap) { min_gap = gap; }
                    if (gap > max_gap) { max_gap = gap; }
                    
                    total_gap += gap;
                } // end if
                
                previous_mins = actual_mins;
                
                // keep previous mins within 0 - 24 hour range
                previous_mins = previous_mins % (24*60);
            } // end if
                      
                
        }// end if
         
        // input statements
        cout << "Enter time in hours and minutes (99 99 to stop): ";
        cin >> hours >> mins; 
        
    }// end while
    
    // output statements   
    cout << endl << valid_times <<" valid times and " << invalid_times << " invalid times were entered." << endl;
    
    if (valid_times > 1) {
        cout << "The shortest gap was " << min_gap << " minutes long.\n";
        cout << "The longest gap was " << max_gap << " minutes long.\n";
        cout << "The average gap length was " << total_gap / (valid_times -1)  << " minutes.\n";
    }
        
    else {
        cout << "Fewer than 2 times entered - no gaps to analyse." << endl;  
    } // end if

    system("PAUSE"); 
    
    return 0;

}
