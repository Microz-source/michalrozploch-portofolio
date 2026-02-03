#pragma once
#include<string>
#include<memory>
#include<iostream>


class BOOKS
{
public:
	
	BOOKS(std::string title, std::string author, std::string genre, int releaseYear, int noPages);
	
	virtual void showInfo() const;		// 'virtual' brukes for polymorfisme - muligheten for at en funksjon i 
										// en baseklasse kan overstyres i en subklasse.
	bool isAvailable() const;
	void setAvailable(bool availability);	// 'availability' brukes til å angi om boka er tilgjengelig eller utlånt.
	virtual int getISBN() const;
	std::string getTitle() const;
	int getBorrowCount() const;
	void incrementBorrowCount();

	void setTitle(const std::string& title);
	void setAuthor(const std::string& author);
	void setGenre(const std::string& genre);
	void setReleaseYear(int year);
	void setNumPages(int pages);

	virtual ~BOOKS();

protected:

	std::string m_title;
	std::string m_author;
	std::string m_genre;
	int m_releaseYear;
	int m_ISBN;
	int m_noPages;

	static int s_nextISBN;			// En statisk variabel som deles av alle bøkene (for unik ISBN-generering).
	
	bool m_available = true;
	int m_timesBorrowed = 0;
};

