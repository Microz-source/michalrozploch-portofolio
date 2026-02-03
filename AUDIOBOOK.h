#pragma once
#include"BOOKS.h"

class AUDIOBOOK : public BOOKS
{
public:
	AUDIOBOOK(std::string title, std::string author, std::string genre, int releaseYear, int noPages, std::string narrator, int length, std::string format);

	void showInfo() const override;
	int getISBN() const override;

	~AUDIOBOOK();

private:

	std::string m_narrator;
	int m_length;
	std::string m_format;
	int m_ISBN;

};

