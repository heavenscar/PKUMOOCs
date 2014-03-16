#include <iostream>
using namespace std;

class HQs {
	// HQs can produce five kinds of warriors
private:
	int dragon, ninja, iceman, lion, wolf;
	int draHp, ninHp, iceHp, lioHp, wolHp;
	int totalWarrior;
	int TotalHP;
public:
	// constructor
	HQs(int d, int n, int i, int l, int w, int hp);
	
	// produce warriors;
	bool produceDragon() {
		if (TotalHP >= draHp) {
			totalWarrior++;
			dragon++;
			TotalHP -= draHp;
			return true;
		}
		else
			return false;
	};
	bool produceNinja(){
		if (TotalHP >= ninHp) {
			totalWarrior++;
			ninja++;
			TotalHP -= ninHp;
			return true;
		}
		else
			return false;
	};
	bool produceIceman() {
		if (TotalHP >= iceHp) {
			totalWarrior++;
			iceman++;
			TotalHP -= iceHp;
			return true;
		}
		else
			return false;
	};
	bool produceLion() {
		if (TotalHP >= lioHp) {
			totalWarrior++;
			lion++;
			TotalHP -= lioHp;
			return true;
		}
		else
			return false;
	};
	bool produceWolf() {
		if (TotalHP >= wolHp) {
			totalWarrior++;
			wolf++;
			TotalHP -= wolHp;
			return true;
		}
		else
			return false;
	};
	
	// get nums of warriors
	int getDragon() {
		return dragon;
	};
	int getNinja() {
		return ninja;
	};
	int getIceman() {
		return iceman;
	};
	int getWolf() {
		return wolf;
	};
	int getLion() {
		return lion;
	};
	int getTotal() {
		return totalWarrior;
	};
	
	// get remain hp
	int getTotalHP() {
		return TotalHP;
	}
};

HQs::HQs(int d=0, int n=0, int i=0, int l=0, int w=0, int hp=0) {
	dragon = 0;
	ninja = 0;
	iceman = 0;
	lion = 0; 
	wolf = 0;
	totalWarrior = 0;
	draHp = d;
	ninHp = n;
	iceHp = i;
	lioHp = l;
	wolHp = w;
	TotalHP = hp;
}

int minWarrior(int d, int n, int i, int l, int w) {
	// find warrior with min hp
	int min;
	min = d;
	if (min > n) min = n;
	else if (min > i) min = i;
	else if (min > l) min = l;
	else if (min > w) min = w;
	return min;
}

int main() {
	
	int groups; // how many data groups are there?
	int dra[100], nin[100], ice[100], lio[100], wol[100]; // hp of warriors
	int min[100];
	int hp[100]; // hp of HQs
	HQs Red[100];
	HQs Blue[100];
	
	cin >> groups;
	
	for(int i = 0; i < groups; i++) {
		// iteratively read-in and store data
		cin >> hp[i];
		cin >> dra[i] >> nin[i] >> ice[i] >> lio[i] >> wol[i];
		min[i] = minWarrior(dra[i], nin[i], ice[i], lio[i], wol[i]);			
		Red[i] = HQs(dra[i], nin[i], ice[i], lio[i], wol[i], hp[i]);
		Blue[i] = HQs(dra[i], nin[i], ice[i], lio[i], wol[i], hp[i]);
	}
	
	for(int i = 0; i < groups; i++) {
		// output
		cout << "Case:" << (i+1) << endl;
		
		int redWarr = 0;
		int blueWarr = 0;
		bool redcomp = false;
		bool bluecomp = false;
		bool redStop = false;
		bool blueStop = false;
		int j = 0;
		
		while(!redStop || !blueStop) {
			// Red HQ
			if (!redStop) {
				if (j < 10) 
					cout << "00" << j << " ";
				else 
					cout << "0" << j << " ";

				if (Red[i].getTotalHP() < min[i]) {
					cout << "red headquarter stops making warriors" << endl;
					redStop = true;
				} else {
					while (!redcomp) {
						if (redWarr == 0) {// try to produce iceman
							redWarr++;
							if (!Red[i].produceIceman()) {
								redcomp = false;
							} else {
								redcomp = true;
								cout << "red iceman " << Red[i].getTotal() << " born with strength "
								<< ice[i] << "," << Red[i].getIceman() << " iceman in red headquarter"
								<< endl;
							}
						}
						else if (redWarr == 1) {// try to produce lion
							redWarr++;
							if (!Red[i].produceLion()) {
								redcomp = false;
							} else {
								redcomp = true;
								cout << "red lion " << Red[i].getTotal() << " born with strength "
								<< lio[i] << "," << Red[i].getLion() << " lion in red headquarter"
								<< endl;
							}
						}
						else if (redWarr == 2) {// try to produce wolf
							redWarr++;
							if (!Red[i].produceWolf()) {
								redcomp = false;
							} else {
								redcomp = true;
								cout << "red wolf " << Red[i].getTotal() << " born with strength "
								<< wol[i] << "," << Red[i].getWolf() << " wolf in red headquarter"
								<< endl;
							}
						}
						else if (redWarr == 3) {// try to produce ninja
							redWarr++;
							if (!Red[i].produceNinja()) {
								redcomp = false;
							} else {
								redcomp = true;
								cout << "red ninja " << Red[i].getTotal() << " born with strength "
								<< nin[i] << "," << Red[i].getNinja() << " ninja in red headquarter"
								<< endl;
							}
						}
						else if (redWarr == 4) {// try to produce dragon
							redWarr = 0;
							if (!Red[i].produceDragon()) {
								redcomp = false;
							} else {
								redcomp = true;
								cout << "red dragon " << Red[i].getTotal() << " born with strength "
								<< dra[i] << "," << Red[i].getDragon() << " dragon in red headquarter"
								<< endl;
							}
						}
					}
					redcomp = false;
				}
			}
			
			
			// Blue HQ
			if (!blueStop) {
				if (j < 10) 
					cout << "00" << j << " ";
				else 
					cout << "0" << j << " ";
				
				if (Blue[i].getTotalHP() < min[i]) {
					cout << "blue headquarter stops making warriors" << endl;
					blueStop = true;
				} else {
					while (!bluecomp) {
						if (blueWarr == 0) {// try to produce lion
							blueWarr++;
							if (!Blue[i].produceLion()) {
								bluecomp = false;
							} else {
								bluecomp = true;
								cout << "blue lion " << Blue[i].getTotal() << " born with strength "
								<< lio[i] << "," << Blue[i].getLion() << " lion in blue headquarter"
								<< endl;
							}
						}
						else if (blueWarr == 1) {// try to produce dragon
							blueWarr++;
							if (!Blue[i].produceDragon()) {
								bluecomp = false;
							} else {
								bluecomp = true;
								cout << "blue dragon " << Blue[i].getTotal() << " born with strength "
								<< dra[i] << "," << Blue[i].getDragon() << " dragon in blue headquarter"
								<< endl;
							}
						}
						else if (blueWarr == 2) {// try to produce ninja
							blueWarr++;
							if (!Blue[i].produceNinja()) {
								bluecomp = false;
							} else {
								bluecomp = true;
								cout << "blue ninja " << Blue[i].getTotal() << " born with strength "
								<< nin[i] << "," << Blue[i].getNinja() << " ninja in blue headquarter"
								<< endl;
							}
						}
						else if (blueWarr == 3) {// try to produce iceman
							blueWarr++;
							if (!Blue[i].produceIceman()) {
								bluecomp = false;
							} else {
								bluecomp = true;
								cout << "blue iceman " << Blue[i].getTotal() << " born with strength "
								<< ice[i] << "," << Blue[i].getIceman() << " iceman in blue headquarter"
								<< endl;
							}
						}
						else if (blueWarr == 4) {// try to produce wolf
							blueWarr = 0;
							if (!Blue[i].produceWolf()) {
								bluecomp = false;
							} else {
								bluecomp = true;
								cout << "blue wolf " << Blue[i].getTotal() << " born with strength "
								<< wol[i] << "," << Blue[i].getWolf() << " wolf in blue headquarter"
								<< endl;
							}
						}
					}
					bluecomp = false;
				}
			}
			
			j++;
		}
	}
	return 0;
}
