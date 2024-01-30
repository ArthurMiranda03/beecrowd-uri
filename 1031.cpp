/*
Beecrowd 1031 - Crise de Energia
Durante uma crise de energia na Nova Zelândia no inverno passado (causada por uma escassez de chuva e, consequentemente, por causa dos níveis baixos nas barragens
hidrográficas), um esquema de contingência foi desenvolvido para desligar a energia para as áreas do país de forma sistemática, de uma forma totalmente justa. 
O país foi dividido em N regiões (Auckland seria a região número 1 e Wellington a número 13). Um número, m, seria escolhido randomicamente e a energia deveria 
ser desligada primeiro na região 1 (claramente o ponto de início mais justo) e então em cada m região após esta, indo de uma a outra região e ignorando as 
regiões já desligadas. Por exemplo, se N = 17 e m = 5, a energia deverá ser desligada em todas as regiões seguindo a seguinte 
ordem: 1,6,11,16,5,12,2,9,17,10,4,15,14,3,8,13,7.

O problema é que, claramente seria mais justo desligar a região de Wellington por último (Isso porque é onde a sede da empresa se encontra). 
Portanto, para um dado N (regiões), o número aleatório m (salto) precisa ser cuidadosamente escolhido de forma que a região 13 seja a última região a 
ser escolhida.

Escreva um programa que leia o número de regiões e determine o menor número m que assegure que Wellington (região 13) possa continuar funcionando enquanto 
o resto do país esteja desligado.

Entrada
A entrada consistirá de uma série de linhas, cada uma contendo o número de regiões N (13 ≤ N ≤ 100 ). O fim da entrada é indicado por uma linha consistindo 
de um valor zero (0).

Saída
A saída consistirá de uma série de linhas, uma linha para cada linha de entrada. Cada linha consistirá de um m de acordo com o esquema acima apresentado.
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

class Node {
private:
    Node* next;
    Node* previous;
    int value;
public:
    Node();
    virtual ~Node();

    Node* getNext();
    Node* getPrevious();
    int getValue();

    void setNext(Node*);
    void setPrevious(Node*);
    void setValue(int);
};

Node::Node() {
    next = NULL;
    previous = NULL;
}

Node::~Node() {}

Node* Node::getNext() {
    return next;
}

Node* Node::getPrevious() {
    return previous;
}

int Node::getValue() {
    return value;
}

void Node::setNext(Node* next) {
    this->next = next;
}

void Node::setPrevious(Node* previous) {
    this->previous = previous;
}

void Node::setValue(int value) {
    this->value = value;
}

class CircularList {
private:
    Node* first;
    Node* last;
    int count;
public:
    CircularList();
    virtual ~CircularList();

    bool isEmpty();
    int length();

    void insert(int, int);
    void remove(int);

    int getValue(int);
    int getPos(int);

    int getNextValue(int);

    int powerCrisis(int);
};

CircularList::CircularList() {
    first = NULL;
    last = NULL;
    count = 0;
}

CircularList::~CircularList() {}

bool CircularList::isEmpty() {
    return count == 0;
}

int CircularList::length() {
    return count;
}

void CircularList::insert(int pos, int value) {
    if(isEmpty() && pos != 1) {
        return;
    }

    if(pos <= 0 || pos > count + 1) {
        return;
    }

    Node* newNode = new Node();
    newNode->setValue(value);

    if(pos == 1) {
        newNode->setNext(first);
        newNode->setPrevious(last);

        if(isEmpty()) {
            last = newNode;
        } else {
            first->setPrevious(newNode);
            last->setNext(newNode);
        }

        first = newNode;
    } else if(pos == length() + 1) {
        newNode->setPrevious(last);
        newNode->setNext(first);
        first->setPrevious(newNode);
        last->setNext(newNode);
        last = newNode;
    } else {
        Node* auxNode = first;

        for(int i = 1; i < pos - 1; i++) {
            auxNode = auxNode->getNext();
        }

        newNode->setPrevious(auxNode);
        newNode->setNext(auxNode->getNext());

        auxNode->getNext()->setPrevious(newNode);
        auxNode->setNext(newNode);
    }

    count++;
}

void CircularList::remove(int pos) {
    if(isEmpty() || pos < 1 || pos > length()) {
        return;
    }

    if(pos == length()) {
        Node* removeNode = last;

        last = removeNode->getPrevious();
        last->setNext(first);
        first->setPrevious(last);

        delete removeNode;
    } else {
        Node* removeNode = first;

        if(pos == 1) {
            first = removeNode->getNext();
            first->setPrevious(last);
            last->setNext(first);
        } else {
            for(int i = 1; i < pos; i++) {
                removeNode = removeNode->getNext();
            }

            removeNode->getPrevious()->setNext(removeNode->getNext());
            removeNode->getNext()->setPrevious(removeNode->getPrevious());
        }

        delete removeNode;
    }

    count--;
}

int CircularList::getValue(int pos) {
    if(isEmpty() || pos < 1 || pos > length()) {
        return -1;
    }

    Node* auxNode;

    if(pos > length() / 2) {
        auxNode = last;

        for(int i = length(); i > pos; i--) {
            auxNode = auxNode->getPrevious();
        }
    } else {
        auxNode = first;

        for(int i = 1; i < pos; i++) {
            auxNode = auxNode->getNext();
        }
    }

    return auxNode->getValue();
}

int CircularList::getPos(int value) {
    if(isEmpty()) {
        return -1;
    }

    Node* auxNode = first;

    for(int i = 1; i <= length(); i++) {
        if(auxNode->getValue() == value) {
            return i;
        }

        auxNode = auxNode->getNext();
    }

    return -1;
}

int CircularList::getNextValue(int pos) {
    if(isEmpty() || pos < 1 || pos > length()) {
        return -1;
    }

    if(pos == length()) {
        return last->getNext()->getValue();
    } else if(pos == 1) {
        return first->getNext()->getValue();
    } else {
        Node* auxNode = first;

        for(int i = 0; i < pos; i++) {
            auxNode = auxNode->getNext();
        }

        return auxNode->getNext()->getValue();
    }

    return -1;
}

int CircularList::powerCrisis(int m) {
    int p = 1;

    while(length() > 1) {
        while(p > length()) {
            p -= length();
        }

        remove(p);
        p += m - 1;
    }

    return first->getValue();
}

int main(int argc, const char * argv[]) {
    int N;

    while(cin >> N && N != 0) {
        CircularList list = CircularList();

        for(int i = 1; i <= N; i++) {
            list.insert(i, i);
        }

        int count = 1;
        while(list.powerCrisis(count) != 13) {
            count++;

            list.remove(1);

            for(int i = 1; i <= N; i++) {
                list.insert(i, i);
            }
        }

        cout << count << endl;
    }

    return 0;
}