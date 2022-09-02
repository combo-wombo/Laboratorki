#ifndef ERRORS_H
#define ERRORS_H


class Error {
protected:
    std::string errMsg;
public:
    static int count;
    static Error** items;
    Error(std::string message);
    ~Error();
    void PrintMsg();

    bool operator==(const Error& other) {
        bool result;
        result = (typeid(*this) == typeid(other)) && (errMsg == other.errMsg);
        if (result == 1){
            std::cout << "\"" << this->errMsg << "\" равно \"" << other.errMsg << "\"" << std::endl;
        }
        else {
            std::cout <<"\"" << this->errMsg << "\" НЕ равно \"" << other.errMsg << "\"" << std::endl;
        }
        return result;
    }
    bool operator!=(const Error& other) {
        return !(*this == other);
    }

    Error& operator=(const Error& other) {
        errMsg = other.errMsg;
        std::cout << "Присваиваем один элемент к другому... " << std::endl;
        return *this;
    }
};

class AccessError : public Error {
protected:
    int accessLevelNeeded;
public:
    AccessError(std::string message);
    ~AccessError();
};

class TranslateError : public Error {
public:
    TranslateError(std::string message);
    ~TranslateError();
    virtual void PrintTypes();
};

class ValueTranslateError : public TranslateError {
public:
    ValueTranslateError(std::string message);
    ~ValueTranslateError();
    void PrintTypes() override;
};

class InterfaceTranslateError : public TranslateError {
public:
    InterfaceTranslateError(std::string message);
    ~InterfaceTranslateError();
    void PrintTypes() override;
};

class ErrorArray {
    Error** ptrArray;  //PointerArray
    int count;  //ArrayElementCount
public:
    ErrorArray();
    int Length() const;
    void AddToList(Error* error);
    void PrintArray() const;
    void operator[](int i);
};

#endif 