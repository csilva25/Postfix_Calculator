
#include <iostream>
#include <cstdio>
#include <string>
#include "stdio.h"
#include "dstack.h"
#include "math.h"

using namespace std;


void error()
{
    cerr << "Error: Invalid expression." << endl;
    exit(1);
}

int main()
{
    double value = 0; //read a double

    Dstack stack;
    char op;
    
    while ( cin.peek() != EOF )
    {
        if (isspace(cin.peek()))
            {
            cin.ignore();
            }
        else if ( isdigit( cin.peek()) || cin.peek() == '.') // if the next thing is a digit
        {
        
            cin >> value; //cin's i.e. 1.234
            if (cin.good() == false)
            {
                error();
            }
            stack.push(value);
            
        }
      
        else {
            
            //assume its something else
            //string extra;
            
            cin >> op;
         
              //read as a SINGLE charactor i.e. ONE + or - or a
    
            double valueR;
            double valueL;
            
            if (stack.size() < 2) {
                error();
            }
            
               else if (stack.size() >= 2 && stack.empty() == false && stack.pop(valueR) && stack.pop(valueL))
                    {
                switch (op)
                {
                    case '+':
                    {
                       
                       
                        value = valueR + valueL;
                        stack.push(value);
                       
                    break;
                    }
                    case '-':
                            {
                               
                                
                            value = valueL - valueR;
                           stack.push(value);
                            
                        break;
                            }
                    case '*':
                            {
                             
                    value = valueR * valueL;
                    stack.push(value);
                            
                        break;
                            }
                    case '/':
                        
                      if (valueL == 0)
                        {
                            break;
                        }
                      else
                      {
                    value = valueL / valueR;
                           stack.push(value);
                      
                        break;
                            }
                  case '^':
                            {
                               
                        value = pow(valueL, valueR);
                           stack.push(value);
                                
                       break;
                            }
           //     case 'sqrt':
             //               {
               //                 final = pow(valueR, .5);
                 //               stack.push(final);
                   //             break;
                     //       }
                    default:
                        {
                        error();
                        break;
                        }
                        }
                    }
            
           else
               error();
        }
        
    }
    
    
    if (stack.size() == 1)
    {
        
        cout << value<<endl;
       
    }
    else
        error();
   
    
    return 0;

}

