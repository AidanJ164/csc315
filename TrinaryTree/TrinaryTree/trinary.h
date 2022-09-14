#ifndef TRINARY_H
#define TRINARY_H

template <typename Comparable>
class trinary
{
    public:
        trinary()
        {
            node root;
        }
        ~trinary()
        {

        }
    private:
        struct node {
            Node* firstNode;
            Node* secondNode;
            Node* thirdNode;
            Comparable element1;
            Comparable element2;
        };
};
#endif
