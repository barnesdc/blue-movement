///////////////////////////////////////////////////////////////////////////////
//===========================================================================//
//                  F I L E     D O C U M E N T A T I O N                    //
//===========================================================================//
//                                                                           //
// Author:              Ibeawuchi Anokam                                     //
//---                                                                        //
// Title:               Strings: Making Anagrams                             //
// Filename:            main.cpp                                             //
//---                                                                        //
// Date of Creation:    06/04/20                                             //
// Last Revised By:     N/A                                                  //
// Last Revision Date:  N/A                                                  //
//---                                                                        //
// Copyright:           Copyright © 2020 Ibeawuchi Anokam.                   //
//                      All rights reserved.                                 //
//---------------------------------------------------------------------------//
//                                                                           //
// Program Description:                                                      //
//                                                                           //
//    We consider two strings to be anagrams of each other if the first      //
//    string's letters can be rearranged to form the second string.          //
//    In other words, both strings must contain the same exact letters       //
//    in the same exact frequency For example, bacdc and dcbac are           //
//    anagrams, but bacdc and dcbad are not.                                 //
//                                                                           //
//    Given two strings, 'a' and 'b', that may or may not be of the same     //
//    length, determine the minimum number of character deletions            //
//    required to make 'a' and 'b' anagrams. Any characters can be           //
//    deleted from either of the strings.                                    //
//                                                                           //
//---------------------------------------------------------------------------//

//---------------------------------------
// System Libraries
//---------------------------------------
#include <fstream>      // Retrieves Inputs
#include <string>       // For Input Value Containers
#include <vector>       // Used in the makeAnagram Function
#include <iostream>     // For Debugging
#include <cmath>        // pow( b, p )
using namespace std;

//---------------------------------------
// File I/O stream
//---------------------------------------
ifstream sample_test_case;

//---------------------------------------
// Function Prototype
//---------------------------------------
int makeAnagram(string a, string b);


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
    string input_1, input_2;    // Note: PROBLEM CONSTRAINT 1 of 2:
                                // It is assumed that the strings only
                                // consist of  ascii[ a-z ]
    int    output;
    
    //---------------------------------------
    // OUTPUTTING
    //---------------------------------------
    cout << "OUTPUTS:" << endl;
    
    while(   !sample_test_case.eof( )     &&
             sample_test_case >> input_1  &&
             sample_test_case >> input_2        )
    {

        try{
            
            // PROBLEM CONSTRAINT 2 of 2:  ( 1 <=  |String Size| == 10^4 ) :
            if( !(static_cast<int>( input_1.size() )  >= 1  &&
                  static_cast<int>( input_1.size() )  <= pow( 10, 4 ))  &&
               
                !(static_cast<int>( input_2.size() )  >= 1  &&
                  static_cast<int>( input_2.size() )  <= pow( 10, 4 ))       )
            {
                
                throw runtime_error(" String lengths are beyond the exceptable range.\n" \
                                    " The exceptable range is between 1 and 10^4, inclusively.\n\n" );
            }
            output = makeAnagram( input_1, input_2 );
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
int makeAnagram(string a, string b) {

    // ascii[a-z] Frequency Table:
    vector< int > a_freq_table(26);
    vector< int > b_freq_table(26);

    
    // Find  string a's  letters:
    int i;
    for( i = 0; i < static_cast<int>(a.size()); i++ ){

        // account for the letter:
        a_freq_table.at(  static_cast<int>(a.at(i)) - 97  ) += 1;
    }
    
    // Find  string b's  letters:
    for( i = 0; i < static_cast<int>(b.size()); i++ ){

        // account for the letter:
        b_freq_table.at(  static_cast<int>(b.at(i)) - 97  ) += 1;
    }
    

    // Account for character deletions:
    int deletion_count = 0;
    for( i = 0;  i < 26; i++ ){

        //CASE 1:
        if( a_freq_table.at(i) > b_freq_table.at(i) ){
            deletion_count += a_freq_table.at(i) - b_freq_table.at(i);
        }
        //CASE 2:
        if( a_freq_table.at(i) < b_freq_table.at(i) ){
            deletion_count += b_freq_table.at(i) - a_freq_table.at(i);
        }
    }

    return ( deletion_count );
}
