// Author: Jia Yu Man (251045227)
// Date: October 4, 2020
// This is the constructor class that contains countryRecord along with its setter and getter methods
// this is where the information gets parsed
#include <iostream>
#include <string>
#include <sstream>
#include "countryRecord.h"

using namespace std;

countryRecord::countryRecord(string newCountryInfo){

    stringstream countryString(newCountryInfo);
    getline(countryString, otherInfo, '"');
    getline(countryString, countryName, '"');       //country name
    getline(countryString, otherInfo, ',');
    getline(countryString, countryCode, ',');       //country code
    getline(countryString, otherInfo, ',');
    getline(countryString, temp, ',');                 //new cases
    newCases = stoi(temp);
    getline(countryString, temp, ',');                 //new deaths
    newDeaths = stoi(temp);
    getline(countryString, temp, ',');                 //new recoveries
    newRecoveries = stoi (temp);
    getline(countryString, otherInfo, ',');
    getline(countryString, otherInfo, ',');
    getline(countryString, temp, ',');                 //total cases
    totCases = stoi (temp);
    getline(countryString, temp, ',');                 //total deaths
    totDeaths = stoi (temp);
    getline(countryString, temp, ',');                 //total recoveries
    totRecoveries = stoi (temp);

}

void countryRecord::setCountry(string country){         //setters and getters
    countryName = country;
}

string countryRecord::getCountry(){
    return countryName;
}

void countryRecord::setCode(string code){
    countryCode = code;
}

string countryRecord::getCode(){
    return countryCode;
}

void countryRecord::setNewCases(int nCase){
    newCases = nCase;
}

int countryRecord::getNewCases(){
    return newCases;
}

void countryRecord::setNewDeaths(int nDeath){
    newDeaths = nDeath;
}

int countryRecord::getNewDeaths(){
    return newDeaths;
}

void countryRecord::setNewRecoveries(int nRecoveries){
    newRecoveries = nRecoveries;
}

int countryRecord::getNewRecoveries(){
    return newRecoveries;
}

void countryRecord::setTotalCases(int tCase){
    totCases = tCase;
}

int countryRecord::getTotalCases(){
    return totCases;
}

void countryRecord::setTotalDeaths(int tDeath){
    totDeaths = tDeath;
}

int countryRecord::getTotalDeaths(){
    return totDeaths;
}

void countryRecord::setTotalRecoveries(int tRecoveries){
    totRecoveries = tRecoveries;
}

int countryRecord::getTotalRecoveries(){
    return totRecoveries;
}

countryRecord::~countryRecord(){};      //destructor
