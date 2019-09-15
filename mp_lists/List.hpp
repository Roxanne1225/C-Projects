/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */

template <class T>
List<T>::List() {
  // @TODO: graded in MP3.1
    ListNode* head_ = NULL;
    ListNode* tail_ = NULL;
    // ListNode* next = NULL;
    // ListNode* prev = NULL;
    length_ = 0;
    // const T data = 0;


}

/**
 * Returns a ListIterator with a position at the beginning of
 * the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::begin() const {
  // @TODO: graded in MP3.1
  //return List<T>::ListIterator(NULL);
  return List<T>::ListIterator(head_);
}

/**
 * Returns a ListIterator one past the end of the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::end() const {
  // @TODO: graded in MP3.1
  //return List<T>::ListIterator(NULL)
  //  ListIterator pos = new ListIterator(tail_->next);
  return List<T>::ListIterator(tail_->next);
}


/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <typename T>
void List<T>::_destroy() {
  /// @todo Graded in MP3.1
  //delete[] head_;
  if (length_ != 0) {
    ListNode *current = head_;
ListNode *temp = NULL;
    while (current->next!= NULL) {
      temp = current;
      current = current->next;
      delete temp;
    }
    delete current;

  }
  head_ = NULL;
  tail_ = NULL;
  length_ = 0;

}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
 //insert front passed
template <typename T>
void List<T>::insertFront(T const & ndata) {
//   /// @todo Graded in MP3.1
  // ListNode * newNode = new ListNode(ndata);
  // newNode -> next = head_;
  // newNode -> prev = NULL;
  //
  // if (head_ != NULL) {
  //   head_ -> prev = newNode;
  // }
  // if (tail_ == NULL) {
  //   tail_ = newNode;
  // }
  ListNode * newNode = new ListNode(ndata);
  //ListNode * newNode = temp;
  if (length_ == 0) {

    head_ = newNode;
    tail_ = newNode;
    length_++;
    newNode = NULL;
    //delete newNode;
    return;
  }

  if (head_ != NULL) {
  //  std::cout<<head_->data<<std::endl;
      //std::cout<<"not NULL"<<std::endl;
        head_ -> prev = newNode;
    newNode -> next = head_;
      // std::cout<<"!"<<std::endl;

  //  std::cout<<head_->data<<std::endl;
    //   std::cout<<"@"<<std::endl;
    head_ = newNode;
      // std::cout<<"^"<<std::endl;
       newNode->prev = NULL;
  }
  // if (head_ == NULL) {
  //   head_ = newNode;
  // }


  length_++;
  //delete newNode;
newNode = NULL;
//delete newNode;

}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertBack(const T & ndata) {
  /// @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata);
  //ListNode * newNode = temp;
  //newNode -> next = head_;
  newNode -> next = NULL;
  newNode->prev = NULL;
  //  std::cout<<newNode->data<<std::endl;

if (length_ == 0) {
  //  std::cout<<"sethead"<<std::endl;
  head_ = newNode;
  tail_ = newNode;
  length_++;
  newNode = NULL;
  return;
}
  //if (tail_ != NULL) {
    //  std::cout<<head_->data<<std::endl;
        tail_ -> next = newNode;
    newNode -> prev = tail_;
  //  std::cout<<tail_->next<<std::endl;
    //std::cout<<"after"<<std::endl;
  //  if (tail_ -> next == NULL ) {

    //tail_ -> next = newNode;
    tail_ = newNode;
    //  std::cout<<"tail = new"<<std::endl;
  //  newNode->next = NULL;
  //  std::cout<<"after next"<<std::endl;
  //  std::cout<<tail_->data<<std::endl;
    //head_ -> prev = newNode;
  //}
//}
  // if (tail_ == NULL) {
  //   std::cout<<"here?"<<std::endl;
  //   tail_ = newNode;
  // }

//std::cout<<"+length"<<std::endl;
  length_++;
//newNode = NULL;
//delete newNode;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List or ListNode objects!
 *
 * This function is also called by the public split() function located in
 * List-given.hpp
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <typename T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {
  /// @todo Graded in MP3.1
  // ListNode * curr = start;
  //
  // for (int i = 0; i < splitPoint || curr != NULL; i++) {
  //   curr = curr->next;
  // }
  //
  // if (curr != NULL) {
  //     curr->prev->next = NULL;
  //     curr->prev = NULL;
  // }
  //
  // return NULL;
  if (splitPoint == 0) {
    return start;
  }
  if (splitPoint >= length_) {
    return NULL;
  }
  ListNode * curr = start;
  if (start == NULL) {
    return NULL;
  }

  for (int i = 0; i < splitPoint && curr->next != NULL; i++) {
    curr = curr->next;
  }

  if (curr != NULL) {
      curr->prev->next = NULL;
      curr->prev = NULL;
  }
  //delete[] curr;
  return curr;
}

/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <typename T>
void List<T>::waterfall() {
  /// @todo Graded in MP3.1
  if (head_ == NULL ) {
    return;
  }
  if (head_->next == NULL) {
    return;
  }
  ListNode *current = head_->next;
  ListNode *temp = current->next;
  int count = 0;

  while (current != NULL && current != tail_) {
    temp = current->next;
    if (count % 2 == 0) {
      ListNode *newTail = current;
      current->next->prev = current->prev;
      current->prev->next = current->next;
      //current = current->next;
      tail_->next = newTail;
     newTail->next = NULL;
      newTail->prev = tail_;
      tail_ = newTail;
      //tail_->next = NULL;
    } //else {current = current->next;}
    current = temp;
    count++;
  }


}

/**
 * Reverses the current List.
 */
template <typename T>
void List<T>::reverse() {
  reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <typename T>
void List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {
//  std::cout<<"in here"<<std::endl;
  /// @todo Graded in MP3.2
   ListNode *temp = NULL;
  ListNode *current = startPoint;
  ListNode *beforeStart = startPoint->prev;
  ListNode *afterEnd = endPoint->next;
    ListNode *tempend = endPoint;
    ListNode *tempstart = startPoint;
  //endPoint->prev = Star

  // endPoint ->next = endPoint->next;
  //  while (current !=  NULL && current != beforeStart){
  if (length_== 0) {
    return;
  }
  if (startPoint == endPoint) {
    return;
  }
  while (current!= endPoint){
      temp = current->prev;
      current->prev = current->next;
      //current->pr
      current->next = temp;
      //endPoint = current->prev;
      current = current->prev;
    }
    // if(temp != NULL ) {
    //    startPoint = temp->prev;
    //  }
    ListNode *pr = current->prev;
    current->prev = beforeStart;
    current->next = pr;

     endPoint = tempstart;
     endPoint->next = afterEnd;
     startPoint = current;

     if(beforeStart == NULL){
		head_ = startPoint;
  } else {
		beforeStart->next = startPoint;
  }
	if(afterEnd == NULL) {
		tail_ = endPoint;
  } else{
		afterEnd->prev = endPoint;
  }

  // ListNode *head = startPoint;
  // ListNode *currentmove = startPoint;
  // ListNode *current = startPoint;
  // ListNode *beforeStart = startPoint->prev;
 //  while (current != endPoint->next && current->next != NULL) {
 //    if (current == head_) {
 //      if (head_->next != NULL) {
 //      head_->prev = head_->next;
 //    }
 //      if (endPoint->next != NULL) {
 //      head_->next = endPoint->next;
 //    }
 //
 //   }
 // }
    // if (currentmove == endPoint) {
    //
    // }
  //   curentmove = currentmove->next;
  //   current ->next = current->prev;
  //   current->prev = currentmove;
  //   current = currentmove;
  // }
  // startPoint = currentmove;
  // endPoint = head;


}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <typename T>
void List<T>::reverseNth(int n) {
  /// @todo Graded in MP3.2
  if (head_ == NULL) {
    return;
  } else {
  ListNode *current = head_;
  //ListNode *newhead = head_;
  ListNode *toend = head_;
//  std::cout<<"head_"<<std::endl;
  while (toend->next != NULL && current->next != NULL) {
    //std::cout<<"in while"<<std::endl;
    //ListNode *toend = current;
    toend = current;
    for (int i = 0; i < n-1; i++) {
    //  std::cout<<"in for"<<std::endl;
      if (toend->next != NULL) {
      toend = toend->next;
    }
    }
    //if (toend != tail_ && toend != NULL) {
     reverse(current, toend);
   //}
    // std::cout<<"out"<<std::endl;
     //break;
   //   if (toend->next != NULL) {
   //      toend->prev = current;
      current = toend ->next;
    }
   //
   // } else {
   //   return;
   // }
    // std::cout<<"end while"<<std::endl;
 }
 }



/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <typename T>
void List<T>::mergeWith(List<T> & otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <typename T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode* second) {
  /// @todo Graded in MP3.2
  if (first == NULL && second == NULL) {

    std::cout<<"both null"<<std::endl;
    return NULL;
  }
  if (first == NULL && second != NULL) {
    std::cout<<"second"<<std::endl;
    return second;
  }
  if (second == NULL && first != NULL) {
    std::cout<<"first"<<std::endl;
    return first;
  }
  ListNode * firsthead = first;
  ListNode * secondHead = second;

  ListNode *currfirst = first;
  ListNode *currsecond = second;

  ListNode *toret = first;
  ListNode *currtoret = NULL;
  if (first->data < second->data) {
    toret = first;
    currfirst = currfirst->next;
  //  currfirst->prev = toret;
    //currtoret = toret;
  } else {
  //if (&first->data > &second ->data) {
    toret = second;
    currsecond = currsecond->next;
  //  currsecond->prev = toret;
  //  currtoret = toret;
 }

currtoret = toret;
  while (currfirst != NULL && currsecond != NULL) {
    //use < dont use >
    if (currfirst->data < currsecond->data) {
      currtoret->next = currfirst;
      currfirst->prev = currtoret;
      currtoret = currtoret->next;
      currfirst = currfirst->next;
    } else {

      currtoret->next = currsecond;
      currsecond->prev = currtoret;
      currtoret = currtoret->next;
      currsecond = currsecond->next;
    }
  }
  if (currfirst == NULL) {
    if (currsecond != NULL) {
      currtoret -> next = currsecond;
      currsecond->prev = currtoret;
    }
  } else {
  if (currsecond == NULL) {
    if (currfirst != NULL) {
      currtoret->next = currfirst;
      currfirst->prev = currtoret;
    }
  }
}

  return toret;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * Called by the public sort function in List-given.hpp
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <typename T>
typename List<T>::ListNode* List<T>::mergesort(ListNode * start, int chainLength) {
  /// @todo Graded in MP3.2
  //base case
  //  typename List<T>::ListNode* ret;
  if (chainLength == 1) {
    return start;
  }
  // if (chainLength == 2) {
  //   return merge(start, start->next);
  // }
  else {
    ListNode *tempstart = start;
    for (int i = 0; i < chainLength/2; i++) {
    //  std::cout<<"in for"<<std::endl;
      start = start->next;
    }
    //separate the two lists!!
    start->prev->next = NULL;
		start->prev = NULL;
    typename List<T>::ListNode* firsthalf = mergesort(tempstart, chainLength/2);
  //  std::cout<<"set first"<<std::endl;
  //  std::cout<<chainLength/2<<std::endl;
    typename List<T>::ListNode* secondhalf = mergesort(start, chainLength-chainLength/2);
  return merge(firsthalf, secondhalf);
  // if (chainLength == 2) {
  //   return merge(start, start->next);
  // }
  }
  //  typename List<T>::ListNode* ret;

}
