#pragma once

#include "node.hpp"
#include <iostream>

enum Operation { Plus, Minus, Mul, Div };

Operation OperationPlus = Plus;
Operation OperationMinus = Minus;
Operation OperationMul = Mul;
Operation OperationDiv = Div;

class Operator
{
    public:
        // TODO: do not take node, but any interface that provides "Node Forward()".
        Operator(const Node l, const Node r, const Operation op) : m_L(l), m_R(r), m_Operation(op) {}

        Node GetL() const
        {
            return m_L;
        }

        Node GetR() const
        {
            return m_R;
        }

        Node GetOperation() const
        {
            return m_Operation;
        }

        Node Forward()
        {
            switch (m_Operation)
            {
                case Plus:
                    return m_L + m_R;
                case Minus:
                    return m_L - m_R;
                case Div:
                    return m_L / m_R;
                case Mul:
                    return m_L * m_R;
            }

            Node n;
            return n;
        }
    private:
        Node m_L, m_R;
        Operation m_Operation;
};

std::ostream& operator<<(std::ostream& stream, Operation operation)
{
    std::string s;
    switch (operation) {
        case(Plus):
            s = "+";
        case(Mul):
            s = "*";
        case(Minus):
            s = "-";
        case(Div):
            s = "/";
        default:
            s = "unknown";
    }

    std::cout << s;
    return stream;
}

std::ostream& operator<<(std::ostream& stream, Operator op)
{
    std::cout << op.GetL() << " >> " << op.GetOperation() << " << " << op.GetR();
    return stream;
}
