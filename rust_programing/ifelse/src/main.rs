fn main() {
    let formal = true;
    let greeting = if formal{
        println!("Good afternoon");
    }else {
        println!("HI ")
    };

    loop{
        println!("hello");
        break;
    }
    let mut number = 3;
    while number!= 0{
        println!("{}",number);
        number -= 1;

    }
    println!{"Lift off!!"};
    let a = [10,20,30,40,50];
    for elem in a.iter() {
        println!("the values id : {}",elem);
    }
}
