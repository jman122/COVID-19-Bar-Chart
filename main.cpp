// Author: Jia Yu Man (251045227)
// Date: October 4, 2020
// This is the main where the user is able to prompt for a certain statistical count
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "countryRecord.h"

using namespace std;

bool sortNewCasesAsc (countryRecord i,countryRecord j) { return (i.getNewCases() < j.getNewCases()); }      //ascending and descending sort functions for the six different statistical counts
bool sortNewCasesDes (countryRecord i,countryRecord j) { return (i.getNewCases() > j.getNewCases()); }

bool sortNewDeathsAsc (countryRecord i,countryRecord j) { return (i.getNewDeaths() < j.getNewDeaths()); }
bool sortNewDeathsDes (countryRecord i,countryRecord j) { return (i.getNewDeaths() > j.getNewDeaths()); }

bool sortNewRecAsc (countryRecord i,countryRecord j) { return (i.getNewRecoveries() < j.getNewRecoveries()); }
bool sortNewRecDes (countryRecord i,countryRecord j) { return (i.getNewRecoveries() > j.getNewRecoveries()); }

bool sortTotCasesAsc (countryRecord i,countryRecord j) { return (i.getTotalCases() < j.getTotalCases()); }
bool sortTotCasesDes (countryRecord i,countryRecord j) { return (i.getTotalCases() > j.getTotalCases()); }

bool sortTotDeathsAsc (countryRecord i,countryRecord j) { return (i.getTotalDeaths() < j.getTotalDeaths()); }
bool sortTotDeathsDes (countryRecord i,countryRecord j) { return (i.getTotalDeaths() > j.getTotalDeaths()); }

bool sortTotRecAsc (countryRecord i,countryRecord j) { return (i.getTotalRecoveries() < j.getTotalRecoveries()); }
bool sortTotRecDes (countryRecord i,countryRecord j) { return (i.getTotalRecoveries() > j.getTotalRecoveries()); }

int main() {

    vector<countryRecord> records;                                      //countryRecord vector that stores all the information
    string line;
    ifstream file("/Users/jman/CLionProjects/test2/summary.csv");
    if (file.is_open()) {
        getline(file, line);
        while (getline(file, line)) {
            records.push_back(countryRecord(line));                     //parse the information from summary csv file
        }
        file.close();
    } else {
        cout << "Unable to open file";
        exit(0);
    }

    string input1, input2, caseString;
    int scale;
    bool userPrint;

    do {                                                                //do while loop that continues to prompt the user until the user exits
        userPrint = false;
        cout << "\n";
        cout << "Enter the statistical count you wish to display or exit: ";
        getline(cin, input1);

        if (input1 == "new confirmed" || input1 == "New Confirmed" || input1 == "newconfirmed" ||   //if the user wants new confirmed cases
            input1 == "NewConfirmed") {

            userPrint = true;
            caseString = "New Confirmed Cases";
            cout << "Sort in ascending or descending: ";            //prompts user for either ascending or descending
            getline(cin, input2);

            if (input2 == "ascending" || input2 == "Ascending") {
                for (int i = 0; i < records.size(); i++) {
                    sort(records.begin(), records.end(), sortNewCasesAsc);  //sort the new cases in the countryRecords vector
                }

                scale = records[0].getNewCases() / 70 + 1;          //scale for determining how much each # should represent

                for (int i = 0; i < 10; i++) {                      //printing out the bar graph for new confirmed cases in ascending
                    cout << records[i].getCode() << " | ";
                    for (int j = 0; j < (records[i].getNewCases() / scale); j++) {
                        cout << "#";
                    }
                    cout << "\n";
                }
            } else {
                for (int i = 0; i < records.size(); i++) {                      //sort the new cases in descending
                    sort(records.begin(), records.end(), sortNewCasesDes);
                }

                scale = records[0].getNewCases() / 70 + 1;          //scale for determining how much each # should represent

                for (int i = 0; i < 10; i++) {                      //printing out the bar graph for new confirmed cases in descending
                    cout << records[i].getCode() << " | ";
                    for (int j = 0; j < (records[i].getNewCases() / scale); j++) {
                        cout << "#";
                    }
                    cout << "\n";
                }
            }
        }

        if (input1 == "new deaths" || input1 == "New Deaths" || input1 == "newdeaths" || input1 == "NewDeaths") {     //if the user wants new deaths

            userPrint = true;
            caseString = "New Deaths";
            cout << "Sort in ascending or descending: ";
            getline(cin, input2);

            if (input2 == "ascending" || input2 == "Ascending") {
                for (int i = 0; i < records.size(); i++) {
                    sort(records.begin(), records.end(), sortNewDeathsAsc);
                }

                scale = records[0].getNewDeaths() / 70 + 1;

                for (int i = 0; i < 10; i++) {
                    cout << records[i].getCode() << " | ";
                    for (int j = 0; j < (records[i].getNewDeaths() / scale); j++) {
                        cout << "#";
                    }
                    cout << "\n";
                }
            } else {
                for (int i = 0; i < records.size(); i++) {
                    sort(records.begin(), records.end(), sortNewDeathsDes);
                }

                scale = records[0].getNewDeaths() / 70 + 1;

                for (int i = 0; i < 10; i++) {
                    cout << records[i].getCode() << " | ";
                    for (int j = 0; j < (records[i].getNewDeaths() / scale); j++) {
                        cout << "#";
                    }
                    cout << "\n";
                }
            }
        }

        if (input1 == "new recovered" || input1 == "New Recovered" || input1 == "newrecovered" || input1 == "NewRecovered") {       //if the user wants new recovered cases

            userPrint = true;
            caseString = "New Recovered Cases";
            cout << "Sort in ascending or descending: ";
            getline(cin, input2);

            if (input2 == "ascending" || input2 == "Ascending") {
                for (int i = 0; i < records.size(); i++) {
                    sort(records.begin(), records.end(), sortNewRecAsc);
                }

                scale = records[0].getNewRecoveries() / 70 + 1;

                for (int i = 0; i < 10; i++) {
                    cout << records[i].getCode() << " | ";
                    for (int j = 0; j < (records[i].getNewRecoveries() / scale); j++) {
                        cout << "#";
                    }
                    cout << "\n";
                }
            } else {
                for (int i = 0; i < records.size(); i++) {
                    sort(records.begin(), records.end(), sortNewRecDes);
                }

                scale = records[0].getNewRecoveries() / 70 + 1;

                for (int i = 0; i < 10; i++) {
                    cout << records[i].getCode() << " | ";
                    for (int j = 0; j < (records[i].getNewRecoveries() / scale); j++) {
                        cout << "#";
                    }
                    cout << "\n";
                }
            }
        }

        if (input1 == "total confirmed" || input1 == "Total Confirmed" || input1 == "totalconfirmed" || input1 == "TotalConfirmed") {       //if the user wants total confirmed cases

            userPrint = true;
            caseString = "Total Confirmed Cases";
            cout << "Sort in ascending or descending: ";
            getline(cin, input2);

            if (input2 == "ascending" || input2 == "Ascending") {
                for (int i = 0; i < records.size(); i++) {
                    sort(records.begin(), records.end(), sortTotCasesAsc);
                }

                scale = records[0].getTotalCases() / 70 + 1;

                for (int i = 0; i < 10; i++) {
                    cout << records[i].getCode() << " | ";
                    for (int j = 0; j < (records[i].getTotalCases() / scale); j++) {
                        cout << "#";
                    }
                    cout << "\n";
                }
            } else {
                for (int i = 0; i < records.size(); i++) {
                    sort(records.begin(), records.end(), sortTotCasesDes);
                }

                scale = records[0].getTotalCases() / 70 + 1;

                for (int i = 0; i < 10; i++) {
                    cout << records[i].getCode() << " | ";
                    for (int j = 0; j < (records[i].getTotalCases() / scale); j++) {
                        cout << "#";
                    }
                    cout << "\n";
                }
            }
        }

        if (input1 == "total deaths" || input1 == "Total Deaths" || input1 == "totaldeaths" || input1 == "TotalDeaths") {       //if the user wants total deaths

            userPrint = true;
            caseString = "Total Deaths";
            cout << "Sort in ascending or descending: ";
            getline(cin, input2);

            if (input2 == "ascending" || input2 == "Ascending") {
                for (int i = 0; i < records.size(); i++) {
                    sort(records.begin(), records.end(), sortTotDeathsAsc);
                }

                scale = records[0].getTotalDeaths() / 70 + 1;

                for (int i = 0; i < 10; i++) {
                    cout << records[i].getCode() << " | ";
                    for (int j = 0; j < (records[i].getTotalDeaths() / scale); j++) {
                        cout << "#";
                    }
                    cout << "\n";
                }
            } else {
                for (int i = 0; i < records.size(); i++) {
                    sort(records.begin(), records.end(), sortTotDeathsDes);
                }

                scale = records[0].getTotalDeaths() / 70 + 1;

                for (int i = 0; i < 10; i++) {
                    cout << records[i].getCode() << " | ";
                    for (int j = 0; j < (records[i].getTotalDeaths() / scale); j++) {
                        cout << "#";
                    }
                    cout << "\n";
                }
            }
        }

        if (input1 == "total recovered" || input1 == "Total Recovered" || input1 == "totalrecovered" || input1 == "TotalRecovered") {       //if the user wants total recovered cases

            userPrint = true;
            caseString = "Total Recovered Cases";
            cout << "Sort in ascending or descending: ";
            getline(cin, input2);

            if (input2 == "ascending" || input2 == "Ascending") {
                for (int i = 0; i < records.size(); i++) {
                    sort(records.begin(), records.end(), sortTotRecAsc);
                }

                scale = records[0].getTotalRecoveries() / 70 + 1;

                for (int i = 0; i < 10; i++) {
                    cout << records[i].getCode() << " | ";
                    for (int j = 0; j < (records[i].getTotalRecoveries() / scale); j++) {
                        cout << "#";
                    }
                    cout << "\n";
                }
            } else {
                for (int i = 0; i < records.size(); i++) {
                    sort(records.begin(), records.end(), sortTotRecDes);
                }

                scale = records[0].getTotalRecoveries() / 70 + 1;

                for (int i = 0; i < 10; i++) {
                    cout << records[i].getCode() << " | ";
                    for (int j = 0; j < (records[i].getTotalRecoveries() / scale); j++) {
                        cout << "#";
                    }
                    cout << "\n";
                }
            }
        }

        if (input1 == "exit"){
            exit(0);
        }

        if (userPrint) {
            cout << "----------------------------------------------------------------------";   //ending print lines
            cout << "\n";
            cout << caseString << ";";                              //prints the statistical count the user has chosen
            cout << " Each # is approx. " << scale << " cases";     //prints the scale relating to the statistical count
            cout << "\n";
        }

    } while (input1 != "new confirmed" || input1 != "New Confirmed" || input1 != "newconfirmed" ||input1 != "NewConfirmed"
             || input1 != "new deaths" || input1 != "New Deaths" || input1 != "newdeaths" || input1 != "NewDeaths"
             || input1 != "new recovered" || input1 != "New Recovered" || input1 != "newrecovered" ||input1 != "NewRecovered"
             || input1 != "total confirmed" || input1 != "Total Confirmed" || input1 != "totalconfirmed" || input1 != "TotalConfirmed"
             || input1 != "total deaths" || input1 != "Total Deaths" || input1 != "totaldeaths" || input1 != "TotalDeaths"
             || input1 != "total recovered" || input1 != "Total Recovered" || input1 != "totalrecovered" || input1 != "TotalRecovered"); //condition for the do while loop

}
