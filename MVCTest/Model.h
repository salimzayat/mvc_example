//
//  Model.h
//  MVCTest
//
//  Created by Salim Zayat on 12/10/18.
//  Copyright © 2018 Salim Zayat. All rights reserved.
//

#ifndef Model_h
#define Model_h

#include "Events.h"
#include "ModelEvents.h"
#include "Defines.h"
#include <string>
#include <vector>

// usefufl helper function to split a string by a given delimiter and add them to the given container
template <class Container>
void Split(std::string input, char delimiter, Container& result)
{
    std::size_t current, previous = 0;
    current = input.find(delimiter);
    while (current != std::string::npos)
    {
        result.push_back(input.substr(previous, current - previous));
        previous = current + 1;
        current = input.find(delimiter, previous);
    }
    result.push_back(input.substr(previous, current - previous));
}

class Date
{
    // encapsulation of a date string
public:
    Date(Month month, int day, int year)
    : m_month(month)
    , m_day(day)
    , m_year(year)
    {
        //
    }
    
    Date()
    : Date(Month::INVALID, 1, 1900)
    {
        
    }
    // getters
    const Month GetMonth() { return m_month; }
    const int GetDay() { return m_day; }
    const int GetYear() { return m_year; }
    // return a YYYY-MM-DD representation of this date as a string
    std::string AsString()
    {
        char buff[10];
        sprintf(buff, "%04d-%02d-%02d", m_year, m_month, m_day);
        return std::string(buff);
    }
    
    // validation check that the days for this month are within the allowable number of days for that month
    bool IsValid()
    {
        if (m_month == Month::INVALID)
        {
            return false;
        }
        // we need mapping of allowed days per month
        int targetDays = k_validDaysPerMonth.at(m_month);
        if ((m_month == Month::FEBRUARY) && (IsLeapYear(m_year)))
        {
            // determine if it is a leap year
            // otherwise, just make sure it is the standard number of days
            targetDays += 1;
        }
        return (m_day <= targetDays);
    }
    
private:
    Month m_month;
    int m_day;
    int m_year;
};

class UserModel : public EventDispatcher
{
    // the fundamental model of the user
    // first name, last name, birth date
public:
    // getters
    const std::string GetFirstName() { return m_firstName; }
    const std::string GetLastName() { return m_firstName; }
    const Date GetBirthDate() { return m_birthDate; }
    // setters
    void SetFirstName(std::string name) { m_firstName = name; }
    void SetLastName(std::string name) { m_lastName = name; }
    // set the birth date from the string
    void SetBirthDate(std::string birthDate)
    {
        // split the input by the '/' delimiter
        std::vector<std::string> result;
        Split(birthDate, '/', result);
        if (result.size() != 3)
        {
            // invalid
            m_birthDate = {};
        }
        else
        {
            // make sure they are valid ints
            int month = std::atoi(result[0].c_str());
            int day = std::atoi(result[1].c_str());
            int year = std::atoi(result[2].c_str());
            
            // validate the month
            if ((month >= Month::JANUARY) && (month <= Month::DECEMBER))
            {
                m_birthDate = { (Month)month, day, year };
            }
            else
            {
                m_birthDate = {};
            }
        }
    }
    
    void Validate()
    {
        // we can also validate the name lengths
        if (m_firstName.size() == 0)
        {
            Dispatch(new UserDataInvalidEvent(EventType::USER_DATA_FIRST_NAME_INVALID, "cannot have zero-length first name"));
        }
        if (m_lastName.size() == 0)
        {
            Dispatch(new UserDataInvalidEvent(EventType::USER_DATA_LAST_NAME_INVALID, "cannot have zero-length last name"));
        }
        // and the birth date
        if (!m_birthDate.IsValid())
        {
            Dispatch(new UserDataInvalidEvent(EventType::USER_DATA_BIRTH_DATE_INVALID, "invalid birth date"));
        }
        // ok it is valid
        // if we had a db connection, this would be the place to persist the data
        Dispatch(new Event(EventType::USER_DATA_VALID));
    }
    
private:
    std::string m_firstName;
    std::string m_lastName;
    Date m_birthDate;
};

#endif /* Model_h */
