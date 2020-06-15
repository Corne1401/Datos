//
// Created by daniel on 14/6/20.
//

#pragma once

#include <iostream>
#include <unordered_map>
using namespace std;

// a hash-like structure was used here because it wont be necessary to increase or decrease
// the amount of elements that it contains

string decode(const string &key){
    unordered_map<string, string> tNine;
    tNine["0"] = " ";

    tNine["1"] = ".";
    tNine["11"] = ",";
    tNine["111"] = "?";
    tNine["1111"] = "!";
    tNine["11111"] = "@";

    tNine["2"] =  "a";
    tNine["22"] = "b";
    tNine["222"] = "c";

    tNine["3"] =  "d";
    tNine["33"] = "e";
    tNine["333"] = "f";

    tNine["4"] = "g";
    tNine["44"] = "h";
    tNine["444"] = "i";

    tNine["5"] = "j";
    tNine["55"] = "k";
    tNine["555"] = "l";

    tNine["6"] = "m";
    tNine["66"] = "n";
    tNine["666"] = "o";

    tNine["7"] = "p";
    tNine["77"] = "q";
    tNine["777"] = "r";
    tNine["7777"] = "s";

    tNine["8"] = "t";
    tNine["88"] = "u";
    tNine["888"] = "v";

    tNine["9"] = "w";
    tNine["99"] = "x";
    tNine["999"] = "y";
    tNine["9999"] = "z";

    return tNine[key];

}
string encode(const char &key){
    unordered_map<char, string> tNine;
    tNine[' '] = "0";

    tNine['.'] = "1";
    tNine[','] = "11";
    tNine['?'] = "111";
    tNine['!'] = "1111";
    tNine['@'] = "11111";

    tNine['a'] = "2";
    tNine['b'] = "22";
    tNine['c'] = "222";

    tNine['d'] = "3";
    tNine['e'] = "33";
    tNine['f'] = "333";

    tNine['g'] = "4";
    tNine['h'] = "44";
    tNine['i'] = "444";

    tNine['j'] = "5";
    tNine['k'] = "55";
    tNine['l'] = "555";

    tNine['m'] = "6";
    tNine['n'] = "66";
    tNine['o'] = "666";

    tNine['p'] = "7";
    tNine['q'] = "77";
    tNine['r'] = "777";
    tNine['s'] = "7777";

    tNine['t'] = "8";
    tNine['u'] = "88";
    tNine['v'] = "888";

    tNine['w'] = "9";
    tNine['x'] = "99";
    tNine['y'] = "999";
    tNine['z'] = "9999";

    return tNine[key];

}
