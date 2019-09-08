#include <iostream>
#include<map>
using namespace std;
void numbers_to_100 (int num , map <int, string> &name) {
    int digit;
    if (num < 14) {
        cout<< name[num]<< ' ';
    } else if (num >= 14 and num < 100) {
        digit = num % 10;
        if (digit != 0) {
            cout << name[num - digit] << '-' << name[digit] << ' ';
        }
        else
            cout << name[num - digit] << ' ' << name[digit] << ' ';
    }
    else if (num >= 100 and num < 1000) {
        cout << name[num / 100] << ' ' << name[100] << ' ';
        numbers_to_100(num % 100, name);
    }
    else if (num >= 1000 and num < 1e6) {
        numbers_to_100(num / 1000, name);
        cout << name[1e3] << ' ';
        numbers_to_100(num % 1000, name);
    }
    else if (num >= 1e6 and num < 1e9) {
        numbers_to_100(num / int(1e6), name);
        cout << name[1e6] << ' ';
        numbers_to_100(num % int(1e6),name);
    }
    else if (num >= 1e9 and num <= 2*1e9) {
        numbers_to_100(num / int(1e9), name);
        cout << name[1e9] << ' ';
        numbers_to_100(num % int(1e9), name);
    }
}
int main() {
    int sum, digit, billions, millions,thousands, hundreds, cents;
    double num;
    bool is_one = false;
    map <int, string> name = {
        {1, "one"}, {2, "two"}, {3, "three"},
        {4, "four"}, {5, "five"}, {6, "six"},
        {7, "seven"}, {8, "eight"}, {9, "nine"},
        {10, "ten"}, {11, "eleven"}, {12, "twelve"},
        {13, "thirteen"},{20, "twenty"},{30, "thirty"},
        {40, "forty"}, {50, "fifty"}, {60, "sixty"},
        {70, "seventy"}, {80, "eighty"}, {90, "ninety"},
        {100, "hundred"}, {1e3, "thousand"}, {1e6, "million"}, {1e9, "billion"}};
    cout << "Enter you number : ";
    cin >> num;
    sum = num;
    cents = (num - sum)* 100 + 0.5;
    if (num > 0)
        cout << "Result : \n";
    if (sum == 1) {
        cout << "one dollar ";
    }
    else if (sum > 1) {
        numbers_to_100(sum, name);
        cout << "dollars ";
    }
    if (cents > 1) {
        numbers_to_100(cents, name);
        cout << "cents";
    }
    else if (cents == 1) {
        cout << "one cent";
    }
    cout<<'\n';
    system("pause");
    return 0;
}
