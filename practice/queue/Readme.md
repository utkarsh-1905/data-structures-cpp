# Queue

- Can be made using array/linked list/stack
- Data inserted at the end
- Data leaving from the front
- Queue is FIFO

### Operations

- Enqueue = push
    - check if queue is filled
        - if yes, produce overflow error and exit
        - if not, increment rear pointer by 1
    - Add element to the location pointed by rear pointer
    - return
- Dequeue = pop
    - check if the queue is empty
        - if yes, produce an underflow error and exit
        - if not, access the element pointed by the front pointer
    - Delete the element pointed by the front pointer
    - return
- isEmpty
    - return front == rear || front > rear ? true : false
- isFull
    - return MAXSIZE == rear ? true : else
- peek
    - return queue[first]

## Priority Queue

- Every element in the queue has a priority associated with it and gets served based on this priority.
- Enqueue the elements based on first-come-first-serve basis, if the elements are filled in based on the priority. ??
