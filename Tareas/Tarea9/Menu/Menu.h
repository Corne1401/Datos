//
// Created by daniel on 14/6/20.
//

#pragma once

#include <iostream>
#include <cctype>
#include "../UserInput/UserInput.h"
using namespace std;

void startMenu(){

    while (true){

        string option;

        cout << "1) Load file" << endl;
        cout << "2) Enter text" << endl;
        cout << "3. Exit" << endl;

        cin >> option;

        if(option == "1"){



        }

        else if(option == "2"){

            cout << "Please enter the message to code or decode" << endl;
            cout << "(Symbols are taken as alphabetical characters)" << endl;

            string usrInput;
            getline(cin >> ws, usrInput); // cin would end reading in the whitespaces while getline(cin, 'string') wouldn't make a pause for the users input
                                                 // but getline(cin >> ws, 'string') solves both problems


            int countAlpha = 0;
            int countNum = 0;

            for (char s : usrInput){
                if (isdigit(s) || s == ';'){
                    countNum++;
                }
                else{
                    countAlpha++;
                }
            }

            if(countAlpha > 0 && countNum > 0){
                cout << "Text cant contain both alphabetical and numerical characters" << endl;
                continue;
            }


            cout << "1) Txt file output" << endl;
            cout << "2) Console output" << endl;
            string outputType;
            cin >> outputType;
            bool outputTxt = true;
            if (outputType == "1") outputTxt = true;
            else if (outputType == "2") outputTxt = false;

            if( countAlpha > 0 && countNum == 0){
                alphaInput(outputTxt, usrInput);
            }
            else if( countNum > 0 && countAlpha == 0){
                numInput(outputTxt, usrInput);
            }


        }


        else if(option == "3") break;
        else cout << "Option not valid" << endl;


    }




}