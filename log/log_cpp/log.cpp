#include "log.h"

void Log(int type, std::string msg, std::string err = "") {
    std::string col = "";
    std::string logtext[] = {
        "\e[1m[INFO]\t\t",
        "\e[1m[WARNING]\t",
        "\e[1m[ERROR]\t\t"
    };

    switch (type) {
        case INFO:      col += ANSI_GREEN;  break;
        case WARNING:   col += ANSI_YELLOW; break;
        case ERROR:     col += ANSI_RED;    break;
        default:        type = INFO;        break;
    }

    std::cout << col << logtext[type] << msg << ANSI_RESET << std::endl;
    if (err.size()) { std::cout << "\t\t" << err << std::endl; }
}
