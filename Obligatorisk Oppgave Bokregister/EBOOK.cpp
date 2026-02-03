#include "EBOOK.h"



EBOOK::EBOOK(std::string title, std::string author, std::string genre, int releaseYear, int noPages, 
	double fileSize, std::string fileFormat) :
	BOOKS (title, author, genre, releaseYear, noPages), m_fileSize(fileSize), m_fileFormat(fileFormat) 
{
	m_ISBN = s_nextISBN;
}

void EBOOK::showInfo() const {
	std::cout << "E-bok: " << m_title << ", Filstørrelse:" << m_fileSize << " MB" << ", ISBN:" << m_ISBN << '\n';
}
int EBOOK::getISBN() const {
	return m_ISBN;
}

EBOOK::~EBOOK() {}