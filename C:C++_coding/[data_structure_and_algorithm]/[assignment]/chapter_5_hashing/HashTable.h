#ifndef __Hash_Table__
#define __Hash_Table__

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode Node_Pointer;

struct Node{
    int value;
    PtrToNode next;
};

class ChainHash{
    private :
    int table_size = 10;
    Node_Pointer array[10];

    public :
    ChainHash();
    ~ChainHash();

    void Insert(int value);
    void Print() const;

    int TableSzie() const {return table_size;}
    int ReturnValue(int input) const {return array[input]->value;}
    Node_Pointer ReturnArray(int input) const {return array[input];}
};
class LinearProbingHash{
    private :
    int table_size = 10;
    Node_Pointer array[10];

    public :
    LinearProbingHash();
    ~LinearProbingHash();

    void Insert(int value);
    void Print() const;

    int TableSzie() const {return table_size;}
    int ReturnValue(int input) const {return array[input]->value;}
    Node_Pointer ReturnArray(int input) const {return array[input];}
};
class QuadraticProbingHash{
    private :
    int table_size = 10;
    Node_Pointer array[10];

    public :
    QuadraticProbingHash();
    ~QuadraticProbingHash();

    void Insert(int value);
    void Print() const;

    int TableSzie() const {return table_size;}
    int ReturnValue(int input) const {return array[input]->value;}
    Node_Pointer ReturnArray(int input) const {return array[input];}
};
class DoubleHashing{
    private :
    int table_size = 10;
    Node_Pointer array[10];

    public :
    DoubleHashing();
    ~DoubleHashing();

    void Insert(int value);
    void Print() const;

    int TableSzie() const {return table_size;}
    int ReturnValue(int input) const {return array[input]->value;}
    Node_Pointer ReturnArray(int input) const {return array[input];}
};

class ReHash{
    private :
    int table_size = 19;
    PtrToNode array[19];

    public :
    ReHash(){
        for (int i = 0; i < table_size; i++){
            array[i] = nullptr;
        }
    }
    ~ReHash(){
        for (int i = 0; i < table_size; i++){
            if (array[i]){
                Node_Pointer temp = array[i];
                while (temp){
                    auto temp_1 = temp->next;
                    delete(temp);
                    temp = temp_1;
                }
            }
        }
    }

    void ChainInsert(int input){
        int key = input % table_size;

        if (!array[key]){
            array[key] = new(struct Node);
            array[key]->next = nullptr;
            array[key]->value = input;
            return;
        }

        Node_Pointer temp = array[key];
        while (temp->next){
            temp = temp->next;
        }
        temp->next = new(struct Node);
        temp = temp->next;
        temp->value = input;
        temp->next = nullptr;
        return;
    }
    void LinearInsert(int input){
        int key = input % table_size;

        if (!array[key]){
            array[key] = new(struct Node);
            array[key]->value = input;
            array[key]->next = nullptr;
            return;
        }

        while (true){
            key++;
            key %= table_size;

            if (!array[key]) {break;}
        }
        array[key] = new(struct Node);
        array[key]->value = input;
        array[key]->next = nullptr;
    }
    void QuadraticInsert(int input){
        int key = input % table_size;

        if (!array[key]){
            array[key] = new(struct Node);
            array[key]->value = input;
            array[key]->next = nullptr;
            return;
        }

        for (int i = 0;; i++){
            int temp = (key + i*i) % table_size;
            if (!array[temp]) {key = temp; break;}
        }
        array[key] = new(struct Node);
        array[key]->value = input;
        array[key]->next = nullptr;
    }
    void DoubleInsert(int input){
        int key = input % table_size;

        if (!array[key]){
            array[key] = new(struct Node);
            array[key]->value = input;
            array[key]->next = nullptr;
            return;
        }

        int temp = 7 - (input % 7);
        
        while (true){
            key = (key + temp) % table_size;
            if (!array[key]) {break;}
        }
        array[key] = new(struct Node);
        array[key]->value = input;
        array[key]->next = nullptr;
    }

    void Print() const{
        std::cout << "This is Rehashed table by 19" << std::endl;

        for (int i = 0; i < table_size; i++){
            std::cout << "[" << i << "] : ";
            
            Node_Pointer temp = array[i];
            while (temp){
                std::cout << temp->value << "(" << temp->value % table_size << ") ";
                temp = temp->next;
            }
            std::cout << std::endl;
        } 
    }

    int TableSzie() const {return table_size;}
};

ReHash* ChainReHashing(ChainHash &input);
ReHash* LinearReHashing(LinearProbingHash &input);
ReHash* QuadraticReHashing(QuadraticProbingHash &input);
ReHash* DoubleReHashing(DoubleHashing &input);

#endif