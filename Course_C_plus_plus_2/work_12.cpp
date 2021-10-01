#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>

#include <phone_number.h>
/*
#pragma once

#include <string>

using namespace std;

/*
class PhoneNumber {
public:
     Принимает строку в формате +XXX-YYY-ZZZZZZ
       Часть от '+' до первого '-' - это код страны.
       Часть между первым и вторым символами '-' - код города
       Всё, что идёт после второго символа '-' - местный номер.
       Код страны, код города и местный номер не должны быть пустыми.
       Если строка не соответствует этому формату, нужно выбросить исключение invalid_argument. Проверять, что номер содержит только цифры, не нужно.

       Примеры:
       * +7-495-111-22-33
       * +7-495-1112233
       * +323-22-460002
       * +1-2-coursera-cpp
       * 1-2-333 - некорректный номер - не начинается на '+'
       * +7-1233 - некорректный номер - есть только код страны и города
    
    explicit PhoneNumber(const string& international_number);

    string GetCountryCode() const;
    string GetCityCode() const;
    string GetLocalNumber() const;
    string GetInternationalNumber() const;

private:
    string country_code_;
    string city_code_;
    string local_number_;
};*/
using namespace std;


PhoneNumber::PhoneNumber(const string& international_number) {
    int i1 = international_number.find('+'), 
        i2 = international_number.find('-'), 
        i3 = international_number.find('-', international_number.find('-') + 1);
    if (i1 == 0 && i2 > 1 && i3 > 0 && i3 != (int)international_number.size() - 1) {
            for (size_t i = 1; i < (size_t)i2; i++) {
                country_code_ += international_number.at(i);
            }
            for (size_t i = i2 + 1; i < (size_t)i3; i++) {
                city_code_ += international_number.at(i);
            }
            for (size_t i = i3 + 1; i < international_number.size(); i++){
                local_number_ += international_number.at(i);
            }          
    }
    else {
        throw invalid_argument(""); 
    }
}
string PhoneNumber::GetCountryCode() const{
    return PhoneNumber::country_code_;
}

string PhoneNumber::GetCityCode() const {
    return PhoneNumber::city_code_;
}

string PhoneNumber::GetLocalNumber() const {
    return PhoneNumber::local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
    return '+' + PhoneNumber::country_code_ + '-' + PhoneNumber::city_code_ + '-' + PhoneNumber::local_number_;
}