#include <iostream>
#include "../include/Time.h"
using namespace std;

// Overload the + operator
Time Time::operator+(const Time &other) const
{   
    int totalMinutes = minutes + other.minutes;
    int newMinutes = totalMinutes % 60;
    int extraHours = totalMinutes / 60;
    int newHours = hours + other.hours + extraHours;
    return Time(newHours, newMinutes);
}

// Overload the += operator
Time& Time::operator+=(const Time &other)
{   
    *this = *this + other;
    return *this;
}

// Overload the < operator
bool Time::operator<(const Time &other) const
{
    return (hours * 60 + minutes) < (other.hours * 60 + other.minutes);
}

// Overload the > operator
bool Time::operator>(const Time &other) const
{
    return (hours * 60 + minutes) > (other.hours * 60 + other.minutes);
}

// Overload the == operator
bool Time::operator==(const Time &other) const
{
    return (hours == other.hours && minutes == other.minutes);
}

// Overload the friend function operator<<
ostream &operator<<(ostream &os, const Time &tm)
{
    os << tm.hours << "h " << tm.minutes << "m";
    return os;
}
