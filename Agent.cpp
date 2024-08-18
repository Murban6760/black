#include "Agent.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

double strategy[52][10]{
    // 2 3 4 5 6 7 8 9 10 A
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, // Val 5
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, // Val 6
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, // Val 7
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, // Val 8
    1, 4, 4, 4, 4, 1, 1, 1, 1, 1, // Val 9
    4, 4, 4, 4, 4, 4, 4, 4, 1, 1, // Val 10
    4, 4, 4, 4, 4, 4, 4, 4, 4, 1, // Val 11
    1, 1, 2, 2, 2, 1, 1, 1, 1, 1, // Val 12
    2, 2, 2, 2, 2, 1, 1, 1, 1, 1, // Val 13
    2, 2, 2, 2, 2, 1, 1, 1, 1, 1, // Val 14
    2, 2, 2, 2, 2, 1, 1, 1, 1, 1, // Val 15
    2, 2, 2, 2, 2, 1, 1, 1, 1, 1, // Val 16
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, // 17
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, // 18
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, // 19
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, // 20
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, // 21
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, // Pairs-A
    1, 1, 1, 4, 4, 1, 1, 1, 1, 1, // A + 2
    1, 1, 1, 4, 4, 1, 1, 1, 1, 1, // A + 3
    1, 1, 4, 4, 4, 1, 1, 1, 1, 1, // A + 4
    1, 1, 4, 4, 4, 1, 1, 1, 1, 1, // A + 5
    1, 4, 4, 4, 4, 1, 1, 1, 1, 1, // A + 6
    2, 4, 4, 4, 4, 2, 2, 1, 1, 1, // A + 7
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, // A + 8
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, // A + 9
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, // A + 10
    3, 3, 3, 3, 3, 3, 1, 1, 1, 1, // Pairs of 2
    3, 3, 3, 3, 3, 3, 1, 1, 1, 1, // P-3
    1, 1, 1, 3, 3, 1, 1, 1, 1, 1, // P-4
    3, 3, 3, 3, 3, 3, 3, 3, 1, 1, // P-5
    3, 3, 3, 3, 3, 1, 1, 1, 1, 1, // P-6
    3, 3, 3, 3, 3, 3, 1, 1, 1, 1, // P-7
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, // P-8
    3, 3, 3, 3, 3, 2, 3, 3, 2, 2, // P-9
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, // P-10
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, // Val 6 >2 cards
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, // Val 7 > 2 cards
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, // Val 8 > 2 cards
    1, 4, 4, 4, 4, 1, 1, 1, 1, 1, // Val 9 > 2 cards
    4, 4, 4, 4, 4, 4, 4, 4, 1, 1, // Val 10 > 2 cards
    4, 4, 4, 4, 4, 4, 4, 4, 4, 1, // Val 11 > 2 cards
    1, 1, 2, 2, 2, 1, 1, 1, 1, 1, // Val 12 > 2 cards
    2, 2, 2, 2, 2, 1, 1, 1, 1, 1, // Val 13 > 2 cards
    2, 2, 2, 2, 2, 1, 1, 1, 1, 1, // Val 14 > 2 cards
    2, 2, 2, 2, 2, 1, 1, 1, 1, 1, // Val 15 > 2 cards
    2, 2, 2, 2, 2, 1, 1, 1, 1, 1, // Val 16  > 2 cards
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, // 17 > 2 cards
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, // 18 > 2 cards
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, // 19 > 2 cards
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, // 20 > 2 cards
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2  // 21 > 2 cards
};

Agent::Agent() : 
        value(0)
{}

void Agent::loadStrat()
{
        std::ifstream inFile("../BasePolicy.txt");
        if (!inFile)
        {
                std::cerr << "Error reading File" << std::endl;
                newStrat.resize(52);
                for (int i = 0; i < 52; i++)
                {
                        std::vector<StateInfo> stratRow(10);
                        for (int j = 0; j < 10; j++)
                        {
                                StateInfo stateInfo;
                                stateInfo.name = j + 2;
                                stateInfo.numActions = 4;
                                stateInfo.numVisits = 0;
                                stateInfo.cardAction = strategy[i][j];
                                stateInfo.stateAction = 0;
                                stratRow[j] = stateInfo;
                        }
                        newStrat.push_back(stratRow);
                }

                return;
        }
        else
        {
                std::vector<std::vector<StateInfo>> matrix;
                std::string line;
                while (std::getline(inFile, line))
                {
                        std::vector<StateInfo> row;
                        std::istringstream iss(line);
                        StateInfo element;
                        while (iss >> element.name >> element.numActions >> element.numVisits >> element.cardAction >> element.stateAction)
                        {
                                row.push_back(element);
                                // ignore the delimiter between structs (3 spaces)
                                 iss.ignore(3, ' ');
                        }
                        matrix.push_back(row);
                }
                inFile.close();
                newStrat = matrix;
        }
}

void Agent::printStrat()
{
        for (int i = 0; i < newStrat.size(); i++)
        {
                for (int j = 0; j < newStrat[i].size(); j++)
                {
                        printf("%d,", newStrat[i][j].name);
                        printf("%f,", newStrat[i][j].numActions);
                        printf("%d,", newStrat[i][j].numVisits);
                        printf("%d,", newStrat[i][j].cardAction);
                        printf("%d,", newStrat[i][j].stateAction);
                }
                printf("\n");
        }
}

void Agent::updateVisits(int i, int j)
{
        newStrat[i][j].numVisits += 1;
}

void Agent::writeStrat()
{
        std::ofstream outFile("../BasePolicy.txt");

        if (!outFile)
        {
                std::cerr << "Error writing File" << std::endl;
        }

        for (const auto &row : newStrat)
        {
                for (const auto &element : row)
                {
                        outFile << element.name << " " << element.numActions << " " << element.numVisits << " " << element.cardAction << " " << element.stateAction;
                        outFile << " ";
                }
                outFile << std::endl;
        }
        outFile.close();
}

/*
double qTable[52][4]
{
///      H    C    D    S
///      I    H    -    P
///      T    K    D    L
        0.25,0.25,0.25,0.25, // 5
        0.25,0.25,0.25,0.25, // 6
        0.25,0.25,0.25,0.25, // 7
        0.25,0.25,0.25,0.25, // 8
        0.25,0.25,0.25,0.25, // 9
        0.25,0.25,0.25,0.25, // 10
        0.25,0.25,0.25,0.25, // 11
        0.25,0.25,0.25,0.25, // 12
        0.25,0.25,0.25,0.25, // 13
        0.25,0.25,0.25,0.25, // 14
        0.25,0.25,0.25,0.25, // 15
        0.25,0.25,0.25,0.25, // 16
        0.25,0.25,0.25,0.25, // 17
        0.25,0.25,0.25,0.25, // 18
        0.25,0.25,0.25,0.25, // 19
        0.25,0.25,0.25,0.25, // 20
        0.25,0.25,0.25,0.25, // 21
        0.25,0.25,0.25,0.25, // A + A
        0.25,0.25,0.25,0.25, // A + 2
        0.25,0.25,0.25,0.25, // A + 3
        0.25,0.25,0.25,0.25, // A + 4
        0.25,0.25,0.25,0.25, // A + 5
        0.25,0.25,0.25,0.25, // A + 6
        0.25,0.25,0.25,0.25, // A + 7
        0.25,0.25,0.25,0.25, // A + 8
        0.25,0.25,0.25,0.25, // A + 9
        0.25,0.25,0.25,0.25, // A + 10
        0.25,0.25,0.25,0.25, // Pairs of 2
        0.25,0.25,0.25,0.25, // P-3
        0.25,0.25,0.25,0.25, // P-4
        0.25,0.25,0.25,0.25, // P-5
        0.25,0.25,0.25,0.25, // P-6
        0.25,0.25,0.25,0.25, // P-7
        0.25,0.25,0.25,0.25, // P-8
        0.25,0.25,0.25,0.25, // P-9
        0.25,0.25,0.25,0.25, // P-10
        0.25,0.25,0.25,0.25, // 6 > 2 cards
        0.25,0.25,0.25,0.25, // 7
        0.25,0.25,0.25,0.25, // 8
        0.25,0.25,0.25,0.25, // 9
        0.25,0.25,0.25,0.25, // 10
        0.25,0.25,0.25,0.25, // 11
        0.25,0.25,0.25,0.25, // 12
        0.25,0.25,0.25,0.25, // 13
        0.25,0.25,0.25,0.25, // 14
        0.25,0.25,0.25,0.25, // 15
        0.25,0.25,0.25,0.25, // 16
        0.25,0.25,0.25,0.25, // 17
        0.25,0.25,0.25,0.25, // 18
        0.25,0.25,0.25,0.25, // 19
        0.25,0.25,0.25,0.25, // 20
        0.25,0.25,0.25,0.25  // 21 > 2 cards
}
*/