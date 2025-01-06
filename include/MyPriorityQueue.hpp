#ifndef _PRIORITY_QUEUE_HPP
#define _PRIORITY_QUEUE_HPP

#include <stdexcept>
#include <vector>
using namespace std;

class PriorityQueueEmptyException : public std::runtime_error {
public:
  PriorityQueueEmptyException(const std::string &err) : std::runtime_error(err) {}
};

template <typename Object> 
class MyPriorityQueue {
  private:
    vector < Object > queue;

  public:
    // You also need a constructor and a destructor.
    MyPriorityQueue();
    ~MyPriorityQueue();

    size_t size() const noexcept;
    bool isEmpty() const noexcept;

    void insert(const Object &elem);

    // Note:  no non-const version of this one.  This is on purpose because
    // the interior contents should not be able to be modified due to the
    // heap property.  This isn't true of all priority queues but
    // for this project, we will do this.
    // min and extractMin should throw PriorityQueueEmptyException if the queue is
    // empty.
    const Object &min() const;

    void extractMin();
};

template <typename Object> MyPriorityQueue<Object>::MyPriorityQueue() 
{}

template <typename Object> MyPriorityQueue<Object>::~MyPriorityQueue()
{}

template <typename Object>
size_t MyPriorityQueue<Object>::size() const noexcept
{
  return queue.size();
}

template <typename Object>
bool MyPriorityQueue<Object>::isEmpty() const noexcept
{
  return queue.empty();
}

template <typename Object>
void MyPriorityQueue<Object>::insert(const Object &elem)
{
  if (isEmpty()) {
    queue.push_back(elem);
    return;
  }
  queue.push_back(elem);
  long unsigned int inserted_index = queue.size() - 1;
  long unsigned int parent_index = (inserted_index - 1) / 2;
  while (parent_index < queue.size()) {
    if (queue[inserted_index] < queue[parent_index]) {
      swap(queue[parent_index], queue[inserted_index]);
      inserted_index = parent_index;
    } else {
      break;
    }
    parent_index = (inserted_index - 1) / 2;
  }
}

template <typename Object> const Object &MyPriorityQueue<Object>::min() const
{
  if (isEmpty()) {
    throw PriorityQueueEmptyException("Queue empty");
  }
  return queue[0];
}

template <typename Object> void MyPriorityQueue<Object>::extractMin()
{
  if (isEmpty()) {
    throw PriorityQueueEmptyException("Queue empty");
  }
  swap(queue[0], queue[queue.size() - 1]);
  queue.pop_back();
  int moving_index = 0;
  long unsigned int left_index = 2 * moving_index + 1;
  long unsigned int right_index = 2 * moving_index + 2;
  while (left_index < queue.size() || right_index < queue.size()) {
    int smallest_of_fam = moving_index;
    if (left_index < queue.size() && queue[left_index] < queue[smallest_of_fam]) {
      smallest_of_fam = left_index;
    }
    if (right_index < queue.size() && queue[right_index] < queue[smallest_of_fam]) {
      smallest_of_fam = right_index;
    }
    if (smallest_of_fam == moving_index) {
      break;
    }
    swap(queue[moving_index], queue[smallest_of_fam]);
    moving_index = smallest_of_fam;
    left_index = 2 * moving_index + 1;
    right_index = 2 * moving_index + 2;
  }
}

#endif
