#include <iostream>
#include <cctype>
#include <fstream>
#include <string>
#include <stdexcept>
#include "linked_stack.h"

bool testeParsing(std::string nome) {
  using namespace std;
  ifstream myfile;
  myfile.open(nome);
  string line;
  auto pilha  = structures::LinkedStack<string> {};
  if (myfile.is_open()) {
		while (getline(myfile, line)) {
			if (line.empty()) {
				continue;
				//break;
			} else {
				    int first_index = 0;
				    int last_index = 0;
				    int size_line = line.size();
				    string character;
				while(size_line > 0) {
					     first_index = line.find_first_of('<', last_index);
					     last_index = line.find_first_of('>', first_index);
					     int size = last_index - first_index;
					     if (first_index != -1 && last_index != -1) {
						      string word = line.substr(first_index, size + 1);
						      int slash_index = word.find('/', 0);
						      if (slash_index == -1) {
							             pilha.push(word);
					      	} else {
							        string slash_remove = word.erase(slash_index, 1);
							    if(slash_remove.compare(pilha.top()) == 0) {
								     pilha.pop();
						    	}	 	  	 	      	      	    	   	  	  	       	 	
						}
					}
					size_line--;
				}
			}
		}
		cout << pilha.size() << "\n" << endl;
    myfile.close();
	} else {
		cout << "Unable to open file";
	}
	if(!pilha.empty()) {
	std::cout << "error" << std::endl;
	return false;
	}
return true;
}