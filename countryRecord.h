// Author: Jia Yu Man (251045227)
// Date: October 4, 2020
// This is the header file for the countryRecord class
#include <iostream>
#include <string>

using namespace std;

class countryRecord{

private:
    string countryName, countryCode, otherInfo, temp;
    int newCases, newDeaths, newRecoveries, totCases, totDeaths, totRecoveries;

public:

    countryRecord(string newCountryInfo);   //constructor

    void setCountry(string country);        //getters and setters
    string getCountry();

    void setCode(string code);
    string getCode();

    void setNewCases(int nCase);
    int getNewCases();

    void setNewDeaths(int nDeath);
    int getNewDeaths();

    void setNewRecoveries(int nRecoveries);
    int getNewRecoveries();

    void setTotalCases(int tCase);
    int getTotalCases();

    void setTotalDeaths(int tDeath);
    int getTotalDeaths();

    void setTotalRecoveries(int tRecoveries);
    int getTotalRecoveries();

    ~countryRecord();       //destructor

};
