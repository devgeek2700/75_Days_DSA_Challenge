#include <iostream>

using namespace std;

int main()
{
// 1)
//       for(int i = 0; i<5; i++){
//         for(int j = 0; j<5; j++){
//             cout<<'*';
//         }
//         cout<<endl;
//     }

// pattern:
// *****
// *****
// *****
// *****
// *****


// 2)
//  for( int i = 0; i<5; i++){
//         for(int j = 0; j<=i; j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }

// pattern:
// *
// **
// ***
// ****
// *****


// 3)

//  for( int i = 0; i<5; i++){
//         for(int j = 0; j<=i; j++){
//             cout<<j+1;
//         }
//         cout<<endl;
//     }

// pattern:
// 1
// 12
// 123
// 1234
// 12345


// 4)
//  for( int i = 0; i<5; i++){
//         for(int j = 0; j<=i; j++){
//             cout<<i+1;
//         }
//         cout<<endl;
//     }

// pattern:
// 1
// 22
// 333
// 4444
// 55555


// 5)
//   for( int i = 0; i<5; i++){
//         for(int j = 5; j>i; j--){
//             cout<<'*';
//         }
//         cout<<endl;
//     }

// pattern:
// *****
// ****
// ***
// **
// *

// 6)
//    for( int i = 0; i<5; i++){
//         for(int j = 1; j<=5-i; j++){
//             cout<<j;
//         }
//         cout<<endl;
//     }

// pattern:
// 12345
// 1234
// 123
// 12
// 1


// 6)
// for( int i = 0; i<5; i++){
//         for(int j = 5; j>i; j--){
//             cout<<i+1;
//         }
//         cout<<endl;
//     }

// pattern:
// 11111
// 2222
// 333
// 44
// 5



// 7)

//   int n = 9;
//     for(int i = 0; i<n; i++){
//         // space left side
//         for(int j = 0; j<n-i-1; j++){
//             cout<<" ";
//         }
        
//          // stars 
//         for(int j = 0; j<2*i+1; j++){
//             cout<<"*";
//         }
        
//         // space right side
//         for(int j = 0; j<n-i-1; j++){
//             cout<<" ";
//         }
//         cout<<endl;
//     }

// pattern:
//         *        
//        ***       
//       *****      
//      *******     
//     *********    
//    ***********   
//   *************  
//  *************** 
// *****************


// 8)
//  int n = 9;
//     for(int i = 0; i<n; i++){
        
       
//         // space left side
//         for(int j = 0; j<i; j++){
//             cout<<" ";
//         }
        
//           // stars 
//         for(int j = 0; j<n-2*i; j++){
//             cout<<"*";
//         }
        
        
//         // space right side
//         for(int j = 0; j<i; j++){
//             cout<<" ";
//         }
//         cout<<endl;
//     }

// pattern:
// *********
//  ******* 
//   *****  
//    ***   
//     * 

    return 0;
}