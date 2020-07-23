///////////////////////////////////////////////////////////////////////////////
//===========================================================================//
//                  F I L E     D O C U M E N T A T I O N                    //
//===========================================================================//
//                                                                           //
// Author:              Ibeawuchi Anokam                                     //
//---                                                                        //
// Title:               Special String Again                                 //
// Filename:            main.cpp                                             //
//---                                                                        //
// Date of Creation:    06/07/20                                             //
// Last Revised By:     N/A                                                  //
// Last Revision Date:  N/A                                                  //
//---                                                                        //
// Copyright:           Copyright © 2020 Ibeawuchi Anokam.                   //
//                      All rights reserved.                                 //
//---------------------------------------------------------------------------//
//                                                                           //
// Program Description:                                                      //
//                                                                           //
//    A string is said to be a special string if either of                   //
//    two conditions is met:                                                 //
//                                                                           //
//      - All of the characters are the same, e.g. aaa.                      //
//      - All characters except the middle one are the same, e.g. aadaa.     //
//                                                                           //
//    A special substring is any substring of a string which meets one       //
//    of those criteria. Given a string, determine how many special          //
//    substrings can be formed from it.                                      //
//                                                                           //
//---------------------------------------------------------------------------//

//---------------------------------------
// System Libraries
//---------------------------------------
#include <fstream>      // Retrieves Inputs
#include <string>       // For Input Value Containers
#include <vector>       // Used in the substrCount Function
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
long substrCount(int n, string s);


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
    int    inputs_size;    // string size
    
    string input;          // Note: PROBLEM CONSTRAINT 1 of 2:
                           // It is assumed that the string only
                           // consist of  ascii[ a-z ]
    long   output;
    
    //---------------------------------------
    // OUTPUTTING
    //---------------------------------------
    cout << "OUTPUTS:" << endl;
    
    while(   !sample_test_case.eof( )         &&
             sample_test_case >> inputs_size  &&
             sample_test_case >> input            )
    {

        try{
            
            // PROBLEM CONSTRAINT 2 of 2:  ( 1 <=  |String Size| == 10^5 ) :
            if( !(  inputs_size  >= 1  &&
                    inputs_size  <= pow( 10, 6 ))    )
            {
                
                throw runtime_error(" String length is beyond the exceptable range.\n" \
                                    " The exceptable range is between 1 and 10^6, inclusively.\n\n" );
            }
            output = substrCount( inputs_size, input );
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
long substrCount(int n, string s){

    //-------------------------------------------------------
    // CASE 1 --
    // EACH INDIVIDUAL LETTER (element)
    // from the Given set
    //-------------------------------------------------------
    long special_substring_count = static_cast<long>(s.size());

//---

    for( int i=0;  i < static_cast<int>(s.size());  i++ ){
        
        //-------------------------------------------------------
        // CASE 2 --
        // ALL subset COMBINATIONS
        // from consecutive repition of letters (elements)
        //-------------------------------------------------------
        int  repition = 0;
        while( i+1 < static_cast<int>(s.size()) &&
               s.at( i+1 ) == s.at( i )               )
        {
            repition++;
            i++;
        }
        special_substring_count += (repition*(repition+1))/2;
    

        //-------------------------------------------------------
        // CASE 3 --
        // ALL subset with 2 letters of DISTINCTION Combinations
        // with the middle letter being the different
        //-------------------------------------------------------
        bool end_loop = false;
        int  ptr  = 1;
        while(  (i-ptr >=0) &&
                (i+ptr < static_cast<int>(s.size())) &&
                end_loop == false                           )
        {
            if(  s.at(i + ptr)==s.at(i - 1) &&
                 s.at(i - ptr)==s.at(i + 1)     ){
                special_substring_count += 1;
                ptr++;
            }
            else{
                end_loop = true;
            }
        }
    }
 
//---
    //-------------------------------------------------------
    // Return Value                                         
    //-------------------------------------------------------
    return ( special_substring_count );
}
