struct cell
{
    unsigned condition:1;
};
class Field
{
    private:
    cell* cells_;
    unsigned int height_;
    unsigned int length_;
    cell& at(unsigned int, unsigned int);
    public:
    Field();
    Field(unsigned int, unsigned int,bool);
    ~Field();
    unsigned int getLength();
    unsigned int getHeight();
    bool getCell(unsigned int,unsigned int);
    void setCell(unsigned int,unsigned int,bool);
    unsigned int CountNei(unsigned int,unsigned int);
    void NextGen();  
};
