/***************************
 *   By: Jeton Sinoimeri   *
 *   Assignment 3 Q1       *
 *   Version: 1.0          *
 ***************************/


#include <iostream>
#include <math.h>

using namespace std;

bool isInt (double value) {
  double dummy;
  return bool(modf(value, &dummy) == 0);
}

double sqr(double value) { return value * value; }

int main (void) {

  // Variables
  double room_di1, // the length of the room
         room_di2, // the width of the room
         carpet_di1, // the length of the carpet
         carpet_di2; // the width of the carpet
  
  // variables for output
  double total_carpets = 0, // total carpets entered
         invalid_carpets = 0, // invalid carpets count
         valid_carpets = 0, // valid carpets count
         perfect_carpets = 0, // perfect carpets count
         trimmed_carpets = 0, // trimmed carpets count
         cannot_carpets = 0, // carpets that cannot be used count
         sum_area = 0, // sum of valid carpet area
         max_area = 0, // max area
         min_area; // min area
         
  int invalid_rooms = 1; // invalid room count


  // Input statements for room's dimensions
  cout << "Enter the room's dimensions: ";
  cin >> room_di1
      >> room_di2;

  /* if room's dimensions are invalid, the code in while loop will loop
     ouput an error message and ask for input until the room's dimensions
     are valid */
  while (room_di1 <= 0 || room_di2 <= 0) {
    invalid_rooms ++; // adds one to invalid rooms
    
    cout << "Those dimensions are invalid" << endl;
    cout << "Enter the rooms dimensions again: ";
    cin >> room_di1
        >> room_di2;
  } // end while

  // Input statements for carpet's dimensions
  cout << "Enter the carpet's dimensions (0 0 to stop): ";
  cin >> carpet_di1
      >> carpet_di2;

  // if both carpet's length and width are 0 then the program quits
  while (carpet_di1 != 0 || carpet_di2 != 0) {
    
     total_carpets ++; // adds one to total carpets entered
    
    // checks if the carpet is able to fit into the room or not
    if ((room_di1 <= carpet_di1 && room_di2 <= carpet_di2) || (room_di1 <= carpet_di2 && room_di2 <= carpet_di1)) {
       
      // checks if the carpet is a perfect match and outputs it is a perfect match
      if ((room_di1 == carpet_di1 || room_di2 == carpet_di1) && (room_di1 == carpet_di2  || room_di2 == carpet_di2)) {
        cout << "The carpet is a perfect fit" << endl;
        perfect_carpets ++ ; // adds one to perfect carpets

      } else {
        /* If the carpet has larger dimensions then the room, 
           the program outputs the carpet can be trimmed */
        cout << "The carpet can be trimmed to size" << endl;
        trimmed_carpets ++; // adds one to trimmed carpets
      } // end if

    } else {

      // checks if one or both of the carpet's inputed dimensions are invalid
      if (((carpet_di1 <= 0 || carpet_di2 <= 0) && carpet_di1 != carpet_di2) || ((carpet_di2 < 0 ||carpet_di1 < 0) && carpet_di2 == carpet_di1)) {
        cout << "Those dimensions are invalid." << endl;
        invalid_carpets ++; // adds one to invalid carpets

      } else {

        /* If the carpet's dimensions are smaller than the room
           the program outputs the carpet cannot be used */
        cout << "The carpet cannot be used" << endl;
        cannot_carpets ++; // adds one to cannot use carpets
      } // end if
      
    } // end if
    
    if (!(((carpet_di1 <= 0 || carpet_di2 <= 0) && carpet_di1 != carpet_di2) || ((carpet_di2 < 0 ||carpet_di1 < 0) && carpet_di2 == carpet_di1))) {
        // finds max
       if (carpet_di1*carpet_di2 > max_area){
            max_area = carpet_di1*carpet_di2;
            }// end if
       
        // finds min 
       if ( valid_carpets == 1 || carpet_di1*carpet_di2 < min_area) {
            min_area = carpet_di1*carpet_di2;
            } // end if
            
        sum_area += (carpet_di1*carpet_di2); // sum of valid carpet area
        valid_carpets ++; // adds one to valid carpets
        
    
    } // end if
            
    // Input statements for carpet's dimensions
    cout << "Enter the carpet's dimensions (0 0 to stop): ";
    cin >> carpet_di1
        >> carpet_di2;

  } // end while
  
  // statistics calculations and output statements
  if (total_carpets != 0){
        
        // percent calculations
        double percent_invalid = ( invalid_carpets / total_carpets )*100; // percent of invalid carpets
        double percent_valid = (  valid_carpets / total_carpets )*100; // percent of valid carpets
        double percent_fit = (  perfect_carpets / total_carpets )*100; // percent of perfect fit carpets
        double percent_trimmed = (  trimmed_carpets / total_carpets )*100; // percent trimmed carpets
        double percent_cannot = (  cannot_carpets / total_carpets )*100; // percent of carpets that cannot be used
        
        // average area calculations
        double avg_valid_area = sum_area / valid_carpets;
        
        // output statements
        cout << "The number of tries to get a valid room size was: " << invalid_rooms << endl;
        
        cout << "\nThe number of carpet sizes entered was: " << total_carpets <<
        "\nThe number of invalid carpet sizes was: " << invalid_carpets <<
        "\nThe number of valid carpet sizes was: " << valid_carpets << endl;
        
        cout << "\nThe number of carpets that fit exactly was: " << perfect_carpets <<
        "\nThe number of carpets that could be trimmed was: " << trimmed_carpets <<
        "\nThe number of carpets that could not be used was: " << cannot_carpets << endl;
        
        cout << "\nThe percent of invalid carpets was: " << percent_invalid <<
        "%\nThe percent of valid carpets was: " << percent_valid <<"%\n";
        
        cout << "\nOf the valid carpets:\n";
        
        cout << "The percent of exact fit carpets was: " << percent_fit <<
        "%\nThe percent of trim to size carpets was: " << percent_trimmed <<
        "%\nThe percent of carpets that could be used was: " << percent_valid - percent_cannot <<
        "%\nThe percent of carpets that could not be used was: " << percent_cannot << "%\n";
        
        cout << "\nThe average valid carpet area was " << avg_valid_area << endl;
        
        cout << "\nThe smallest valid carpet area was " << min_area <<
        "\nThe largest valid carpet area was " << max_area << endl;
        
        } // end if

  system("PAUSE"); 
  
  return 0;
  
}
