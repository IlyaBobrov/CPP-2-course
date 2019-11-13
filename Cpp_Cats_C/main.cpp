#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <functional>
#include <set>
#include <queue>
#include <string>
#include <map>
#include <iomanip>
#include <sstream>
#include <cassert>

//#include <string>
int get_month(int month, int year) {
    switch (month) {
        case 1:
            return 31;
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                return 29;
            else
                return 28;
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
        default:
            return 0;
    }
}
class Date {
public:
    Date(int year, int month, int day) {
        this->year = year;
        this->month = month;
        this->day = day;
    }

    bool IsLeap() const {
        return ((this->year % 4 == 0 &&
                 this->year % 100 != 0) ||
                (this->year % 400 == 0));
    }

    std::string ToString() const {
        std::string ziro_month = ".", ziro_year = ".";
        if (this->month < 10) ziro_month = ".0";
        if (this->year < 1000) ziro_year = ".0";
        if (this->year < 100) ziro_year = ".00";
        if (this->year < 10) ziro_year = ".000";

        if (this->day < 10)
            return "0"+ std::to_string(this->day) + ziro_month +
                   std::to_string(this->month) + ziro_year +
                   std::to_string(this->year);
        else
            return std::to_string(this->day) + ziro_month +
                   std::to_string(this->month) + ziro_year +
                   std::to_string(this->year);
    }

    Date DaysLater(int days) const {
        int sum_day = this->day + days;
        int new_year = this->year;
        int new_month = this->month;
        int temp_mouth = get_month(new_month, new_year);
        while (sum_day > temp_mouth) {
            sum_day -= temp_mouth;
            new_month++;
            if (new_month > 12) {
                new_month = 1;
                new_year++;
            }
            temp_mouth = get_month(new_month, new_year);
        }
        Date new_date(new_year, new_month, sum_day);
        return new_date;
    }

    int DaysLeft(const Date &date) const {
        if (this->day == date.day &&
            this->month == date.month &&
            this->year == date.year)
            return 0;
        bool THIS_MIN_DATE = true;
        if (this->year > date.year)
            THIS_MIN_DATE = false;
        else if (this->month > date.month)
            THIS_MIN_DATE = false;
        else if (this->day > date.day)
            THIS_MIN_DATE = false;
        int min_year, min_month, min_day;
        int max_year, max_month, max_day;
        if (THIS_MIN_DATE) {
            min_year = this->year;
            min_month = this->month;
            min_day = this->day;
            max_day = date.day;
            max_month = date.month;
            max_year = date.year;
        } else {
            min_year = date.year;
            min_month = date.month;
            min_day = date.day;
            max_day = this->day;
            max_month = this->month;
            max_year = this->year;
        }
        int count = 0;
        while (!(min_day == max_day &&
                 min_month == max_month &&
                 min_year == max_year)) {
            min_day++;
            if (min_day > get_month(min_month, min_year)) {
                min_day = 1;
                min_month++;
            }
            if (min_month > 12) {
                min_month = 1;
                min_year++;
            }
            count++;
        }
        return count;
    }

private:
    int year, month, day;
};


int main() {
    {
        Date dt(1997, 1, 19);
        assert(!dt.IsLeap());
        assert(dt.ToString() == "19.01.1997");
    }
    {
        Date dt(100, 10, 1);
        assert(!dt.IsLeap());

        assert(dt.ToString() == "01.10.0100");
    }
    {
        Date dt(1, 1, 1);
        assert(!dt.IsLeap());
        assert(dt.ToString() == "01.01.0001");
    }
    {
        Date dt(2000, 10, 22);
        assert(dt.IsLeap());
        assert(dt.ToString() == "22.10.2000");
    }
    {
        Date dt(400, 1, 9);
        assert(dt.IsLeap());
        assert(dt.ToString() == "09.01.0400");
    }
    {
        Date dt(1996, 7, 8);
        assert(dt.IsLeap());
        assert(dt.ToString() == "08.07.1996");
    }
    {
        Date dt(2000, 1, 1);
        assert(dt.DaysLater(0).ToString() == "01.01.2000");
        assert(dt.DaysLater(10).ToString() == "11.01.2000");
        assert(dt.DaysLater(30).ToString() == "31.01.2000");
        assert(dt.DaysLater(31).ToString() == "01.02.2000");
        assert(dt.DaysLater(60).ToString() == "01.03.2000");
        assert(dt.DaysLater(366).ToString() == "01.01.2001");
    }
    {
        Date dt(2001, 1, 1);
        assert(dt.DaysLater(0).ToString() == "01.01.2001");
        assert(dt.DaysLater(10).ToString() == "11.01.2001");
        assert(dt.DaysLater(30).ToString() == "31.01.2001");
        assert(dt.DaysLater(31).ToString() == "01.02.2001");
        assert(dt.DaysLater(59).ToString() == "01.03.2001");
        assert(dt.DaysLater(365).ToString() == "01.01.2002");
    }
    {
        Date dt(2000, 1, 1);
        assert(dt.DaysLeft(Date{2000, 1, 1}) == 0);
        assert(dt.DaysLeft(Date{2000, 1, 11}) == 10);
        assert(dt.DaysLeft(Date{2000, 1, 31}) == 30);
        assert(dt.DaysLeft(Date{2000, 2, 1}) == 31);
        assert(dt.DaysLeft(Date{2000, 3, 1}) == 60);
        assert(dt.DaysLeft(Date{2001, 1, 1}) == 366);
    }

    //Date dr(2000, 1, 1);
    //std::cout<<dr.DaysLeft(Date{2000, 1, 11}) <<std::endl;

    {
        Date dt(2001, 1, 1);
        assert(dt.DaysLeft(Date{2001, 1, 1}) == 0);
        assert(dt.DaysLeft(Date{2001, 1, 11}) == 10);
        assert(dt.DaysLeft(Date{2001, 1, 31}) == 30);
        assert(dt.DaysLeft(Date{2001, 2, 1}) == 31);
        assert(dt.DaysLeft(Date{2001, 3, 1}) == 59);
        assert(dt.DaysLeft(Date{2002, 1, 1}) == 365);
    }
    std::cout << 1;
}