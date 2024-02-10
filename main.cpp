#include <iostream>
#include <fstream>
#include <cstring>
int main() {
	std::string path;
	std::cout << "Enter full path to file: ";
	std::cin >> path;
	std::ifstream file(path);
	std::cout << "Reading file...\n";
	std::string data = "";
	std::string newdata;
	file >> std::noskipws;
	while (getline(file, data)) {}
	std::string isincr;
	int u = 0;
	uint64_t pass;
	while (u < 5) {isincr = isincr + data[u]; u++;}
	if (isincr == "encry") {
		std::cout << "[-] File alredy encrypted! Enter file password: ";
		std::cin >> pass;
		int u = 0;
		int i = 5;
		int aeefm;
		while (data[i] != '\0') { // while file data still founding
			std::string asciiSym = "";
			while (data[i] != '/') {
				asciiSym = asciiSym + data[i];
				i++;
			} aeefm = std::stoi(asciiSym);
			aeefm = aeefm / pass;
			newdata = newdata + static_cast<char>(aeefm);
			i += 1;
		}
		std::ofstream openfile(path);
		openfile << newdata;
		openfile.close();
		std::cout << "File succefully decrypted!";
	} 
	else { // crypting
	std::cout << "[+] Set password for crypt file (example - 12345): ";
	std::cin >> pass;
	int i = 0;
	while (data[i] > 0 || data[i] == ' ') {
	  newdata = newdata + std::to_string((static_cast<int>(data[i])) * pass) + '/';
	  i++;
	}
	
	std::ofstream openfile(path);
	openfile << "encry" << newdata;
	openfile.close();
	std::cout << "File succefully encrypted!";
	}
	file.close();
}
