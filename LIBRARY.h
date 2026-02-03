#pragma once
#include<memory>
#include<vector>
#include<algorithm> //for sort()
#include<stdexcept>
#include"BOOKS.h"
#include"USER.h"


class LIBRARY
{
public:

	LIBRARY();
	~LIBRARY();

	void addBook(std::shared_ptr<BOOKS> book);
	void addUser(std::shared_ptr<USER> user);
	void removeBook( int isbn);
	
	std::shared_ptr<BOOKS> searchBook(const int isbn);  // Funksjonen returnerer en smart peker (std::shared_ptr) 
														// som peker på et BOOKS-objekt.
	void rentBook( std::shared_ptr<USER> user, const int isbn);
	void reserveBook(std::shared_ptr<USER> user, const int isbn);				// rent/returnBook() - '&' betyr at funksjonen mottar
	void returnBook(std::shared_ptr<USER> user, const int isbn);				//  en referanse til et eksisterende USER-objekt — ikke en kopi.
														
	void listAvailable();
	void listUnavailable();
	void rapportPopular();

	void updateBookInfo(int isbn, const std::string& title,
		const std::string& author, const std::string& genre,
		int year, int pages);


private:
	
	std::vector<std::shared_ptr<USER>> m_user;
	std::vector<std::shared_ptr<BOOKS>> m_books;
};

