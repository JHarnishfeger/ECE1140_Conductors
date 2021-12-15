#include "string_utils.hpp"

std::string string_utils::nth_word(std::string input, unsigned int index, char delim){
	auto strings = separate_strings(input, delim);
	if(index >= strings.size()){
		return "";
	}else{
		auto iterator = strings.begin();
		std::advance(iterator, index);
		return *iterator;
	}
}

std::list<std::string> string_utils::separate_strings(std::string input, char delim){
	std::list<std::string> rtn;
	
	unsigned int i = 0;
	std::string s;
	while(i < input.size()){
		if(input[i] == delim){
			rtn.push_back(s);
			s.clear();
		}else{
			s += input[i];
		}
		i++;
	}
	if(!s.empty()){
		rtn.push_back(s);
		s.clear();
	}
	return rtn;
}

int string_utils::num_delims(std::string input, char delim){
	int count = 0;
	for(char& itr : input){
		if(itr == delim) count++;
	}
	return count;
}

char string_utils::char_to_rgb(char alpha){
	if(alpha >= 'a' && alpha <= 'z'){
		alpha = alpha - 'a';
		float fraction = static_cast<float>(alpha) / 26.f;
		fraction = fraction * 256.f;
		return static_cast<char>(fraction);
		
	}else if(alpha >= 'A' && alpha <= 'Z'){
		alpha = alpha - 'A';
		float fraction = static_cast<float>(alpha) / 26.f;
		fraction = fraction * 256.f;
		return static_cast<char>(fraction);
		
	}else{
		return 0;
	}
}
