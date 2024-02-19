#ifndef MAPREADER_H
#define MAPREADER_H
#include <string>

class mapReader
{
private:
    std::string map[10][10];
public:
    mapReader();
    /**
     * \brief init check if the file is here and create a board with its content.
     */
    void init(int);
    /**
     * \brief getValueOf give the value of the entity on the board x;y.
     * \param x the x-axis.
     * \param y the y-axis.
     * \return a string, value of the entity of the board.
     */
    std::string getValueOf(int x,int y)const;
};

#endif // MAPREADER_H
