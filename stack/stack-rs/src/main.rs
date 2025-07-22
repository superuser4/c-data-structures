#[derive(Debug)]
struct Stack<T> {
    list: Vec<T>, 
}

impl<T> Stack<T> {
   fn new() -> Stack<T> {
       Stack { 
           list: Vec::new(),
       }
   } 
   fn push(&mut self, data: T) {
       self.list.push(data);
   }
   fn pop(&mut self) -> Option<T> {
      self.list.pop()
   }
   fn top(&self) -> Option<&T> {
       self.list.last()
   }
   fn is_empty(&self) -> bool {
       self.list.is_empty()
   }
   fn size(&self) -> usize {
       self.list.len()
   }
}

fn main() {
    let mut stack: Stack<i32> = Stack::new();
    stack.push(10);
    stack.push(11);
    stack.push(12);
    println!("Peek: {:?}", stack.top());
    stack.pop();
    println!("Stack: {:?}", stack);
    println!("Is empty?: {:?}", stack.is_empty());
    println!("Size: {:?}", stack.size());
}
