#include "USER.h"

USER::USER(std::string name, int userID) :
	m_name(name), m_userID(userID) {}

USER::~USER() {}

std::string USER::getName() const {
	return m_name;
}

void USER::borrowBook(std::shared_ptr<BOOKS> book) { 
	m_borrowedBooks.push_back(book); 
}

void USER::reserveBook(std::shared_ptr<BOOKS> book) { 
	m_reservedBooks.push_back(book); 
}