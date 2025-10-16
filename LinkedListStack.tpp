template <typename T>
LinkedListStack<T>::LinkedListStack()
{ }

template <typename T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedListStack<T>& LinkedListStack<T>::operator=(const LinkedListStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedListStack<T>::~LinkedListStack() {
    clear();
}

template <typename T>
void LinkedListStack<T>::clear() {
    // TO DO: Delete all the elements in the stack
    while (top != nullptr)
    {
        Node<T>* temp = top;
        top = top->next;
        delete temp;
    }
    this->length = 0;
}

template <typename T>
void LinkedListStack<T>::copy(const LinkedListStack<T>& copyObj) {
    if (copyObj.isEmpty()) {
        top = nullptr;
        return;
    }

    Node<T>* src = copyObj.top;
    top = new Node<T>(src->data);
    Node<T>* dest = top;
    src = src->next;

    while (src != nullptr) {
        dest->next = new Node<T>(src->data);
        dest = dest->next;
        src = src->next;
    }
    this->length = copyObj.length;
}

template <typename T>
int LinkedListStack<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedListStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
T LinkedListStack<T>::peek() const {
    // TO DO: implement peek
    if (this->isEmpty()) throw std::string("Can't peek. Stack is empty");
    return top->data;
}

template <typename T>
void LinkedListStack<T>::pop() {
    // TO DO: Implement pop
    if (this->isEmpty()) throw std::string("Can't pop. Stack is empty");
    this->length--;
    Node<T> *temp = this->top;
    this->top = this->top->next;
    delete temp;
}

template <typename T>
void LinkedListStack<T>::push(const T& elem) {
    // TO DO: Implement push
    if (this->length == 0) top = new Node<T>(elem);
    else
    {
        Node<T> * newNode = new Node<T>(elem);
        newNode->next = top;
        top = newNode;
    }
    this->length++;
}

template <typename T>
void LinkedListStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TO DO: Implement rotate
    if (dir == Stack<T>::RIGHT)
    {
        Node<T>* temp = top;

        while (temp->next->next != nullptr)
            temp = temp->next;

        Node<T>* newTop = temp->next;
        temp->next = nullptr;
        newTop->next = top;
        top = newTop;
    }
    else
    {
        Node<T>* newBottom = this->top;
        Node<T>* temp = top;
        top = top->next;

        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newBottom;
        newBottom->next = nullptr;
    }
}

template <typename T>
void LinkedListStack<T>::print() {
    cout << "LinkedListStack contents: ";
    if (isEmpty()) {
        cout << "Stack is empty, no elements to display.\n";
    }
    else {
        Node<T> *curr = top;
        while (curr != nullptr){
            cout <<  curr->data  << "\t";
            curr = curr->next;
        }
    }

    cout << endl;
}
