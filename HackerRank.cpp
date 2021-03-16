#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<string>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

// trim from start (in place)
static inline void ltrim(std::string& s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
		return !std::isspace(ch);
		}));
}

// trim from end (in place)
static inline void rtrim(std::string& s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
		return !std::isspace(ch);
		}).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(string& s) {
	ltrim(s);
	rtrim(s);
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	map <string, string> tagName;
	queue<string> tags;
	queue<string> createKey;
	string line;

	int n = 0, q = 0;
	cin >> n >> q;
	cin.ignore();

	for (int x = 0; x < n; x++) {
		getline(cin, line);

		//parse line
		if (line[1] == '/') {
			//  closing tag
			tags.pop();
		}
		else {
			//  Opening tag
			int spacePos = line.find(' ');
			string tag = line.substr(1, spacePos - 1);
			tags.push(tag);
			unsigned int numOfEqualSigns = std::count(line.begin(), line.end(), '=');
			unsigned int equalSign = 0;
			unsigned int first_quote = 0, second_quote = 0;

			for (unsigned int x = 0; x < numOfEqualSigns; x++) {
				equalSign = line.find('=', equalSign+1);
				spacePos = line.rfind(' ', equalSign -2);
				string key = line.substr(spacePos + 1, equalSign - spacePos - 2);  //  find the space between the tag and the kexy
				//  need to update the variable space pos.........( or something......)
				trim(key);
				first_quote = line.find('\"',second_quote+1);
				second_quote = line.find('\"', first_quote+1);
				string value = line.substr(first_quote+1, second_quote-first_quote-1);
				createKey = tags;
				string mapKey = "";
				while (!createKey.empty()) {
					mapKey += createKey.front() + ".";
					createKey.pop();
				}
				unsigned int strLengh = mapKey.length();
				mapKey[strLengh - 1] = '~';
				mapKey += key;
				tagName.insert(pair<string, string>(mapKey,value));
			}
		}
	} //  end of reading in lines

	//  handle queries
	map <string, string>::iterator it;
	for (int x = 0; x < q; x++) {
		getline(cin, line);
		it = tagName.find(line);
		if (it != tagName.end()) {
			cout << it->second << endl;
		}
		else
			cout << "Not Found!\n";
	}

	return 0;
}
