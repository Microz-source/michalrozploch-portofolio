#pragma once
#include"BOOKS.h"

class EBOOK : public BOOKS
{
public:

	EBOOK(std::string title, std::string author, std::string genre, int releaseYear, int noPages, double fileSize, std::string fileFormat);

	void showInfo() const override;
	int getISBN() const override;

	~EBOOK();

private:

	double m_fileSize;
	std::string m_fileFormat;
	int m_ISBN;

};

