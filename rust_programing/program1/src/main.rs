use std::collections::HashSet; // Make sure to include the semicolon

struct Books {
    id: i32,
    title: String,
    author: String,
    quantity: i32,
}

impl Books {
    fn new(id: i32, title: String, author: String, quantity: i32) -> Self {
        Books { id, title, author, quantity }
    }

    fn show_books(&self) {
        println!(
            "id: {}, title: {}, author: {}, quantity: {}",
            self.id, self.title, self.author, self.quantity
        );
    }

    fn update_book_quantity(&mut self, new_quant: i32) { // This should work
        self.quantity = new_quant;
    }
}

fn main() {
    let mut book = Books::new(12, String::from("ssss"), String::from("sssss"), 5);
    book.show_books();
    book.update_book_quantity(34);
    book.show_books(); // Show the updated book details
}
