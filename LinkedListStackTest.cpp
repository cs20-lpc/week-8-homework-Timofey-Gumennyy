#include <iostream>
#include "LinkedListStack.hpp"
#include "ArrayStack.hpp" // assuming you have a similar array-based stack
using namespace std;

int main() {
    cout << "===== TEST 1: Basic integer stack operations =====" << endl;
    LinkedListStack<int> s1;
    cout << "Initially empty? " << boolalpha << s1.isEmpty() << endl;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout << "After pushes: "; s1.print();
    cout << "Top element (peek): " << s1.peek() << endl;
    cout << "Length: " << s1.getLength() << endl;

    s1.pop();
    cout << "After one pop: "; s1.print();
    cout << "Top now: " << s1.peek() << endl;
    cout << "Length now: " << s1.getLength() << endl;

    cout << "Clearing stack..." << endl;
    s1.clear();
    cout << "Empty after clear? " << s1.isEmpty() << endl;
    cout << endl;
    s1.print();

    // ------------------------------------------------------------
    cout << "===== TEST 2: String stack operations =====" << endl;
    LinkedListStack<string> s2;
    s2.push("apple");
    s2.push("banana");
    s2.push("cherry");
    cout << "String stack: "; s2.print();
    cout << "Peek: " << s2.peek() << endl;
    s2.pop();
    cout << "After pop: "; s2.print();
    cout << endl;

    // ------------------------------------------------------------
    cout << "===== TEST 3: Copy constructor and assignment =====" << endl;
    s2.push("date");
    cout << "Original stack (s2): "; s2.print();

    LinkedListStack<string> s3(s2); // copy constructor
    cout << "Copied stack (s3): "; s3.print();

    s3.pop();
    cout << "After modifying s3: "; s3.print();
    cout << "Original remains unchanged: "; s2.print();


    // ------------------------------------------------------------
    cout << "===== TEST 4: Rotate function =====" << endl;
    LinkedListStack<int> s5;
    for (int i = 1; i <= 5; i++)
        s5.push(i);
    cout << "Before rotation: "; s5.print();

    cout << "Rotate left: ";
    s5.rotate(Stack<int>::Direction::LEFT);
    s5.print();

    cout << "Rotate right: ";
    s5.rotate(Stack<int>::Direction::RIGHT);
    s5.print();
    cout << endl;

    // ------------------------------------------------------------
    cout << "===== TEST 5: Comparing ArrayStack vs LinkedListStack =====" << endl;
    ArrayStack<int> a1(10);
    LinkedListStack<int> l1;

    for (int i = 0; i < 5; ++i) {
        a1.push(i * 10);
        l1.push(i * 10);
    }

    cout << "ArrayStack contents: "; a1.print();
    cout << "LinkedListStack contents: "; l1.print();

    cout << "Both top elements: " << a1.peek() << " and " << l1.peek() << endl;
    a1.pop(); l1.pop();
    cout << "After popping both: " << endl;
    cout << "ArrayStack: "; a1.print();
    cout << "LinkedListStack: "; l1.print();
    cout << endl;

    cout << "===== STRESS TEST 6: Exception safety (empty peek/pop) =====" << endl;
    LinkedListStack<char> s7;
    try {
        cout << "Trying to peek empty stack..." << endl;
        cout << s7.peek() << endl;
    } catch (const std::string &e) {
        cout << "Caught exception: " << e << endl;
    }
    try {
        cout << "Trying to pop empty stack..." << endl;
        s7.pop();
    } catch (const std::string &e) {
        cout << "Caught exception: " << e << endl;
    }
    cout << endl;

    //
    cout << "===== ALL TESTS COMPLETE =====" << endl;
    return 0;
}
