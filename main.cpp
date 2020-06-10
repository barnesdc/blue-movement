//
//  main.cpp
//  Week 2 BB
//
//  Created by Trey Brooks on 6/9/20.
//  Copyright © 2020 Trey Brooks. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void permut(string a, int x, int b)
{
    
    if (x == b)
        cout<< a <<endl;
    else
    {
       
        for (int i = x; i <= b; i++)
        {
  
            swap(a[x], a[i]);
  
           
            permut(a, x+1, b);
  
            swap(a[x], a[i]);
        }
    }
}

int main() {
    string str = "";
    string per ="";
    string pal ="";
    string temp ="";
    int size = str.size();
    int h=0;
    int r=0;
    int x=0;
     for(int i=size-1; i >= 0; i-- )
                per += str[i];
    // perfect Palindrome
    if (per==str) {
        for(int i=size-1; i >= 0; i-- )
             pal += str[i];
         
    }
    // Not perfect
    else{
        for(h; h < size -1; h++){
        
            for(int c=size-1; c >=0; c--){
            
            if (str[h] ==str[c] && c !=h ) {
               x=h;
               r=c;
                while(str[h] == str[c]){
                    temp += str[c];
                    h++;
                    c--;
                }
                h=x;
                c=r;
                if(temp.size() > pal.size()){
                    pal=temp;
                    temp="";
                }
                else
                    temp="";
                
            }
            }
            
        }
        
    }
    
    cout << pal << endl;
           
//Permutations
    permut(str, 0, size-1);
    
    return 0;
}
  
