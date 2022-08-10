#include <iostream>

using namespace std;

struct GPU {
    float clockFREQ;
    int ram;
    string brand;
};


struct Computer {
    int gbRAM = 0;
    float opFreq = 0.0;
    string brand = "";
    string architecture = "";

    GPU graphicCard {1.7, 512, "AMD"};

    void downgradePC(){
            gbRAM -=1;
            opFreq -=3;
            graphicCard.ram -= 200;
            graphicCard.clockFREQ -= 1;
    }
};


struct Computer2 {
    int gbRAM;
    double opFreq;
    string brand;
    string architecture;
};


Computer upgradePC(Computer myPC)
{
    myPC.gbRAM *= 2;
    myPC.opFreq += 3;

    return myPC;
}


int main() {
    Computer colorPC {13, 3.6, "DELL", "FULL"};
    Computer2 megaColorPC = {17, 3.6, "DELL", "FULL"};
    cout << colorPC.brand << endl;
    cout << sizeof(colorPC) << endl;
    cout << sizeof(megaColorPC) << endl;

    colorPC = upgradePC(colorPC);

    cout << "new op freq is: " << colorPC.opFreq << endl;
    cout << "new ram is : " << colorPC.gbRAM << endl;

    colorPC.downgradePC();
    cout << "new op freq is: " << colorPC.opFreq << endl;
    cout << "new ram is : " << colorPC.gbRAM << endl;
    cout << "new graphic ram is" << colorPC.graphicCard.ram << endl;
    cout << "new graohic process is: " << colorPC.graphicCard.clockFREQ << endl;

}