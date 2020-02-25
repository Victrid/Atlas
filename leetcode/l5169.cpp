#include "lc.hpp"
class Solution {
public:
    struct Date {
        int year;
        int month;
        int day;
        Date(string a) {
            year  = stoi(a.substr(0, 4));
            month = stoi(a.substr(5, 2));
            day   = stoi(a.substr(8, 2));
        }
        Date() {}
    };
    int days(Date a, Date b) {
        int day1 = 0;
        Date temp;
        int monthdays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if ((a.year < b.year) || ((a.year == b.year) && (a.month < b.month)) || ((a.year == b.year) && (a.month == b.month) && (a.day < b.day))) {
            temp = a;
            a    = b;
            b    = temp;
        }
        if (a.year != b.year) {
            day1 += (a.year - b.year - 1) * 365;
            day1 += ((((a.year - 1) / 4) - ((a.year - 1) / 100) + ((a.year - 1) / 400)) - (((b.year - 1) / 4) - ((b.year - 1) / 100) + ((b.year - 1) / 400)));

            for (int i = b.month; i <= 12; i++) {
                day1 += monthdays[i - 1];
            }
            day1 -= b.day;
            for (int i = a.month - 1; i >= 1; i--) {
                day1 += monthdays[i - 1];
            }
            day1 += a.day;
            if (((b.year % 4 == 0 && b.year % 100 != 0) || (b.year % 400 == 0)) && (b.month > 2))
                day1 -= 1;
            if (((a.year % 4 == 0 && a.year % 100 != 0) || (a.year % 400 == 0)) && (a.month > 2))
                day1 += 1;
        } else {
            for (int i = b.month; i < a.month; i++) {
                day1 += monthdays[i - 1];
            }
            day1 += a.day;
            day1 -= b.day;
            if (b.month == 2 && b.day == 29)
                day1++;
            if (((a.year % 4 == 0 && a.year % 100 != 0) || (a.year % 400 == 0)) && (b.month <= 2 && b.day != 29 && a.month > 2)) {
                day1++;
            }
        }
        return day1;
    }
    int daysBetweenDates(string date1, string date2) {
        Date d1(date1);
        Date d2(date2);
        return days(d1,d2);
    }
};
int main(){
    string a = "1972-02-10";
    string b = "2020-11-07";
    Solution Sol;
    cout << Sol.daysBetweenDates(a,b);
    return 0;
}
