
#include <iostream>
#include "bst.cpp"
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <iomanip>

using namespace std;


BST<string,int>* create_bst() {
    // Read the txt file and build the BST
    BST<string,int>* bst= new BST<string,int>;
    ifstream file("binhex.txt");
    string bin, hex;

    while (file >> bin >> hex) {
        bst->insert(bin, hex[0]);
    }
    return bst;
}


string convert(BST<string,int>* bst) {
    // Prompt the user for a binary value and convert it to hex
    string binary;
    cout << "Enter binary representation for conversion:" << endl;
    cin >> binary;

    string hex_result = "";
    for (int i = 0; i < binary.length(); i += 4) {
        string sub_bin = binary.substr(i, 4);
        int isub=stoi(sub_bin);
        string hex_str = bst->get(isub);
        hex_result += hex_str;
    }

    // Display the result
    cout << "Hexadecimal representation of " << binary << " is 0x" << hex << hex_result << endl;

    return binary;
}