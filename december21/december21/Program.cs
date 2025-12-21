using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace december21
{
    class Book
    {
        public int Id;
        public string Title;
        public string Author;
        public int TotalCopies;
        public int AvailableCopies; 
        public Book(int id, string title, string author, int totalCopies) 
        {
            Id = id;
            Title = title;
            Author = author;    
            TotalCopies = totalCopies;
            AvailableCopies = totalCopies;
        }
        public bool IsAvailable()
        {
            return AvailableCopies > 0;
        }
    }

    class Reader
    {
        public int Id;
        public string Name;
        public int BorrowLimit;
        public List<int> BorrowedBookIds;

        public Reader(int id, string name, int borrowLimit)
        {
            Id= id;
            Name = name;
            BorrowLimit = borrowLimit;
            BorrowedBookIds = new List<int>();

        }

        public bool CanBorrow()
        {
            return BorrowedBookIds.Count < BorrowLimit;
        }
    }

    class Loan
    {
        public int Id;
        public int BookId;
        public int ReaderId;
        public string LoanDate;
        public string ReturnDate;
        public string Status;

        public Loan(int id, int bookId, int readerId, string loanDate)
        {
            Id = id;
            BookId = bookId;
            ReaderId = readerId;
            LoanDate = loanDate;
            Status = "ACTIVE";
        }
    }
    class Library
    {
        private List<Book> books = new List<Book>();
        private List<Reader> readers = new List<Reader>();
        private List<Loan> loans = new List<Loan>();
        private int loanIdCounter = 1;

        public void AddBook(Book book)
        {
            books.Add(book);
        }

        public void RegisterReader(Reader reader)
        {
            readers.Add(reader);
        }

        public void BorrowBook(int readerId, int bookId, string date)
        {
            Book book = books.FirstOrDefault(b => b.Id == bookId);
            Reader reader = readers.FirstOrDefault(r => r.Id == readerId);

            if (book == null || reader == null)
            {
                Console.WriteLine("BORROW FAILED: book or reader not found");
                return;
            }

            if (!book.IsAvailable())
            {
                Console.WriteLine($"BORROW FAILED: {reader.Name} cannot borrow \"{book.Title}\" (no copies available)");
                return;
            }

            if (!reader.CanBorrow())
            {
                Console.WriteLine($"BORROW FAILED: {reader.Name} reached borrow limit");
                return;
            }

            book.AvailableCopies--;
            reader.BorrowedBookIds.Add(bookId);

            loans.Add(new Loan(loanIdCounter++, bookId, readerId, date));

            Console.WriteLine($"BORROW OK: {reader.Name} borrowed \"{book.Title}\"");
        }

        public void ReturnBook(int loanId, string date)
        {
            Loan loan = loans.FirstOrDefault(l => l.Id == loanId && l.Status == "ACTIVE");
            if (loan == null) return;

            Book book = books.First(b => b.Id == loan.BookId);
            Reader reader = readers.First(r => r.Id == loan.ReaderId);

            loan.Status = "RETURNED";
            loan.ReturnDate = date;

            book.AvailableCopies++;
            reader.BorrowedBookIds.Remove(book.Id);

            Console.WriteLine($"RETURN OK: \"{book.Title}\" returned by {reader.Name}");
        }

        public void PrintChristmasReport()
        {
            Console.WriteLine("\nCHRISTMAS LIBRARY REPORT");

            foreach (var book in books)
            {
                Console.WriteLine($"{book.Title}: {book.AvailableCopies} / {book.TotalCopies} available");
            }

            Console.WriteLine("\nACTIVE LOANS");
            foreach (var loan in loans.Where(l => l.Status == "ACTIVE"))
            {
                Book book = books.First(b => b.Id == loan.BookId);
                Reader reader = readers.First(r => r.Id == loan.ReaderId);
                Console.WriteLine($"{reader.Name} → {book.Title}");
            }
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            Library library = new Library();

            library.AddBook(new Book(1, "Clean Code", "Robert C. Martin", 2));
            library.AddBook(new Book(2, "The Pragmatic Programmer", "Andrew Hunt", 1));
            library.AddBook(new Book(3, "Refactoring", "Martin Fowler", 1));

            library.RegisterReader(new Reader(1, "Alice", 2));
            library.RegisterReader(new Reader(2, "Bob", 1));

            library.BorrowBook(1, 1, "2024-12-20");
            library.BorrowBook(1, 1, "2024-12-20");
            library.BorrowBook(2, 1, "2024-12-20");

            library.ReturnBook(1, "2024-12-24");

            library.PrintChristmasReport();

            Console.ReadLine();
        }
    }
}
