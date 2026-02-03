// Obligatorisk Oppgave  Bokregister.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include"EBOOK.h"
#include"MAGAZINE.h"
#include"AUDIOBOOK.h"
#include"BOOKS.h"
#include"USER.h"
#include"LIBRARY.h"
#include<memory>
#include<iostream>
#include<vector>


int main()
{
    // Opprette bibliotek
    LIBRARY library;

    // Opprette noen bøker/Lage et nytt BOOKS-objekt på heapen
    auto book1 = std::make_shared<BOOKS>("Dune", "Frank Herbert", "Fantasy", 1965, 412);
    auto book2 = std::make_shared<BOOKS>("Ringenes Herre", "J.R.R. Tolkien", "Fantasy", 1954, 1200);
    auto book3 = std::make_shared<BOOKS>("1984", "George Orwell", "Sci-Fi", 1949, 328);
    auto book4 = std::make_shared<BOOKS>("Quo Vaidis", "Dragan", "Fag", 2025, 315);
    
    auto lydbook1 = std::make_shared<AUDIOBOOK>("Maskiner som tenker", "Strømke", "Fag", 2022, 335, "Eriksen", 420, "MP3");
    auto lydbook2 = std::make_shared<AUDIOBOOK>("Skriket", "Fjell/Horst", "Krim", 2024, 334, "Nygaard", 482, "MP3");
    
    auto ebok1 = std::make_shared<EBOOK>("Pippi Långstrump", "Lindgren", "Barnebøker", 1925, 255, 85, "PDF");
    auto ebok2 = std::make_shared<EBOOK>("Emil of Lønneberga", "Lindgren", "Barnebøker", 1935, 285, 95, "PDF");
    
    auto magazine1 = std::make_shared<MAGAZINE>("The Time", "Time Magazine", "Fakta", 2023, 35, 9);
    auto magazine2 = std::make_shared<MAGAZINE>("Discavery", "Discavery Chanel", "Fritid", 2024, 55, 10);

    // Legge bøker til bibliotek
    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
    library.addBook(book4);

    library.addBook(lydbook1);
    library.addBook(lydbook2);
    
    library.addBook(ebok1);
    library.addBook(ebok2);

    library.addBook(magazine1);
    library.addBook(magazine2);


    // Opprette brukere
    auto user1 = std::make_shared<USER>("Michal", 1);
    auto user2 = std::make_shared<USER>("Susanne", 2);
    auto user3 = std::make_shared<USER>("Marius", 3);

    // Legge user til bibliotek
    library.addUser(user1);
    library.addUser(user2);
    library.addUser(user3);

    // Liste over alle bøker som er tilgjengelige i biblitek
    std::cout << "Alle tilgjengelige bøker i biblioteket:\n";
    library.listAvailable();
    std::cout << "-------------------------\n";

    // Fjerne en bok av bibliotek
    library.removeBook(1004);

    // Låne bøker av biblioteket
    library.rentBook(user1, 1001);          // Michal låner "Dune"
    library.rentBook(user2, 1002);          // Susanne låner "Ringenes Herre"
    library.rentBook(user2, 1006);          // Susanne låner "Maskiner som tenker"
    library.rentBook(user2, 1009);          // Susanne låner "Emil of Lønneberga"

    // Liste over bøker som er tilgjengelige etter utlån.
    std::cout << "Tilgjengelige bøker etter utlån:\n";
    library.listAvailable();
    std::cout << "-------------------------\n";                 
    
    // Et forsøk på å låne ut en utilgjengelig bok.
    std::cout << "Marius prøver å låne book2 Ringenes Herre(ISBN:1002).\n";
    try {
    library.rentBook(user3, 1002);            // Marius prøver å låne "Ringenes Herre"
    }
    catch (const std::runtime_error& e) { 
        std::cout << "Feil: " << e.what() << std::endl; 
    }
    std::cout << "-------------------------\n";                 

    // Liste over utlånte bøker
    std::cout << "Liste over utlånte bøker:\n";
    library.listUnavailable();
    std::cout << "-------------------------\n";
    
    //Reservasjon av en bok som er utlånt                            
    std::cout << "Reservasjon av en bok som er utlånt: \n";
    library.reserveBook(user3, 1002);                   // Marius reserverer "Ringenes Herre"
    std::cout << "-------------------------\n";
    
    // Retur av en bok som er utlånt
    std::cout << "Return av en bok som er utlånt: \n";
    library.returnBook(user2, 1002);                    // Susanne returnerer "Ringenes Herre"
    std::cout << "-------------------------\n";

    // Liste over bøker som er tilgjengelige etter retu.
    std::cout << "Tilgjengelige bøker etter retur:\n";
    library.listAvailable();
    std::cout << "-------------------------\n";

    // Rapport over mest populære bøker
    std::cout << "Rapport over mest populære bøker:\n";
    library.rapportPopular();
    std::cout << "-------------------------\n";
    
    // Oppdatering av bøker
    library.updateBookInfo(1001, "Crime and punishment", "Dostojevskij", "Roman", 1866, 1200);
    library.updateBookInfo(1002, "White Nights", "Dostojevskij", "Roman", 1848, 1300);
    
    std::cout << "Book 1 etter oppdatering: ";
    book1->showInfo();
    std::cout << "Book 2 etter oppdatering: ";
    book2->showInfo();
    std::cout << "-------------------------\n";

    // Bruk av polimorfisme ved showInfo()-funksjon.
    std::cout << "Vis informasjon om subklassetittler:\n";
    lydbook1->showInfo();
    ebok1->showInfo();
    magazine1->showInfo();
    std::cout << "-------------------------\n";
   
    // Et forsøk på å finne en bok basert på en unik ISBN/ISSN,
    // og samtidig demonstarsjon av exception-handling.
    std::cout << "Forsøk på å finne en bok basert på en ISBN.\n";
    try {
    auto b = library.searchBook(1004);
    b->showInfo();
    }
    catch (const std::runtime_error& e) { 
        std::cout << "Feil: " << e.what() << std::endl; 
    }
	
    
    return 0;
}

