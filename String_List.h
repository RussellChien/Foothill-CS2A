// Student ID: 20393765
// String_List.h

#ifndef String_List_h
#define String_List_h

#include <iostream>
#include <sstream>

class String_List
{
private:
   struct Node
   {
      std::string data;
      Node* next;
      Node(std::string s = "") : data(s), next(nullptr) {}
   };

   Node* _head, * _tail, *_prev_to_current;
   size_t _size;

public:
   String_List()
   {
      _head = new Node("_SENTINEL_");
      _tail = _head;
      _prev_to_current = _head;
      _size = 0;
   }

   ~String_List()
   {
      clear();
      delete _head;
   }

   String_List* insert_at_current(std::string s)
   {
      Node* oldCurrent = _prev_to_current->next;
      Node* newCurrent = new Node(s);
      _prev_to_current->next = newCurrent;
      newCurrent->next = oldCurrent;
      _size++;
      return this;
   }

   String_List* push_back(std::string s)
   {
      if (_head == nullptr)
      {
         _head = new Node(s);
         return this;
      }
      Node* tmp = new Node(s);
      _tail->next = tmp;
      _tail = tmp;
      _size++;
      return this;
   }

   String_List* push_front(std::string s)
   {
      if (_head == _tail)
      {
         _head->next = new Node(s);
         _tail = _tail->next;
         _size++;
      }
      else
      {
         Node* current = _head->next;
         Node* newNode = new Node(s);
         _head->next = newNode;
         newNode->next = current;
         _size++;
      }
      return this;
   }

   String_List* advance_current()
   {
      if (_prev_to_current == _tail)
         return nullptr;
      else
      {
         _prev_to_current = _prev_to_current->next;
         return this;
      }
   }

   std::string get_current() const
   {
      if (_prev_to_current->next != nullptr)
         return _prev_to_current->next->data;
      else
         return _head->data;
   }

   String_List* remove_at_current()
   {
      Node *current = _prev_to_current->next;
      Node *newCurrent = _prev_to_current->next->next;
      _prev_to_current->next = newCurrent;
      delete current;
      _size--;
      return this;
   }

   size_t get_size() const
   {
      return _size;
   }

   String_List* rewind()
   {
      _prev_to_current = _head;
      return this;
   }

   void clear()
   {
      if (_head == _tail)//list is already empty
      {
         _prev_to_current = _head;
         _size = 0;
         _head->next = nullptr;
         return;
      }
      Node* current = _head->next;
      while (current->next != nullptr)
      {
         Node* nextNode = current->next;
         delete current;//deletes the current node
         current = nextNode;//current then points to the next node in the list which will be deleted in the next iteration
      }
      delete current;//last node in list
      _prev_to_current = _head;
      _tail = _head;
      _size = 0;
      _head->next = nullptr;
   }

   std::string& find_item(std::string s) const 
   {       
      Node *current = _head;
      if (current->data == s)
         return current->data;
      while (current->next != nullptr)
      {
         current = current->next;
         if (current->data == s)
            return current->data;
      }

      //if the string is not found
      return _head->data;
   }

   std::string to_string() const 
   {      
      std::string returnStr = "# String-List - " + std::to_string(get_size()) + " entries total. Starting at cursor:\n";
      Node* tmp = _prev_to_current;
      if (get_size() > 25)
      {
         for (int i = 0; i < 25; i++)
         {
            returnStr += tmp->data + "\n";
            if (tmp->next == nullptr)
               return returnStr;
            else
               tmp = tmp->next;
         }
         returnStr += "...";
         return returnStr;
      }
      else
      {
         for (size_t i = 0; i < get_size(); i++)
         {
            returnStr += tmp->data + "\n";
            if (tmp->next == nullptr)
               return returnStr;
            else
               tmp = tmp->next;
         }
         return returnStr;
      }
   }


   friend class Tests; // Don't remove this line
};


#endif // !String_List_h