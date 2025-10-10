// #include <iostream>
// using namespace std;

// int main() {
//     int n;

//     cout << "\nEnter n: ";
//     cin >> n;

//     // --------------(Upper Triangle)--------------
//     cout << "\nPattern: " << endl;
//     for (int i = 0; i < (n/2)+1; i++) {
//         for (int j = 0; j < (n/2)-i; j++) {
//             cout << " ";
//         }
//         for (int k = 0; k < (2*i)+1; k++) {
//             cout << "*";
//         }
//         cout << endl;
//     }

//     //----------------(Lower Triangle)--------------
//     for (int i = 0; i < (n/2); i++) {
//         for (int j = 0; j < (2*i)+1-i; j++) {
//             cout << " ";
//         }

//         for (int k = 0; k <= (n/2)-i; k++) {
//             cout << "*";
//         }
//         cout << endl;
//     }
//     return 0;
// }