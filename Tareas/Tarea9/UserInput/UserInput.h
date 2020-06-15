//
// Created by daniel on 14/6/20.
//

#pragma once
#include <iostream>
#include <fstream>
#include "../Encoder-Decoder/EncoderDecoder.h"
using namespace std;

// In the moment of encoding if there is a button that must be pressed more than one time
// a delimiter id added (;) in order to be decoded in case that the user wishes to do it

void alphaInput(bool output, string message){

    string buffer = "";
    string finalMessage;

    for( auto s : message ){

        if(encode(s)[0] == finalMessage[finalMessage.length()-1]) finalMessage+=";";
        finalMessage += encode(s);

    }
    if(output){
        ofstream decodedMessage;
        decodedMessage.open("../Output/Encoded_Message.txt");
        decodedMessage << finalMessage;
    } else cout << finalMessage << endl;
};
void numInput(bool output,string message){
    string buffer = "";
    string finalMessage;

    for( auto s : message ){

        if (buffer == ""){
            buffer += s;
        }
        else if(buffer.length() != 4 && s == buffer[0]){
            buffer += s;
        }
        else if(buffer.length() == 4 || s != buffer[0] || s == ';'){

            finalMessage += decode(buffer);
            buffer = "";
            buffer += s;
        }
    }
    finalMessage += decode(buffer);

    if(output){
        ofstream decodedMessage;
        decodedMessage.open("../Output/Decoded_Message.txt");
        decodedMessage << finalMessage;
    } else cout << finalMessage << endl;

};
