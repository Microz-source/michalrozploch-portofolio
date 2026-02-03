#include "AUDIOBOOK.h"


AUDIOBOOK :: AUDIOBOOK(std::string title, std::string author, std::string genre, int releaseYear, int noPages, 
	std::string narrator, int length, std::string format) :
	BOOKS(title, author, genre, releaseYear, noPages), m_narrator(narrator), m_length(length), m_format(format) 
{
	m_ISBN = s_nextISBN;
}

void AUDIOBOOK::showInfo() const {
	std::cout << "Lydbook: " << m_title << ", Forteller: " << m_narrator << ", Lengde:" << m_length << " min," << " ISBN:" << m_ISBN << '\n';
}
int AUDIOBOOK::getISBN() const 
{
	return m_ISBN;
}

AUDIOBOOK :: ~AUDIOBOOK(){}
