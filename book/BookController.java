package com.apple.book;

import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;

@Controller
public class BookController {
	
	// get all books ở đây
	@GetMapping("/books2")
	public String getAllBooks(Model model) throws IOException {
	    Connection connection = null;
	    Statement statement = null;
	    ResultSet resultSet = null;
	    List<Book> books = new ArrayList<Book>();
	    try {
	        Class.forName("com.mysql.cj.jdbc.Driver");
	        connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/jdbc_demo", "root", "12345");
	        statement = connection.createStatement();
	        resultSet = statement.executeQuery("select * from book");
	        while (resultSet.next()) {
	            int bookcode = resultSet.getInt(1);
	            String title = resultSet.getString(2);
	            String author = resultSet.getString(3);
	            String category = resultSet.getString(4);
	            int approved = resultSet.getInt(5);
	            books.add(new Book(bookcode, title, author, category, approved == 0 ? false : true));
	        }
	    } catch (Exception e) {
	    }
	    model.addAttribute("books", books);
	    return "books";
	}
	// den trang edit-book
	@GetMapping("/book/{bookcode}")
	public String editbookForm(@PathVariable String bookcode, Model model) {
		model.addAttribute("bookcode", bookcode);
		Connection connection = null;
		PreparedStatement ps = null;
		ResultSet result = null;
		Book book = new Book();
		try {
			Class.forName("com.mysql.cj.jdbc.Driver");
			connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/jdbc_demo", "root", "12345");
			ps = connection.prepareStatement("select * from book where bookcode = ?");
			ps.setInt(1, Integer.valueOf(bookcode));
			result = ps.executeQuery();
			while(result.next()) {
				book.setBookcode(result.getInt(1));
				book.setTitle(result.getString(2));
				book.setAuthor(result.getString(3));
				book.setCategory(result.getString(4));
				book.setApproved(result.getInt(5) == 0 ? false : true);
			}
		} // End of try block
		catch (Exception e) {
			e.printStackTrace();
		}
		model.addAttribute("book", book);
		return "edit-book";
	}
	// update book
	@PutMapping("/book/save/{bookcode}")
	public String updatebook(Book book, @PathVariable String bookcode, Model model) {
		if(!check(book).equals("noError")) {
			if(check(book).equals("existed")) {
				model.addAttribute("error", "true");
			}
			if (book.getTitle().equals("")) {
			    model.addAttribute("NullTitle", "true");
			}
			if(book.getAuthor().equals("")) {
				model.addAttribute("NullAuthor", "true");
			}
			if(book.getCategory().equals("")) {
				model.addAttribute("NullCategory", "true");
			}
			return "edit-book";
		}
		
		Connection connection = null;
		PreparedStatement ps = null;
		int result = 0;
		
		try {
			Class.forName("com.mysql.cj.jdbc.Driver");
			connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/jdbc_demo", "root", "12345");
			ps = connection.prepareStatement("UPDATE `jdbc_demo`.`book` SET `title` = ?, `author` = ?, `category` = ?, `approved` = ? WHERE (`bookcode` = ?);");
			ps.setString(1, book.getTitle());
			ps.setString(2, book.getAuthor());
			ps.setString(3, book.getCategory());
			ps.setInt(4, book.isApproved() ? 1 : 0);
			ps.setInt(5, Integer.valueOf(book.getBookcode()));
			result = ps.executeUpdate();

			ps.close();
			connection.close();

			// Redirect the response to success page
			return "redirect:/books2";
		} // End of try block
		catch (Exception e) {
			e.printStackTrace();
		}
		return "error"; // tạo trang Error
	}
	@GetMapping("/book/new")
	public String newBookForm(Model model) {
		Book book = new Book();
		model.addAttribute("book", book);
		return "new-book";
	}
	// add book
	@PostMapping("/book/save/{bookcode}")
	public String addbook(Book book, @PathVariable String bookcode, Model model) {
		if(!check(book).equals("noError")) {
			if(check(book).equals("existed")) {
				model.addAttribute("error", "true");
			}
			if (book.getTitle().equals("")) {
			    model.addAttribute("NullTitle", "true");
			}
			if(book.getAuthor().equals("")) {
				model.addAttribute("NullAuthor", "true");
			}
			if(book.getCategory().equals("")) {
				model.addAttribute("NullCategory", "true");
			}
			return "edit-book";
		}
		
		Connection connection = null;
		PreparedStatement ps = null;
		int result = 0;
		
		try {
			Class.forName("com.mysql.cj.jdbc.Driver");
			connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/jdbc_demo", "root", "12345");
			ps = connection.prepareStatement("INSERT INTO `jdbc_demo`.`book` (`title`, `author`, `category`, `approved`) VALUES (?, ?, ?, ?);");
			ps.setString(1, book.getTitle());
			ps.setString(2, book.getAuthor());
			ps.setString(3, book.getCategory());
			ps.setInt(4, book.isApproved() ? 1 : 0);
			result = ps.executeUpdate();

			ps.close();
			connection.close();

			// Redirect the response to success page
			return "redirect:/books2";
		} // End of try block
		catch (Exception e) {
			e.printStackTrace();
		}
		return "error"; // tạo trang Error
	}
	@DeleteMapping("/book/{bookcode}")
	public String deleteBook(@PathVariable String bookcode, Book book) {
		Connection connection = null;
		PreparedStatement ps = null;
		int result = 0;

		try {
			Class.forName("com.mysql.cj.jdbc.Driver");
			connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/jdbc_demo", "root", "12345");
			ps = connection.prepareStatement("DELETE FROM book WHERE (`bookcode` = ?);");
			ps.setInt(1, Integer.valueOf(book.getBookcode()));
			result = ps.executeUpdate();

			ps.close();
			connection.close();

			// Redirect the response to success page
			return "redirect:/books2";
		} // End of try block
		catch (Exception e) {
			e.printStackTrace();
		}
		return "error";
	}
	
	
	
	public String check(Book book) {
	    Connection connection = null;
	    Statement statement = null;
	    ResultSet resultSet = null;
	    List<Book> books = new ArrayList<Book>();
	    try {
	        Class.forName("com.mysql.cj.jdbc.Driver");
	        connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/jdbc_demo", "root", "12345");
	        statement = connection.createStatement();
	        resultSet = statement.executeQuery("select * from book");
	        while (resultSet.next()) {
	            int bookcode = resultSet.getInt(1);
	            String title = resultSet.getString(2);
	            String author = resultSet.getString(3);
	            String category = resultSet.getString(4);
	            int approved = resultSet.getInt(5);
	            books.add(new Book(bookcode, title, author, category, approved == 0 ? false : true));
	        }
	    } catch (Exception e) {
	    }
	    for(Book b: books) {
	    	if(b.getTitle().toLowerCase().equals(book.getTitle().toLowerCase()) 
	    			&& b.getAuthor().toLowerCase().equals(book.getAuthor().toLowerCase())
	    			&& b.getBookcode() != book.getBookcode()) {
	    		return "existed";
	    	}
	    }
	    if(book.getTitle().equals("") || book.getAuthor().equals("")) {
	    	return "nullError";
	    }
	    return "noError";
	}
}
