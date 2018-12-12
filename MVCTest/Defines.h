//
//  Defines.h
//  MVCTest
//
//  Created by Salim Zayat on 12/11/18.
//  Copyright © 2018 Salim Zayat. All rights reserved.
//

#ifndef Defines_h
#define Defines_h

#include <map>
#include <string>

// a month enum
enum Month
{
    INVALID,
    JANUARY,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

// a mapping of month to the max number of days in that month (with the exclusion of FEBRUARY)
const std::map<Month, int> k_validDaysPerMonth =
{
    {Month::JANUARY, 31},
    {Month::FEBRUARY, 28},
    {Month::MARCH, 31},
    {Month::APRIL, 30},
    {Month::MAY, 31},
    {Month::JUNE, 30},
    {Month::JULY, 31},
    {Month::AUGUST, 31},
    {Month::SEPTEMBER, 30},
    {Month::OCTOBER, 31},
    {Month::NOVEMBER, 30},
    {Month::DECEMBER, 31}
};


// returns whether the year is a leap year or not
bool IsLeapYear(int year);

#endif /* Defines_h */
