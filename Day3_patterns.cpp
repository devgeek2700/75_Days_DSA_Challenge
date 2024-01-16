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
    //         for(int j = 0; j<2*n-(2*i+1); j++){
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

    // 9)
    //     int n = 5;
    //   for(int i = 0; i<n; i++){
    //             // space left side
    //             for(int j = 0; j<n-i-1; j++){
    //                 cout<<" ";
    //             }

    //              // stars
    //             for(int j = 0; j < (2*i)+1; j++){
    //                 cout<<"*";
    //             }

    //             // space right side
    //             for(int j = 0; j<n-i-1; j++){
    //                 cout<<" ";
    //             }
    //             cout<<endl;
    //         }

    //     // printrev9(5);

    //        for(int i = 0; i<n; i++){

    //             // space left side
    //             for(int j = 0; j<i; j++){
    //                 cout<<" ";
    //             }

    //               // stars
    //             for(int j = 0; j<2*n-(2*i+1); j++){
    //                 cout<<"*";
    //             }

    //             // space right side
    //             for(int j = 0; j<i; j++){
    //                 cout<<" ";
    //             }
    //             cout<<endl;
    //         }

    // pattern:
    //     *
    //    ***
    //   *****
    //  *******
    // *********
    // *********
    //  *******
    //   *****
    //    ***
    //     *

    // 10)
    // int n = 5;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j <= i; j++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = n; j > i; j--)
    //     {
    //         cout << '*';
    //     }
    //     cout << endl;
    // }

    // pattern:
    // *
    // **
    // ***
    // ****
    // *****
    // *****
    // ****
    // ***
    // **
    // *

    // 11)
    // int n = 6;
    // int start = 1;
    // for (int i = 0; i < 5; i++)
    // {
    //     if (i % 2 == 0)
    //     {
    //         start = 1;
    //     }
    //     else
    //     {
    //         start = 0;
    //     }

    //     for (int j = 0; j <= i; j++)
    //     {
    //         cout << start << " ";
    //         start = 1 - start;
    //     }
    //     cout << endl;
    // }

    // pattern:
    // 1
    // 0 1
    // 1 0 1
    // 0 1 0 1
    // 1 0 1 0 1

    // 12)
    // int n = 5;
    // int space = 2 * (n - 1);

    // for (int i = 0; i < n; i++)
    // {
    //     // numbers 1
    //     for (int j = 0; j <= i; j++)
    //     {
    //         cout << j + 1;
    //     }

    //     // space
    //     for (int j = 0; j < space; j++)
    //     {
    //         cout << " ";
    //     }

    //     // numbers 2
    //     for (int j = i; j >= 0; j--)
    //     {
    //         cout << j + 1;
    //     }

    //     cout << endl;
    //     space -= 2;
    // }

    // pattern:
    // 1        1
    // 12      21
    // 123    321
    // 1234  4321
    // 1234554321

    // 13)
    // int n = 5;
    // int k = 1;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j <= i; j++)
    //     {
    //         cout << k++ << " ";
    //     }
    //     cout << endl;
    // }

    // pattern:
    // 1
    // 2 3
    // 4 5 6
    // 7 8 9 10
    // 11 12 13 14 15

    // 14)

    // int n = 5;
    // for (int i = 0; i < n; i++)
    // {
    //     char ch = 'A';
    //     for (int j = 0; j <= i; j++)
    //     {
    //         cout << ch << " ";
    //         ch++;
    //     }
    //     cout << endl;
    // }

    // pattern:
    // A
    // A B
    // A B C
    // A B C D
    // A B C D E

    // 15)
    // int n = 5;
    // for (int i = 0; i < n; i++)
    // {
    //     char ch = 'A';
    //     for (int j = 1; j <= n - i; j++)
    //     {
    //         cout << ch << " ";
    //         ch++;
    //     }
    //     cout << endl;
    // }

    // pattern:
    // A B C D E
    // A B C D
    // A B C
    // A B
    // A

    // 16)
    // int n = 5;
    // char ch = 'A';

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j <= i; j++)
    //     {
    //         cout << ch << " ";
    //     }
    //     cout << endl;
    //     ch++;
    // }

    // pattern:
    // A
    // B B
    // C C C
    // D D D D
    // E E E E E

    // 17)
 
    return 0;
}