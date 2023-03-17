#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{

    for(int numTest = 1; numTest <= 1000; ++numTest)
    {
        // Chay chuong trinh
        system("Gen_Input.exe");
        system("bruteforces.exe");
        system("code.exe");

        //Kiem tra
        // fc

        if(system("fc SUBSEQ.ANS SUBSEQ.OUT") == 0)
            cout << "Accepted\n";
        else {
            cout << "Wrong Answer\n";
            break;
        }
    }
}


