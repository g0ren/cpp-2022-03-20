/*
 * Задание 1. Разработайте программу «Библиотека». Соз-
 дайте структуру «Книга» (название, автор, издательство,
 жанр). Создайте массив из 10 книг. Реализуйте для него
 следующие возможности:
 ■ ■ Редактировать книгу;
 ■ ■ Печать всех книг;
 ■ ■ Поиск книг по автору;
 ■ ■ Поиск книги по названию;
 ■ ■ Сортировка массива по названию книг;
 ■ ■ Сортировка массива по автору;
 ■ ■ Сортировка массива по издательству.
 */

#include <iostream>
#include <cstring>
using namespace std;
#define SIZE 10

struct book {
	string name;
	string author;
	string publisher;
	string genre;
};

book* makeLibrary(int size = SIZE);
void printBook(book b);
void printLibrary(book *lib, int size = SIZE);
void editBook(book *lib);
void searchByAuthor(book *lib, string str, int size = SIZE);
void searchByTitle(book *lib, string str, int size = SIZE);

/*
 * ■ ■ Сортировка массива по названию книг;
 */
void swap(book *lib, int i, int j) {
	book t { };
	t = lib[i];
	lib[i] = lib[j];
	lib[j] = t;
}

void sortByTitle(book*lib,int size=SIZE){
	bool sorted{};
	while(!sorted){
		sorted=true;
		for(int i=1;i<size;i++){
			if((lib+i)->name<(lib+i-1)->name){
				sorted=false;
				swap(lib,i,i-1);
			}
		}
	}
}

/*
 * ■ ■ Сортировка массива по автору;
 */
void sortByAuthor(book*lib,int size=SIZE){
	bool sorted{};
	while(!sorted){
		sorted=true;
		for(int i=1;i<size;i++){
			if((lib+i)->author<(lib+i-1)->author){
				sorted=false;
				swap(lib,i,i-1);
			}
		}
	}
}

/*
 * ■ ■ Сортировка массива по издательству.
 */
void sortByPublisher(book*lib,int size=SIZE){
	bool sorted{};
	while(!sorted){
		sorted=true;
		for(int i=1;i<size;i++){
			if((lib+i)->publisher<(lib+i-1)->publisher){
				sorted=false;
				swap(lib,i,i-1);
			}
		}
	}
}


int main() {
	book *lib;
	lib = makeLibrary();
	printLibrary(lib);
	//editBook(lib);
	cout<<endl;
	searchByAuthor(lib, "J.R.R. Tolkien");
	cout<<endl;
	searchByTitle(lib, "Don Quixote");
	cout<<endl;
	sortByTitle(lib);
	printLibrary(lib);
	cout<<endl;
	sortByAuthor(lib);
	printLibrary(lib);
	cout<<endl;
	sortByPublisher(lib);
	printLibrary(lib);
	cout<<endl;


	return 0;
}

// Создаём базовый массив
book* makeLibrary(int size) {
	book *lib = new book[10];
	book *ptr = lib;
	ptr->author = "Miguel de Cervantes";
	ptr->name = "Don Quixote";
	ptr->publisher = "Simon & Schuster";
	ptr->genre = "Comic novel";
	ptr++;
	ptr->author = "J.R.R. Tolkien";
	ptr->name = "Lord of the Rings";
	ptr->publisher = "Houghton Mifflin Harcourt";
	ptr->genre = "Fantasy";
	ptr++;
	ptr->author = "J.K Rowling";
	ptr->name = "Harry Potter and the Sorcerer's Stone";
	ptr->publisher = "Scholastic Inc";
	ptr->genre = "Fantasy";
	ptr++;
	ptr->author = "Agatha Christie";
	ptr->name = "And Then There Were None";
	ptr->publisher = "Collins Crime Club";
	ptr->genre = "Mystery";
	ptr++;
	ptr->author = "Lewis Carroll";
	ptr->name = "Alice's Adventures in Wonderland";
	ptr->publisher = "Penguin Books";
	ptr->genre = "Children's novel";
	ptr++;
	ptr->author = "Antoine de Saint-Exupery";
	ptr->name = "The Little Prince";
	ptr->publisher = "HarperCollins";
	ptr->genre = "Children’s Novel";
	ptr++;
	ptr->author = "Carlo Collodi";
	ptr->name = "Pinocchio";
	ptr->publisher = "Paris Publishing";
	ptr->genre = "Children's novel";
	ptr++;
	ptr->author = "J.D. Salinger";
	ptr->name = "Catcher in the Rye";
	ptr->publisher = "Back Bay Books";
	ptr->genre = "Realistic fiction";
	ptr++;
	ptr->author = "Mark Twain";
	ptr->name = "The Adventures of Huckleberry Finn";
	ptr->publisher = "Bantam Classics";
	ptr->genre = "Picaresque novel";
	ptr++;
	ptr->author = "Jules Verne";
	ptr->name = "Twenty Thousand Leagues Under the Sea";
	ptr->publisher = "CreateSpace";
	ptr->genre = "Adventure";
	return lib;
}

/*
 * ■ ■ Редактировать книгу;
 */
void editBook(book *lib) {
	int n { }, c { };
	cout << "Which book # would you like to edit?" << endl;
	cin >> n;
	book *ptr = lib + n;
	do {
		printBook(*ptr);
		cout << "What would you like to change about this book?" << endl;
		cout << "1. Book author" << endl;
		cout << "2. Book title" << endl;
		cout << "3. Publisher" << endl;
		cout << "4. Genre" << endl;
		cout << "0. Stop editing the book" << endl;
		cin >> c;
		switch (c) {
		case 0:
			break;
		case 1:
			cout << "Enter new author: ";
			cin.ignore();
			getline(cin, ptr->author);
			break;
		case 2:
			cout << "Enter new title: ";
			cin.ignore();
			getline(cin, ptr->name);
			break;
		case 3:
			cout << "Enter new publisher: ";
			cin.ignore();
			getline(cin, ptr->publisher);
			break;
		case 4:
			cout << "Enter new genre: ";
			cin.ignore();
			getline(cin, ptr->genre);
			break;
		default:
			cout << "Wrong command!";
		}
	} while (c);
}

/*
 *■ ■ Печать всех книг;
 */
void printBook(book b) {
	cout << b.author << ": \"" << b.name << "\". " << b.publisher << ". - "
			<< b.genre << "." << endl;
}

void printLibrary(book *lib, int size) {
	for (int i = 0; i < size; i++) {
		cout << i << ". ";
		printBook(lib[i]);
	}
}

/*
 * ■ ■ Поиск книг по автору;
 */
void searchByAuthor(book *lib, string str, int size) {
	for (int i = 0; i < size; i++)
		if ((lib + i)->author == str) {
			cout << i << ". ";
			printBook(*(lib + i));
		}
}

/*
 * ■ ■ Поиск книги по названию;
 */
void searchByTitle(book *lib, string str, int size) {
	for (int i = 0; i < size; i++)
		if ((lib + i)->name == str) {
			cout << i << ". ";
			printBook(*(lib + i));
		}
}
