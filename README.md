# queue
Simple queue module
![GitHub branch status](https://img.shields.io/github/checks-status/DuncanTestTask/queue/main)

A trivial queue that only does that it needs with unit tests.

# Purpose 
Make a test task

# key points

- Pure C code
- Minimal dependency
- Fully functional code


#  concept

Queue is FIFO stream with fixed size and used int as item datatype, it is imply that queue is used sequentially.

Implemented as circular buffer, fixed size array with head and tail indexes.

`count` and `max` fields can indicated usage and capacity queue.

There are functions to allocate `queue_init` and release `queue_free` memory for the queue.

There are functions to add element `queue_add` and get element `queue_get` from the queue.

Error processing is implemented by keeping error code of last operation in queue structure.

Also, there verbose debug output can be activated in DEBUG BUILD. `make clean testing DEBUG=1`

Build process automated by `Makefile`

