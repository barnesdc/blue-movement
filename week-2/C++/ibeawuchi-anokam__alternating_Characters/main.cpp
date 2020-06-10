///////////////////////////////////////////////////////////////////////////////
//===========================================================================//
//                  F I L E     D O C U M E N T A T I O N                    //
//===========================================================================//
//                                                                           //
// Author:              Ibeawuchi Anokam                                     //
//---                                                                        //
// Title:               Alternating Characters                               //
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
//    You are given a string containing characters 'A' and 'B' only.         //
//    Your task is to change it into a string such that there are no         //
//    matching adjacent characters. To do this, you are allowed to delete    //
//    zero or more characters in the string.                                 //
//                                                                           //
//    Your task is to find the minimum number of required deletions.         //
//                                                                           //
//---------------------------------------------------------------------------//

//---------------------------------------
// System Libraries
//---------------------------------------
#include <fstream>      // Retrieves Inputs
#include <string>       // For Input Value Containers
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
int alternatingCharacters(string s);


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
    int    number_of_inputs;    // number of string queries
    
    string input;               // Note: PROBLEM CONSTRAINT 1 of 3:
                                // It is assumed the string consists of only
                                // the 'A' and 'B' character
    int    output;
    
    
    //---------------------------------------
    // OUTPUT VALUES
    //---------------------------------------
    cout << "OUTPUTS:" << endl;
    

    // PROBLEM CONSTRAINT 2 of 3 - Query Size :
    try{
        sample_test_case >> number_of_inputs;
        if( !(number_of_inputs >= 1  &&  number_of_inputs <= 10) ){
            
            throw runtime_error(" The number of inputs is beyond the exceptable range.\n" \
            " The exceptable range is between 1 and 10, inclusively.\n\n" );
        }
    }
    catch ( runtime_error& excpt ) {
         cout<< "ERROR: " << excpt.what() << "\n";
         number_of_inputs = -1; // Put the value out of range to by-pass While-Loop
    }
    
    
    // IFF  number_of_inputs >= 1  &&  number_of_inputs <= 10:
    int i = 0;
    while(   !sample_test_case.eof( )  &&   (i <  number_of_inputs)   &&   sample_test_case >> input  ){

        try{
            
            // PROBLEM CONSTRAINT 3 of 3:  ( 1 <=  |String Size| == 10^5 ) :
            if( !(static_cast<int>( input.size() )  >= 1  &&
                static_cast<int>( input.size() )  <= pow( 10, 5 ))  ){
                
                throw runtime_error(" String Length is beyond the exceptable range.\n" \
                                    " The exceptable range is between 1 and 10^5, inclusively.\n\n" );
            }
            output = alternatingCharacters( input );
            cout << output << endl;
        }
        catch ( runtime_error& excpt ) {
             cout<< "ERROR: " << excpt.what() << "\n";
        }

        // increment - Find the next input to check:
        i++;
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
// Function Definition
//--------------------------------------------------
int alternatingCharacters(string s){

    int number_of_char_deletions = 0;
    char last_char_to_check= ' ';
    int  i;
    for( i = 0;  i < static_cast<int>(s.size());  i++ ){

        if( i > 0 ){

            if( last_char_to_check == s.at(i)){
                number_of_char_deletions++;
            }
        }
        // store the last character to be seen:
        last_char_to_check = s.at(i);
    }
    return ( number_of_char_deletions );
}
