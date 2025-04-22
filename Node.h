#ifndef NODE_H
#define NODE_H

namespace matrices {

    class Node {
    private:
        double* arr;
        int name;
        Node* next;

    public:
        Node(double* value, int name); // קונסטרקטור עם שם
        ~Node();

        int getname() const;
        double* getarr() const;
        void setarr(double* value);
        
        Node* getnext() const;
        void setnext(Node* nextNode);

        Node* goTo(int index); // שינוי שם כי goto זה מילה שמורה
        double* get(int index);

        void set(double* value);

        void set(int nodeindex, int arrindex, double value);
        double getvalinarr(int nodeindex, int arrindex);
    };

} // namespace matrices

#endif // NODE_H
