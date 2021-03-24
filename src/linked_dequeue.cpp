#include "linked_dequeue.hpp"

#include <stdexcept>  // logic_error

namespace itis {

void LinkedDequeue::Enqueue(Element e) {
  // TODO: напишите здесь свой код ...
  auto node = new DoublyNode(e, nullptr, back_);
  if(size_ == 0){
      front_ = node;
  }
  else{
      back_->previous = node;
  }
  back_ = node;
  size_++;
}

void LinkedDequeue::EnqueueFront(Element e) {
  // TODO: напишите здесь свой код ...
    auto node = new DoublyNode(e, front_, nullptr);
    if(size_ == 0){
        back_ = node;
    }
    else{
        front_->next = node;
    }
    front_ = node;
    size_++;
}

void LinkedDequeue::Dequeue() {
  if (size_ == 0) {
    throw std::logic_error("cannot not dequeue from empty queue");
  }

  // TODO: напишите здесь свой код ...
  if(size_ == 1){
      delete front_;
      back_ = nullptr;
      front_ = nullptr;
  }
  else{
      front_ = front_->previous;
      delete front_->next;
  }
  size_--;
}

void LinkedDequeue::DequeueBack() {
  if (size_ == 0) {
    throw std::logic_error("cannot not dequeue from empty queue");
  }

  // TODO: напишите здесь свой код ...
    if(size_ == 1){
        delete back_;
        back_ = nullptr;
        front_ = nullptr;
    }
    else{
        back_ = back_->next;
        delete back_->previous;
    }
    size_--;
}

void LinkedDequeue::Clear() {
  // TODO: напишите здесь свой код ...
  while(size_ != 0){
      DequeueBack();
  }
}

// === РЕАЛИЗОВАНО ===

LinkedDequeue::~LinkedDequeue() {
  Clear();
}

std::optional<Element> LinkedDequeue::front() const {
  return front_ == nullptr ? std::nullopt : std::make_optional(front_->data);
}

std::optional<Element> LinkedDequeue::back() const {
  return back_ == nullptr ? std::nullopt : std::make_optional(back_->data);
}

bool LinkedDequeue::IsEmpty() const {
  return size_ == 0;
}

int LinkedDequeue::size() const {
  return size_;
}

// === НЕОБХОДИМО ДЛЯ ТЕСТИРОВАНИЯ ===

std::ostream &operator<<(std::ostream &os, const LinkedDequeue &queue) {
  os << "size: " << queue.size_ << '\n';
  for (auto current_node = queue.front_; current_node != nullptr; current_node = current_node->previous) {
    if (current_node == queue.front_) os << "[FRONT] ";
    if (current_node == queue.back_) os << "[BACK] ";
    os << enum2str(current_node->data) << '\n';
  }
  return os;
}

}  // namespace itis
