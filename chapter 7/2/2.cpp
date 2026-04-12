#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book
{
    public:
    string bookname;
    double price;
    int number;
    string author;
    string ISBN;
    Book (string bknm,double prc,int nmb,string ath,string isbn):
    bookname(bknm),price(prc),number(nmb),author(ath),ISBN(isbn){}
    string  checkname();
};
class Library
{
  private:
  vector <Book> books;
  public:
  void addBook (Book);
  void removeBook (string isbn);
  void displayBooks();
  
};

string Book::checkname ()
{
  return ISBN;
}

void Library::addBook (Book in)
{
   books.push_back(in);
}

void Library::removeBook (string isbn)
{
    int quant= books.size();
    for (int i=0;i<quant;i++)
    {
        if ((books[i].checkname())==isbn)
        {
            for (int j=i;j<quant-1;j++)
            {
                books[j]=books[j+1];
            }
            books.pop_back();
            return;
        }
        
    }
    return;
}

void Library::displayBooks()
{
    int quant =books.size();
    for (int i=0;i<quant;i++)
    {
        cout<<"书名: "<<(books[i]).bookname<<", "
        <<"价格: "<<(books[i]).price<<", "
        <<"存书数量: "<<(books[i]).number<<", "
        <<"作者: "<<(books[i]).author<<", "
        <<"ISBN: "<<(books[i]).ISBN;
        cout<<endl;
    }
}

int main() {
	Library library;
	library.addBook(Book("C++ Primer", 99.9, 3, "Stanley B. Lippman", "1234567890123"));
	library.addBook(Book("Effective Modern C++", 59.9, 5, "Scott Meyers", "1234567890124"));
	cout << "图书馆当前藏书：" << endl;
	library.displayBooks(); // 显示所有图书信息
	library.removeBook("1234567890123"); // 删除一本图书
	cout << "删除后图书馆藏书：" << endl;
	library.displayBooks(); // 再次显示所有图书信息
	return 0;
}