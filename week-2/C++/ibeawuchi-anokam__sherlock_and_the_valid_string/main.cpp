///////////////////////////////////////////////////////////////////////////////
//===========================================================================//
//                  F I L E     D O C U M E N T A T I O N                    //
//===========================================================================//
//                                                                           //
// Author:              Ibeawuchi Anokam                                     //
//---                                                                        //
// Title:               Sherlock and the Valid String                        //
// Filename:            main.cpp                                             //
//---                                                                        //
// Date of Creation:    06/05/20                                             //
// Last Revised By:     N/A                                                  //
// Last Revision Date:  N/A                                                  //
//---                                                                        //
// Copyright:           Copyright © 2020 Ibeawuchi Anokam.                   //
//                      All rights reserved.                                 //
//---------------------------------------------------------------------------//
//                                                                           //
// Program Description:                                                      //
//                                                                           //
//    Sherlock considers a string to be valid if all characters of the       //
//    string appear the same number of times. It is also valid if he         //
//    can remove just 1 character at 1 index in the string, and the          //
//    remaining characters will occur the same number of times.              //
//                                                                           //
//    Given a string 's', determine if it is valid.                          //
//    If so, return "YES", otherwise return "NO".                            //
//                                                                           //
//---------------------------------------------------------------------------//

//---------------------------------------
// System Libraries
//---------------------------------------
#include <fstream>      // Retrieves Inputs
#include <string>       // For Input Value Containers
#include <vector>       // Used in the isValid Function
#include <iostream>     // For Debugging
#include <cmath>        // pow( b, p )
using namespace std;

//---------------------------------------
// File I/O stream
//---------------------------------------
ifstream sample_test_case;

//---------------------------------------
// Function Prototypes
//---------------------------------------
string isValid(string s);


//--------------------------------------------------
// Main Program
//--------------------------------------------------
int main( ){
    //---------------------------------------
    // Open the Stream
    //---------------------------------------
    sample_test_case.open("sample_test_cases.txt");

    //---------------------------------------
    // Variable declarations  -
    // TEST INPUT / OUTPUT
    //---------------------------------------
    string input;    // Note: PROBLEM CONSTRAINT 1 of 2:
                     // It is assumed that the string only
                     // consist of  ascii[ a-z ]
    string output;
    
    //---------------------------------------
    // OUTPUTTING
    //---------------------------------------
    cout << "OUTPUTS:" << endl;
    
    while(   !sample_test_case.eof( )     &&
             sample_test_case >> input         )
    {

        try{
            
            // PROBLEM CONSTRAINT 2 of 2:  ( 1 <=  |String Size| == 10^5 ) :
            if( !(static_cast<int>( input.size() )  >= 1  &&
                  static_cast<int>( input.size() )  <= pow( 10, 5 ))    )
            {
                
                throw runtime_error(" String lengths are beyond the exceptable range.\n" \
                                    " The exceptable range is between 1 and 10^4, inclusively.\n\n" );
            }
            output = isValid( input );
            cout << output << endl;
        }
        catch ( runtime_error& excpt ) {
             cout<< "ERROR: " << excpt.what() << "\n";
        }
    }
    
    //---------------------------------------
    // Close the Stream
    //---------------------------------------
    sample_test_case.close( );
    //---------------------------------------
    // Windows-specific Console Macro
    //---------------------------------------
    #if defined (_WIN32) || defined (_WIN64)
        system( "pause" );
    #endif
    //---------------------------------------
    // End program
    //---------------------------------------
    return 0;
}


//--------------------------------------------------
// Function Definition:
//--------------------------------------------------
string isValid(string s) {

    //-------------------------------------------------------------------------
    // Create the frequency table
    //-------------------------------------------------------------------------
    vector< int > ascii_lowercaseLetters_freq(26);

    //-------------------------------------------------------------------------
    // Variables
    //-------------------------------------------------------------------------
    int highest_freq = 0, lowest_freq = 10*10*10*10*10+1; // tracks the highest
                                                          // and lowest
                                                          // frequency value
                                                          // found in the
                                                          // frequency table
                                                          
    int highest_freq_count = 0, lowest_freq_count = 0;    // counts the instances
                                                          // of the highest and
                                                          // lowest frequncy

    //-------------------------------------------------------------------------
    // Initialize the Frequency Table
    //-------------------------------------------------------------------------
    int i;
    for( i = 0;   i < static_cast<int>(s.size());   i++ ){

        // insert characters count:
        ascii_lowercaseLetters_freq.at(  static_cast<int>(s.at(i)) - 97  ) += 1;
    }

    //-------------------------------------------------------------------------
    // FINDING MAX + MIN
    //-------------------------------------------------------------------------
    for( i = 0;  i < static_cast<int>(ascii_lowercaseLetters_freq.size()); i++)
    {

        if( ascii_lowercaseLetters_freq.at(  i  ) > 0){
            // Check for the highest Frequency:
            if( ascii_lowercaseLetters_freq.at( i ) > highest_freq  ){

                    highest_freq =
                    ascii_lowercaseLetters_freq.at( i );
            }

            // Check for the lowest Frequency:
            if( ascii_lowercaseLetters_freq.at(  i  ) < lowest_freq ){

                    lowest_freq =
                    ascii_lowercaseLetters_freq.at( i );
            }
        }
    }


    // FINDING MAX COUNTER + MIN COUNTER:
    for( i = 0; i < static_cast<int>(ascii_lowercaseLetters_freq.size()); i++ )
    {
        // Check for the highest Frequency:
        if( ascii_lowercaseLetters_freq.at(  i  ) == highest_freq   ){
                // count:
                highest_freq_count++;
        }

        // Check for the highest Frequency:
        if( ascii_lowercaseLetters_freq.at(  i  ) == lowest_freq    ){
                // count:
                lowest_freq_count++;
        }
    }


    // CREATE a Copy of 'ascii_lowercaseLetters_freq' for DISTINCT(unique) analysis:
    vector<int> number_of_DISTINCT_freq (ascii_lowercaseLetters_freq);


    // SORT the vector - preprocess to deleteing duplicates
    sort( number_of_DISTINCT_freq.begin(), number_of_DISTINCT_freq.end() );
    // DELETE the adjacent duplicate characters
    auto new_last = unique(number_of_DISTINCT_freq.begin(), number_of_DISTINCT_freq.end());
    // ERASE the empty indices created by new_last
    number_of_DISTINCT_freq.erase( new_last, number_of_DISTINCT_freq.end());


    //-------------------------------------------------------------------------
    // Output Conditions
    //-------------------------------------------------------------------------
    // NONE ARE GETTING DELETED
    if( highest_freq == lowest_freq ){ // equal
        
        return "YES";
    }
    // THE MINIMUM IS GETTING DELETED:
    else if( highest_freq != lowest_freq ){
        
        // NOTE!: The minus 1 discounts the zero in the frequency table
        // (in the next line):
        if( static_cast<int>(number_of_DISTINCT_freq.size()) - 1  >= 1  &&
            static_cast<int>(number_of_DISTINCT_freq.size()) - 1  <= 2      ){
            
            if(   highest_freq == lowest_freq +1  &&
                  highest_freq_count ==  1        &&
                  lowest_freq_count  >= 1              ){
                
                return "YES";
            }
            else if (   lowest_freq == 1              &&
                        lowest_freq_count  ==  1      &&
                        highest_freq >= 2             &&
                        highest_freq_count >= 1            ){
                
                return "YES";
            }
            else{
                return "NO";
            }
            
        }
        else{
            return "NO";
        }
    }
    else{
        
        return "NO";
    }
}


