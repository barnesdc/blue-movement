///////////////////////////////////////////////////////////////////////////////
//===========================================================================//
//                  F I L E     D O C U M E N T A T I O N                    //
//===========================================================================//
//                                                                           //
// Author:              Ibeawuchi Anokam                                     //
//---                                                                        //
// Title:               Common Child                                         //
// Filename:            main.cpp                                             //
//---                                                                        //
// Date of Creation:    06/08/20                                             //
// Last Revised By:     N/A                                                  //
// Last Revision Date:  N/A                                                  //
//---                                                                        //
// Copyright:           Copyright © 2020 Ibeawuchi Anokam.                   //
//                      All rights reserved.                                 //
//---------------------------------------------------------------------------//
//                                                                           //
// Program Description:                                                      //
//                                                                           //
//    A string is said to be a child of a another string if it can be        //
//    formed by deleting 0 or more characters from the other string.         //
//    Given two strings of equal length, what's the longest string that      //
//    can be constructed such that it is a child of both?                    //
//                                                                           //
//---------------------------------------------------------------------------//

//---------------------------------------
// System Libraries
//---------------------------------------
#include <fstream>      // Retrieves Inputs
#include <string>       // For Input Value Containers
#include <vector>       // Used in the commonChild Function
#include <iostream>     // For Debugging
using namespace std;

//---------------------------------------
// File I/O stream
//---------------------------------------
ifstream sample_test_case;

//---------------------------------------
// Function Prototypes
//---------------------------------------
int commonChild(string s1, string s2);


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
                                // consist of ascii[ A-Z ]
    int output;
    
    //---------------------------------------
    // OUTPUTTING
    //---------------------------------------
    cout << "OUTPUTS:" << endl;
    
    while(   !sample_test_case.eof( )     &&
             sample_test_case >> input_1  &&
             sample_test_case >> input_2        )
    {

        try{
            
            // PROBLEM CONSTRAINT 2 of 2:  ( 1 <=  |String Size| == 5000 ) :
            if(  !(static_cast<int>( input_1.size() )  >= 1 &&
                   static_cast<int>( input_1.size() )  <= 5000  )
                                   &&
                 !(static_cast<int>( input_2.size() )  >= 1  &&
                   static_cast<int>( input_2.size() )  <= 5000  )      )
            {
                
                throw runtime_error(" String lengths are beyond the exceptable range.\n" \
                                    " The exceptable range is between 1 and 5000, inclusively.\n\n" );
            }
            output = commonChild( input_1, input_2 );
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
// Function Definition
//--------------------------------------------------
int commonChild(string s1, string s2){

    //Initialize LCS (longest common subsequence) Matrix (table):
    int s1_row    = static_cast<int>(s1.size())+1;	// the +1 allows for the zero row
    int s2_column = static_cast<int>(s2.size())+1;  // the +1 allows for the zero column
    vector< vector<int> > lcs_matrix(  s1_row,  vector<int>(s2_column, 0)  );
    
    
    // Fill in the matrix:
    int i, j;
    for( i = 1;  (i < s1_row);  i++  ){
        
        for(  j = 1;  (j < s2_column);  j++  ){
            
            // Continue IF the Row to column comparison yields a FALSE result:
            if( s1.at(i-1) !=  s2.at(j-1) ){
                
                
                if( (lcs_matrix.at(i)).at(j-1)>(lcs_matrix.at(i-1)).at(j) ){
                    
                    (lcs_matrix.at(i)).at(j) =(lcs_matrix.at(i)).at(j-1);
                }
                else if((lcs_matrix.at(i)).at(j-1)<(lcs_matrix.at(i-1)).at(j)){
                    
                    (lcs_matrix.at(i)).at(j) =(lcs_matrix.at(i-1)).at(j);
                }
                else{ // ... lcs_matrix[i][j-1] == lcs_matrix[i-1][j];
                      // Use either ...
                    (lcs_matrix.at(i)).at(j) =(lcs_matrix.at(i)).at(j-1);
                }
            }
            // Else, Continue IF the Row to column comparison yields a TRUE result:
            else{ // ...if( s1.at(i-1) ==  s2.at(j-1) )
                
                (lcs_matrix.at(i)).at(j) =(lcs_matrix.at(i-1)).at(j-1)+1;
            }
        }
    }
    
    
    // FIND the largest subsequence size and return it:
    int max_subsequence_length=(lcs_matrix.at(s1_row-1)).at(s2_column-1);
    return( max_subsequence_length );
}
