#include "BOOKS.h"
#include<iostream>

int BOOKS::s_nextISBN = 1001;       // Startnummer for unik ISBN-generering.

BOOKS::BOOKS(std::string title, std::string author, std::string genre, int releaseYear, int noPages) :
	m_title(title), m_author(author), m_genre(genre), m_releaseYear(releaseYear), m_noPages(noPages) 
{
    m_ISBN = s_nextISBN++;          // Hver gagng økes ISBN med 1 (for unik ISBN-generering).
}

BOOKS::~BOOKS() {} 
	
void BOOKS::showInfo() const
	{ std::cout << "Bok: " << m_title << " av " << m_author << " (" << m_releaseYear << ") " << "ISBN:" << m_ISBN << '\n'; }

bool BOOKS::isAvailable() const { 
    return m_available; 
}
void BOOKS::setAvailable(bool availability) { 
    m_available = availability; 
}
int BOOKS::getISBN() const { 
    return m_ISBN; 
}
std::string BOOKS::getTitle() const { 
    return m_title; 
}
int BOOKS::getBorrowCount() const { 
    return m_timesBorrowed; 
}
void BOOKS::incrementBorrowCount() { 
    m_timesBorrowed++; 
}

void BOOKS::setTitle(const std::string& title) {
    m_title = title;
}
void BOOKS::setAuthor(const std::string& author) {
    m_author = author;
}
void BOOKS::setGenre(const std::string& genre) {
    m_genre = genre;
}
void BOOKS::setReleaseYear(int year) {
    m_releaseYear = year;
}
void BOOKS::setNumPages(int pages) {
    m_noPages = pages;
}
