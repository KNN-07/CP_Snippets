#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

long long mul(long long a, long long b, long long mod)
{
    if(b == 0) return 0;
    if(b == 1) return a;
    long long x = mul(a, b/2, mod);
    return (x + x + mul(a, b % 2, mod)) % mod;
}

long long Rand(long long l, long long h) {
    assert(l <= h);
    long long x = (long long)rand() * rand() + rand();
    long long y = (long long)rand() * rand() + rand();
    long long z = (long long)rand() * rand() + rand();
    long long t = (mul(x, y, h - l + 1) + z) % (h - l + 1) + l;
    return t;
}
bool bit01() { // tra ve 0 hoac 1
    return Rand(1, 1e5)%2;
}
char az() { // tra ve ki tu ngau nhien tong ['a' .. 'z']
    return (char)(Rand('a', 'z'));
}
char AZ() { // tra ve ki tu ngau nhien tong ['A' .. 'Z']
    return (char)(Rand('A', 'Z'));
}
char num() { // tra ve ['0' .. '9']
    return '0' + Rand(0, 9);
}
void ShuffleArray(vector<int> &arr, int n) {
    int minPosition;
    int maxPosition = n - 1;
    int swapPosition;
    int i = 0;
    while (i < n - 1) {
        minPosition = i + 1;
        swapPosition = Rand(1, 1e7) % (maxPosition - minPosition + 1) + minPosition;
        swap(arr[i], arr[swapPosition]);
        ++i;
    }
}

string str(long long a)
{
    if(a == 0) return "0";
    if(a < 0) return "-" + str(-a);
    string ans = "";
    while(a > 0)
    {
        ans = "0" + ans;
        ans[0] = (a % 10) + '0';
        a /= 10;
    }
    return ans;
}

void cop(long long i)
{
    ifstream inp("output.txt");
    string w, s;
    while(getline(inp, s))
    {
        w += s + '\n';
    }
    ofstream out("testcases\\output." + str(i));
    out << w;
    inp.close();
    out.close();
}

void cop2(long long i)
{
    ifstream inp("testcases\\input." + str(i));
    string w, s;
    while(getline(inp, s))
    {
        w += s + '\n';
    }
    ofstream out("input.txt");
    out << w;
    inp.close();
    out.close();
}

map<long long, bool>tests;

void buildtest(long long i)
{
    ofstream inp("testcases\\input." + str(i)); // phai tao truoc thu muc testcases
    cerr << "testcases\\input." + str(i) << endl;
	/* code sinh test o day, output bang inp << thay vi cout << */

	/* ^^^^^^ */
	inp.close();
	cop2(i);
	system("solution.exe"); // file loi giai solution.cpp
	cop(i);
}

int main()
{
    srand(time(NULL));
	system("g++ -g solution.cpp -o solution.exe");
    for(int i = 1; i <= 100; i ++)
    {
        buildtest(i);
    }
}
