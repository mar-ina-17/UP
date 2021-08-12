#include <iostream>

//A dominoes structure representing the dominoe block
struct Dominoe
{
    size_t firstHalf;
    size_t secondHalf;

    Dominoe& addNewDominoe();
    Dominoe& flipDominoe(); 
    Dominoe& operator=(const Dominoe& other);
    Dominoe& operator*(){return *this;}
};

//adds a new domino based on the user input values for both sides of the block
Dominoe& Dominoe::addNewDominoe()
{
    int firstH = -1, secondH = -1;
    
    while(firstH < 0 || secondH < 0)
    {
        std::cin >> firstH >> secondH;
    }
    
    this->firstHalf = firstH; 
    this->secondHalf = secondH;

    return *this;
}

//flips the domino block 
Dominoe& Dominoe::flipDominoe()
{
    size_t tmp = this->firstHalf;
    this->firstHalf = this->secondHalf;
    this->secondHalf = tmp;

    return *this;
}

Dominoe& Dominoe::operator=(const Dominoe& other)
{
    this->firstHalf = other.firstHalf;
    this->secondHalf = other.secondHalf;
    return *this;
}

//A structure for the collection of dominos
struct Chain
{
    Dominoe* dominos;
    size_t size;

    Chain() : size(0){};
    Chain& createCollectionOfBlocks(size_t size);
    void newChain(size_t size);

    bool chainIsEmpty() const;
    
    void addDominoeToChain(Dominoe& dom);
    void addDominoeAt(size_t index, Dominoe& dom);
    Dominoe& removeDominoeFromChain(size_t index);
    Dominoe& getDominoe(size_t index);

    void printChain();
    void deleteChain();

};

//deletes the dynamic array
void Chain::deleteChain() 
{
    delete[]this->dominos;
}

//creates a newly allocated space for the dynamic array
Chain& Chain::createCollectionOfBlocks(size_t size) 
{
    this->dominos = new Dominoe [size];
    this->size = size;
    if(!this->dominos) 
    {
        std::cout<<"Dominoe array creation failed!"<<std::endl;
        exit(1);
    }

    return *this;
}

//Function that lets the user input the domioe blocks of the newly created collection
void Chain::newChain(size_t size)
{
    createCollectionOfBlocks(size);

    for(size_t i = 0; i < size;i++) 
    {
        this->dominos[i].addNewDominoe();
    }
}

void Chain::printChain()
{
    for(size_t i = 0; i < size; i++)
    {
        std::cout << this->dominos[i].firstHalf << "-" << this->dominos[i].secondHalf <<" ";
    }
    std::cout<<std::endl;
}

Dominoe& Chain::getDominoe(size_t index)
{   
    if(index >= size || index < 0) exit(1);
    return this->dominos[index];
}

//adds the dominoe to the end of the chain and icrements the size of the chain
void Chain::addDominoeToChain(Dominoe& dom)
{   
    this->size++;
    this->dominos[this->size-1] = dom;
}

//adds a dominoe block at certain index to the chain
void Chain::addDominoeAt(size_t index, Dominoe& dom)
{
    if(this->chainIsEmpty()) 
    {
        this->dominos[0] = dom;
        this->size++;
    }

    else if(index == 0)
    {
        this->size++;

        for(int i = this->size; i > 0; i--)
        {
            this->dominos[i] = this->dominos[i-1];
        }

        this->dominos[0] = dom;
    }

    else
    {
        this->size++;

        for(int i = this->size; i >= index; i--) 
        {    
            if(i == index) this->dominos[i] = dom;
            else this->dominos[i] = this->dominos[i-1];
        }
    }
}

//removes a domino from a certain index and decreases the size of the dominos array
//returns the removed domino
Dominoe& Chain::removeDominoeFromChain(size_t index)
{
    Dominoe dom;

    if(index == this->size - 1) this->size--;

    else
    {      
        dom = this->dominos[index];

        if(index < this->size) 
        {           
            this->size--; 

            for (size_t j = index; j<this->size; j++)
            {
                this->dominos[j] = this->dominos[j+1];
            }
        }
    }

    return *dom;
}

bool Chain::chainIsEmpty() const
{
    return (this->size == 0) ? true : false;
}

//Function that checks whether a dominoe can be added to the chain
const bool canBeAdded(const Dominoe& dom, Chain& other)
{
    bool result = false;

    if(other.chainIsEmpty()) result = true;

    for(size_t i = 0; i < other.size; ++i)
    {
        if(dom.firstHalf == other.getDominoe(i).secondHalf) result = true;
        if(dom.secondHalf == other.getDominoe(i).firstHalf) result = true;
    }

    return result;
}

//returns the index of the position where a dominoe should be inserted
size_t whereCanBeAdded(const Dominoe& dom, Chain& other)
{
    size_t result;

    if(other.chainIsEmpty()) result = 0;

    for(size_t i = 0; i < other.size; ++i)
    {
        if(dom.firstHalf == other.getDominoe(i).secondHalf) result = i+1;
        if(dom.secondHalf == other.getDominoe(i).firstHalf) result = i-1;
        if(i == 0 && dom.secondHalf == other.getDominoe(i).firstHalf) result = 0;
    }

    return result;
}

//This is the game function:
void dominoFunction(Chain& chain, Chain& collection) 
{
    std::cout<<"============================================================="<<std::endl;
    //based of the size of the collection this function enters a for loop, 
    for (size_t i = 0; i < collection.size; i++)
    {
        //the current index i, indicates the current dominoe from the collection
        //which we check if could be added to the chain
        Dominoe dominoeBlock = collection.getDominoe(i);

        if(canBeAdded(dominoeBlock, chain))
        {
            //if it can be added to the chain, th eexact position is found and then
            size_t pos = whereCanBeAdded(dominoeBlock, chain);
            //it is added to the chain
            chain.addDominoeAt(pos, dominoeBlock);

            chain.printChain();
            
            //then the dominoe that we recently used is removed from the collection
            Dominoe removed = collection.removeDominoeFromChain(i);

            //and the function is called recursively with the new collection
            dominoFunction(chain, collection);

            //then the removed dominoe is added to the collection again
            collection.addDominoeAt(i, removed);
            //and the added element is removed from the chain
            chain.removeDominoeFromChain(pos);
            //that is done in order to test all the combinations of the blocks 
        }

        //if the first if statement was false then we flip the dominoe
        dominoeBlock = dominoeBlock.flipDominoe();
    
        //and we check if this time it can be added to the chain by going through the same steps as above
        if(canBeAdded(dominoeBlock, chain))
        {
            size_t pos = whereCanBeAdded(dominoeBlock, chain);
            chain.addDominoeAt(pos, dominoeBlock);
 
            chain.printChain();
            Dominoe removed = collection.removeDominoeFromChain(i);
            
            dominoFunction(chain, collection);

            collection.addDominoeAt(i, removed);
            chain.removeDominoeFromChain(pos);
        }
    }    
}

//user input size
size_t inputSize()
{
    size_t size = 0;

    while (size <= 0)
    {
        std::cin>>size;
    }

    return size;
}

int main()
{

    Chain dominoBlocks;
    Chain dominoGameCombo;
    size_t size = inputSize();

    dominoGameCombo.createCollectionOfBlocks(0);
    dominoBlocks.newChain(size);

    dominoFunction(dominoGameCombo, dominoBlocks);

    return 0;
}