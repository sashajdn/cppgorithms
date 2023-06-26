#pragma once

#include <iostream>
#include <string>

class Node
{
public:
    Node(float value) : m_Value(value) {
        m_ID = ""; // TODO: not sure if this is entirely correct just yet.
    }

    Node(float value, std::string& id) : m_Value(value), m_ID(id) {}

    Node() {
        m_Value = 0.0f;
        m_ID = "";
    }

    float GetValue() const
    {
        return m_Value;
    }

    std::string GetID() const
    {
        return m_ID;
    }

    Node operator+(Node other) const
    {
        Node n(m_Value + other.m_Value);
        return n;
    }

    Node operator-(Node other) const
    {
        Node n(m_Value + (-1 * other.m_Value));
        return n;
    }

    Node operator*(Node other) const
    {
        Node n(m_Value * other.m_Value);
        return n;
    }

    Node operator/(Node other) const
    {
        // TODO: check for zero div.
        Node n(m_Value / other.m_Value);
        return n;
    }

    // TODO: Add pow & exp
private:
    float m_Value;
    std::string m_ID;
};

std::ostream& operator<<(std::ostream& stream, Node n)
{
    std::cout << n.GetID() << ": " << n.GetValue();
    return stream;
}
