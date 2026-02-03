#pragma once
#include<string>
#include<memory>
#include<vector>
# include"BOOKS.h"


class USER
{
public:

	USER(std::string name,int userID);
	~USER();

	std::string getName() const;

	void borrowBook(std::shared_ptr<BOOKS> book);	// Funksjonen får inn en kopi av smart peker (shared_ptr) til en bok,
	void reserveBook(std::shared_ptr<BOOKS> book);	// og legger denne bokpekeren inn i brukerens vektor: m_borrowedBooks/m_reservedBooks.

	
	std::vector<std::shared_ptr<BOOKS>> m_reservedBooks; 
	
private:

	std::string m_name;
	int m_userID;

	std::vector<std::shared_ptr<BOOKS>> m_borrowedBooks; 
};

