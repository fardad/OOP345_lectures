#ifndef SICT_QUEUE_H__
#define SICT_QUEUE_H__

class Queue;
class Qnode {
  double m_data;
  Qnode* m_next;
  Qnode* m_prev;
  Qnode(const double& data={}, Qnode* prev = nullptr, Qnode* next = nullptr);
  friend class Queue;
};
class Queue {
  Qnode* m_head = nullptr;
  Qnode* m_tail = nullptr;
  size_t m_size = 0;
  static size_t m_serial;
public:
  Queue();
  Queue(size_t size);
  Queue(size_t size, const double& data);
  Queue(const Queue& Q);
  Queue(Queue&& Q)noexcept;
  ~Queue();
  Queue& operator=(const Queue& Q);
  Queue& operator=(Queue&& Q)noexcept;
  size_t size()const;
  bool empty()const;
  double& operator[](size_t index);
  const double& operator[](size_t index)const;
  double& front();
  const double& front()const;
  double& back();
  const double& back()const;
  void push_back(const double& data); 
  void push_front(const double& data);
  void pop_back();
  void pop_front();
  void clear();
  static size_t serial();
};



#endif
