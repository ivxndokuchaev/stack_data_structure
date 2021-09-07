#include <iostream>

class Stack {
    private:
        int *m_stack;
        int m_length;
        int m_clength;

    public:
        Stack(int length = 10) : m_length(length), m_clength(0), m_stack(new int[length])
        {
        }

        bool push(int num) {
            if (m_clength == m_length) {
                std::cout << "Unable to push(). Stack is full.\n";
                return false;
            } else {
                m_clength++;
                *(m_stack + m_clength - 1) = num;
                return true;
            }
        }

        bool pop() {
            if (m_clength == 0) {
                std::cout << "Pop() is meaningless. Stack is empty.\n";
                return false;
            } else {
                *(m_stack + m_clength - 1) = 0;
                m_clength--;
                return true;
            }
        }

        void print() {
            for (int i=0; i<m_clength; ++i) {
                std::cout << *(m_stack + i) << " ";
            }
            std::cout << '\n';
        }

        ~Stack() {
            delete[] m_stack;
        }
};


int main() {
    using namespace std;
    
    Stack stack(5);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.print();

    stack.push(666);

    stack.pop();
    stack.pop();
    stack.print();

    stack.push(666);
    stack.print();

    return 0;
}
