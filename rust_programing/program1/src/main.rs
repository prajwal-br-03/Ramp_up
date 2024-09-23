use std::io;
use std::vec::Vec;

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

    fn update_book_quantity(&mut self, new_quant: i32) { 
        self.quantity = new_quant;
    }
}
fn main() {
    let mut Book = vec![Books{id:13,title:String::from("Pride and prejudice"),author:String::from("jane austen"),quantity:12}];
    let mut cont:bool = true;
    while cont {
    println!("Select an option:");
    println!("Enter 1 to add new book");
    println!("Enter 2 to show all the books");
    println!("Enter 3 to update a book quantity");
    println!("Press 4 to exit menu");
    
    let mut choice = String::new();
    io::stdin().read_line(&mut choice).unwrap();
    let a:i32 = choice.trim().parse().unwrap();
    if a == 1{
        println!("Enter the id of the book");
        let mut b = String::new();
        io::stdin().read_line(&mut b).unwrap();
        let ids:i32 = b.trim().parse().unwrap();
        println!("Enter the title of the book");
        let mut lin = String::new();
        let titles = std::io::stdin().read_line(&mut lin).unwrap();
        println!("Enter the author of the book");
        let mut lins = String::new();
        let authors = std::io::stdin().read_line(&mut lin).unwrap();
        println!("Enter the quantity of the books");
        let mut c = String::new();
        io::stdin().read_line(&mut c).unwrap();
        let quant:i32 = c.trim().parse().unwrap();
        Book.push(Books::new(ids,lin,lins,quant));
    }
    else if a == 2{
        for boo in Book.iter(){
            boo.show_books();
        }
    }
    else if a == 3{
        println!("Enter the book id you want to update quantity");
        let mut e = String::new();
        io::stdin().read_line(&mut e).unwrap();
        let upid = e.trim().parse().unwrap();
        for bo in Book.iter_mut(){
            if bo.id == upid {
        
                println!("Enter the value you want to update");
                let mut d = String::new();
                io::stdin().read_line(&mut d).unwrap();
                let upquan = d.trim().parse().unwrap();
                bo.update_book_quantity(upquan);


            }
        }

        
    }
    else if a == 4{
        cont = false;
    }
    else{
        println!("Invalid option");
    }
    }
    
}
