//
//  main.cpp
//  That Arithmetic Progression
//
//  Created by Carlos Feitosa on 7/19/14.
//  Copyright (c) 2014 Carlos Feitosa. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include <algorithm>

using namespace std;

bool processArithmeticProgressions(int arrayOfIntegers[], int numbersOfCards) {
    int reason = 0, number = 0;

    switch (numbersOfCards) {
        case 1:
            cout << -1;
            break;

        case 2:
            if (arrayOfIntegers[0] == arrayOfIntegers[1]) {
                cout << 1 << endl << arrayOfIntegers[0];
            } else {
                reason = arrayOfIntegers[1] - arrayOfIntegers[0];
                number = ((arrayOfIntegers[0] + arrayOfIntegers[1]) / 2);

                if (((number - arrayOfIntegers[0]) == (arrayOfIntegers[1] - number)) and ((number + reason) == arrayOfIntegers[1])) {
                    cout << 3 << endl << arrayOfIntegers[0] - reason << " " << number << " " << arrayOfIntegers[1] + reason;
                } else {
                    cout << 2 << endl << arrayOfIntegers[0] - reason << " " << arrayOfIntegers[1] + reason;
                }
            }

            break;
        default:
            sort(arrayOfIntegers, arrayOfIntegers + numbersOfCards);

            reason = arrayOfIntegers[numbersOfCards - 1] - arrayOfIntegers[0];

            for (int i = 1; i < numbersOfCards; i++) {
                reason = min(reason, arrayOfIntegers[i] - arrayOfIntegers[i - 1]);
            }

            int x = 0;

            for (int i = 1; i < numbersOfCards; i++) {
                if (arrayOfIntegers[i]-arrayOfIntegers[i - 1] == (reason * 2)) {
                    x++;

                    number = (arrayOfIntegers[i] + arrayOfIntegers[i - 1])/2;
                }

                if ((arrayOfIntegers[i] - arrayOfIntegers[i - 1] != reason) and (arrayOfIntegers[i] - arrayOfIntegers[i-1] != (reason * 2))) {
                    cout << 0;

                    return true;
                }
            }

            if (1 == x) {
                cout << 1 << endl << number << endl;
                
            } else {
                if (0 == x) {
                    cout << 2 << endl << arrayOfIntegers[0] - reason << " " << arrayOfIntegers[numbersOfCards - 1] + reason;
                } else if (0 == reason) {
                    cout << 1 << endl << arrayOfIntegers[0];
                } else {
                    cout << 0;
                }
            }

            break;
    }

    return true;
}

int main(int argc, const char * argv[])
{
    int numbersOfCards;
    int* arrayOfIntegers = new int[100002];

    fscanf(stdin, "%i", &numbersOfCards);

    assert((numbersOfCards >= 1) and (numbersOfCards <= 100000));

    for (int i = 0; i < numbersOfCards; i++) {
        if (i != numbersOfCards) {
            fscanf(stdin, "%i ", &arrayOfIntegers[i]);
        } else {
            fscanf(stdin, "%i\n", &arrayOfIntegers[i]);
        }

        assert((arrayOfIntegers[i] >= 1) and (arrayOfIntegers[i] <= 100000000));
    }

    exit (! (int) processArithmeticProgressions(arrayOfIntegers, numbersOfCards));
}

