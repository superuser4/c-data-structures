#[derive(Debug)]
struct Queue <T> {
    list: Vec<T>, 
}

impl<T> Queue<T> {
    fn new() -> Queue<T> {
        Queue { 
            list: Vec::new()
        }
    }
    fn enqueue(&mut self, data: T) {
        self.list.push(data);
    }
    fn dequeue(&mut self) -> Option<T> {
        if self.list.is_empty() {
            None
        } else {
            Some(self.list.remove(0))
        }
    }
    fn is_empty(&self) -> bool {
        self.list.is_empty()
    }
    fn top(&self) -> Option<&T> {
       self.list.last() 
    }
    fn bottom(&self) -> Option<&T> {
        self.list.first()
    }
}

fn main() {
    let mut queue: Queue<i32> = Queue::new();
    queue.enqueue(10);
    queue.enqueue(11);
    queue.enqueue(12);
    println!("Queue: {:?}", queue);
    queue.dequeue();
    println!("Queue: {:?}", queue);

    println!("Empty?: {}", queue.is_empty());
    println!("Top: {:?}\n Bottom: {:?}", queue.top(), queue.bottom());
}
