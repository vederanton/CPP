#include "pch.h"
#include "PrettyPrint.h"


PrettyPrint::PrettyPrint() {}

std::string PrettyPrint::concString(const std::string a, const std::string b) const { // конкатенация 2 строк с точкой между ними.
	std::string concatStr = a;
	concatStr.append(".").append(b);
	return concatStr;
}

std::string PrettyPrint::replaceAO(std::string a) const { // замена символов а на о.
	std::string tmp = "";
	for (int i = 0; i < a.length(); ++i) {
		if (a[i] == 'a') {
			tmp += 'o';
		}
		else {
			tmp += a[i];
		}
	}
	a.clear();
	a = tmp;
	return a;
}

std::string PrettyPrint::upend(std::string a) const { // перевертывание строки.
	std::string tmp;
	for (int i = a.length() - 1; i >= 0; --i) {
		tmp += a[i];
	}
	a.clear();
	a = tmp;
	return a;
}

PrettyPrint::~PrettyPrint() {}
