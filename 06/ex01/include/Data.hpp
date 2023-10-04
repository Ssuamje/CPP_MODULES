#ifndef DATA_HPP
#define DATA_HPP

class Data {
    private:
        std::string data;

    public:
        Data();
        Data(const Data& ref);
        ~Data();

        Data&	operator=(const Data& ref);

        std::string getData() const;
};

#endif
