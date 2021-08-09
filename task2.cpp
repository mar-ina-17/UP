#include <iostream>
const int MAX_STRING_LENGTH = 10;
const int MAX_SENTENCE_LENGTH = 1000;

//Function that allows user to input desired size for new array
size_t inputSize()
{
    size_t size = 0;

    while (size < 1)
    {
        std::cin >> size;
    }

    return size;
}

//Function that returns the size of an one-dimensional character array
size_t getSize(const char* array)
{
    size_t size = 0;

    while (array[size])
    {
        size++;
    }

    return size-1;
}

//Function that creates one-dimensional array using the desired size as parameter 
//and returns the array if it's successfully created.
//It is used mainly for the letters of the CryptingTable.
char* createArray(size_t size)
{
    char* array = new (std::nothrow) char[size];
    if(!array)
    {
        std::cout << "ERROR! Memory allocation problem!" << std::endl;
        exit(1);
    }

    return array;
}

//Function that creates two-dimensional array using the specified size as parameter
//and then allocating const max size for the words in the array
//Used to create the encoding of the letters in the CryptingTable, as every encoded word has ist own size
char** create2DArray(size_t size)
{
    char** array = new (std::nothrow) char*[size];

    for(size_t i = 0; i < size; i++)
    {
        array[i] = new (std::nothrow) char[MAX_STRING_LENGTH];
        if(!array[i])
        {
            std::cout << "ERROR! Memory allocation problem!" << std::endl;
            exit(1);
        }
    }

    return array;
}

//Function that inputs the CryptingTable 
void inputCryptingTable(char* letters, char** values, size_t size)
{
    for(size_t i = 0; i < size; i++)
    {
        std::cin>>letters[i]>>values[i];
    }
}

//Function that inputs the sentences that will be encoded or decoded
void inputSentences(char** sentences, size_t size)
{
    std::cin.ignore();

    for(size_t i = 0, j = 0; i < size; i++)
    {
        std::cin.getline(sentences[i], MAX_SENTENCE_LENGTH); 
    }
}

//Function that converts an upper-case character to a lowercase character
char currentCharToLower(char currentChar)
{
    return (currentChar > 64 && currentChar < 91) ? currentChar += 32 : currentChar;
}

//ENCRYPTING CODE

//Function that searches in the CryptingTable by comparing the current character (converted to lowercase in advance) of a sentence
//to the letters in the table and prints the corresponding encodings by the index of the letter in the table.
//Otherwise prints the current character of the word.
void searchInCryptingTable(char character, char* letters, char** values, size_t size)
{
    bool isFound = false;

    for(size_t i = 0; i < size; i++)
    {
        if(currentCharToLower(character) == letters[i])
        {
            std::cout <<values[i];
            isFound = true;
        } 
    }

    if(!isFound)
    {
       std::cout <<character; 
    } 
}

//Function that encrypts the user input sentences one by one,
// calling the search function for each character of the sentence
void encrypt(char*letters, char** values, size_t size, char** sentences, size_t sentencesSize)
{
    std::cout<<"------Encrypted sentences------"<<std::endl;
   
    for(int i = 0; i < sentencesSize; i++)
    {
        for(int j = 0; j <= getSize(sentences[i]); j++)
        {
            searchInCryptingTable(sentences[i][j], letters, values, size);
        }

        std::cout<<std::endl;
    }
}

//DECRYPTING CODE

//Function that checks if each of the encodings from the table is contained in current given word of a sentence 
bool containsEncryptedValue(char* word, char*encryptedValue)
{
    bool isFound = false; //bool to determine if a character of the encryptedValue is contained in the word
    int index = -1, counter = 0; 
    // index - used to show where is an equal character located in the word
    //counter - increments every time a character is found  

    for(size_t encrPos = 0, wordPos = 0; encrPos < getSize(encryptedValue), word[wordPos];)
    {
        //in order to increase the times a character is found the given word character should be equal to the encryptedValue character
        //AND the current should be equal to (index + 1), as index holds the position of the previously found character
        //OR index = -1 this indicates that this is either the first character in word or a newly found sequence
        if(word[wordPos] == encryptedValue[encrPos] && (wordPos == (index+1) || index == -1))
        {
            isFound = true;
            index = wordPos;
            counter++;
            encrPos++;
            wordPos++;
        }
        else
        {
            isFound = false;
            index = -1;
            counter = 0;
            encrPos = 0;
            wordPos++;
        }
        
        //returns true if the whole encryptedValue is found in the word
        if((counter-1) == getSize(encryptedValue)) return true;
    }

    return isFound;
}

//Function that counts the size of each word in the senetence
size_t countCharacters(char* word, size_t pos)
{
    //if the current position is 0 then this is the first word in the sentence and initializes i with a 0
    //else i is incremented with 2,because of the interval between the previous and the current word
    size_t i = (pos == 0) ? 0 : pos+2;

    while(word[i])
    {
        if(word[i] == ' ') break;
        i++; 
    } 

    return i;
}

//Function that determines array size by counting the intervals between the words
//the amount of intervals + 1 is the number of words in a sentence.
//This is used to create an array of words for each sentence.
size_t determineArraySize(char* sentence)
{
    const char delimiter = ' ';
    size_t i = 0, size = 1;

    while(sentence[i])
    {
        if(sentence[i] == delimiter && sentence[i+1] != delimiter)
        {
            size++;
        }

        i++;
    }

    return size;
}

//Function that creates new array for a sentence
char** createSentenceArray(size_t size)
{
    char** array = new (std::nothrow) char*[size+1];    

    if(!array)
    {
        std::cout << "ERROR!New array not created" << std::endl;
        exit(1);
    }

    return array;
}

//This function is used to allocate space for each word of a sentence in a newly created array
//then having the corresponding wods located in the array and searching for encryptedValues in them
char** decrypt(char* sentence, char *letters, char**values,size_t size )
{
    
    size_t newArraySize = determineArraySize(sentence);

    char** newArray = createSentenceArray(newArraySize);
        
    size_t n = 0, tmp;

    for(size_t j = 0; j < newArraySize; j++)
    {
        tmp = n+1;
        n = countCharacters(sentence, n);

        newArray[j] = new (std::nothrow) char[n-tmp];
        if(!newArray[j])
        { 
            std::cout<<"ERROR"<<std::endl;
            exit(1);
        }

        for(size_t s = tmp-1, m = 0; s < n; s++, m++)
        {
            if(sentence[s] != ' ')
            {
                newArray[j][m] = sentence[s];
            }

            else
            {
                newArray[j][m] = sentence[s+1];
                s++;
            }
        }
    }

    for(size_t j = 0; j < newArraySize; j++)
    {
        for(size_t i = 0; i < size; i++)
        {
            bool isFound = containsEncryptedValue(newArray[j], values[i]);

            if(isFound) std::cout<<letters[i];
        }

        std::cout<<" ";
    }

    return newArray;
}

//Processes each input sentence for decrypting
void decryptProcessing(char *letters, char**values,size_t size , char**sentences,size_t sentencesSize)
{
    std::cout<<"------Decrypted sentences------"<<std::endl;
    
    for(int i = 0; i < sentencesSize; i++)
    {
        decrypt(sentences[i],letters, values, size);
    }
}

//deletes 2D arrays
void delete2DArray(char** array, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        delete[] array[i];
    }
    delete[] array;
}

int main()
{
    size_t size = inputSize();
    char* letters = createArray(size);
    char** values = create2DArray(size);

    inputCryptingTable(letters, values, size);

    size_t sentencesArraySize = inputSize();
    char** sentencesArray = create2DArray(sentencesArraySize);
    inputSentences(sentencesArray, sentencesArraySize);
    encrypt(letters, values,  size, sentencesArray, sentencesArraySize);

    size_t decryptArraySize = inputSize();
    char** decryptArray = create2DArray(decryptArraySize);
    inputSentences(decryptArray, decryptArraySize);
    decryptProcessing(letters, values,  size, decryptArray, decryptArraySize);

    delete[] letters;
    delete2DArray(values, size);
    delete2DArray(decryptArray, decryptArraySize);

    return 0;
}