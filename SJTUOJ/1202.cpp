#include <iostream>

using namespace std;

struct uzel {
    uzel* niz;
    uzel* vys;
    char czs;
    uzel(char& cz, uzel* lf) : czs(cz), vys(lf->vys), niz(lf) {
        lf->vys = this;
    }
    uzel(char& cz, uzel* hf, int plc) : czs(cz), niz(hf->niz), vys(hf) {
        hf->niz = this;
    }
    uzel() {
        vys = nullptr;
        niz = nullptr;
        czs = '0';
    }
};
struct uzch {
    uzel* hf;
    uzel* lf;
    uzch() {
        hf      = new uzel;
        lf      = new uzel;
        hf->niz = lf;
        lf->vys = hf;
    }
    uzch* uchi(char cz) {
        new uzel(cz, lf);
        return this;
    }
    uzch* uchi(char cz, int plc) {
        new uzel(cz, hf, 1);
        return this;
    }
};
int main() {
    uzch i1, i2, i3;
    char cz;
    while (scanf("%c", &cz) && cz != '\n') {
        i1.uchi(cz);
    }
    while (scanf("%c", &cz) && cz != '\n') {
        i2.uchi(cz);
    }
    uzel *ptrf1 = i1.lf->vys, *ptrf2 = i2.lf->vys;
    bool ppf = false; // !                       |
    //! highest should not be ignored!         \ | /
    //!                                         \|/
    while (ptrf1 != i1.hf || ptrf2 != i2.hf || ppf) {
        char ans = ptrf1->czs + ptrf2->czs + ppf - '0' - '0';
        ppf      = ans / 10;
        i3.uchi('0' + ans % 10, 1);
        if (ptrf1 != i1.hf)
            ptrf1 = ptrf1->vys;
        if (ptrf2 != i2.hf)
            ptrf2 = ptrf2->vys;
    }
    bool stf = false;
    for (uzel* hff = i3.hf->niz; hff != i3.lf; hff = hff->niz) {
        if (hff->czs != '0' || stf || hff->niz == i3.lf) {
            cout << hff->czs;
            stf = true;
        }
    }
    return 0;
}