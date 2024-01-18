//
// Created by lenovo on 2023/7/5.
//

#ifndef FINAL_LIBRARY_H
#define FINAL_LIBRARY_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>

using namespace std;
class User;
class Accountistrator;
class Consumer;
class ConsumerGroup;
class Video;
class Programa;
class ProgramaGroup;

enum video_type {NONE,MOVIE,TELEPLAY,SHOTVIDEO,ADVERTISEMENT};
enum programa_type {NNONE,SPORT,FOOD,GAME,DANCE};
map<string, video_type> VT= {
        {"none", NONE},
        {"movie", MOVIE},
        {"teleplay", TELEPLAY},
        {"shotvideo", SHOTVIDEO},
        {"advertisement", ADVERTISEMENT}
};

map<string, programa_type> PT= {
        {"nnone", NNONE},
        {"sport", SPORT},
        {"food", FOOD},
        {"game", GAME},
        {"dance", DANCE}
};
istream& operator>>(istream& is, video_type& v) {
    string input;
    is >> input;

    if (input == "movie") {
        v = MOVIE;
    } else if (input == "teleplay") {
        v = TELEPLAY;
    } else if (input == "shotvideo") {
        v = SHOTVIDEO;
    } else if (input == "advertisement") {
        v = ADVERTISEMENT;
    } else {
        v=NONE;
    }
    return is;
}
ostream& operator<<(ostream &stream, video_type &ob){
    switch (ob) {
        case MOVIE:
            stream<<"Movie";
            break;
        case TELEPLAY:
            stream<<"Teleplay";
            break;
        case SHOTVIDEO:
            stream<<"Shotvideo";
            break;
        case ADVERTISEMENT:
            stream<<"Advertisement";
            break;
        default:
            stream<<"None";
    }
    return stream;
}

istream& operator>>(istream& is, programa_type& p) {
    string input;
    is >> input;
    if (input == "sport") {
        p = SPORT;
    } else if (input == "food") {
        p = FOOD;
    } else if (input == "game") {
        p = GAME;
    } else if (input == "dance") {
        p = DANCE;
    } else {
        p=NNONE;
    }
    return is;
}

ostream& operator<<(ostream &stream, programa_type& p){
    switch (p) {
        case SPORT:
            stream<<"Sport";
            break;
        case FOOD:
            stream<<"Food";
            break;
        case GAME:
            stream<<"Game";
            break;
        case DANCE:
            stream<<"Dance";
            break;
        default:
            stream<<"Nnone";
    }
    return stream;
}
vector<string> split(const string& str, char delimiter,bool flag= true) {
    vector<string> tokens;
    istringstream iss(str);
    string token;

    while (getline(iss, token, delimiter)) {
        if(flag)
            token.pop_back();
        tokens.push_back(token);
    }

    return tokens;
}


#endif //FINAL_LIBRARY_H
