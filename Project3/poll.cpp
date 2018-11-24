#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
using namespace std;

bool hasProperSyntax(string pollData);
bool isValidStateCode(string stateCode);
bool isValidStateForecast(string stateForecast);
int tallySeats(string pollData, char party, int& seatTally);
string toUppercase(string s);
bool hasIllegalCharacters(string pollData);

int main() {
    int s = 666;
    assert(tallySeats("IL11R,DE5G,MD7D", 'D', s) == 0  &&  s == 7);
    assert(tallySeats("CA39D14R,FL15R11D,TX11D25R", 'R', s) == 0  &&  s == 54);
    assert(tallySeats("MI4D4R5R,TN1D4R1D3R", 'R', s) == 0  &&  s == 16);
    assert(tallySeats(
		"AL1D6R,AK1R,AZ4D5R,AR4R,CA39D14R,CO3D4R,CT5D,DE1D,FL11D16R,"
		"GA4D10R,HI2D,ID2R,IL11D7R,IN2D7R,IA1D3R,KS4R,KY1D5R,LA1D5R,"
		"ME1D1R,MD7D1R,MA9D,MI5D9R,MN5D3R,MS1D3R,MO2D6R,MT1R,NE3R,"
		"NV3D1R,NH2D,NJ7D5R,NM2D1R,NY18D9R,NC3D10R,ND1R,OH4D12R,"
		"OK5R,OR4D1R,PA1D11R,RI2D,SC1D6R,SD1R,TN2D7R,TX11D25R,UT4R,"
		"VT1D,VA4D7R,WA6D4R,WV3R,WI3D5R,WY1R", 'D', s) == 0  &&  s == 190);
    assert(tallySeats(
		"AL1D6R,AK1R,AZ4D5R,AR4R,CA39D14R,CO3D4R,CT5D,DE1D,FL11D16R,"
		"GA4D10R,HI2D,ID2R,IL11D7R,IN2D7R,IA1D3R,KS4R,KY1D5R,LA1D5R,"
		"ME1D1R,MD7D1R,MA9D,MI5D9R,MN5D3R,MS1D3R,MO2D6R,MT1R,NE3R,"
		"NV3D1R,NH2D,NJ7D5R,NM2D1R,NY18D9R,NC3D10R,ND1R,OH4D12R,"
		"OK5R,OR4D1R,PA1D11R,RI2D,SC1D6R,SD1R,TN2D7R,TX11D25R,UT4R,"
		"VT1D,VA4D7R,WA6D4R,WV3R,WI3D5R,WY1R", 'R', s) == 0  &&  s == 239);
}

//calculate the number of seats won by a certain party
int tallySeats(string pollData, char party, int& seatTally) {
    if(!hasProperSyntax(pollData)) {
        return 1;
    }
    if(!isalpha(party)) {
        return 2;
    }

    party = toupper(party);
    pollData = toUppercase(pollData);
    
	//determine how many voters there are for the indicated party
    int currentPos = 0;
    string stringVotes = "";
    int numVotes = 0;
	//find the party character in the string and check the number that precedes it
    while(pollData.find(party) != -1) {
        currentPos = pollData.find(party);
		if(currentPos >= 2 && isdigit(pollData[currentPos - 2])) {
            	stringVotes = pollData.substr(currentPos-2, 2);
            	numVotes += (stringVotes[0]-'0')*10;
            	numVotes += stringVotes[1] - '0';
        } 
        else {
            if(isdigit(pollData[currentPos - 1])) {
				stringVotes = pollData[currentPos-1];
				numVotes += stringVotes[0]-'0';
			} else {
				stringVotes = "0";
			}
        }
		//shorten the string to everything after the first instance of the party character
        pollData = pollData.substr(pollData.find(party)+1);
    }

    seatTally = numVotes;
    return 0;
}

//check if the pollData string is valid
bool hasProperSyntax(string pollData) {
    if(pollData == "") {
        return true;        
    }

    if(hasIllegalCharacters(pollData)) {
        return false;
    }

	//break up pollData into individual state forecasts using commas as a marker
    string currentStateForecast = "";
    while(pollData.find(',') != -1) {
        currentStateForecast = pollData.substr(0, pollData.find(','));

        if(!isValidStateForecast(currentStateForecast)) {
            return false;
        }
		//clear currentStateForecast for the next iteration and remove the first state forecast from the pollData string
        currentStateForecast = "";
        pollData = pollData.substr(pollData.find(',')+1);
    }

    return isValidStateForecast(pollData);
}

//check if the string is a valid state forecast
bool isValidStateForecast(string stateForecast) {
    size_t pos = 0;
    string stateCode = "";
    string partyResult = "";
    string party = "";
    
	//isolate and check if the state code is valid
    while(isalpha(stateForecast[pos])) {
        stateCode += stateForecast[pos];
        pos++;
    }
    if(!isValidStateCode(stateCode)) {
        return false;
    }

	//parse through state forecast and check for valid party result
    for(;pos < stateForecast.length();) {
        while(isdigit(stateForecast[pos])) {
            partyResult += stateForecast[pos];
            pos++;
        }

        if(partyResult.length() > 2) {
            return false;
        }

        while(pos < stateForecast.length() && isalpha(stateForecast[pos])) {
            party += stateForecast[pos];
            pos++;
        }

        if(party.length() != 1) {
            return false;
        }

        partyResult = "";
        party = "";
    }

    return true;
    
}

bool isValidStateCode(string stateCode) {
    const string codes =
        "AL.AK.AZ.AR.CA.CO.CT.DE.FL.GA.HI.ID.IL.IN.IA.KS.KY."
        "LA.ME.MD.MA.MI.MN.MS.MO.MT.NE.NV.NH.NJ.NM.NY.NC.ND."
        "OH.OK.OR.PA.RI.SC.SD.TN.TX.UT.VT.VA.WA.WV.WI.WY";

    for(int i = 0; i < stateCode.length(); i++) {
        stateCode[i] = toupper(stateCode[i]);
    }
    return(stateCode.size() == 2 && stateCode.find('.') == -1 && codes.find(stateCode) != -1);
}

string toUppercase(string s) {
    for(int i = 0; i < s.length(); i++) {
        s[i] = toupper(s[i]);
    }
    return s;
}

bool hasIllegalCharacters(string pollData) {
    for(int i = 0; i < pollData.length(); i++) {
        if(!isdigit(pollData[i]) && !isalpha(pollData[i]) && pollData[i] != ',') {
            return true;
        }
    }
    return false;
}