#pragma once
#include <string>

class PrettyPrint {
public:
	PrettyPrint();

	std::string concString(const std::string, const std::string) const;
	std::string replaceAO(std::string) const;
	std::string upend(std::string) const;

	virtual ~PrettyPrint();
};

