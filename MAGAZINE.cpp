#include "MAGAZINE.h"

int MAGAZINE::s_nextISSN = 2001;

MAGAZINE::MAGAZINE(std::string title, std::string author, std::string genre, int releaseYear, int noPages, int edition) :
	BOOKS(title, author, genre, releaseYear, noPages), m_edition(edition) 
{
	m_ISSN = s_nextISSN++;
}
void MAGAZINE::showInfo() const {
	std::cout << "Tidsskrift: " << m_title << ", Utgave:" << m_edition << ", ISSN:" << m_ISSN << '\n';
}
int MAGAZINE::getISBN() const {
	return m_ISSN;
}

MAGAZINE::~MAGAZINE() {}
