#include "CommandProcessing.h"

std::string strip(const std::string& str){

    std::string stripped = "";
    int i = 0;
    while(str[i] == ' ' || str[i] == '\t'){
        i++;
    }

    int j = str.size()-1;
    while(str[j] == ' ' || str[j] == '\t'){
        j--;
    }

    stripped = str.substr(i, j - i + 1);
    return stripped;
}