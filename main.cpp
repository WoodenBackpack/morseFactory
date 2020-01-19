#include <iostream>

#include "factory.h"

//mozliwa jest edycja maina.
int main() {
    try {
        factory f;
        f.setExternalInfo("200 100 50 100 100");				//ustawia parametry po kolei oddzielajac spacja:pa frequency, pauseTime, dotTime, dashTime, charPauseTime
        f.setOutput(factory::beep);				//ustawia rodzaj morsowania
        f.convert("Ala ma kota");					//Tlumaczy slowo na morsa
        f.setOutput(factory::disk);
        f.convert("a pies");
        f.convert(123);
        f.convert(1.23);
    } catch (std::exception* ex ) {
        std::cout<< ex->what();
    }
    system("PAUSE");
	return 0;
}