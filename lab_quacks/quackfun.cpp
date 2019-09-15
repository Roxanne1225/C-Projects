/**
 * @file quackfun.cpp
 * This is where you will implement the required functions for the
 * stacks and queues portion of the lab.
 */

namespace QuackFun {

/**
 * Sums items in a stack.
 *
 * **Hint**: think recursively!
 *
 * @note You may modify the stack as long as you restore it to its original
 * values.
 *
 * @note You may use only two local variables of type T in your function.
 * Note that this function is templatized on the stack's type, so stacks of
 * objects overloading the + operator can be summed.
 *
 * @note We are using the Standard Template Library (STL) stack in this
 * problem. Its pop function works a bit differently from the stack we
 * built. Try searching for "stl stack" to learn how to use it.
 *
 * @param s A stack holding values to sum.
 * @return  The sum of all the elements in the stack, leaving the original
 *          stack in the same state (unchanged).
 */
template <typename T>
T sum(stack<T>& s)
{
  //base case
  if (s.empty()) {
    return T();
  }
  T first = s.top();
  T sumofall = s.top();
  //remove one
  s.pop();

  //sum is the top value plus whatever that is left
  //delete sumofall;
  sumofall +=  sum(s);
  //push back
  s.push(first);
//s.push(first);

//delete sumofall;
//delete first;
  return sumofall;
  //delete sumofall;


    // Your code here
  //  return T(); // stub return value (0 for primitive types). Change this!
                // Note: T() is the default value for objects, and 0 for
                // primitive types
}

/**
 * Checks whether the given string (stored in a queue) has balanced brackets.
 * A string will consist of square bracket characters, [, ], and other
 * characters. This function will return true if and only if the square bracket
 * characters in the given string are balanced. For this to be true, all
 * brackets must be matched up correctly, with no extra, hanging, or unmatched
 * brackets. For example, the string "[hello][]" is balanced, "[[][[]a]]" is
 * balanced, "[]]" is unbalanced, "][" is unbalanced, and "))))[cs225]" is
 * balanced.
 *
 * For this function, you may only create a single local variable of type
 * `stack<char>`! No other stack or queue local objects may be declared. Note
 * that you may still declare and use other local variables of primitive types.
 *
 * @param input The queue representation of a string to check for balanced brackets in
 * @return      Whether the input string had balanced brackets
 */
bool isBalanced(queue<char> input)
{
  int numleft = 0;
  int numright = 0;
    stack<char> toput;
//create a slack with all elements of input reversed
    // for(int i = 0; i < input.size(); i ++) {
    //   char front = input.front();
    //   input.pop();
    //   toput.push(front);
    //   //pop and then push takes the element to the back
    //   input.push(front);
    // }
    // while (!input.empty()) {
    //   char fromback = toput.top();
    //   char fromfront = input.front();
    //   if (fromback != '[' || fromback != ']') {
    //     toput.pop();
    //     continue;
    //   } else {
    //     if (fromback == '[') {
    //       while
    //     }
    //   }
    // }

    while (!input.empty()) {
    char front = input.front();
    if (front == '[') {
      numleft ++;
    }
    if (front == ']') {
      numright++;
    }
    if (numright > numleft) {
      return false;
    }
    input.pop();
    toput.push(front);
  }
    // @TODO: Make less optimistic
    return numleft==numright;

}

/**
 * Reverses even sized blocks of items in the queue. Blocks start at size
 * one and increase for each subsequent block.
 *
 * **Hint**: You'll want to make a local stack variable.
 *
 * @note Any "leftover" numbers should be handled as if their block was
 * complete.
 *
 * @note We are using the Standard Template Library (STL) queue in this
 * problem. Its pop function works a bit differently from the stack we
 * built. Try searching for "stl stack" to learn how to use it.
 *
 * @param q A queue of items to be scrambled
 */
template <typename T>
void scramble(queue<T>& q)
{
    stack<T> s;
     //optional: queue<T> q2;

    // Your code here
    //TWO
    //unsigned long originalsize = q.size();
    queue<T> q2;
    int count = 2;
    //unsigned long wentthroughcount = 3;
    int front = q.front();
    q2.push(front);
    q.pop();
    while (!q.empty()) {
    //  std::cout << "not empty" << std::endl;
      if (count%2 == 0) {
        std::cout << "even" << std::endl;
        //std::cout << "5" << std::endl;

      for (int x = 0; x < count; x++) {
        if (q.empty()){
             std::cout << "break" << std::endl;
          break;
        }
          std::cout << "here" << std::endl;
          int popped = q.front();
          q.pop();
          s.push(popped);
          std::cout << popped << std::endl;
        }
          //continue;
        while(!s.empty()){
            std::cout << "while" << std::endl;
        int stop = s.top();
        q2.push(stop);
      //  std::cout << q2.front() << std::endl;
        s.pop();
      }

    count++;
    continue;
    }else {
        std::cout << "else" << std::endl;
    //  while (!q.empty()){
        for (int x = 0; x < count; x++){
          if (q.empty()) {
            break;
          }
        int popped = q.front();
        q.pop();
        q2.push(popped);
    //  }
      // count++;
      // continue;
    }
      }
      // if (!s.empty()) {
      //   while(!s.empty()){
      //   int stop = s.top();
      //   q2.push(stop);
      //   s.pop();
      // }
      std::cout << "+count" << std::endl;
      count++;
    }
    while(!q2.empty()) {
      //std::cout << "copy back" << std::endl;
      int twofront = q2.front();
      q.push(twofront);
      q2.pop();
    }



    //one
    // queue<T> q2;
    // int count = 2;
    // unsigned long wentthroughcount = 0;
    // int front = q.front();
    // q2.push(front);
    // q.pop();
    // for(; wentthroughcount < q.size(); wentthroughcount+=count) {
    //   for (int x = 0; x < count; x++) {
    //     if (count%2 == 0) {
    //       int popped = q.front();
    //       q.pop();
    //       s.push(popped);
    //       //continue;
    //     } else {
    //       int popped = q.front();
    //       q.pop();
    //       q2.push(popped);
    //     }
    //   }
    //   if (!s.empty()) {
    //     while(!s.empty()){
    //     int stop = s.top();
    //     q2.push(stop);
    //     s.pop();
    //   }
    //   }
    //   count++;
    // }
}

/**
 * Checks if the parameter stack and queue are the same. A stack and a queue
 * are considered to the "the same" if they contain only elements of exactly
 * the same values in exactly the same order.
 *
 * @note You may assume the stack and queue contain the same number of items!
 *
 * @note The back of the queue corresponds to the top of the stack!
 *
 * @note There are restrictions for writing this function.
 * - Your function may not use any loops
 * - In your function you may only declare ONE local boolean variable to use in
 *   your return statement, and you may only declare TWO local variables of
 *   parametrized type T to use however you wish.
 * - No other local variables can be used.
 * - After execution of verifySame, the stack and queue must be unchanged. Be
 *   sure to comment your code VERY well.
 *
 * @param s The stack to compare
 * @param q The queue to compare
 * @return  true if the stack and the queue are the same; false otherwise
 */
template <typename T>
bool verifySame(stack<T>& s, queue<T>& q)
{
    //bool retval = true; // optional
    // T temp1; // rename me
    // T temp2; // rename :)

    // Your code here

    bool retval = true; // optional
     T stop; // rename me
     T qfront; // rename :)
     //base case
     if (s.empty()){
       std::cout << "empty" << std::endl;
       return true;
     }
    // if (s.)
     //retval = verifySame(s, q);
     stop = s.top();
     std::cout << s.top() << std::endl;
     s.pop();
     retval = verifySame(s, q);
     s.push(stop);
     qfront = q.front();
     q.pop();
     q.push(qfront);
     if(qfront != stop) {
       return false;
     }

    return retval;
     //return retval;
}

}
