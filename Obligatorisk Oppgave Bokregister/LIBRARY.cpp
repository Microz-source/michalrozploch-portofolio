#include "LIBRARY.h"
#include<iostream>

										// Funksjon som brukes av std::sort() for å sammenligne to bøker,
bool compareBooksByPopularity(const std::shared_ptr<BOOKS>& a,		// så sjekker den om a > b.
	const std::shared_ptr<BOOKS>& b)
{
	return a->getBorrowCount() > b->getBorrowCount();
}


LIBRARY::LIBRARY() {}

LIBRARY::~LIBRARY() {}

void LIBRARY::addBook(std::shared_ptr<BOOKS> book) {
	m_books.push_back(book);
}
void LIBRARY::removeBook(int isbn) {				
	for (size_t i = 0; i < m_books.size(); ++i) {	// Funksjonen går gjennom alle bøker i vektoren.
		if (m_books[i]->getISBN() == isbn) {		// Sjekker om boka har samme ISBN.
			m_books.erase(m_books.begin() + i);		// Fjerner boka.
			break;									//  Løkke stopper etter første treff.
		}
	}
}
std::shared_ptr<BOOKS> LIBRARY::searchBook(const int isbn) {
	for (auto& b : m_books) {					// 'b' er en referanse til hvert element i vektoren (std::shared_ptr<BOOKS>).
		if (b->getISBN() == isbn) 				// Vi bruker referanse & for å unngå å kopiere smartpekeren hver gang.
			return b;
		}
		throw std::runtime_error("Bok har ikke funnet!");	// Hvis ingen bok matcher → returner exception-handling.							
}
void LIBRARY::rentBook(USER& user, int isbn) {		// Vi sjekker om boka finnes,
	auto b = searchBook(isbn);						// searchBook() returnerer en std::shared_ptr<BOOKS> eller 	
													// returnerer exception-handling hvis boka ikke finnes.
	if (!b->isAvailable())							// Når vet vi at boka finnes, sjekker vi om den er tilgjengelig.
		throw std::runtime_error("Boken er ikke tilgjengelig!");		// Hvis ikke, kaster den exception-handling.
										
	b->setAvailable(false);				// Programmet markerer boka som utlånt.
	b->incrementBorrowCount();			// Det øker antall ganger boka har vært lånt..
	user.borrowBook(b);					// Boken legges inn i brukerens egen liste over lånte bøker.
}
void LIBRARY::reserveBook(USER& user, int isbn) {
	
	auto book = searchBook(isbn);

	if (book->isAvailable())
	{
		std::cout << "Boken er tilgjengelig – lån den i stedet.\n";
		return;
	}
	user.reserveBook(book);
	std::cout << "Boken \"" << book->getTitle()
		<< "\" er reservert for bruker: " << user.getName() << '\n';
}

void LIBRARY::returnBook(USER& user, int isbn)
{
	auto book = searchBook(isbn);
	book->setAvailable(true);

														// Løkken sjekker om noen har reservert boka.
	for (auto& member : m_user)							
	{													// Løkken går gjennom alle brukere i biblioteket, etterpå
		for (auto& resBook : member->m_reservedBooks)	// går den gjennom alle reserverte bøker for hver bruker, 
		{												// og kaller den resBook.
			if (resBook->getISBN() == isbn)				// Løkken sjekker om en av bøkene har samme ISBN som den returnerte boken,
			{
				std::cout << "Boken var reservert av "
					<< member->getName()			
					<< ".\n";							// og skriver ut hvem som hadde reservert den.
				return;
			}
		}
	}
	std::cout << book->getTitle() <<" - Bok returnert.\n";
}
void LIBRARY::listAvailable() {
	for (auto& b : m_books)					// Funksjonen går gjennom alle bøker,
		if (b->isAvailable())				// og sjekker om boken har status bool == true.
			b->showInfo();
}
void LIBRARY::listUnavailable() {
	for (auto& b : m_books)
		if (!b->isAvailable())
			b->showInfo();
}														// Funksjonen lager en liste over de mest populære bøkene.
void LIBRARY::rapportPopular() {						// Først lager den en kopi av smartpekerne i en ny vector som heter temp.
	std::vector<std::shared_ptr<BOOKS>> temp = m_books;
														// Definisjon til compareBooksPopulatity() ligger oppover.
	std::sort(temp.begin(), temp.end(), compareBooksByPopularity);
														// Funksjonen sorterer bøkene etter popularitet,
	for (auto& b : temp) {								// og deretter skriver den ut den sorterte listen.
		std::cout << b->getBorrowCount() << " utlånt: ";
		b->showInfo();
	}
}

void LIBRARY::updateBookInfo(int isbn, const std::string& title,
	const std::string& author, const std::string& genre,
	int year, int pages)
{
	auto book = searchBook(isbn);			// Først finner funksonen boken eller kaster den feil.

	book->setTitle(title);
	book->setAuthor(author);
	book->setGenre(genre);
	book->setReleaseYear(year);
	book->setNumPages(pages);
}