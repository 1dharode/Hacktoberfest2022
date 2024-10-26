// C++
#include <iostream>
#include <string>
using namespace std;

int isRotatedBy2Places(string a, string b) {
    // Check if both strings are of the same length
    if (a.length() != b.length())
        return 0;

    // Perform anti-clockwise rotation by 2
    string antiClockwiseRotation = a.substr(2) + a.substr(0, 2);

    // Perform clockwise rotation by 2
    string clockwiseRotation = a.substr(a.length() - 2) + a.substr(0, a.length() - 2);

    // Check if b matches either rotation
    if (b == antiClockwiseRotation || b == clockwiseRotation)
        return 1;
    else
        return 0;
}

int main() {
    string a = "amazon";
    string b = "azonam";
    cout << isRotatedBy2Places(a, b) << endl;  
    return 0;
}



