#pragma once
#include"BOOKS.h"


class MAGAZINE : public BOOKS
{
public:

	MAGAZINE(std::string title, std::string author, std::string genre, int releaseYear, int noPages, int edition);

	void showInfo() const override;
	int getISBN() const override;

	~MAGAZINE();

private:

	int m_ISSN;
	int m_edition;

	int static s_nextISSN;

};

